//
// BulletBlueStar.h
// CarrotFantasy
//
// Created by ������ on 18-4-11.
//
//
#pragma once
#ifndef __CarrotFantasy__BulletBlueStar__
#define __CarrotFantasy__BulletBlueStar__
#include "BulletBase.h"
class VictimEntityBase;

class BulletBlueStar :public BulletBase {

	friend class TowerBlueStar;

protected:
	/*
	* @brief �����ǵĻ�������
	*/
	void doAction();
	/*
	* @brief ����������ӵ����ƶ�
	*/
	void doMove()override;
	/*
	* @brief ��֤�ӵ������init����ʵ��
	*/
	virtual bool init(const int &rId, VictimEntityBase *rVictimEntity);

	static BulletBlueStar * create(const int &rId, VictimEntityBase *rVictimEntity);
};
#endif /* defined(__CarrotFantasy__BulletBlueStar__) */