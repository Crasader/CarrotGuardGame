/**
* @brief ����������
* @extends TowerBase
* @details ��������������ת
* @authors ������
* @date 20180423
* */
#pragma once
#pragma once
#ifndef TOWER_ARROW_H
#define TOWER_ARROW_H

#include "TowerBase.h"

class TowerArrow : public TowerBase
{

	int const rId = 49;

	/**
	* @brief ��д��ʼ������
	* @extends TowerBase
	* */
	virtual bool init();

	/**
	* @brief ��д����Ĺ�������
	* @param dt ������Ҫ�������õ��ĵ���ʱ��
	* @details ������ľ�����Ϸ�߼�д������
	* @see Ȼ��ʵ�ʵĹ���Ч����attack()������ʵ��
	*/
	virtual void fire(float dt);


	Sprite *_doAnimationSprite;

public:
	/**
	* @brief ʵ�ʵĹ���Ч������
	* @details ��fire���õĹ���ʵ�ʹ���Ч���ĺ���
	* @todo ������ͳһ
	* */
	void attack();

	CREATE_FUNC(TowerArrow);
};

#endif /* defined(TOWER_ARROW_H) */