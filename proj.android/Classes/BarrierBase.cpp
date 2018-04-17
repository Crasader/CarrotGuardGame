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
		CC_BREAK_IF(!VictimEntityBase::init(rId, BARRIERCSVFILE)); //���ø���ĳ�ʼ�������϶�����ɳ�ʼ������
		BarrierManager::getInstance()->addBarrier(this); //��������ע���Լ�
		bRet = true;
	} while (0);

	return bRet;
}

BarrierBase * BarrierBase::create(const int &rId) 
{

	BarrierBase * pBarriers = new BarrierBase(); //newһ������

	if (pBarriers && pBarriers->init(rId)) //���г�ʼ������
	{
		pBarriers->autorelease();
		return pBarriers; //Ҫ�ǳ�ʼ���ɹ��ˣ�����
	}
	CC_SAFE_DELETE(pBarriers);
	return nullptr;
}

void BarrierBase::deadAction(const std::string &rSDeadImageFile)
{
	NOTIFY->postNotification("BarrierDead", this); //�����ϰ���ҵ���֪ͨ
	MapUtil::getInstance()->removeBarrierRect(getPosition()); //��ͼȥ���ϰ�������������λ��
	VictimEntityBase::deadAction();
}



