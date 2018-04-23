/**
* @brief ������������
* @extends TowerBase
* @details �����㲻������תЧ�������з�Χ����Ч��
* @authors ������
* @date 20180419
* */
#pragma once
#ifndef __CarrotFantasy__TowerCuttle__
#define __CarrotFantasy__TowerCuttle__

#include "TowerBase.h"

class TowerCuttle :public TowerBase
{
private:
	const int rId = 40;

	AtkProperty atk;

	//����ִ�о��飻
	Sprite *_doAnimationSprite;

	/**
	* @brief ��д����ĳ�ʼ������
	* @details Ҫע����ת��������
	* @see ��ʱ�������ת
	*/
	virtual bool init();

	/**
	* @brief ��д������
	* @details ������������������
	* @param dt ������Ҫ������Ĳ���
	*/
	virtual void fire(float dt);

public:

	CREATE_FUNC(TowerCuttle);
};
#endif /* defined(__CarrotFantasy__TowerCuttle__) */