#include "BossModeLevelSelectLayer.h"
#include "ui/CocosGUI.h"
#include "LocalLevelDataUtil.h"
#include "SceneManager.h"

using namespace ui;

BossModeLevelSelectLayer::~BossModeLevelSelectLayer()
{
    removeAllChildren();
    CC_SAFE_RELEASE_NULL(_pBossDetailsSprite);
    CC_SAFE_RELEASE_NULL(_pLockedBtn);
    CC_SAFE_RELEASE_NULL(_pStartBtn);
}

bool BossModeLevelSelectLayer::init()
{
    bool bRet = false;
    do
    {
        CC_BREAK_IF(!Layer::init());
        _pBossDetailsSprite = Sprite::create();
        loadData();
        loadSource();
        bRet = true;
    }
    while (0);
    return bRet;
}

void BossModeLevelSelectLayer::loadSource()
{
    //����������
    auto aBackground = Sprite::createWithSpriteFrameName("boss_theme_bg.png");
    aBackground->setPosition(VisibleRectUtil::center());
    addChild(aBackground);

    //��������
    auto aTitle = Label::createWithSystemFont(TITLE_BOSS_MODE, "Microsoft YaHei UI", 30);
    aTitle->setPosition(475, 609);
    addChild(aTitle);

    //�����ƹ�
    if (_pCheckLockedMap->at(1))
    {
        auto aLight = Sprite::createWithSpriteFrameName("light.png");
        aLight->setPosition(480, 430);
        //addChild(aLight);
        _pBossDetailsSprite->addChild(aLight);
    }


    //һ��ʼ����ʾ��һ��
    //Ĭ��չʾ��һ���ֵ���Ϣ
    Sprite* bossNameSp = Sprite::createWithSpriteFrameName("name_01_normal.png");
    bossNameSp->setPosition(Vec2(480, 490));
    _pBossDetailsSprite->addChild(bossNameSp);

    Sprite* bossHpSp = Sprite::createWithSpriteFrameName("blood_80000.png");
    bossHpSp->setPosition(Vec2(480, 130));
    _pBossDetailsSprite->addChild(bossHpSp, 10);

    Sprite* bossHpBg = Sprite::createWithSpriteFrameName("blood_bg.png");
    bossHpBg->setPosition(Vec2(480, 130));
    _pBossDetailsSprite->addChild(bossHpBg);

    Sprite* bossTime = Sprite::createWithSpriteFrameName("timelimit_90_CN.png");
    bossTime->setPosition(Vec2(350, 55));
    bossTime->setScale(0.93);
    _pBossDetailsSprite->addChild(bossTime);

    addChild(_pBossDetailsSprite);

    loadBossLevelButton();
    loadMenuItem();
}

