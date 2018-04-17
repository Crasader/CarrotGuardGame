//
//  HpSlot.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-12.
//
//
#pragma once
#ifndef __CarrotFantasy__HpSlot__
#define __CarrotFantasy__HpSlot__

#include "CommonDefine.h"
class VictimEntityBase;

class HpSlot : public Node
{
public:

	virtual ~HpSlot();

	static HpSlot *create(VictimEntityBase *pVictimEntity);
	/**
	* @brief ��������ֵ
	* @param rIHp ��������ֵ
	*/
	virtual void setHp(const int &rIHp);
	/**
	* @brief ��ȡ��ǰͼ�Ĵ�С
	*/
	virtual const Size &getContentSize()const;


protected:
	/**
	* @brief ������,��ѧ���
	*/
	virtual bool init(VictimEntityBase *pVictimEntity);

private:
	//ʵ��ָ��;
	VictimEntityBase *_pVictimEntity = nullptr;

public:
	//����ֵ��ָ��;
	ProgressTimer *_pHpSlot = nullptr;

	int _iHpMax = 0;
};

#endif /* defined(__CarrotFantasy__HpSlot__) */