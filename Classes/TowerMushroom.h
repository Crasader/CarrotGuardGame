/**
* @brief Ģ��������
* @extends TowerBase
* @details Ģ����������תЧ�������з�Χ����Ч��
* @authors ������
* @date 20180422
* */
#pragma once
#ifndef __CarrotFantasy__TowerMushroom__
#define __CarrotFantasy__TowerMushroom__

#include "TowerBase.h"

class TowerMushroom : public TowerBase
{
private:

	const int rId = 46;

	/**
	* @brief ��д����ĳ�ʼ������
	* @details Ҫע����ת��������
	* @see ��ʱ����ػ�ת
	*/
	virtual bool init();

	/**
	* @brief ��д������
	* @details ������������������
	* @param dt ������Ҫ������Ĳ���
	*/
	virtual void fire(float dt);

	//����ִ�о��飻
	Sprite *_doAnimationSprite;

	/**
	* @brief Ģ��ʵ�ʵĹ���Ч������
	* @details ��fire���õ�Ģ��ʵ�ʹ���Ч���ĺ���
	* @todo ������ͳһ
	* */
	void attack();

public:

	CREATE_FUNC(TowerMushroom);
};

#endif /* defined(__CarrotFantasy__TowerSun__) */