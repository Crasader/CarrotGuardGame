//
//  TowerSnow.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-12.
//  
//
#pragma once
#ifndef __CarrotFantasy__TowerSnow__
#define __CarrotFantasy__TowerSnow__
#include "TowerBase.h"
class TowerSnow :public TowerBase {

	int const rId = 31;
	/**
	* @brief ȷ�����Ļ���init����ʵ��
	* @see ��ʱ����ػ�ת
	* @see �����������鲢��������
	*/
	virtual bool init();
	/**
	* @brief ѩ���Ĺ���Ч��
	*/
	virtual void fire(float dt);
	//�������飻
	Sprite * _doAnimationSprite;

	void attack();

public:

	CREATE_FUNC(TowerSnow);
};
#endif /* defined(__CarrotFantasy__TowerSnow__) */