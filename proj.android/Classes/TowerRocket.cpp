//
//  BulletBase.cpp
//  CarrotFantasy
//
//  Created by 何泓兵 on 18-4-12.
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
	if (!_pAtkTarget || _pAtkTarget->getIsDead()) return; //死了就赶紧返回
	auto fireActionCF = CallFunc::create([=]() { fireAction(); });

	auto createBulletCF = CallFunc::create([=]() {
		if (!_pAtkTarget) return;
		//子弹启动
		//第一个参数是子弹ID，第二个参数是目标怪物
		BulletRocket * pBullet = BulletRocket::create(_iBulletId, _pAtkTarget);
		pBullet->setPosition(this->getPosition()); //确定发射位置
		//确定发射角度，公式还是一样的
		pBullet->setRotation(90 - 180 * (_pAtkTarget->getPosition() - this->getPosition()).getAngle() / M_PI);
		pBullet->doMove(); //子弹发射启动
	});

	this->runAction(Sequence::create(fireActionCF, DelayTime::create(0.35), createBulletCF, nullptr));
}