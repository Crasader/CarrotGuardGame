//
//  CountDownLayer.cpp
//  CarrotFantasy
//
//  Created by ������ on 18-4-13.
//
#include "CountDownLayer.h"
#include "MapUtil.h"
#include "SoundUtil.h"

bool CountDownLayer::init() {
	if (!Layer::init())
	{
		return false;
	}

	Director::getInstance()->resume();

	countDownSprite = Sprite::createWithSpriteFrameName("countdown_11.png");
	countDownSprite->setName("countDownSprite");
	countDownSprite->setPosition(480, 320);
	addChild(countDownSprite, 2);

    //initEffectPosBlink();
    this->scheduleOnce(schedule_selector(CountDownLayer::effectPosBlink), 0.1f);

	this->schedule(schedule_selector(CountDownLayer::runArrow1), 0.40f);
	this->schedule(schedule_selector(CountDownLayer::runArrow2), 0.60f);
	this->schedule(schedule_selector(CountDownLayer::runArrow3), 0.80f);

	this->scheduleOnce(schedule_selector(CountDownLayer::Num1), 0.0f);
	this->scheduleOnce(schedule_selector(CountDownLayer::Num2), 1.0f);
	this->scheduleOnce(schedule_selector(CountDownLayer::Num3), 2.0f);
	this->scheduleOnce(schedule_selector(CountDownLayer::GameGo), 3.0f);
	this->scheduleOnce(schedule_selector(CountDownLayer::childDisappear), 3.6f);


	registerNoTouch();
	return true;
}
void CountDownLayer::Circle() 
{
	auto run = Sprite::createWithSpriteFrameName("countdown_12.png");
	auto r1 = RotateBy::create(3.0f, -1080);//��������ʱ����ת1080�ȣ�
	run->setPosition(100, 100);
	run->runAction(r1);
	countDownSprite->addChild(run, 2);
}
void CountDownLayer::runArrow1(float t) 
{
	auto arrowSprite1 = Sprite::createWithSpriteFrameName("arrow.png");
	
	std::vector<Vec2> value = MapUtil::getInstance()->getMovePoses();
	//�ж�·������
	Vec2 point1 = value.at(0);
	Vec2 point2 = value.at(1);

	if (point1.x == point2.x && point1.y >= point2.y) //���±��ͷ
	{
		arrowSprite1->setRotation(90);
		arrowSprite1->setPosition(point1.x + 40, point1.y - 60);

	}
	else if (point1.x == point2.x && point1.y < point2.y) //���ϱ��ͷ
	{
		arrowSprite1->setRotation(-90);
		arrowSprite1->setPosition(point1.x + 40, point1.y + 60);

	}
	else if (point1.y == point2.y && point1.x >= point2.x) //������ͷ
	{
		arrowSprite1->setScaleX(-1); //���淭ת
		arrowSprite1->setPosition(point1.x - 5, point1.y - 30);
	}
	else if (point1.y == point2.y && point1.x < point2.x)
	{
		//�ҷ���Ϊ��ʼ����
		arrowSprite1->setPosition(point1.x + 80, point1.y - 30); //���ұ��ͷ
	}
	//����������
	auto fade = FadeOut::create(0.7f);
	arrowSprite1->runAction(fade);
	addChild(arrowSprite1);

	i++;
}
void CountDownLayer::runArrow2(float t) 
{
	auto arrowSprite2 = Sprite::createWithSpriteFrameName("arrow.png");

	std::vector<Vec2> value = MapUtil::getInstance()->getMovePoses();

	Vec2 point1 = value.at(0);
	Vec2 point2 = value.at(1);

	if (point1.x == point2.x && point1.y >= point2.y)
	{
		arrowSprite2->setRotation(90);
		arrowSprite2->setPosition(point1.x + 40, point1.y - 90);

	}
	else if (point1.x == point2.x && point1.y < point2.y)
	{
		arrowSprite2->setRotation(-90);
		arrowSprite2->setPosition(point1.x + 40, point1.y + 90);

	}
	else if (point1.y == point2.y && point1.x >= point2.x)
	{
		arrowSprite2->setScaleX(-1);
		arrowSprite2->setPosition(point1.x - 35, point1.y - 30);
	}
	else if (point1.y == point2.y && point1.x < point2.x)
	{
		arrowSprite2->setPosition(point1.x + 110, point1.y - 30);
	}


	auto fade = FadeOut::create(0.7f);
	arrowSprite2->runAction(fade);
	addChild(arrowSprite2);
	i++;
}
void CountDownLayer::runArrow3(float t) 
{
	auto arrowSprite3 = Sprite::createWithSpriteFrameName("arrow.png");

	std::vector<Vec2> value = MapUtil::getInstance()->getMovePoses();

	Vec2 point1 = value.at(0);
	Vec2 point2 = value.at(1);

	if (point1.x == point2.x && point1.y >= point2.y)
	{
		arrowSprite3->setRotation(90);
		arrowSprite3->setPosition(point1.x + 40, point1.y - 120);
	}
	else if (point1.x == point2.x && point1.y < point2.y)
	{
		arrowSprite3->setRotation(-90);
		arrowSprite3->setPosition(point1.x + 40, point1.y + 120);
	}
	else if (point1.y == point2.y && point1.x >= point2.x)
	{
		arrowSprite3->setScaleX(-1);
		arrowSprite3->setPosition(point1.x - 65, point1.y - 30);
	}
	else if (point1.y == point2.y && point1.x < point2.x)
	{
		arrowSprite3->setPosition(point1.x + 140, point1.y - 30);
	}
	auto fade = FadeOut::create(0.7f);
	arrowSprite3->runAction(fade);
	addChild(arrowSprite3);


	i++;
}
void CountDownLayer::Num1(float t) 
{
	auto three = Sprite::createWithSpriteFrameName("countdown_01.png");//3
	Circle();
	SoundUtil::getInstance()->playEffectSound(COUNTDOWN);//����ʱ����Ч���֣�
	three->setPosition(100, 100);
	countDownSprite->addChild(three, 2);
}
void CountDownLayer::Num2(float t) 
{
	//������к��ӽ�㣻
	countDownSprite->removeAllChildren();
	Circle();
	SoundUtil::getInstance()->playEffectSound(COUNTDOWN);
	auto two = Sprite::createWithSpriteFrameName("countdown_02.png");//2
	two->setPosition(100, 100);
	countDownSprite->addChild(two, 2);

}
void CountDownLayer::Num3(float t) 
{
	countDownSprite->removeAllChildren();
	Circle();
	SoundUtil::getInstance()->playEffectSound(COUNTDOWN);
	auto one = Sprite::createWithSpriteFrameName("countdown_03.png");//1
	one->setPosition(100, 100);
	countDownSprite->addChild(one, 2);
}
void CountDownLayer::GameGo(float t) 
{
	countDownSprite->removeAllChildren();
	Circle();
	SoundUtil::getInstance()->playEffectSound(GO);
	auto GO = Sprite::createWithSpriteFrameName("countdown_13.png");
	//�����趨����ѧ����1.05f��
	auto scale = ScaleBy::create(0.3f, 1.05f);
	//GOת��һȦ������
	auto arotate = RotateBy::create(0.1f, 360);

	GO->setPosition(100, 100);
	countDownSprite->addChild(GO);
	GO->runAction(Spawn::create(scale, arotate, NULL));
}
void CountDownLayer::childDisappear(float t) 
{
	//this->removeChildByName("countDownSprite");
    this->removeAllChildren();
	//���������
	NOTIFY->postNotification("startBuildMonster");
	//���ڵ��������
	removeFromParent();
}

