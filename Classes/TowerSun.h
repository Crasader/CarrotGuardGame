//
//  TowerSun.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-12.
//  �����й�
//
#pragma once
#ifndef __CarrotFantasy__TowerSun__
#define __CarrotFantasy__TowerSun__
#include "TowerBase.h"
class TowerSun :public TowerBase {
private:

	int const rId = 22;
	/**
	* @brief ȷ�����Ļ���init������ʵ��
	* @see ��������ִ�о��鲢��������
	*/
	virtual bool init();
	/**
	* @brief ̫������ȼ��Ч��
	* @param dt ����֪��������������
	*/
	virtual void fire(float dt);
	//����ִ�о��飻
	Sprite * _doAnimationSprite;

	void attack();

public:

	CREATE_FUNC(TowerSun);
};
#endif /* defined(__CarrotFantasy__TowerSun__) */