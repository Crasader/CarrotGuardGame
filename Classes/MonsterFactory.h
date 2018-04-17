//
//  MonsterFactory.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-9.
//
//
#pragma once
#ifndef __CarrotFantasy__MonsterFactory__
#define __CarrotFantasy__MonsterFactory__

#include "CommonDefine.h"

class MonsterFactory
{
public:
	/*
	* @brief ���ֹ���Ŷ�����²��£����ó����
	*/
	static MonsterBase *createMonster(const MonsterType &rMonsterType);
};

#endif /* defined(__CarrotFantasy__MonsterFactory__) */