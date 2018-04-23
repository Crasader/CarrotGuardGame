/**
* @brief �����ӵ���ײ�����
* @authors ������ x �½���
* @date 20180412
* */
#pragma once
#ifndef __CarrotFantasy__CollisionManager__
#define __CarrotFantasy__CollisionManager__

#include "CommonDefine.h"

class CollisionManager
{
public:
	/**
	* @brief ������ײ
	* @param rBarrierVec �ϰ���vec
	* @param rMonsterVec ����vec
	* @param rBulletVec �ӵ�vec
	*/
	static void collision(Vector<BarrierBase *> &rBarrierVec, Vector<MonsterBase *> &rMonsterVec, Vector<BulletBase*> &rBulletVec);

protected:
	/**
	* @brief �ӵ��͹������ײ
	* @param pBullet �ӵ���ָ��
	* @param rMonSterVec ����vec
	*/
	static void MonsterAndBullet(BulletBase * pBullet, Vector<MonsterBase *> &rMonsterVec);
	/**
	* @brief �ϰ�����ӵ�����ײ
	* @param pBullet �ӵ���ָ��
	* @param rBarrierVec �ϰ���vec
	*/
	static void BarrierAndBullet(BulletBase * pBullet, Vector<BarrierBase *> &rBarrierVec);
	/**
	* @brief ��������
	* @param BulletName �ӵ�����
	* @param SpriteFrameCount ����֡��Ŀ
	*/
	static Animation * AnimationMaker(std::string BulletName, int SpriteFrameCount);

};

#endif /* defined(__CarrotFantasy__CollisionManager__) */