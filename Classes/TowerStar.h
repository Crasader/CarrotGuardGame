//
//  TowerStar.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-12.
//  
//
#pragma once
#ifndef __CarrotFantasy__TowerStar__
#define __CarrotFantasy__TowerStar__
#include "TowerBase.h"
class TowerStar :public TowerBase {

	int const rId = 13;
	/**
	* @brief ȷ�����Ļ���init����ʵ��
	* @see ��ʱ����ػ�ת
	*/
	virtual bool init();
	/**
	* @brief ���ǵ�����Ч��
	*/
	virtual void fire(float dt);

public:

	CREATE_FUNC(TowerStar);
};
#endif /* defined(__CarrotFantasy__TowerStar__) */