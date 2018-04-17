/**
* @brief �ӵ�������
* @details ����ӵ���ͼ�㡢���ӵ���������ͳһ������
* @author ������
* @date 180410
* */
#pragma once
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
	/**
	* @brief ��ȡ�ӵ�vector������
	*/
	virtual BulletVec &getBulletVec();
	/*
	* @brief ����ӵ���ͼ������ú���
	*/
	virtual void setFuncAddBulletLayer(const std::function<void(Entity*)> &rFuncAddBulletLayer);
	/*
	* @brief ����ӵ��Ƿ���
	*/
	virtual void checkBulletIsDead();
	/*
	* @brief ���������
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
	* @brief ���ӵ�vectorָ������ڴ�ռ�
	*/
	virtual bool init();

private:
	//�ӵ�vector��ָ�룻
	BulletVec *_pBulletVec = nullptr;

	std::function<void(Entity*)> _funcAddBulletLayer;

private:

	BulletManager();

	virtual ~BulletManager();

	BulletManager(const BulletManager &) = delete;

	BulletManager &operator=(const BulletManager &) = delete;

};

#endif /* defined(__CarrotFantasy__BulletManager__) */
