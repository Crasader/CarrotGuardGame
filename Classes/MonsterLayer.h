/**
 * @brief ��������Ľ�Ǯ��ʾͼ����
 * @todo ���ļ�����Ĳ���
 * @author ������
 * @date 20180409
 * */
#pragma once
#ifndef __CarrotFantasy__MonsterLayer__
#define __CarrotFantasy__MonsterLayer__

#include "EntityLayerBase.h"

class MonsterBase;

class MonsterLayer :public EntityLayerBase
{
public:

	CREATE_FUNC(MonsterLayer);

protected:

	/**
	 * @brief ��ʼ������
	 * */
	virtual bool init();

	/**
	 * @breif ע����������¼���Ĵ�����
	 * @details ��������֮�󣬻���Ͻ�Ǯͼ��
	 * */
	virtual void registerMonsterDeadEvent();

	/*
	* @brief ����������Ǯ�����ͼ����ʾ
	* @details ������������Ǯ�����ӹ���
	* @details ׼ȷ��˵��������֮���Ǹ���Ǯ�Ŀ�������Ķ���
	*/
	virtual void monsterDead(Ref *pData);

	virtual void onExit()override;

};

#endif /* defined(__CarrotFantasy__MonsterLayer__) */
