//
//  BulletBase.cpp
//  CarrotFantasy
//
//  Created by ������ on 18-4-12.
//  
//
#include "TowerRocket.h"
#include "BulletRocket.h"
#include "VictimEntityBase.h"

bool TowerRocket::init()
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!TowerBase::init(rId));

		bRet = true;
	} while (0);
	return bRet;
}

void TowerRocket::fire(float dt) {
	if (!_pAtkTarget || _pAtkTarget->getIsDead()) return; //���˾͸Ͻ�����
	auto fireActionCF = CallFunc::create([=]() { fireAction(); });

	auto createBulletCF = CallFunc::create([=]() {
		if (!_pAtkTarget) return;
		//�ӵ�����
		//��һ���������ӵ�ID���ڶ���������Ŀ�����
		BulletRocket * pBullet = BulletRocket::create(_iBulletId, _pAtkTarget);
		pBullet->setPosition(this->getPosition()); //ȷ������λ��
		//ȷ������Ƕȣ���ʽ����һ����
		pBullet->setRotation(90 - 180 * (_pAtkTarget->getPosition() - this->getPosition()).getAngle() / M_PI);
		pBullet->doMove(); //�ӵ���������
	});

	this->runAction(Sequence::create(fireActionCF, DelayTime::create(0.35), createBulletCF, nullptr));
}