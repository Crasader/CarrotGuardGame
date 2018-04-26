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
    createBarriers(); //�����ϰ���

    //ð��ģʽ�����ܲ���BOSSģʽû�е�
    if (GameManager::getInstance()->getCurrGameType() == en_Adventure)
        _pMonsterLayer->addEntity(_pCarrot); //�ڹ������������ܲ�

    registerGameEvent(); //TODO ������ע��

    SoundUtil::getInstance()->playBackgroundSound(StringUtils::format(THEMEBACKGROUNDMUSIC, SceneManager::getInstance()->getCurrentPageIndex() + 1).c_str());

    schedule(schedule_selector(GameSceneII::collisionUpDate), 0.05);
}

void GameSceneII::onExit()
{
    NOTIFY->removeAllObservers(this);
    unLoadSource();
    Scene::onExit();
}

//TODO ����̫�е�����
void GameSceneII::preLoadSource()
{
    int iCurThemeIndex = SceneManager::getInstance()->getCurrentPageIndex() + 1;
    int iCurLevelIndex = SceneManager::getInstance()->getCurrentLevelIndex() + 1;

    LevelConfigUtil::getInstance()->loadLevelConfig();
    //���ڿ�ʼ������Դ
    //�Ѷ�Ӧ�ؿ���Դ����ȫ·������һ��������
    //Ȼ���Ӧ����ÿ��Ԫ�ؽ����첽����
    _pSourceVec->push_back(StringUtils::format(GAMESCENEBG1, iCurThemeIndex));
    //���ض�Ӧ�ؿ���Ϸ����ı���
    _pSourceVec->push_back(StringUtils::format(GAMESCENEMAP, iCurThemeIndex, iCurLevelIndex) + "BG-hd");
    //�����ϰ�����Դ
    _pSourceVec->push_back(StringUtils::format(GAMESCENEBARRIER, iCurThemeIndex));
    //����С������Դ
    _pSourceVec->push_back(StringUtils::format(GAMESCENEMONSTER1, iCurThemeIndex));
    //���ش������Դ
    _pSourceVec->push_back(StringUtils::format(GAMESCENEMONSTER2, iCurThemeIndex));

    //��������ÿһ����Դ·���������첽����
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
    //TODO Ŀǰֻ֧�ּ��ص�ͼ������ͼ��
    _pTiledMapLayer = TiledMapLayer::create();
    _pTiledMapLayer->retain();

    _pMonsterLayer = MonsterLayer::create();
    _pMonsterLayer->setName("monsterLayer");
    _pMonsterLayer->retain();

    _pBarriersLayer = BarriersLayer::create();
    _pBarriersLayer->retain();

    //�ϰ�������������ͼ��ķ�����Ϊ�ϰ������ʱ����ʾ����
    BarrierManager::getInstance()->setFuncAddBarrierToLayer(CC_CALLBACK_1(BarriersLayer::addEntity, _pBarriersLayer));

    MonsterManager::getInstance()->setFuncAddMonsterToLayer(
            CC_CALLBACK_1(MonsterLayer::addEntity, _pMonsterLayer)); //��������������ͼ��ķ�����Ϊ�¹������ʱ����ʾ����

    //TODO ֻ���ڵ���
    // NOTIFICATION_CENTER->postNotification("startBuildMonster");

    _pTowersLayer = TowersLayer::create();
    _pTowersLayer->retain();

    TowerManager::getInstance()->setFuncAddTowerLayer(CC_CALLBACK_1(TowersLayer::addEntity, _pTowersLayer));

    _pBulletsLayer = BulletLayer::create();
    _pBulletsLayer->setTag(1);
    _pBulletsLayer->retain();
    BulletManager::getInstance()->setFuncAddBulletLayer(CC_CALLBACK_1(BulletLayer::addEntity, _pBulletsLayer));

    /*********************************************/
    /****�����Ϸģʽ�����жϣ�ѡȡ��ͬ�Ĺ���������****/
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
    //bug ��Ү������д��
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
    addChild(pGameEndLayer, 11); //Ҫ���ڹ���ͼ������
}

void GameSceneII::startBuildMonster(Ref *pData)
{
    /*********************************************/
    /****�����Ϸģʽ�����жϣ�ѡȡ��ͬ�Ĺ���������****/
    /*********************************************/
    if (GameManager::getInstance()->getCurrGameType() == en_Adventure)
        addChild(MonsterBuilder::create());
    else
        addChild(BM_MonsterBuilder::create());

    auto aScheduler = Director::getInstance()->getScheduler();
    aScheduler->setTimeScale(1.8f); //TODO �ٶ�
}

void GameSceneII::createBarriers()
{
    addChild(BarrierBuilder::create()); //bug fixed
}