void BossModeLevelSelectLayer::loadBossLevelButton()
{
    //�ǵ���16����BOSS��
    auto aPageView = PageView::create();
    addChild(aPageView);
    aPageView->setContentSize(Size(960.0f, 640.0f));
    Size contentSize = this->getContentSize();

    for (int i = 0; i < 16; i++)
    {
        std::string bossImgPath = "boss_" + StringUtils::format("%02d", i + 1) + "_";
        Layout* pLayout = Layout::create();

        //TODO ����������״̬������û�б��������������ҵ����ݶ���
        //TODO ��������ǿ�ҲҪ��

        int iTheme = i / 4 + 1; //��ȡ���BOSS��Ӧ������
        //����Ƿ�����
        if (!_pCheckLockedMap->at(iTheme))
            bossImgPath += "locked" + PHOTOPOSTFIX;
        else
            bossImgPath += "normal" + PHOTOPOSTFIX;

        auto gameButton = Button::create(bossImgPath, bossImgPath, bossImgPath, TextureResType::PLIST);
        gameButton->setPosition(Vec2(contentSize.width / 2, contentSize.height / 2));
        gameButton->addTouchEventListener([&](Ref* pSender, Widget::TouchEventType event)
        {
            if (event == Widget::TouchEventType::ENDED)
            {
                this->changeToGameScene();
            }
        });

        pLayout->addChild(gameButton);

        aPageView->insertPage(pLayout, i);
    }

    aPageView->setPassFocusToChild(true);
    aPageView->scrollToPage(_iCurLevelIndex); //��������һ��ҳ��
    aPageView->addEventListener([=](Ref* pSender, PageView::EventType event)
    {
        if (event == PageView::EventType::TURNING)
        {
            _iCurLevelIndex = aPageView->getCurrentPageIndex();
            _pBossDetailsSprite->removeAllChildrenWithCleanup(true);

            //����Boss״̬ˢ�µƹ�״̬
            if (_pCheckLockedMap->at(_iCurLevelIndex / 4 + 1))
            {
                auto aLight = Sprite::createWithSpriteFrameName("light.png");
                aLight->setPosition(480, 430);
                //addChild(aLight);
                _pBossDetailsSprite->addChild(aLight);
            }

            //���¿�ʼ��ť״̬
            _pStartBtn->setVisible(_pCheckLockedMap->at(_iCurLevelIndex / 4 + 1));
            _pLockedBtn->setVisible(!_pStartBtn->isVisible());

            //ˢ��Boss��ϸ��Ϣ
            Sprite* bossNameSp = Sprite::createWithSpriteFrameName(
                StringUtils::format("name_%02d_normal.png", _iCurLevelIndex + 1));
            bossNameSp->setPosition(Vec2(480, 490));
            _pBossDetailsSprite->addChild(bossNameSp);

            int currBossHp = CsvUtil::getInstance()->getInt(_iCurLevelIndex + 1, en_BossHp, BOSSCSVFILE);
            Sprite* bossHpSp = Sprite::createWithSpriteFrameName(StringUtils::format("blood_%d.png", currBossHp));
            bossHpSp->setPosition(Vec2(480, 130));
            _pBossDetailsSprite->addChild(bossHpSp, 10);

            Sprite* bossHpBg = Sprite::createWithSpriteFrameName("blood_bg.png");
            bossHpBg->setPosition(Vec2(480, 130));
            _pBossDetailsSprite->addChild(bossHpBg);

            int currBossTime = CsvUtil::getInstance()->getInt(_iCurLevelIndex + 1, en_BossTime, BOSSCSVFILE);
            Sprite* bossTime = Sprite::createWithSpriteFrameName(
                StringUtils::format("timelimit_%d_CN.png", currBossTime));
            bossTime->setScale(0.93);
            bossTime->setPosition(Vec2(350, 55));
            _pBossDetailsSprite->addChild(bossTime);
        }
    });

    //addChild(aPageView, 3);
}

