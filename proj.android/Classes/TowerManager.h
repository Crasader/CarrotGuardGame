//
//  TowerManager.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-11.
//
//
#pragma once
#ifndef __CarrotFantasy__TowerManager__
#define __CarrotFantasy__TowerManager__

#include "CommonDefine.h"

class Entity;

class TowerManager :public Ref
{
public:

	CREATE_INSTANCE_FUNCTION(TowerManager);

	DESTROY_INSTANCE_FUNCTION();
	/*
	* @brief ��ȡ����vec
	*/
	virtual TowerVec &getTowerVec();
	/*
	* @brief �������layer��
	*/
	virtual void setFuncAddTowerLayer(const std::function<void(Entity*)> &rFuncAddEntityLayer);
	/*
	* @brief ����manager
	*/
	virtual void clearManager();
	/*
	* @brief ������Ľ�Ǯ�����ú���
	*/
	virtual void setFuncCheckMoney(const std::function<int()> &rFuncCheckMoney);
	/*
	* @brief ��ȡ���ڵĽ��
	*/
	virtual int getMoney();
protected:
	/*
	* @brief ������Ԫ������
	*/
	friend class TowerBase;
	/*
	* @brief ������ĺ���
	*/
	virtual void addTower(TowerBase *pTower);
	/*
	* @ע�����������¼�
	*/
	virtual void registerTowerDeadEvent();
	/*
	* @brief ������vecָ���ڴ棬��ע���¼�
	*/
	virtual bool init();
	/*
	* @brief ��manager���������
	*/
	virtual void removeTowerFromManager(Ref *pSender);

private:
	//����vecָ�룻
	TowerVec *_pTowerVec = nullptr;

	std::function<void(Entity*)> _funcAddTowerToLayer;

	std::function<int()> _funcCheckMoney;


private:

	TowerManager();

	virtual ~TowerManager();

	TowerManager(const TowerManager &) = delete;

	TowerManager &operator=(const TowerManager &) = delete;

};


#endif /* defined(__CarrotFantasy__TowerManager__) */
