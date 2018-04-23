
//
//  BarriersLayer.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-8.
//
//
#pragma once
#ifndef __CarrotFantasy__BarriersLayer__
#define __CarrotFantasy__BarriersLayer__

#include "EntityLayerBase.h"

/**
 *  @brief �ϰ����������ʾ�ϰ���
 */

class BarriersLayer : public EntityLayerBase
{

public:

	CREATE_FUNC(BarriersLayer);

protected:
	/*
	 * @brief ִ���ϰ���ʵ������ĳ�ʼ����
	 */
	virtual bool init();
	/**
	* @brief ��ʾ�ϰ��ﱻ���ʱ���ֵ�ͼ��
	*/
	void DeleteBarrierLayer(Ref* rBarrierVec);

};

#endif /* defined(__CarrotFantasy__BarriersLayer__) */
