//
//  TowerBall.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-12.
//  
//
#pragma once
#ifndef __CarrotFantasy__TowerBall__
#define __CarrotFantasy__TowerBall__
#include "TowerBase.h"

class TowerBall :public TowerBase {
protected:
	/**
	* @brief ȷ�����Ļ���init����ʵ��
	* @see �����������鲢��������
	* @see ��ʱ����ػ�ת
	*/
	virtual bool init();
	/**
	* @brief ѡ�񹥻�Ŀ��
	*/
	void  chooseAtkTarget();
	/**
	* @brief ħ����Ĺ���Ч��
	*/
	void fire(float dt);
	/**
	* @brief ʧȥ����Ŀ��
	*/
	void missAtkTarget();

	int const rId = 10;
	//�������飻
	Sprite * _doActionSprite;

public:

	CREATE_FUNC(TowerBall);

};
#endif/* defined (__CarrotFantasy__TowerBall__)*/
