//
//  TowerPin.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-12.
//  
//
#pragma once 
#include "TowerBase.h"
class TowerPin :public TowerBase
{
protected:
	int const rId = 28;
	/**
	* @brief ����Ĺ���Ч��
	*/
	void fire(float dt);
	/**
	* @brief ȷ�����Ļ���init����ʵ��
	*/
	virtual bool init();
public:

	CREATE_FUNC(TowerPin);
};
