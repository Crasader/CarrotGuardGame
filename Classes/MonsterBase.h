/**
 * @brief �������
 * @details ����Ĺ�������
 * @authors ������ x �½���
 * @date 20180409
 * */
#pragma once
#ifndef __CarrotFantasy__MonsterBase__
#define __CarrotFantasy__MonsterBase__

#include "VictimEntityBase.h"
#include "DynamicPropertyInterface.h"

class MoveControllerBase;

class MonsterBase : public VictimEntityBase, public DynamicPropertyInterface
{
	friend class MonsterFactory;

public:
	/**
	 * @brief ���ݹ���id��������
     * @method ���ģʽ�еĹ���ģʽ
	 * @param rIId ����Id
	 * @return ����ID��Ӧ��ʵ��
	 */
	static MonsterBase * create(const int &rIId);

	/**
	 * @brief ��������ٶ�
	 * @param iSpeed ���������ٶ�
	 */
	void setMaxSpeed(const int &iSpeed);

    /**
    * @brief ���ﱻ(�ӵ�)�˺���Ĵ�����
    * @param rBeHurtValue ��������
    * @details �����дֻ�����BOSS���ѣ�����С��ֻ�Ǽ򵥵��ø����ͬ����������
    */
    void beHurt(const AtkProperty tBeHurtValue) override;

protected:
	/**
	 * @brief ִ����������
	 * @extends VictimEntityBase
	 * @param rSDeadImageFile ��������֡ͼƬ
	 * @see ʵ�ʿɼ���������������Entity��ķ���ִ��
	 * @todo ����ûʲô��
	 */
	virtual void deadAction(const std::string &rSDeadImageFile = "")override;

	/**
	 * @brief ģ�;���������
	 * @extends DynamicPropertyInterface
	 * @param rDt ��������Ҫ�Ĳ������ӳ�ʱ��
	 */
	virtual void doAction(const float &rDt);

	/**
	 * @brief �����ʼ������
	 * @param rIId �����ID
	 */
	virtual bool init(const int &rIId);

	/**
	 * @brief �������ﶯ��
	 */
	virtual void createAnimation();

	/**
 	 * @brief ����Ĺֽ��������²���
	 */
	virtual void MonsterSound();

	/**
	 * @brief �жϹ���ķ���
	 */
	CC_SYNTHESIZE_PASS_BY_REF(bool, _bIsLeft, IsLeft);

	MoveControllerBase * _pMoveController = nullptr;
};

#endif /* defined(__CarrotFantasy__MonsterBase__) */
