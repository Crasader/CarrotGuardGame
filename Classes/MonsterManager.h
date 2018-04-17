//
//  MonsterManager.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-9.
//
//
#pragma once
#ifndef __CarrotFantasy__MonsterManager__
#define __CarrotFantasy__MonsterManager__


#include "CommonDefine.h"

class Entity;

class MonsterManager : public Ref
{
public:
	/*
	* @brief cocos��ĺ�
	* @details �������ģʽ
	*/
	CREATE_INSTANCE_FUNCTION(MonsterManager);

	DESTROY_INSTANCE_FUNCTION();
	/*
	* @brief ��ȡ����vector������
	*/
	virtual MonsterVec &getMonsterVec();
	/*
	* @brief ��ӹ��ﵽͼ������ú���
	*/
	virtual void setFuncAddMonsterToLayer(const std::function<void(Entity*)> &rFuncAddMonsterToLayer);
	/*
	* @brief ���������
	*/
	virtual void clearManager();
	/*
	* @brief ���������������״̬
	*/
	virtual void clearBeAtkLockState();

protected:
	/*
	* @brief ������Ԫ��
	*/
	friend class MonsterBase;
	/*
	* @brief �����Ϸ�Ƿ��������
	*/
	virtual void openCheckGameEnd(Ref *pSender);
	/*
	* @brief ��ӹ���
	*/
	virtual void addMonster(MonsterBase *pBullet);
	/*
	* @brief ȷ��ע���������¼�
	* @return true ע��ɹ������򷵻�false
	*/
	virtual bool init();
	/*
	* @brief ע�������¼�
	*/
	virtual void registerDeadEvent();
	/*
	* @brief ��manager��ɾȥ����
	*/
	virtual void removeMonsterFromManager(Ref *pMonster);

private:
	//����vector����ָ�룻
	MonsterVec *_pMonsterVec = nullptr;

	std::function<void(Entity *)> _funcAddMonsterToLayer;

	bool _bIsOpenCheckGameEnd = false;

private:

	MonsterManager();

	virtual ~MonsterManager();

	MonsterManager(const MonsterManager &) = delete;

	MonsterManager &operator=(const MonsterManager &) = delete;

};


#endif /* defined(__CarrotFantasy__MonsterManager__) */
