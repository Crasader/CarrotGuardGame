//
//  BulletBase.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-10.
//  ���ڲ�����
//
#pragma once
#ifndef __CarrotFantasy__BulletBase__
#define __CarrotFantasy__BulletBase__

#include "Entity.h"
#include "DynamicPropertyInterface.h"

class BulletBase :public Entity, public DynamicPropertyInterface
{

public:
	std::set<int>& getIdMap();

	virtual void doMove();

	static BulletBase *create(const int &rIId, VictimEntityBase *rVictimEntity);
	/*
	* @brief �ӵ�������
	*/
	virtual AtkProperty getAtkPro();
	/*
	* @brief ��������
	*/
	virtual void deadAction(const std::string &rSDeadImageFile = "");

	/*
	* @brief ����
	* @param rDt �ӳ�ʱ��
	*/
	virtual void doAction(const float &rDt);

protected:
	/*
	* @brief ȷ��ʵ����Ͷ�̬�������init��ʵ��
	* @retails ��ȡ�ӵ�����״̬���ӵ����ͣ�����������Ŀ��������ƺõ��ӵ���������
	* @param rId
	* @param rVictimEntity ���˺�ʵ���ͬ�ڹ���Ŀ��
	*/
	virtual bool init(const int &rId, VictimEntityBase *rVictimEntity);
	/*
	* @brief ��������Ƿ����࣬��ô���ٱ��
	*/
	CC_SYNTHESIZE_PASS_BY_REF(int, _iAtkState, IAtkState);

	CC_SYNTHESIZE_PASS_BY_REF(int, _iBulletType, IBulletType);

	CC_SYNTHESIZE_PASS_BY_REF(int, _iDeadActCount, IDeadActCount);
	//����Ŀ��ָ�룻
	VictimEntityBase *_pAtkTarget = nullptr;

	std::set<int> *_IdMap = nullptr;
};

#endif /* defined(__CarrotFantasy__BulletBase__) */