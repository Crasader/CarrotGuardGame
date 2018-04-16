//
// Created by jeza1 on 2018/4/9.
//

#include "SelectSceneMenuPanelLayer.h"
#include "SoundUtil.h"
#include "CommonSource.h"

bool MenuPanelLayer::init()
{
    bool bRet = false;
    do
    {
        CC_BREAK_IF(!Layer::init());

        createItemPanel();

        bRet = true;
    } while (0);

    return bRet;
}

void MenuPanelLayer::setPageTurnFunction(const std::function<void(const bool &)> &rfFuncPageTurn) {
    _funcPageTurn = rfFuncPageTurn;
}

void MenuPanelLayer::createItemPanel() {
    //����������ҳ��ť
    //��һ��������������̬���ڶ�������������ȥ����̬
    auto aBtnHome = MenuItemSprite::create(Sprite::createWithSpriteFrameName("theme_home_normal.png"), Sprite::createWithSpriteFrameName("theme_home_pressed.png"), [](Ref *pSender)
    {
        //����¼�������֪ͨ�л�����ҳ����
        auto enWelcomeScene = std::make_tuple(en_WelcomeScene, -1);
        NOTIFICATION_CENTER->postNotification("changeScene", reinterpret_cast<Ref*>(&enWelcomeScene));
    });
    aBtnHome->setPosition(Vec2(-445, 290));
    aBtnHome->setScale(1.4);

    //����������ť
    auto aBtnHelp = MenuItemSprite::create(Sprite::createWithSpriteFrameName("ss_help_normal.png"), Sprite::createWithSpriteFrameName("ss_help_pressed.png"), [](Ref *pSender)
    {
        //����¼�������֪ͨ�л�����������
        auto tEnHelpScene = std::make_tuple(en_GameHelpScene, 0);
        NOTIFICATION_CENTER->postNotification("changeScene", reinterpret_cast<Ref*>(&tEnHelpScene));
    });
    aBtnHelp->setPosition(Vec2(445, 290));
    aBtnHelp->setScale(1.4);
    //���а�ť
    auto aBtnLeft = MenuItemSprite::create(Sprite::createWithSpriteFrameName("theme_pointleft_normal.png"), Sprite::createWithSpriteFrameName("theme_pointleft_pressed.png"), [this](Ref *pSender)
    {
        _funcPageTurn(true);
    });
    aBtnLeft->setPosition(Vec2(-400, 0)); //bug fixed: ê�����е�λ��

    //���а�ť
    auto aBtnRight = MenuItemSprite::create(Sprite::createWithSpriteFrameName("theme_pointright_normal.png"), Sprite::createWithSpriteFrameName("theme_pointright_pressed.png"), [this](Ref *pSender)
    {
        _funcPageTurn(false);
    });
    aBtnRight->setPosition(Vec2(400, 0));

    auto aMenu = Menu::create(aBtnHome, aBtnHelp, aBtnLeft, aBtnRight, nullptr);
    addChild(aMenu);
}