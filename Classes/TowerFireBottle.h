//
//  TowerFireBottle.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-12.
//  
//
#pragma once
#ifndef __CarrotFantasy__TowerFireBottle__
#define __CarrotFantasy__TowerFireBottle__
#include "TowerBase.h"

class TowerFireBottle :public TowerBase {
protected:
	/**
	* @brief ȷ�����Ļ���init����ʵ��
	* @see �����������鲢��������
	*/
	virtual bool init();
	/**
	* @brief ��ȡ����Ŀ��
	*/
	void  chooseAtkTarget();
	/**
	* @brief ʧȥ����Ŀ��
	*/
	void missAtkTarget();
	/**
	* @brief ����Ͱ�Ĺ���Ч��
	*/
	void fire(float dt);

	int const rId = 16;
	//�������飻
	Sprite * _doActionSprite;

public:

	CREATE_FUNC(TowerFireBottle);

};
#endif/* defined(__CarrotFantasy__TowerFireBottle__)*/