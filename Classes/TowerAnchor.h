//
//  TowerAnchor.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-12.
//  
//
#pragma once
#include "TowerBase.h"
class TowerAnchor :public TowerBase
{
private:
	Sprite * _doActionSprite;
	int const rId = 37;
	/**
	* @brief ê�Ĺ���Ч��
	*/
	void fire(float dt);
	/**
	* @brief ȷ�����Ļ���init����ʵ��
	*/
	virtual bool init();
public:
	CREATE_FUNC(TowerAnchor);
};
