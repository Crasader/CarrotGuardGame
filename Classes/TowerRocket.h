//
//  TowerRocket.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-12.
//  
//
#pragma once
#ifndef __CarrotFantasy__TowerRocket__
#define __CarrotFantasy__TowerRocket__
#include "TowerBase.h"
class TowerRocket :public TowerBase {

	int const rId = 25;
	/**
	* @brief ȷ�����Ļ���init����ʵ��
	*/
	virtual bool init();
	/**
	* @brief �������Ч��
	*/
	virtual void fire(float dt);

public:

	CREATE_FUNC(TowerRocket);
};
#endif /* defined(__CarrotFantasy__TowerRocket__) */