//
//  BarrierBase.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-7.
//
//
#pragma once
#ifndef __CarrotFantasy__BarrierBase__
#define __CarrotFantasy__BarrierBase__


#include "VictimEntityBase.h"

class BarrierBase :public VictimEntityBase
{

public:

	static BarrierBase * create(const int &rId);
	/*
	* @brief ��Ԫ�ϰ��﹤��
	*/
	friend class BarrierFactory;

protected:
	/*
	* @brief ����ϰ���
	* @details ������ʵ������init
	* @return true ��ӳɹ������򷵻�false
	*/
	virtual bool init(const int &rId);
	/*
	* @brief ��������
	*/
	virtual void deadAction(const std::string &rSDeadImageFile = "");
	/*
	* @brief ���˶���
	*/
	virtual void behurtAction();

};

#endif /* defined(__CarrotFantasy__BarrierBase__) */
