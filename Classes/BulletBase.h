/**
<<<<<<< HEAD
 * @brief �ӵ�����
 * @details ��һЩ�����Ĺ����߼�������������ӵ�������뿪���ģ��������һЩ�������ԣ��ӵ����ฺ�������Ĺ����߼�
 * @author �½��� x ������
 * @date 20180410
 * */
=======
* @brief �ӵ�����
* @details �ӵ��Ĺ�������
* @authors ������
* @date 20180410
* */
>>>>>>> 2b54e38197accaaf381028f2c3f0fdfb3905acdb
#pragma once
#ifndef __CarrotFantasy__BulletBase__
#define __CarrotFantasy__BulletBase__

#include "Entity.h"
#include "DynamicPropertyInterface.h"

class BulletBase : public Entity, public DynamicPropertyInterface
{

public:
<<<<<<< HEAD
    /**
     * @todo ����������ûɶ��
     * */
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
    /**
     * @brief ��ʼ������
     * @retails ��ȡ�ӵ�����״̬���ӵ����ͣ�����������Ŀ��������ƺõ��ӵ���������
     * @param rId �ӵ�ID
     * @param rVictimEntity �ӵ���ԵĹ���Ŀ��
     */
    virtual bool init(const int &rId, VictimEntityBase *rVictimEntity);
    /**
     * @brief ��������Ƿ����࣬��ô���ٱ��
     */
    CC_SYNTHESIZE_PASS_BY_REF(int, _iAtkState, IAtkState);

    CC_SYNTHESIZE_PASS_BY_REF(int, _iBulletType, IBulletType);

    CC_SYNTHESIZE_PASS_BY_REF(int, _iDeadActCount, IDeadActCount);
    //����Ŀ��ָ�룻
    VictimEntityBase *_pAtkTarget = nullptr;

    std::set<int> *_IdMap = nullptr;
=======
	//
	std::set<int>& getIdMap();
	/**
	* @brief �ӵ����ƶ�����
	* @details ��Ҫȷ���ӵ�����Ŀ���Ƿ������������ӵ����ƶ�������ƶ�����
	*/
	virtual void doMove();
	/**
	* @brief ��ʼ���ӵ�����
	* @param rIId �ӵ���id
	* @param rVictimEntity �ӵ��Ĺ���Ŀ�꣨ʵ����ࣩ
	*/
	static BulletBase *create(const int &rIId, VictimEntityBase *rVictimEntity);
	/**
	* @brief �ӵ���������
	* @details �ӵ��Ĺ������ͣ����������ӵ����࣬��������ʱ��
	*/
	virtual AtkProperty getAtkPro();
	/**
	* @brief ִ����������
	* @extends VictimEntityBase
	* @param rSDeadImageFile ��������֡ͼƬ
	* @see ʵ�ʿɼ���������������Entity��ķ���ִ��
	*/
	virtual void deadAction(const std::string &rSDeadImageFile = "");

	/**
	* @brief ģ�;���������
	* @extends DynamicPropertyInterface
	* @param rDt ��������Ҫ�Ĳ���
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
>>>>>>> 2b54e38197accaaf381028f2c3f0fdfb3905acdb
};

#endif /* defined(__CarrotFantasy__BulletBase__) */