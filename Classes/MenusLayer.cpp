#include "MenusLayer.h"

bool MenusLayer::init()
{
    bool res = false;
    do 
    {
        CC_BREAK_IF(!Layer::init());
        createMenuItems();
        res = true;
    } while (0);
    return res;
}

void MenusLayer::createMenuItems()
{
    auto pBtnAdventureMode = MenuItemSprite::create(
        Sprite::createWithSpriteFrameName("btn_adventure_normal_CN.png"),
        Sprite::createWithSpriteFrameName("btn_adventure_pressed_CN.png"),
        [](Ref *pSender)
        {
        auto levelScene = std::make_tuple(en_PageSelectScene, 0);  // ����ð�ť�����ҳ��ѡ�񳡾�����ؿ�ѡ��
        NOTIFICATION_CENTER->postNotification("changeScene", reinterpret_cast<Ref*>(&levelScene));  // ֪ͨ�л�����
        }
    );
    pBtnAdventureMode->setPosition(Vec2(180, 100));

    auto pBtnBossMode = MenuItemSprite::create(
        Sprite::createWithSpriteFrameName("btn_boss_normal_CN.png"),
        Sprite::createWithSpriteFrameName("btn_boss_pressed_CN.png"),
        [](Ref* pSender)
        {
            //TODO
        }
    );
    pBtnBossMode->setPosition(Vec2(pBtnAdventureMode->getPositionX() + 300, pBtnAdventureMode->getPositionY()));

    if (true)  // bossģʽû����ɣ��ȼ�����
    {
        auto pLock = Sprite::createWithSpriteFrameName("locked.png");
        pLock->setPosition(pBtnBossMode->getPositionX() + pBtnBossMode->getContentSize().width / 2 - 20, pBtnBossMode->getPositionY() - 20);
        addChild(pLock, 1);
    }

    auto pBtnNestMode = MenuItemSprite::create(
        Sprite::createWithSpriteFrameName("btn_nest_normal_CN.png"),
        Sprite::createWithSpriteFrameName("btn_nest_pressed_CN.png"),
        [](Ref* pSender)
        {
            //TODO
        }
    );
    pBtnNestMode->setPosition(Vec2(pBtnBossMode->getPositionX() + 300, 100));

    if (true)  // nestģʽû����ɣ��ȼ�����
    {
        auto pLock = Sprite::createWithSpriteFrameName("locked.png");
        pLock->setPosition(pBtnNestMode->getPositionX() + pBtnNestMode->getContentSize().width / 2 - 20, pBtnNestMode->getPositionY() - 20);
        addChild(pLock, 1);
    }

    auto pBtnSetting = MenuItemSprite::create(
        Sprite::createWithSpriteFrameName("btn_setting_normal.png"),
        Sprite::createWithSpriteFrameName("btn_setting_pressed.png"),
        [](Ref *pSender)
        {
            auto gameSettingScene = std::make_tuple(en_GameSettingScene, 0);
            NOTIFICATION_CENTER->postNotification("changeScene", reinterpret_cast<Ref*>(&gameSettingScene));
        }
    );
    pBtnSetting->setPosition(Vec2(200, 220));

    auto pBtnHelp = MenuItemSprite::create(
        Sprite::createWithSpriteFrameName("btn_help_normal.png"),
        Sprite::createWithSpriteFrameName("btn_help_pressed.png"),
        [](Ref *pSender)
        {
            auto GameHelpScene = std::make_tuple(en_GameHelpScene, 0);
            NOTIFICATION_CENTER->postNotification("changeScene", reinterpret_cast<Ref*>(&GameHelpScene));
        }
    );
    pBtnHelp->setPosition(Vec2(750, 220));

    auto pMenu = Menu::create(pBtnAdventureMode, pBtnBossMode, pBtnNestMode, pBtnSetting, pBtnHelp);
    pMenu->setPosition(Vec2::ZERO);
    addChild(pMenu);
}




