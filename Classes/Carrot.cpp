//
//Carrot.cpp
//CarrotFantasy
//
//Created by ������ on 18-4-11
//
//
#include "Carrot.h"
#include "MapUtil.h"
#include "MonsterBase.h"
#include "MonsterManager.h"
#include "GameManager.h"
#include "SoundUtil.h"

Carrot::~Carrot()
{
	NOTIFY->removeAllObservers(this);
}

bool Carrot::init()
{
	bool bret = false;

	do
	{
		//�����ܲ���ʵ�壬Ϊ�˷���̳��˹���ʵ����ࣻ
		CC_BREAK_IF(!Entity::init(18, MONSTERCSVFILE));
		//�ܲ�����ֵ��
		iHp = 10;
		//�����ܲ�������ֵ��
		GameManager::getInstance()->setICarrotHp(iHp);
		//��ȡ�ܲ����ƶ�λ�ã�
		auto aPoints = MapUtil::getInstance()->getMovePoses();
		//����ê�㣻
		getSprite()->setAnchorPoint(Vec2(0.5, 0));
		//�ܲ���λ���趨��
		this->setPosition((*(aPoints.end() - 2)).x + getContentSize().width / 2 - 20, (*(aPoints.end() - 2)).y - getContentSize().height / 2);
		//�ܲ�����ֵ����֡��
		_HpSprite = Sprite::createWithSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("BossHP10.png"));
		//�����ܲ�����ֵͼ���λ�ã�
		_HpSprite->setPosition(*(aPoints.end() - 1) - *(aPoints.end() - 2) + Vec2(-20, 10));
		//���������ӽ�ȥ��
		addChild(_HpSprite);
		//���ù۲�֪ͨ�������ַ���"CarrotHurt"������CarrotHurt��������
		NOTIFY->addObserver(this, callfuncO_selector(Carrot::CarrotBeHurt), "CarrotHurt", nullptr);
		//ע���ܲ��������¼���
		registerCarrotTouchEvent();
		//TODO��
		srand(time(0));
		//ÿ������ܲ���һ���ȣ�
		schedule(schedule_selector(Carrot::doAction), 6);

		bret = true;
	} while (0);

	return  bret;
}

void Carrot::registerCarrotTouchEvent()
{
	//���ô������㴥����
	auto pTouchEvent = EventListenerTouchOneByOne::create();

	pTouchEvent->onTouchBegan = [=](Touch * t, Event * e)
	{
		//����������ں��ܲ��Ŀ�ͼ�ڣ�
		if (getBoundingBox().containsPoint(t->getLocation())) 
		{
			//��ȡ���ܲ����飻
			auto pCarrot = getSprite();
			//ֹͣ�κζ�����
			pCarrot->stopAllActions();
			//���ò���ת��
			pCarrot->setRotation(0);
			//todo
			pCarrot->setTexture(SpriteFrameCache::getInstance()->getSpriteFrameByName(_sModelName + PHOTOPOSTFIX)->getTexture());
			pCarrot->runAction(doShakeOrBlink(10, 9));
		}
		return false;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(pTouchEvent, getSprite());
}

ActionInterval * Carrot::doShakeOrBlink(int iImageFirstNumber, int iImageCount)
{
	//��ȡʵ����
	auto cache = SpriteFrameCache::getInstance();
	//����������
	Animation * pAnimation = Animation::create();
	std::string sSpriteFrameName;
	for (int i = iImageFirstNumber; i < iImageFirstNumber + iImageCount; i++)
	{
		std::string sSpriteFrameName = _sName + StringUtils::format("%2d.png", i);
		pAnimation->addSpriteFrame(cache->getSpriteFrameByName(sSpriteFrameName));
	}
	pAnimation->addSpriteFrame(cache->getSpriteFrameByName(_sModelName + PHOTOPOSTFIX));
	//�����ӳ�ʱ�䣻
	pAnimation->setDelayPerUnit(0.1);
	//����һ�ζ������ɣ�
	pAnimation->setLoops(1);
	Animate * pAnimate = Animate::create(pAnimation);
	return pAnimate;
}

void Carrot::doAction(float t)
{
	//ֹͣ������
	getSprite()->stopAllActions();
	int tRandom = rand() % 3;
	switch (tRandom)
	{
		//�������ʽȷ��ִ�к��ܲ������ȶ�����
	case 0: getSprite()->runAction(doShakeOrBlink(10, 9));
		break;
	case 1: getSprite()->runAction(doShakeOrBlink(21, 3));
		break;
		//���ܲ���ʽ���ȣ�
	case 2: getSprite()->runAction(Sequence::create(RotateBy::create(0.2, -20), RotateBy::create(0.2, 20), RotateBy::create(0.2, 30), RotateBy::create(0.2, -30), NULL));
		break;
	default:
		break;
	}
	//���ܲ������������������
	SoundUtil::getInstance()->playEffectSound(StringUtils::format(CARROT, tRandom + 1));
}

void Carrot::CarrotBeHurt(Ref * pRef)
{
	//��Ū���ˣ�
	SoundUtil::getInstance()->playEffectSound(CARROTCRASH);
	MonsterBase * pMonster = (MonsterBase *)pRef;
	//����ֵ����
	iHp -= pMonster->getIAtk();
	if (iHp <= 0)
	{
		//���ú��ܲ�����Ϊ0��
		GameManager::getInstance()->setICarrotHp(0);
		auto tGameEndType = en_GameLose;
		//����֪ͨ����Ϸʧ�ܣ��ֹ����Ŭ����
		NOTIFY->postNotification("gameEnd", reinterpret_cast<Ref*>(&tGameEndType));
		NOTIFY->removeAllObservers(this);
		return;
	}
	//���º��ܲ���������ֵ��
	GameManager::getInstance()->setICarrotHp(iHp);
	//TODO;
	Director::getInstance()->getEventDispatcher()->removeEventListenersForTarget(getSprite());
	unscheduleAllSelectors();
	_HpSprite->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(StringUtils::format("BossHP%02d.png", iHp)));
	std::string HurtSpriteName;
	if (iHp == 5 || iHp == 7)
	{
		HurtSpriteName = StringUtils::format("hlb%d.png", iHp + 1);
	}
	else
	{
		HurtSpriteName = StringUtils::format("hlb%d.png", iHp);
	}
	getSprite()->stopAllActions();
	getSprite()->setSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(HurtSpriteName));
}

Rect Carrot::getBoundingBox()const
{
	return Rect(getPositionX() - getContentSize().width / 2, getPositionY(), getContentSize().width, getContentSize().height);
}
