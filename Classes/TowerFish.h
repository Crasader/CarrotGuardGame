/**
* @brief ���ͷ������
* @extends TowerBase
* @details ���ͷ������תЧ�������и��ʶ���(��ѣ��)����
* @authors ������
* @date 20180422
* */

#pragma once

#ifndef __CarrotFantasy__TowerFish__
#define __CarrotFantasy__TowerFish__

#include "TowerBase.h"

class TowerFish : public TowerBase
{

	int const rId = 43;

	/**
	* @brief ��д��ʼ������
	* @extends TowerBase
	*/
	virtual bool init();

	/**
	* @brief ��д���ͷ���ں���
	* @details ����һ�¿����Ъʱ��
	* @todo
	*/
	virtual void fire(float dt);

public:

	CREATE_FUNC(TowerFish);
};

#endif /* defined(__CarrotFantasy__TowerFish__) */
