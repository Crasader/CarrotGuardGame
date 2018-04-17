//
// BulletRocket.cpp
// CarrotFantasy
//
// Created by ������ on 18-4-11.
//
//

#include "BulletRocket.h"
#include "VictimEntityBase.h"

bool BulletRocket::init(const int & rId, VictimEntityBase *rVictimEntity)
{
	bool bRet = false;
	do
	{
		//ȷ���ӵ�����ĳɹ���ʼ����
		CC_BREAK_IF(!BulletBase::init(rId, rVictimEntity));

		bRet = true;
	} while (0);
	return bRet;
}

BulletRocket * BulletRocket::create(const int & rId, VictimEntityBase *rVictimEntity)
{
	//�����ڴ棻
	BulletRocket * pBullet = new BulletRocket();
	if (pBullet && pBullet->init(rId, rVictimEntity))
	{
		//��ʼ���ɹ��������Զ��ͷţ�
		pBullet->autorelease();
		return pBullet;
	}
	//����ɾ������
	CC_SAFE_DELETE(pBullet);
	return nullptr;
}

void BulletRocket::doAction()
{

	for (int i = 1; i <= _IAnimationFrameCount; ++i)
	{

		std::string SpriteFrameName = _sModelName + StringUtils::format("%d.png", i);
		_pAnimation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(SpriteFrameName));
	}
	//�����ӳ�ʱ�䣻
	_pAnimation->setDelayPerUnit(0.05);
	//����ִ�У�һֱ�е������
	_pAnimation->setLoops(-1);
	//���ж�����
	getSprite()->runAction(Animate::create(_pAnimation));
}
//��д��BulletBase���doMove(),��Ϊ����������䴩�������������
void BulletRocket::doMove() 
{
	if (_pAtkTarget->getIsDead())
	{
		//�������Ŀ���Ѿ��������Ӹ��ڵ���ɾȥ���������������أ�
		removeFromParent();
		setIsDead(true);
		return;
	}
	doAction();
	//��������䴩������ϰ��
	float Hypotenuse = Vec2::ZERO.distance(Director::getInstance()->getVisibleSize());
	Vec2 MovetoPosition = Vec2(Hypotenuse * sin(this->getRotation() * M_PI / 180), Hypotenuse * cos(this->getRotation() * M_PI / 180));
	float MoveDistance = MovetoPosition.distance(this->getPosition());
	//���ж�����
	this->runAction(MoveBy::create(MoveDistance / _iSpeed, MovetoPosition));
}