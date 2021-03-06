//
// Created by jeza on 18-4-11.
//

#include "GameSceneII.h"
#include "BarrierBuilder.h"
#include "SceneManager.h"
#include "OptLayer.h"
#include "MonsterLayer.h"
#include "ScoreAndControlLayer.h"
#include "BM_ScoreAndControlLayer.h" //BOSS MODE
#include "TiledMapLayer.h"
#include "TowersLayer.h"
#include "BarriersLayer.h"
#include "BulletLayer.h"
#include "BulletManager.h"
#include "TowerManager.h"
#include "BarrierManager.h"
#include "MonsterManager.h"
#include "MapUtil.h"
#include "BarrierBase.h"
#include "CollisionManager.h"
#include "MonsterBuilder.h"
#include "BM_MonsterBuilder.h" //BOSS MODE
#include "TowerFactory.h"
#include "Carrot.h"
#include "TowerOptBtn.h"
#include "CountDownLayer.h"
#include "GameEndLayer.h"
#include "BM_GameEndLayer.h" //BOSS MODE
#include "SoundUtil.h"
#include "LevelConfigUtil.h"
#include "GameManager.h"

GameSceneII::~GameSceneII()
{
    removeAllChildrenWithCleanup(true);

    CC_SAFE_RELEASE_NULL(_pBarriersLayer);
    CC_SAFE_RELEASE_NULL(_pBulletsLayer);
    CC_SAFE_RELEASE_NULL(_pCarrot);
    CC_SAFE_RELEASE_NULL(_pMonsterLayer);
    CC_SAFE_RELEASE_NULL(_pOptLayer);
    CC_SAFE_RELEASE_NULL(_pScoreAndControllerLayer);
    CC_SAFE_RELEASE_NULL(_pTiledMapLayer);
    CC_SAFE_RELEASE_NULL(_pTowersLayer);
    CC_SAFE_RELEASE_NULL(_pCountDownLayer);
    CC_SAFE_DELETE(_pSourceVec);

    clearAllManager();
}

Carrot * GameSceneII::getCarrot()
{
    return _pCarrot;
}

void GameSceneII::clickChooseItem()
{
    if (GameManager::getInstance()->getCurrGameType() == en_Adventure)
    {
        dynamic_cast<ScoreAndControllerLayer*>(_pScoreAndControllerLayer)->clickChooseItem();
    }
    else
    {
        dynamic_cast<BM_ScoreAndControllerLayer*>(_pScoreAndControllerLayer)->clickChooseItem();
    }
}

bool GameSceneII::init()
{
    bool bRet = false;
    do
    {
        CC_BREAK_IF(!Scene::init());

        _pSourceVec = new std::vector<std::string>;
        this->setName("GameScene");
        preLoadSource();

        bRet = true;

    } while (0);
    return bRet;
}

void GameSceneII::onEnter()
{
    Scene::onEnter();
    addLayers();
    createBarriers(); //创建障碍物

    //冒险模式才有萝卜，BOSS模式没有的
    if (GameManager::getInstance()->getCurrGameType() == en_Adventure)
        _pMonsterLayer->addEntity(_pCarrot); //在怪物层里面添加萝卜

    registerGameEvent(); //TODO 在这里注册

    //播放对应主题的背景音乐
    SoundUtil::getInstance()->playBackgroundSound(StringUtils::format(THEMEBACKGROUNDMUSIC, SceneManager::getInstance()->getCurrentPageIndex() + 1).c_str());

    schedule(schedule_selector(GameSceneII::collisionUpDate), 0.05);
}

void GameSceneII::onExit()
{
    NOTIFY->removeAllObservers(this);
    unLoadSource();
    Scene::onExit();
}

