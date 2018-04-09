//
//  VictimBase.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-7.
//
//
#pragma once
#ifndef __CarrotFantasy__VictimEntityBase__
#define __CarrotFantasy__VictimEntityBase__

#include "Entity.h"
class HpSlot;

class VictimEntityBase :public Entity
{
public:

	virtual ~VictimEntityBase();

	/**
	*  @brief ʵ�屻�˺������б��˺�func
	*  @param rBeHurtValue ���ڹ�����
	*/
	virtual void beHurt(const AtkProperty tBeHurtValue);
	/*
	* @brief ���ù���Ŀ��
	*/
	virtual void setAtkTarget(const bool &rBisAtkTarget);
	/*
	* @brief ��ȡ����Ŀ��
	*/
	virtual bool getAtkTarget()const { return _bIsAtkTarget; };
	/*
	* @��������Ŀɼ�����
	*/
	virtual void hpSlotVisible(const bool &rBIsVisible);

protected:
	/*
	* @brief �ر�����ֵ��ʾ
	*/
	virtual void closeHpSlot(float dt);
	/*
	* @brief ��鹥��Ŀ��
	*/
	virtual void checkAtkTarget(float dt);
	/*
	* @
	*/
	virtual bool init(const int &rIId, const std::string &rSCsvFileName);
	/*
	* @brief ����������־����
	*/
	virtual void createLockFlagAnimate();
	/*
	* @brief �Ѿ��������ֵ��۰󶨲�����
	*/
	virtual void createHpSlotSprite();
	/*
	* @brief �Ѿ������������Ŀ��󶨲�����
	*/
	virtual void createLockAtkSprite();
	/*
	* @brief ִ����������
	*/
	virtual void deadAction(const std::string &rSDeadImageFile = "")override;
	/*
	* @brief ���˶�������������
	*/
	virtual void behurtAction() = 0;
	/*
	* @brief �ϰ���͹����hp
	*/
	CC_SYNTHESIZE_PASS_BY_REF(int, _iHp, IHp);
	/*
	* @brief ����λ
	*/
	CC_SYNTHESIZE_PASS_BY_REF(int, _iState, IState);
	/*
	* @brief ״̬����ʱ��
	*/
	CC_SYNTHESIZE_PASS_BY_REF(float, _fSlowDuration, FSlowDuration);
	CC_SYNTHESIZE_PASS_BY_REF(float, _fStopDuration, fStopDuration);
	CC_SYNTHESIZE_PASS_BY_REF(float, _fPoisonDuration, fPoisonDuration);

	CC_SYNTHESIZE_PASS_BY_REF(float, _iBulletStateType, IBulletStateType);
	/*
	*  @brief �����۹ر�ʱ��
	*/
	const int _iHpCloseTime = 3;

private:

	bool _bHpSlotExsit = false;

	/*
	* @brief �����۾���
	*/
	HpSlot *_pHpSlot = nullptr;
	/*
	* @brief ����������־����
	*/
	Sprite *_pLockAtkTarget = nullptr;
	/*
	* @brief ������־����
	*/
	Animate *_pLockFlagAnimate = nullptr;

	/*
	* @brief ��־�ܺ����ǹ���Ŀ��
	*/
	bool _bIsAtkTarget = false;

	Vec2 _Pos;

	Size _Size;
};

#endif /* defined(__CarrotFantasy__VictimBase__) */
