#include "SpritesLayer.h"
#include "CommonSource.h"
#include "VisibleRect.h"

void SpritesLayer::createStaticSprites()
{
    auto pWelcomeMainBg = Sprite::createWithSpriteFrameName(MAIN_BACKGROUND);
    pWelcomeMainBg->setPosition(VisibleRectUtil::center());
    addChild(pWelcomeMainBg);

    auto pWelcomeMainBg_CN = Sprite::createWithSpriteFrameName(MAIN_BACKGROUND_CN);
    pWelcomeMainBg_CN->setPosition(_VisibleSize.width / 2 - 20, _VisibleSize.height / 2);
    addChild(pWelcomeMainBg_CN, 6);
}

void SpritesLayer::createDynamicSprites()
{
    //���ȣ���һ���Ϸ��Ǹ��ᴩ��Ļ���Ƕ����
    auto pCloud1 = Sprite::createWithSpriteFrameName("cloud1.png");
    pCloud1->setAnchorPoint(Vec2(0, 0.5f));
    pCloud1->setPosition(-pCloud1->getContentSize().width, 450);
    //ȷ���ó�ʼλ��
    auto pCloud1CallBack = CallFunc::create([pCloud1]() {pCloud1->setPositionX(-pCloud1->getContentSize().width); });
    //�ƶ��켣
    auto pCloud1MoveBy = MoveBy::create(20, Vec2(960 + pCloud1->getContentSize().width, 0));
    pCloud1->runAction(RepeatForever::create(Sequence::create(pCloud1CallBack, pCloud1MoveBy, nullptr)));
    addChild(pCloud1);

    //�ڶ������·��Ǹ��ߵĺܿ����
    auto pCloud2 = Sprite::createWithSpriteFrameName("cloud2.png");
    pCloud2->setAnchorPoint(Vec2(0, 0.5f));
    pCloud2->setPosition(-pCloud2-> getContentSize().width, 550);
    auto pCloud2CallBack = CallFunc::create([pCloud2]() {pCloud2->setPositionX(-pCloud2->getContentSize().width); });
    auto pCloud2MoveBy = MoveBy::create(35, Vec2(960 + pCloud2->getContentSize().width, 0));
    pCloud2->runAction(RepeatForever::create(Sequence::create(pCloud2CallBack, pCloud2MoveBy, nullptr)));
    addChild(pCloud2);

    //��󣬰���ֻ�񻭳���
    auto pBird = Sprite::createWithSpriteFrameName("bird.png");
    pBird->setPosition(Vec2(200, 460));
    auto pBirdMoveBy = MoveBy::create(2, Vec2(0, 30));
    //ѭ�����������¶�
    pBird->runAction(RepeatForever::create(Sequence::create(pBirdMoveBy, pBirdMoveBy->reverse(), nullptr)));

}