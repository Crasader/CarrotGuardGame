//
//  BarrierBase.cpp
//  CarrotFantasy
//
//  Created by ������ on 18-4-8.
//
//  ��һ���յĺ���

#include "BarrierBase.h"
#include "BarrierManager.h"
#include "MapUtil.h"

bool BarrierBase::init(const int &rId)
{
	bool bRet = false;

	do
	{
		CC_BREAK_IF(!VictimEntityBase::init(rId, BARRIERCSVFILE));
		BarrierManager::getInstance()->addBarrier(this);
		bRet = true;
	} while (0);

	return bRet;
}

BarrierBase * BarrierBase::create(const int &rId) 
{

	BarrierBase * pBarriers = new BarrierBase();

	if (pBarriers && pBarriers->init(rId))
	{
		pBarriers->autorelease();
		return pBarriers;
	}
	CC_SAFE_DELETE(pBarriers);
	return nullptr;
}

void BarrierBase::deadAction(const std::string &rSDeadImageFile)
{
	NOTIFY->postNotification("BarrierDead", this);
	MapUtil::getInstance()->removeBarrierRect(getPosition());
	VictimEntityBase::deadAction();
}
//�����ôû��д����������
void BarrierBase::behurtAction()
{

}


