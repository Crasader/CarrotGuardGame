//
// BulletAnchor.h
// CarrotFantasy
//
// Created by ������ on 18-4-11.
//
//
#pragma once
#include "BulletBase.h"
class BulletAnchor :public BulletBase
{

	friend class TowerAnchor;

protected:
	/**
	* @brief ê�ӵ��Ļ�������
	*/
	void doAction();
	/**
	* @brief ê�ӵ����˶�
	*/
	void doMove()override;
	/**
	* @brief ��֤�ӵ�����ĳɹ���ʼ��
	*/
	virtual bool init(const int &rId, VictimEntityBase *rVictimEntity);
	/**
	* @brief ����ê���ӵ�
	*/
	static BulletAnchor * create(const int &rId, VictimEntityBase * rVictimEntity);

};