#include "BM_ScoreAndControlLayer.h"
#include "PauseLayer.h"
#include "NumSprite.h"
#include "LevelConfigUtil.h"
#include "SoundUtil.h"
#include "CommonSource.h"
#include "MonsterLayer.h"
#include "GameSceneII.h"
#include "GameManager.h"
#include "SceneManager.h"

bool BM_ScoreAndControllerLayer::init()
{
    bool bRet = false;
    do
    {
        CC_BREAK_IF(!Layer::init());

        registerNotifyEvent();

        loadData();
        loadBg();

        createTopPanel();
        createBottomPanel();

        //�����һ��̫���ˣ��ĳ�1.8s = 1s
        schedule(schedule_selector(BM_ScoreAndControllerLayer::timeChange), 1.8f, 150, 4);
        schedule(schedule_selector(BM_ScoreAndControllerLayer::bossHpChanged), 0.6f);

        bRet = true;
    }
    while (0);

    return bRet;
}

void BM_ScoreAndControllerLayer::loadBg()
{
    auto tVisibleSize = Director::getInstance()->getVisibleSize();
    //�˵���屳����
    auto pPanelBg = Sprite::createWithSpriteFrameName("MenuBG.png");
    pPanelBg->setPosition(Vec2(tVisibleSize.width / 2, tVisibleSize.height - pPanelBg->getContentSize().height / 2));
    addChild(pPanelBg);

    auto tSize = Sprite::create(MONSTERBATCHIMAGE)->getContentSize();
    auto pMonsterBatchCountSprite = NumSprite::createNum(
        StringUtils::format("%d", LevelConfigUtil::getInstance()->getCurrentMonsterBatchCount()), MONEYNUMIMAGE);
    addChild(pMonsterBatchCountSprite);

    _pMoneyLabel = NumSprite::createNum(StringUtils::format("%d", _iMoney), MONEYNUMIMAGE);
    addChild(_pMoneyLabel);
    _pMoneyLabel->release();
    _pMoneyLabel->setPosition(100, 603);

    //����Ѫ������
    auto aBossHpBarBg = Sprite::createWithSpriteFrameName("menublood_02.png");
    aBossHpBarBg->setPosition(465, 603);
    addChild(aBossHpBarBg);
    //todo Ҫ��Ҫ�Ŵ�

    //����Ѫ��������
    auto aBossHpBar = ProgressTimer::create(Sprite::createWithSpriteFrameName("menublood_01.png"));
    aBossHpBar->setType(ProgressTimer::Type::BAR);
    aBossHpBar->setName("BossHpBar");

    aBossHpBarBg->setScaleX(aBossHpBar->getContentSize().width / aBossHpBarBg->getContentSize().width - 0.14);
    aBossHpBarBg->setScaleY(aBossHpBar->getContentSize().height / aBossHpBarBg->getContentSize().height);


    //todo �����ٷ�api����
    aBossHpBar->setMidpoint(Vec2::ANCHOR_MIDDLE_LEFT); //�������
    //aBossHpBar->setAnchorPoint(Vec2::ANCHOR_MIDDLE_RIGHT);
    aBossHpBar->setBarChangeRate(Vec2::ANCHOR_BOTTOM_RIGHT);
    aBossHpBar->setPercentage(100);
    aBossHpBar->setPosition(465, 603);
    addChild(aBossHpBar);
}

void BM_ScoreAndControllerLayer::createTopPanel()
{
    auto pPauseItem = MenuItemSprite::create(Sprite::createWithSpriteFrameName("pause01.png"),
                                             Sprite::createWithSpriteFrameName("pause02.png"));
    auto pContinueItem = MenuItemSprite::create(Sprite::createWithSpriteFrameName("pause11.png"),
                                                Sprite::createWithSpriteFrameName("pause12.png"));
    //��ͣ�����л���
    auto pPauseItemToggleItem = MenuItemToggle::createWithCallback([&](Ref* pSender)
    {
        auto pDirector = Director::getInstance()->getInstance();
        pDirector->isPaused() ? pDirector->resume() : pDirector->pause();
        auto pGameManager = GameManager::getInstance();
        pGameManager->setIsPause(!pGameManager->getIsPause());
    }, pPauseItem, pContinueItem, nullptr);
    pPauseItemToggleItem->setPosition(300, 275);

    auto pChooseItems = MenuItemSprite::create(Sprite::createWithSpriteFrameName("menu01.png"),
                                               Sprite::createWithSpriteFrameName("menu02.png"), [&](Ref* pSender)
                                               {
                                                   this->clickChooseItem();
                                               });
    pChooseItems->setPosition(400, 275);
    _pChooseItem = pChooseItems;
    //�˵���壻
    auto pMenuPanel = Menu::create(pPauseItemToggleItem, pChooseItems, nullptr);
    addChild(pMenuPanel);
}

