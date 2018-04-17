//
//  TowersLayer.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-11.
//
//
#pragma once
#ifndef __CarrotFantasy__TowersLayer__
#define __CarrotFantasy__TowersLayer__

#include "EntityLayerBase.h"

/*
* @brief ������ʾ��
*/
class TowersLayer :public EntityLayerBase
{
public:

	CREATE_FUNC(TowersLayer);

protected:
	/*
	* @brief ��ʾ��������ļ���
	*/
	virtual void checkTowerGrade(float dt);
	/*
	* @details ȷ��layer��init����ʵ��
	* @details ��������֡���沢��ֵ
	* @details ��ʱ��������ļ���
	*/
	virtual bool init();


};

#endif /* defined(__CarrotFantasy__TowersLayer__) */
