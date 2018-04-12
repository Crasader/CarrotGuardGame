//
//  TowerFactory.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-12.
//
//
#pragma once
#ifndef __CarrotFantasy__TowerFactory__
#define __CarrotFantasy__TowerFactory__

#include "CommonDefine.h"

class TowerBase;

class TowerFactory
{
public:
	/**
	* @brief ������
	* @param rTowerType ��������
	* @param tPosition λ������
	*/
	static TowerBase *createTower(const TowerType &rTowerType, Vec2 tPosition);
};

#endif /* defined(__CarrotFantasy__TowerFactory__) */
