//
// Created by jeza on 18-4-11.
//
#include "OptionLayer.h"
#include "SoundUtil.h"


bool OptionLayer::init()
{
    bool bRet = false;
    do
    {
        CC_BREAK_IF(!Layer::init());
        loadSource();
        bRet = true;
    } while (0);

    return bRet;
}

void OptionLayer::loadSource()
{
    //���ȼ�������ͼ��ı���
    //��Ϊÿһ��ͼ��ı�������̫��ͬ
    //������Ҫ���ÿһ��ͼ����ж�Ӧ�ı�����Ⱦ
    auto aBg = Sprite::createWithSpriteFrameName("setting_bg.png");
    addChild(aBg);

    auto aText = Sprite::createWithSpriteFrameName("setting_bg_CN.png");
    addChild(aText);

    //��ȡ��ǰ��������Ϣ
    auto aCurSoundUtil = SoundUtil::getInstance();
    //��ȡ��ǰ�������ֵ�״̬
    bool bIsBgSoundOpen = aCurSoundUtil->getIsBackgroundSoundOpen();
    //��ȡ��ǰ��Ч��״̬
    bool bIsEfSoundOpen = aCurSoundUtil->getIsEffectSoundOpen();

    //����һ����Ч���ذ�ť
    auto aEfSoundBtnOn = MenuItemSprite::create(Sprite::createWithSpriteFrameName("soundfx_on_CN.png"), nullptr);
    auto aEfSoundBtnOff = MenuItemSprite::create(Sprite::createWithSpriteFrameName("soundfx_off_CN.png"), nullptr);
    auto aEfSoundBtnToggle = MenuItemToggle::createWithCallback([aCurSoundUtil](Ref *pSender)
                                                                {
                                                                    //�����л�
                                                                    aCurSoundUtil->setIsEffectSoundOpen(
                                                                            !aCurSoundUtil->getIsEffectSoundOpen());
                                                                },
            //TODO ������˼
                                                                bIsEfSoundOpen ? aEfSoundBtnOn : aEfSoundBtnOff,
                                                                bIsEfSoundOpen ? aEfSoundBtnOff : aEfSoundBtnOn,
                                                                nullptr); //nullptrһ��Ҫ����

    aEfSoundBtnToggle->setPosition(-100, 83);

    //����һ���������ֿ��ذ�ť
    auto aBgSoundBtnOn = MenuItemSprite::create(Sprite::createWithSpriteFrameName("bgmusic_on_CN.png"), nullptr);
    auto aBgSoundBtnOff = MenuItemSprite::create(Sprite::createWithSpriteFrameName("bgmusic_off_CN.png"), nullptr);
    auto aBgSoundBtnToggle = MenuItemToggle::createWithCallback([aCurSoundUtil](Ref *pSender)
                                                                {
                                                                    //�����л�
                                                                    aCurSoundUtil->setIsBackgroundSoundOpen(
                                                                            !aCurSoundUtil->getIsBackgroundSoundOpen());
                                                                },
            //TODO ������˼
                                                                bIsBgSoundOpen ? aBgSoundBtnOn : aBgSoundBtnOff,
                                                                bIsBgSoundOpen ? aBgSoundBtnOff : aBgSoundBtnOn,
                                                                nullptr);
                                                                
    aBgSoundBtnToggle->setPosition(100, 83);
    auto aMenu = Menu::create(aEfSoundBtnToggle, aBgSoundBtnToggle, nullptr);
    aMenu->setPosition(0, 0); //Ǳ��bug fixed
    addChild(aMenu);
}
