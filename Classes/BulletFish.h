//
// BulletFish.h
// CarrotFantasy
//
// Created by ������ on 18-4-22.
//
//
#pragma once
#ifndef __CarrotFantasy__BulletFish__
#define __CarrotFantasy__BulletFish__
#include "BulletBase.h"
class VictimEntityBase;

class BulletFish :public BulletBase 
{

	friend class TowerFish;

protected:
	/*
	* @brief ���ͷ����׼��
	*/
	void doAction();
	/*
	* @brief ���ͷ����ӵ����ƶ�
	*/
	void doMove()override;
	/*
	* @brief ��֤�ӵ������init����ʵ��
	*/
	virtual bool init(const int &rId, VictimEntityBase *rVictimEntity);
	/**
	* @�ӵ�����
	*/
	static BulletFish * create(const int &rId, VictimEntityBase *rVictimEntity);
	/**
	* @brief ����Ч�������
	*/
    int _iCrit_Effect_Random_Number;


};
#endif /* defined(__CarrotFantasy__BulletFish__) */