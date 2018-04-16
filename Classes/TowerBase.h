//
//  TowerBase.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-9.
//  ���ڲ�������
//
#pragma once
#ifndef __CarrotFantasy__TowerBase__
#define __CarrotFantasy__TowerBase__

#include "Entity.h"

class VictimEntityBase;


class TowerBase :public Entity
{
public:

	static TowerBase* create(const int &rId);

	/*
	*  Tower rocate
	* @��Ү�����Ǹ����
	*/
	virtual void doRocation(float dt);

	virtual ~TowerBase();
	/*
	* @brief ��ȡ���������ɱ�
	*/
	virtual int getTowerGradeCost();

	/*
	* @brief �趨��ǰ����Ŀ��
	* @param pVictimEntity Ŀ���
	*/
	virtual void setAtkTarget(VictimEntityBase *pVictimEntity);
	/*
	* @brief ��ʾ�ȼ���־
	*/
	virtual void showGradeMark();
	/*
	* @brief ���صȼ���־
	*/
	virtual void hideGradeMark();

	/*
	* @brief �������Ƿ��ڹ�����Χ
	* @param rPos ����Ŀ��λ��
	* @return true �ڷ����ڣ����򷵻�false
	*/
	virtual bool isInAtkRange(const Vec2 &rPos);
	/*
	* @brief ������
	*/
	virtual void upGrade();
protected:
	/*
	* @brief ������������ִ��
	*/
	virtual void deadAction(const std::string &rSDeadImageFile = "")override;
	/*
	* @brief ��鹥��Ŀ��
	* @param rDt ֡��
	*/
	virtual void checkAtkTarget(float dt);
	/*
	* @brief ѡ�񹥻�Ŀ��
	*/
	virtual void chooseAtkTarget();
	/*
	* @brief ��鹥��Ŀ���Ƿ���˷�Χ
	*/
	virtual void checkTargetIsOutOfRange();
	/*
	* @brief �������Ŀ��
	*/
	virtual void missAtkTarget();
	/*
	* @brief �ӵ�����
	*/
	virtual void fire(float dt);
	/*
	* @brief ����init
	*/
	virtual void initTower();
	/*
	* @brief ȷ��ʵ��init����init������ʵ��
	* @details ���ü�ʱ�������������ȫ����
	*/
	virtual bool init(const int &rId);
	/*
	* @brief ��������Ч��
	*/
	virtual void fireAction();
	/*
	* @brief �������ӵ���id
	*/
	CC_SYNTHESIZE_PASS_BY_REF(int, _iBulletId, IBulletId);
	/*
	* @brief �ӵ�����
	*/
	CC_SYNTHESIZE_PASS_BY_REF(int, _iAtkRange, IAtkRange);
	/*
	* @brief ���Ĺ����ռ�
	*/
	CC_SYNTHESIZE_PASS_BY_REF(double, _iAtkSpace, IAtkSpace);
	/*
	* @brief �������ĳɱ�����
	*/
	CC_SYNTHESIZE_PASS_BY_REF(std::string, _sUpgradeCost, SUpgradeCose);
	/*
	* @brief ���ļ�����
	*/
	CC_SYNTHESIZE_PASS_BY_REF(int, _iUpgradeCount, IUpgradeCount);
	/*
	* @brief �Ƿ��ת
	*/
	CC_SYNTHESIZE_PASS_BY_REF(bool, _bIsRotation, BIsRotation);
	/*
	* @brief ���������ѳɱ�
	*/
	CC_SYNTHESIZE_PASS_BY_REF(int, _iCreateCost, ICreateCost);

	/*
	* @brief ����Ŀ���Ƿ�ӵ��
	*/
	CC_SYNTHESIZE_PASS_BY_REF(bool, _bIsHaveAtkTarget, IsHaveAtkTarget);

protected:
	/*
	* @brief �ȼ���־
	*/
	Sprite* _pGradeMark = nullptr;
	/*
	* @brief �������
	*/
	Sprite *_pTowerPanel = nullptr;
	/*
	* @brief ����Ŀ��Ч��
	*/
	VictimEntityBase *_pAtkTarget = nullptr;
};

#endif /* defined(__CarrotFantasy__TowerBase__) */
