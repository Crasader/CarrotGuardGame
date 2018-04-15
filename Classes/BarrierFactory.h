/**
 * @brief �ϰ��﹤����
 * @details �����ϰ������ͣ����ɶ�Ӧ���ϰ������
 * @author ������
 * @date 20180408
 * @todo ���ᱻ�����˰ɣ���
 * */
#pragma once
#ifndef __CarrotFantasy__BarrierFactory__
#define __CarrotFantasy__BarrierFactory__

#include "CommonDefine.h"

class BarrierBase;

class BarrierFactory
{
public:
	/**
	 * @brief �����ϰ�����ྲ̬����
	 * @details ���ݸ������ϰ������ͣ����ɶ�Ӧ���ϰ������
	 * @param rBarrierType �ϰ�������
	 * */
	static BarrierBase *createBarrier(const BarrierType &rBarrierType);
};

#endif /* defined(__CarrotFantasy__BarrierFactory__) */
