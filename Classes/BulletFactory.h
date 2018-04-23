/**
* @brief �ӵ�������
* @details 1-�����ӵ����͡��������ͺͱ�������ʵ�崴�������ӵ�
* @details 2-�����ӵ����������ת�Լ��ӵ��ĳ�ĩλ��
* @author ������
* @date 20180410
* */
#pragma once
#ifndef __CarrotFantasy__BulletFactory__
#define __CarrotFantasy__BulletFactory__

#include "CommonDefine.h"

class VictimEntityBase;

class BulletFactory
{
public:
	/**
	* @brief ���������ӵ�
	* @param rBulletId �ӵ���id
	* @param rTower �������ָ��
	* @param rVictimEntity ����ʵ�壬��ͬ�ڹ���Ŀ��
	*/
	static BulletBase *createBullet(const int &rBulletId, TowerBase* rTower, VictimEntityBase *rVictimEntity);

    /**
     * @brief ���������ӵ�
     * @param rCuttleBulletId �����ӵ���ID
     * @param rTower �������ָ��
     * @param level �����ӵ��ĵȼ�����Ϊ��ͬ�ȼ����ӵ�����̫һ��
     */
    static void createCuttleBullets(const int& rCuttleBulletId, TowerBase* rTower, VictimEntityBase *rVictimEntity);
};

#endif /* defined(__CarrotFantasy__BulletFactory__) */