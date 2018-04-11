//
// BullePin.h
// CarrotFantasy
//
// Created by ������ on 18-4-11.
//
//
#pragma once
#include "BulletBase.h"
class  BulletPin :public BulletBase
{

	friend class TowerPin;

protected:
	/*
	* @brief ����Ļ�������
	*/
	void doAction();
	/*
	* @brief ���붾Һ���ƶ�
	*/
	void doMove()override;
	/*
	* @brief ��֤�ӵ������init����ʵ��
	*/
	virtual bool init(const int &rId, VictimEntityBase *rVictimEntity);
	static BulletPin * create(const int &rId, VictimEntityBase * rVictimEntity);

};