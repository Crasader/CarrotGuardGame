//
//  GameManager.cpp
//  CarrotFantasy
//
//  Created by ������ on 18-4-8.
//
//

#include "GameManager.h"

GameManager *GameManager::_gInstance;


bool GameManager::init()
{
	_bIsPause = false;
	return true;
}