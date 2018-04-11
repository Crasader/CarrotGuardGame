//
//  MonsterBase.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-9.
//
//
#pragma once
#ifndef __CarrotFantasy__MonsterBase__
#define __CarrotFantasy__MonsterBase__

#include "VictimEntityBase.h"
#include "DynamicPropertyInterFace.h"

class MoveControllerBase;

class MonsterBase : public VictimEntityBase, public DynamicPropertyInterFace
{
	friend class MonsterFactory;

public:
	/*
	* @brief ���ݹ���id��������
	*/
	static MonsterBase * create(const int &rIId);
	/*
	* @brief ��������ٶ�
	*/
	void setMaxSpeed(const int &iSpeed);

protected:
	/*
	* @brief ִ����������
	*/
	virtual void deadAction(const std::string &rSDeadImageFile = "")override;
	/*
	* @brief ģ�;���������
	*/
	virtual void doAction(const float &rDt);
	/*
	* @brief ����init
	*/
	virtual bool init(const int &rIId);
	/*
	* @brief ���˶���
	*/
	virtual void behurtAction();
	/*
	* @brief �������ﶯ��
	*/
	virtual void createAnimation();
	/*
	* @brief ����Ĺֽ��������²���
	*/
	virtual void MonsterSound();
	/*
	* @brief �жϹ���ķ���
	*/
	CC_SYNTHESIZE_PASS_BY_REF(bool, _bIsLeft, IsLeft);

	MoveControllerBase * _pMoveController = nullptr;
};

#endif /* defined(__CarrotFantasy__MonsterBase__) */
