//
//  LayerBase.cpp
//  CarrotFantasy
//
//  Created by ������ on 18-4-7.
//
//

#include "EntityLayerBase.h"
#include "Entity.h"

void EntityLayerBase::addEntity(Entity *pEntity)
{
	addChild(pEntity);
}