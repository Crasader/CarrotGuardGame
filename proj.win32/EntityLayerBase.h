//
//  LayerBase.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-7.
//
//
#pragma once
#ifndef __CarrotFantasy__EntityLayerBase__
#define __CarrotFantasy__EntityLayerBase__

#include "cocos2d.h"
using namespace cocos2d;

class Entity;

class EntityLayerBase :public Layer
{

public:
	/*
	* @brief ���ʵ��
	*/
	virtual void addEntity(Entity *pEntity);
};

#endif /* defined(__CarrotFantasy__LayerBase__) */
