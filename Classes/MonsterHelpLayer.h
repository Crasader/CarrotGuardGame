//
//  MonsterHelpLayer.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-9.
//
//
#pragma once
#ifndef __CarrotFantasy__MonsterHelpLayer__
#define __CarrotFantasy__MonsterHelpLayer__

#include "CommonDefine.h"

class MonsterHelpLayer :public Layer
{
public:

	CREATE_FUNC(MonsterHelpLayer);

protected:
	/*
	* @brief ��ӹ��������ͼ��
	*/
	virtual bool init()override;
};

#endif /* defined(__CarrotFantasy__MonsterHelpLayer__) */