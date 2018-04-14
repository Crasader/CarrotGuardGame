/**
 * @brief ���޹�����
 * @details 1-���������..
 * @details 2-���ݹ�������(MonsterType)���ɲ�ͬ�Ĺ������(MonsterBase)
 * @author ������
 * @co_author �½���
 * @date 20180410
 * */
#pragma once
#ifndef __CarrotFantasy__MonsterFactory__
#define __CarrotFantasy__MonsterFactory__

#include "CommonDefine.h"

class MonsterFactory
{
public:
	/**
	 * @brief ���ɹ���Ŷ
	 * @details ���ó����Ŷ
	 * @details �����²���
	 * @details �²���!
	 * @param rMonsterType ��������
	 * @return �������
	 * */
	static MonsterBase *createMonster(const MonsterType &rMonsterType);
};

#endif /* defined(__CarrotFantasy__MonsterFactory__) */