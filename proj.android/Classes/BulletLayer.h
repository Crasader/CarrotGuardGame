/**
* @brief �ӵ�ͼ����
* @details 1-��������ˣ��������ͼ���ࣻ
* @details 2-���ü�ʱ��(update())��(scheduleUpdate())���¼���ӵ��Ƿ�������
* @author ������
* @date 20180411
* */
#pragma once
#ifndef __CarrotFantasy__BulletsLayer__
#define __CarrotFantasy__BulletsLayer__

#include "EntityLayerBase.h"

/**
*  BulletsLayer use to show Bullet
*/

class BulletLayer :public EntityLayerBase
{
public:

	CREATE_FUNC(BulletLayer);

protected:

	virtual bool init();
	/*
	* @brief ����ӵ��Ƿ��������
	*/
	virtual void update(float dt);
};

#endif /* defined(__CarrotFantasy__BulletsLayer__) */
