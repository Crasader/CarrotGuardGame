//
// BulletLittleAnchor.h
// CarrotFantasy
//
// Created by ������ on 18-4-11.
//
//
#pragma once
#include "BulletAnchor.h"
class BulletLittleAnchor :public BulletAnchor
{

protected:
	/*
	* @brief ȷ��BulletAnchor��init����ʵ��
	*/
	virtual bool init(const int &rId, VictimEntityBase *rVictimEntity);

	static BulletLittleAnchor * create(const int &rId, VictimEntityBase * rVictimEntity);

};

