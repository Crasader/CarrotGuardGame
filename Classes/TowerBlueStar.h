//
//  TowerBlueStar.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-12.
//  
//
#pragma once
#ifndef __CarrotFantasy__TowerBlueStar__
#define __CarrotFantasy__TowerBlueStar__
#include "TowerBase.h"
class TowerBlueStar :public TowerBase {

	int const rId = 19;
	/**
	* @brief ȷ�����Ļ���init����ʵ��
	* @see ��ʱ����ػ�ת
	*/
	virtual bool init();
	/**
	* @brief �����ǵĹ���Ч��
	*/
	virtual void fire(float dt);

public:

	CREATE_FUNC(TowerBlueStar);
};
#endif /* defined(__CarrotFantasy__TowerBlueStar__) */