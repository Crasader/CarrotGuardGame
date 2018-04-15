/**
 * @brief �ƶ�������
 * @details �����ڵ�ͼ���ƶ���Ҫ�����������
 * @authors �½��� x ������
 * @date 20180409
 * */
#pragma once
#ifndef CarrotFantasy_MoveControllerBase_h
#define CarrotFantasy_MoveControllerBase_h

#include "MonsterBase.h"

class MoveControllerBase : public Node
{
	friend class MonsterBase;
public:

	virtual ~MoveControllerBase();

	/**
	 * @brief ���ڵ�����ʹ�õĹ����ƶ����Ⱥ���
	 * @param t ����ʱ��
	 */
	virtual void listenerMonster(float t);


private:
	/**
	 * @brief �󶨹���
	 * @param pMonster ���󶨵Ĺ���
	 */
	void setMonster(MonsterBase * pMonster);

	/**
	 * @brief �������߹켣����
	 * @details �������ƶ�֮��֮ǰ�߹��Ĺ켣Ҫ��ʱ����
	 * */
	void erasePoint();

	virtual bool init(MonsterBase * pMonster);

	/**
	 * @brief ����MonsterBase�����ɶ�Ӧ��MonsterControllerBase
	 * @details �γ�һ�ְ󶨹�ϵ
	 * @param pMonster ��Ӧ��MonsterBase
	 * */
	static MoveControllerBase * create(MonsterBase * pMonster);

	CC_SYNTHESIZE_PASS_BY_REF(int, _iMonsterSpeed, IMonsterSpeed);

	/**
	 * @brief �ƶ����������⶯������ʾ����
	 * @details ���������ܵ����١�ֹͣ�����Թ���ʱ����һЩ����Ķ�����ʾ�����������������
	 * @param iBulletType �ӵ�����
	 * @param t ����ʱ��
	 * */
	Animation * AnimationMaker(int iBulletType, float t);

	MoveControllerBase() {}
private:

	MonsterBase *_pMonster = nullptr;

	std::vector<Vec2> * _pMapPoints;

};


#endif/* defined(CarrotFantasy_MoveControllerBase_h)*/
