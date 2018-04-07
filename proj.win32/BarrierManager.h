//
//  BarrierManager.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-7.
//
//

#pragma once
#ifndef __CarrotFantasy__BarrierManager__
#define __CarrotFantasy__BarrierManager__

#include "PublicDefine.h"

class Entity;

class BarrierManager : public Ref
{
public:
	/*
	* @brief �������ģʽ
	* @see ��Դ��cocos�ĺ�
	*/
	CREATE_INSTANCE_FUNC(BarrierManager);

	DESTROY_INSTANCE_FUNC();
	/*
	* @brief ��ȡ�ϰ���vector
	*/
	BarrierVec &getBarrierVec();
	/*
	* @brief ��������ϰ��ﵽlayer��
	* @param 
	*/
	virtual void setFuncAddBarrierToLayer(const std::function<void(Entity*)> &rFuncAddBarrierToLayer);
	/*
	* @brief ��������������״̬
	*/
	virtual void clearBeAtkLockState();
	/*
	* @brief �������
	*/
	virtual void clearManager();

protected:

	friend class BarrierBase;
	/*
	* @brief ����ϰ���
	*/
	virtual void addBarrier(BarrierBase *pBarrier);
	/*
	* @brief ����BarrierVec����ע���¼�
	* @return true �㶨���أ����򷵻�false
	*/
	virtual bool init();
	/*
	* @brief ע���ϰ��ﱻ�ɵ��¼�
	*/
	virtual void registerBarrierDeadEvent();
	/*
	* @brief ��manager��ɾȥָ�����ϰ���
	*/
	virtual void removeBarrierFromManager(Ref *pBarrier);

private:
	//����vector��
	BarrierVec *_pBarrierVec = nullptr;

	std::function<void(Entity*)> _funcAddBarrierToLayer;

private:

	BarrierManager();

	virtual ~BarrierManager();

	BarrierManager(const BarrierManager &) = delete;

	BarrierManager &operator=(const BarrierManager &) = delete;
};

#endif /* defined(__CarrotFantasy__BarrierManager__) */