
//
//  BarrierFactory.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-8.
//
//
#pragma once
#ifndef __CarrotFantasy__BarrierFactory__
#define __CarrotFantasy__BarrierFactory__

#include "CommonDefine.h"

class BarrierBase;

class BarrierFactory
{
public:
	/*
	* @brief �ֹ�Ŀǰ�ϰ���ֻ���ĸ��������Ǹ߼�����Ա���Ϲ��ľ�ͷ��ѧ����
	*/
	static BarrierBase *createBarrier(const BarrierType &rBarrierType);
};

#endif /* defined(__CarrotFantasy__BarrierFactory__) */