//TODO 好像不太行的样子
void GameSceneII::preLoadSource()
{
    int iCurThemeIndex = SceneManager::getInstance()->getCurrentPageIndex() + 1;
    int iCurLevelIndex = SceneManager::getInstance()->getCurrentLevelIndex() + 1;

    LevelConfigUtil::getInstance()->loadLevelConfig();
    //现在开始加载资源
    //把对应关卡资源的完全路径放在一个向量中
    //然后对应向量每个元素进行异步加载
    _pSourceVec->push_back(StringUtils::format(GAMESCENEBG1, iCurThemeIndex));
    //加载对应关卡游戏界面的背景
    _pSourceVec->push_back(StringUtils::format(GAMESCENEMAP, iCurThemeIndex, iCurLevelIndex) + "BG-hd");
    //加载障碍物资源
    _pSourceVec->push_back(StringUtils::format(GAMESCENEBARRIER, iCurThemeIndex));
    //加载小怪兽资源
    _pSourceVec->push_back(StringUtils::format(GAMESCENEMONSTER1, iCurThemeIndex));
    //加载大怪兽资源
    _pSourceVec->push_back(StringUtils::format(GAMESCENEMONSTER2, iCurThemeIndex));

    //对向量的每一个资源路径，进行异步加载
    for (auto &iterSourcePath : *_pSourceVec)
    {
        Director::getInstance()->getTextureCache()->addImageAsync(iterSourcePath + PHOTOPOSTFIX,
                                                                  [&](Texture2D *pTexture)
                                                                  {
                                                                      _iSourceCount++;
                                                                      SpriteFrameCache::getInstance()->addSpriteFramesWithFile(
                                                                              iterSourcePath + PLISTPOSTFIX, pTexture);
                                                                      if (_iSourceCount == _pSourceVec->size())
                                                                      {
                                                                          createLayers();
                                                                          NOTIFICATION_CENTER->postNotification(
                                                                                  "loadFinished",
                                                                                  static_cast<Ref *>(this));
                                                                      }
                                                                  });
    }
}

void GameSceneII::unLoadSource()
{
    sourceManager(*_pSourceVec, false);
}

void GameSceneII::collisionUpDate(float dt)
{
    CollisionManager::collision(BarrierManager::getInstance()->getBarrierVec(), MonsterManager::getInstance()->getMonsterVec(), BulletManager::getInstance()->getBulletVec());
}

void GameSceneII::createLayers()
{
    //TODO 目前只支持加载地图、怪物图层
    _pTiledMapLayer = TiledMapLayer::create();
    _pTiledMapLayer->retain();

    _pMonsterLayer = MonsterLayer::create();
    _pMonsterLayer->setName("monsterLayer");
    _pMonsterLayer->retain();

    _pBarriersLayer = BarriersLayer::create();
    _pBarriersLayer->retain();

    //障碍物管理类用这个图层的方法作为障碍物添加时的显示函数
    BarrierManager::getInstance()->setFuncAddBarrierToLayer(CC_CALLBACK_1(BarriersLayer::addEntity, _pBarriersLayer));

    MonsterManager::getInstance()->setFuncAddMonsterToLayer(
            CC_CALLBACK_1(MonsterLayer::addEntity, _pMonsterLayer)); //怪物管理类用这个图层的方法作为新怪物添加时的显示函数

    //TODO 只用于调试
    // NOTIFICATION_CENTER->postNotification("startBuildMonster");

    _pTowersLayer = TowersLayer::create();
    _pTowersLayer->retain();

    TowerManager::getInstance()->setFuncAddTowerLayer(CC_CALLBACK_1(TowersLayer::addEntity, _pTowersLayer));

    _pBulletsLayer = BulletLayer::create();
    _pBulletsLayer->setTag(1);
    _pBulletsLayer->retain();
    BulletManager::getInstance()->setFuncAddBulletLayer(CC_CALLBACK_1(BulletLayer::addEntity, _pBulletsLayer));

    /*********************************************/
    /****需对游戏模式进行判断，选取不同的怪物生成类****/
    /*********************************************/
    if (GameManager::getInstance()->getCurrGameType() == en_Adventure) 
    {
        _pScoreAndControllerLayer = ScoreAndControllerLayer::create();
        _pScoreAndControllerLayer->retain();
        TowerManager::getInstance()->setFuncCheckMoney(CC_CALLBACK_0(ScoreAndControllerLayer::getCurMoney, dynamic_cast<ScoreAndControllerLayer*>(_pScoreAndControllerLayer)));
    }
    else
    {
        _pScoreAndControllerLayer = BM_ScoreAndControllerLayer::create();
        _pScoreAndControllerLayer->retain();
        TowerManager::getInstance()->setFuncCheckMoney(CC_CALLBACK_0(BM_ScoreAndControllerLayer::getCurMoney, dynamic_cast<BM_ScoreAndControllerLayer*>(_pScoreAndControllerLayer)));
    }


    _pOptLayer = OptLayer::create();
    _pOptLayer->retain();

    GameManager::getInstance()->getCurrGameType() == en_Adventure ?
        dynamic_cast<TowerOptBtn*>(_pOptLayer->getChildByName("TowerOptBtn"))->setFuncCheckMoney(CC_CALLBACK_0(ScoreAndControllerLayer::getCurMoney, dynamic_cast<ScoreAndControllerLayer*>(_pScoreAndControllerLayer))) :
        dynamic_cast<TowerOptBtn*>(_pOptLayer->getChildByName("TowerOptBtn"))->setFuncCheckMoney(CC_CALLBACK_0(BM_ScoreAndControllerLayer::getCurMoney, dynamic_cast<BM_ScoreAndControllerLayer*>(_pScoreAndControllerLayer)));

    if (GameManager::getInstance()->getCurrGameType() == en_Adventure)
    {
        _pCarrot = Carrot::create();
        _pCarrot->retain();
    }

    _pCountDownLayer = CountDownLayer::create();
    _pCountDownLayer->setName("CoundDown");
    _pCountDownLayer->retain();
}

