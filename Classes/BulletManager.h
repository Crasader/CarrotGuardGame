#pragma once
//
//  BulletManager.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-10.
//
//

#ifndef __CarrotFantasy__BulletManager__
#define __CarrotFantasy__BulletManager__

#include "CommonDefine.h"
class Entity;
class BulletManager : public Ref
{
public:
	/*
	* @brief �������ģʽ
	* @details cocos��ĺ궨��
	*/
	CREATE_INSTANCE_FUNCTION(BulletManager);

	DESTROY_INSTANCE_FUNCTION();
	/*
	* @brief ��ȡ�ӵ���vec
	*/
	virtual BulletVec &getBulletVec();
	/*
	* @brief ����ӵ���ͼ��ĺ���
	* @param rFunAddBulletLayer 
	*/
	virtual void setFuncAddBulletLayer(const std::function<void(Entity*)> &rFuncAddBulletLayer);
	/*
	* @brief ����ӵ��Ƿ���
	*/
	virtual void checkBulletIsDead();
	/*
	* @brief ���manager
	*/
	virtual void clearManager();

protected:
	/*
	* @brief ������Ԫ�ӵ�����
	*/
	friend class BulletBase;
	/*
	* @brief ����ӵ�
	* @param �ӵ�����ָ��
	*/
	virtual void addBullet(BulletBase *pBullet);
	/*
	* @brief ���ӵ�vec��ָ������ڴ�ռ�
	*/
	virtual bool init();

private:
	//�ӵ�vec��ָ�룻
	BulletVec *_pBulletVec = nullptr;

	std::function<void(Entity*)> _funcAddBulletLayer;

private:

	BulletManager();

	virtual ~BulletManager();

	BulletManager(const BulletManager &) = delete;

	BulletManager &operator=(const BulletManager &) = delete;

};

#endif /* defined(__CarrotFantasy__BulletManager__) */
