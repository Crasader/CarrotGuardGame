//
// Created by jeza on 18-4-11.
//

#include "GameSceneII.h"
#include "EntityLayerBase.h"
#include "SceneManager.h"
#include "TiledMapLayer.h"
#include "LevelConfigUtil.h"
#include "MonsterLayer.h"
#include "MonsterManager.h"
#include "MonsterBuilder.h"

GameSceneII::~GameSceneII()
{
    CC_SAFE_RELEASE_NULL(_pBarriersLayer);
    CC_SAFE_RELEASE_NULL(_pBulletsLayer);
    //CC_SAFE_RELEASE_NULL(_pCarrot);
    CC_SAFE_RELEASE_NULL(_pMonsterLayer);
    CC_SAFE_RELEASE_NULL(_pOptLayer);
    CC_SAFE_RELEASE_NULL(_pScoreAndControllerLayer);
    CC_SAFE_RELEASE_NULL(_pTiledMapLayer);
    CC_SAFE_RELEASE_NULL(_pTowersLayer);
    CC_SAFE_DELETE(_pSourceVec);

    clearAllManager();
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
        registerGameEvent(); //TODO ������ע��

        bRet = true;

    } while (0);
    return bRet;
}

void GameSceneII::onEnter()
{
    Scene::onEnter();
    addLayers();
}

void GameSceneII::onExit()
{

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

void GameSceneII::createLayers()
{
    //TODO Ŀǰֻ֧�ּ��ص�ͼ������ͼ��
    _pTiledMapLayer = TiledMapLayer::create();
    _pTiledMapLayer->retain();

    _pMonsterLayer = MonsterLayer::create();
    _pMonsterLayer->setName("monsterLayer");
    _pMonsterLayer->retain();

    MonsterManager::getInstance()->setFuncAddMonsterToLayer(CC_CALLBACK_1(MonsterLayer::addEntity, _pMonsterLayer)); //��������������ͼ��ķ�����Ϊ�¹������ʱ����ʾ����

    //TODO ֻ���ڵ���
    NOTIFICATION_CENTER->postNotification("startBuildMonster");
}

void GameSceneII::addLayers()
{
    //TODO Ŀǰֻ֧�ּ����ͼͼ�㡢����ͼ��
    addChild(_pTiledMapLayer);
    addChild(_pMonsterLayer);

}

void GameSceneII::clearAllManager()
{
    MonsterManager::getInstance()->clearManager();
}

void GameSceneII::registerGameEvent()
{
    //TODO Ŀǰֻ֧��ע�ṹ�������¼�
    NOTIFICATION_CENTER->addObserver(this, callfuncO_selector(GameSceneII::startBuildMonster), "startBuildMonster", nullptr);
}

void GameSceneII::startBuildMonster(Ref * pData)
{
    addChild(MonsterBuilder::create());
    auto aScheduler = Director::getInstance()->getScheduler();
    aScheduler->setTimeScale(2.0f); //TODO ???
}