void GameSceneII::addLayers()
{
    addChild(_pCountDownLayer, 100);
    addChild(_pTiledMapLayer);
    addChild(_pBarriersLayer);
    addChild(_pTowersLayer);
    addChild(_pMonsterLayer);
    addChild(_pBulletsLayer);
    addChild(_pOptLayer);
    addChild(_pScoreAndControllerLayer);
}


void GameSceneII::clearAllManager()
{
    //bug 妈耶，忘记写了
    MonsterManager::getInstance()->clearManager();
    TowerManager::getInstance()->clearManager();
    BulletManager::getInstance()->clearManager();
    BarrierManager::getInstance()->clearManager();
}

void GameSceneII::registerGameEvent()
{
    NOTIFICATION_CENTER->addObserver(this, callfuncO_selector(GameSceneII::startBuildMonster), "startBuildMonster",
                                     nullptr);
    NOTIFICATION_CENTER->addObserver(this, callfuncO_selector(GameSceneII::showGameEndLayer), "gameEnd", nullptr);
}

void GameSceneII::showGameEndLayer(Ref * pData)
{
    auto tGameEndType = *(reinterpret_cast<GameEndType*>(pData));
    Layer *pGameEndLayer = nullptr;
    if (GameManager::getInstance()->getCurrGameType() == en_Adventure)
        pGameEndLayer = GameEndLayer::create(tGameEndType);
    else
        pGameEndLayer = BM_GameEndLayer::create(tGameEndType);

    pGameEndLayer->setName("GameEnd");
    addChild(pGameEndLayer, 11); //要叠在怪物图层上面
}

void GameSceneII::startBuildMonster(Ref *pData)
{
    /*********************************************/
    /****需对游戏模式进行判断，选取不同的怪物生成类****/
    /*********************************************/
    if (GameManager::getInstance()->getCurrGameType() == en_Adventure)
        addChild(MonsterBuilder::create());
    else
        addChild(BM_MonsterBuilder::create());

    auto aScheduler = Director::getInstance()->getScheduler();
    aScheduler->setTimeScale(1.8f); //TODO 速度
}

void GameSceneII::createBarriers()
{
    addChild(BarrierBuilder::create()); //bug fixed
}
