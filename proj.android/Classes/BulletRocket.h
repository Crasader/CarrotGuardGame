//
// BulletRocket.h
// CarrotFantasy
//
// Created by ������ on 18-4-11.
//
//
#pragma once
#ifndef __CarrotFantasy__BulletRocket__
#define __CarrotFantasy__BulletRocket__
#include "BulletBase.h"
class VictimEntityBase;

class BulletRocket :public BulletBase {

	friend class TowerRocket;

protected:
	/*
	* @brief ����ӵ��Ļ�������
	*/
	void doAction();
	/*
	* @brief ��������ƶ�
	*/
	void doMove()override;
	/*
	* @brief ��֤�ӵ������init����ʵ��
	*/
	virtual bool init(const int &rId, VictimEntityBase *rVictimEntity);

	static BulletRocket * create(const int &rId, VictimEntityBase *rVictimEntity);
};
#endif /* defined(__CarrotFantasy__BulletRocket__) */