void CountDownLayer::initEffectPosBlink()
{
    effPosSprites = Sprite::create();
    auto aFadeIn = FadeIn::create(0.5f);
    auto aFadeOut = FadeOut::create(0.5f);
    _pFadeSequence = Sequence::create(aFadeIn, DelayTime::create(0.5f), aFadeOut, DelayTime::create(0.2f), 
        aFadeIn, DelayTime::create(0.5f), aFadeOut, nullptr);

    auto effPos = MapUtil::getInstance()->getEffectTowerPoses();

    for (auto &iter : effPos)
    {
        float x = iter.origin.x;
        float y = iter.origin.y;
        float width = iter.size.width;
        float height = iter.size.height;

        auto posSprite = Sprite::createWithSpriteFrameName("select_00.png");
        posSprite->setPosition(x + width / 2, y + height / 2); 
        posSprite->setCascadeOpacityEnabled(true); //MUST BE ATTENTIONED ���ӱ���Ҫ�����������ܸ����ϰ�ͬ��͸����
        effPosSprites->addChild(posSprite);
    }
    effPosSprites->setCascadeOpacityEnabled(true); //�ϰ�ҲҪ�������������뺢��һ�����͸����
    effPosSprites->setName("effPosSprites");
    addChild(effPosSprites, 0);
}

void CountDownLayer::effectPosBlink(float t)
{
    initEffectPosBlink();
    effPosSprites->runAction(_pFadeSequence);
}

void CountDownLayer::registerNoTouch()
{
    //����ʱ��ʱ�򴥿���Ч��
	auto pListener = EventListenerTouchOneByOne::create();

	pListener->setSwallowTouches(true);
	pListener->onTouchBegan = [](Touch *pTouch, Event *pEvent) {return true; };

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(pListener, this);

}