void BM_ScoreAndControllerLayer::createBottomPanel()
{
    //������������屳��
    auto aTimerPanelSp = Sprite::createWithSpriteFrameName("honor_0.png");
    aTimerPanelSp->setPosition(100, 40); //todo
    addChild(aTimerPanelSp, 100);

    createNumSprite();
}

void BM_ScoreAndControllerLayer::registerNotifyEvent()
{
    NOTIFY->addObserver(this, callfuncO_selector(BM_ScoreAndControllerLayer::moneyChange), "moneyChange", nullptr);
}

void BM_ScoreAndControllerLayer::unRegisterNotifyEvent()
{
    NOTIFY->removeAllObservers(this);
}

void BM_ScoreAndControllerLayer::moneyChange(cocos2d::Ref* pData)
{
    setMoneyNum(*(reinterpret_cast<int*>(pData)));
}

void BM_ScoreAndControllerLayer::bossHpChanged(float dt)
{
    _iBossCurrHp = GameManager::getInstance()->getIBossHp();
    //_iBossCurrHp = (_iBossCurrHp > 0 ? _iBossCurrHp : 0);
    auto aPercentage = _iBossCurrHp * 1.0f / _iBossTotalHp * 100;
    (dynamic_cast<ProgressTimer*>(getChildByName("BossHpBar")))->setPercentage(aPercentage);
}

void BM_ScoreAndControllerLayer::timeChange(float dt)
{
    if (_iTimeLimit == 0)
        return;

    _iTimeLimit -= 1;
    GameManager::getInstance()->setICurrTime(_iTimeLimit);

    removeChildByName("TimerSp");
    createNumSprite(); //�ع���ʱ����

    //todo GameManager Ҫ��Ҫһ��ʱ�����������ͳ�ƽ�� 

    //todo ʱ��ı仯�ܲ�Ҳ��仯

    if(_iTimeLimit == 0)
    {
        //��Ϸʧ��
        auto aGameType = en_GameLose;
        NOTIFICATION_CENTER->postNotification("gameEnd", reinterpret_cast<Ref*>(&aGameType));
    }
}

void BM_ScoreAndControllerLayer::setMoneyNum(const int& rIMoneyNum)
{
    auto tPos = _pMoneyLabel->getPosition();
    _pMoneyLabel->removeFromParent();
    _iMoney += rIMoneyNum;
    _pMoneyLabel = NumSprite::createNum(StringUtils::format("%d", _iMoney), MONEYNUMIMAGE);
    addChild(_pMoneyLabel);
    _pMoneyLabel->setPosition(tPos);
}

void BM_ScoreAndControllerLayer::loadData()
{
    //�ؿ���ʼ��Ǯ��
    _iMoney = LevelConfigUtil::getInstance()->getCurrentLevelInitialMoney();

    //todo �Ƿ��0��ʼ��
    int iThemeIndex = SceneManager::getInstance()->getCurrentPageIndex();
    int iLevelIndex = SceneManager::getInstance()->getCurrentLevelIndex();
    int iBossId = (iThemeIndex + 1) * (iLevelIndex - 12) + 1;

    _iTimeLimit = CsvUtil::getInstance()->getInt(iBossId, en_BossTime, BOSSCSVFILE);
    _iBossCurrHp = _iBossTotalHp = CsvUtil::getInstance()->getInt(iBossId, en_BossHp, BOSSCSVFILE);
    GameManager::getInstance()->setIBossHp(_iBossTotalHp);

    GameManager::getInstance()->setICurrTime(_iTimeLimit); //����Ϸ���������ʱ��
}

void BM_ScoreAndControllerLayer::setPauseFlagIsClose()
{
    _bIsOpenChooseMenu = false;
}

void BM_ScoreAndControllerLayer::onExit()
{
    Layer::onExit();
    unRegisterNotifyEvent();
}

void BM_ScoreAndControllerLayer::createNumSprite()
{
    _pTimeSp = NumSprite::createNum(StringUtils::format("%d", _iTimeLimit), "Themes/Items/numyellow-hd.png", 35);
    _pTimeSp->setName("TimerSp");
    _pTimeSp->setPosition(50, 35);
    addChild(_pTimeSp, 100);
}

void BM_ScoreAndControllerLayer::clickChooseItem()
{
    if (!_bIsOpenChooseMenu)
    {
        auto pPauseLayer = PauseLayer::create();
        pPauseLayer->setFuncFlagPauseLayerIsClose(CC_CALLBACK_0(BM_ScoreAndControllerLayer::setPauseFlagIsClose, this));
        this->addChild(pPauseLayer, 1);
        _bIsOpenChooseMenu = true;
    }
}
