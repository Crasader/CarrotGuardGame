//
//BulletStar.h
//CarrotFantasy
//
//Created by ������ on 18-4-11
//
//
#pragma once
#ifndef __CarrotFantasy__BulletStar__
#define __CarrotFantasy__BulletStar__
#include "BulletBase.h"
class VictimEntityBase;

class BulletStar :public BulletBase {

	friend class TowerStar;

protected:
	/*
	* @brief ���������Ļ�������
	*/
	void doAction();
	/*
	* @brief ���ǵ��ӵ����ƶ�
	*/
	void doMove()override;
	/*
	* @brief ��֤�ӵ������init����ʵ��
	*/
	virtual bool init(const int &rId, VictimEntityBase *rVictimEntity);

	static BulletStar * create(const int &rId, VictimEntityBase *rVictimEntity);
};
#endif /* defined(__CarrotFantasy__BulletStar__) */