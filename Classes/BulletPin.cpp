//
// BullePin.cpp
// CarrotFantasy
//
// Created by ������ on 18-4-11.
//
//
#include "BulletPin.h"
#include "BulletPin.h"
#include "VictimEntityBase.h"

bool BulletPin::init(const int & rId, VictimEntityBase *rVictimEntity)
{
	bool bRet = false;
	do
	{
		//��֤�ӵ�����ĳ�ʼ���ɹ���
		CC_BREAK_IF(!BulletBase::init(rId, rVictimEntity));

		bRet = true;
	} while (0);
	return bRet;
}

BulletPin * BulletPin::create(const int & rId, VictimEntityBase *rVictimEntity)
{
	//�����ڴ���ӵ�ָ�룻
	BulletPin * pBullet = new BulletPin();
	if (pBullet && pBullet->init(rId, rVictimEntity))
	{
		//��ʼ���ɹ��������Զ��ͷţ�
		pBullet->autorelease();
		return pBullet;
	}
	//���ɹ���ɾ������
	CC_SAFE_DELETE(pBullet);
	return nullptr;
}

void BulletPin::doAction()
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
//��д��BulletBase���doMove()��
void BulletPin::doMove() {

	if (_pAtkTarget->getIsDead())
	{
		//�������Ŀ���Ѿ��������Ӹ��ڵ���ɾȥ���������������أ�
		removeFromParent();
		setIsDead(true);
		return;
	}
	doAction();

	auto deadActionCF = CallFunc::create([=]()
	{
		//�������Ŀ����ڲ�û������������
		if (_pAtkTarget != nullptr && !_pAtkTarget->getIsDead())
			_pAtkTarget->beHurt(getAtkPro());
		//ִ������������
		deadAction(_sName);
	});
	//���б�߲���û���õ���Ī�����
	float Hypotenuse = Vec2::ZERO.distance(Director::getInstance()->getVisibleSize());
	//��ͨ�Ĺ��������Ǵ�͸������
	Vec2 MovetoPosition = _pAtkTarget->getPosition() - this->getPosition();
	float MoveDistance = this->getPosition().distance(_pAtkTarget->getPosition());
	this->runAction(Sequence::create(MoveBy::create(MoveDistance / _iSpeed, MovetoPosition), deadActionCF, NULL));
}