void BossModeLevelSelectLayer::loadMenuItem()
{
    //����������ҳ��ť
    auto aHomeBtn = MenuItemSprite::create(Sprite::createWithSpriteFrameName("theme_home_normal.png"),
                                           Sprite::createWithSpriteFrameName("theme_home_pressed.png"),
                                           [&](Ref* pSender)
                                           {
                                               auto enWelcomeScene = std::make_tuple(en_WelcomeScene, 0);
                                               NOTIFICATION_CENTER->postNotification("changeScene",
                                                                                     reinterpret_cast<Ref *>(&
                                                                                         enWelcomeScene));
                                           });
    aHomeBtn->setPosition(-445, 290);

    //����������ť
    auto aHelpBtn = MenuItemSprite::create(Sprite::createWithSpriteFrameName("ss_help_normal.png"),
                                           Sprite::createWithSpriteFrameName("ss_help_pressed.png"), [&](Ref* pSender)
                                           {
                                               auto enHelpScene = std::make_tuple(en_GameHelpScene, 0);
                                               NOTIFICATION_CENTER->postNotification("changeScene",
                                                                                     reinterpret_cast<Ref *>(&
                                                                                         enHelpScene));
                                           });
    aHelpBtn->setPosition(450, 290);
    aHelpBtn->setScale(1.4);

    //������ʼ��ť
    _pStartBtn = MenuItemSprite::create(Sprite::createWithSpriteFrameName("theme_play_normal_CN.png"),
                                        Sprite::createWithSpriteFrameName("theme_play_pressed_CN.png"),
                                        [&](Ref* pSender)
                                        {
                                            this->changeToGameScene();
                                        });
    _pStartBtn->setPosition(Vec2(130, -265));
    _pStartBtn->setScale(0.9);
    addChild(Menu::create(aHomeBtn, aHelpBtn, _pStartBtn, nullptr));
    _pCheckLockedMap->at(1) ? _pStartBtn->setVisible(true) : _pStartBtn->setVisible(false); //һ��ʼ���¿�ʼ��ť�Ƿ���Ч

    //������ס��ť
    _pLockedBtn = Sprite::createWithSpriteFrameName("theme_locked_CN.png");
    _pLockedBtn->setPosition(Vec2(610, 55));
    addChild(_pLockedBtn, 1);
    _pLockedBtn->setVisible(!_pStartBtn->isVisible());
}

std::tuple<int, bool> BossModeLevelSelectLayer::getLevelData(const int& riIndex)
{
    int iCurThemeIndex = riIndex / 4; //�����
    int iActualLevelIndex = riIndex % 4 + 12; //ʵ�ʵĹؿ���

    //��ȡ�ùؿ���valueֵ
    auto aKey = StringUtils::format(LEVELKEY, iCurThemeIndex + 1, iActualLevelIndex + 1);
    int iValue = _DataValueMap[aKey].asInt();

    //��ȡ��Ӧ������
    int iCarrotType = iValue / 10;
    bool iBarriersAllCleaned = iValue % 10 != 0;

    //����Ԫ��
    return std::make_tuple(iCarrotType, iBarriersAllCleaned);
}

void BossModeLevelSelectLayer::changeToGameScene()
{
    int iCurThemeIndex = _iCurLevelIndex / 4; //�����
    int iActualLevelIndex = _iCurLevelIndex % 4 + 12; //ʵ�ʵĹؿ���

    SceneManager::getInstance()->setCurrentPageIndex(iCurThemeIndex);

    if (std::get<0>(getLevelData(_iCurLevelIndex)) == LEVEL_LOCK)
        return;

    auto enGameScene = std::make_tuple(en_GameScene, iActualLevelIndex);
    NOTIFICATION_CENTER->postNotification("changeScene", reinterpret_cast<Ref *>(&enGameScene));
}

void BossModeLevelSelectLayer::loadData()
{
    _DataValueMap = LocalLevelDataUtil::getInstance()->getLevelData();
    checkThemeUnlocked();
}

//TODO ��������
void BossModeLevelSelectLayer::checkThemeUnlocked()
{
    auto aValueMap = LocalLevelDataUtil::getInstance()->getLevelData();

    _pCheckLockedMap = new std::map<int, bool>();
    //��ʼ������ͨ�ع�ϣ��
    for (int i = 1; i <= 4; i++)
        _pCheckLockedMap->insert(std::make_pair(i, false));


    //TODO Ŀǰֻ֧����������
    //������������
    for (int iTheme = 1; iTheme <= 3; iTheme++)
    {
        //ÿ�������õڰ˸��ؿ�ͨ������Ϳ�����
        std::string sKey = StringUtils::format(LEVELKEY, iTheme, 8);
        int iValue = aValueMap[sKey].asInt();
        bool bIsLevelPast = iValue / 10 > 1;
        if (!bIsLevelPast)
            break;
        _pCheckLockedMap->at(iTheme) = true; //����ڰ˹�ͨ���ˣ���ζ�������Ĵ�Boss����������
    }
}
