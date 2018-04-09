//
//  MonsterLayer.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-9.
//
//
#pragma once
#ifndef __CarrotFantasy__MonsterLayer__
#define __CarrotFantasy__MonsterLayer__

#include "EntityLayerBase.h"

class MonsterBase;

/*
* @brief ������ʾ����
*/
class MonsterLayer :public EntityLayerBase
{
public:

	CREATE_FUNC(MonsterLayer);

protected:

	/*
	* @brief ��ӹ�����ڽ�ͼ��
	*/
	virtual bool init();
	/*
	* @brief ע����������¼�
	* @details ����������ܲ�������
	*/
	virtual void registerMonsterDeadEvent();
	/*
	* @brief ������������
	* @details �����������ܲ������ӹ���
	*/
	virtual void monsterDead(Ref *pData);
	/*
	* @brief ��������
	*/
	virtual void onExit()override;

};

#endif /* defined(__CarrotFantasy__MonsterLayer__) */
