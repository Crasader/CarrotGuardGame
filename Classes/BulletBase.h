/**
 * @brief �ӵ�����
 * @details ��һЩ�����Ĺ����߼�������������ӵ�������뿪���ģ��������һЩ�������ԣ��ӵ����ฺ�������Ĺ����߼�
 * @author �½��� x ������
 * @date 20180410
 * */

#pragma once
#ifndef __CarrotFantasy__BulletBase__
#define __CarrotFantasy__BulletBase__

#include "Entity.h"
#include "DynamicPropertyInterface.h"

class BulletBase : public Entity, public DynamicPropertyInterface
{

public:
    std::set<int> &getIdMap();

    /**
     * @brief �ƶ��������麯��
     * @details �ӵ��ƶ�����������Ϸ�߼�����
     * @details �̳е�����ɸ�����Ҫ��д�ƶ�����
     * */
    virtual void doMove();

    /**
     * @brief �����ӵ�ID��ѡ��������ഴ���ӵ�����
     * @details ���ģʽ�еĹ���ģʽ���������������ӵ�
     * @param rIId �ӵ�ID
     * @param rVictimEntity ѡ����Ŀ��������
     * @return �����������ӵ�����
     * */
    static BulletBase *create(const int &rIId, VictimEntityBase *rVictimEntity);

    /**
     * @brief ��ȡ�ӵ���������
     * @return ���ӵ�����Ĺ�������
     */
    virtual AtkProperty getAtkPro();

    /**
     * @brief ��������
     * @extends Entity
     * @details �ӵ�������Ķ�������
     * @param rSDeadImageFile ��������֡·��ǰ׺
     */
    virtual void deadAction(const std::string &rSDeadImageFile = "");

    /**
     * @brief �ӵ������ڶ��Ķ���
     * @details ��������ʹ�õĺ���
     * @param rDt ������Ҫ������ĵ���ʱ��
     */
    virtual void doAction(const float &rDt);

protected:
	/*
	* @brief ȷ�Ϲ��������init��ʵ�֣�����ʼ��
	* @retails ��ȡ�ӵ�����״̬���ӵ����ͣ�����������Ŀ��������ƺõ��ӵ������������
	* @param rId �ӵ�id
	* @param rVictimEntity ���˺�ʵ���ͬ�ڹ���Ŀ��
	*/
	virtual bool init(const int &rId, VictimEntityBase *rVictimEntity);
	/*
	* @brief ��������
	*/
	CC_SYNTHESIZE_PASS_BY_REF(int, _iAtkState, IAtkState);
	/**
	* @brief �ӵ�����
	*/
	CC_SYNTHESIZE_PASS_BY_REF(int, _iBulletType, IBulletType);
	/**
	* @brief ����������
	*/
	CC_SYNTHESIZE_PASS_BY_REF(int, _iDeadActCount, IDeadActCount);
	//����Ŀ��ָ�룻
	VictimEntityBase *_pAtkTarget = nullptr;

	std::set<int> *_IdMap = nullptr;
};

#endif /* defined(__CarrotFantasy__BulletBase__) */