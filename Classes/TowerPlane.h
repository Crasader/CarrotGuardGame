//
//  TowerPlane.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-12.
//
//
#pragma once
#ifndef __CarrotFantasy__TowerPlane__
#define __CarrotFantasy__TowerPlane__

#include "TowerBase.h"
class TowerPlane :public TowerBase {

	int const rId = 34;
	/**
	* @brief ȷ�����Ļ���init����ʵ��
	* @see �����������鲢��������
	*/
	virtual bool init();
	/**
	* @brief �ɻ��Ĺ���Ч��
	*/
	virtual void fire(float dt);
	//�������飻
	Sprite * _doAnimationSprite;

public:
	void attack();
	CREATE_FUNC(TowerPlane);
};

#endif /* defined(__CarrotFantasy__TowerPlane__) */