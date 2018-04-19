/**
 * @brief ��������
 * @details ���ڷ�װ���������Ĺ�ͬ����
 * @details ����ÿ������֮�������һЩ���죬����������಻ͬ���ϰ�����ࡢ������ۣ�������Ҫ��ͬ����������װ�����Լ������⹦��
 * @authors ������ x �½���
 * @date 20180409
 * */
#pragma once
#ifndef __CarrotFantasy__TowerBase__
#define __CarrotFantasy__TowerBase__

#include "Entity.h"

class VictimEntityBase;


class TowerBase : public Entity
{
public:

    static TowerBase *create(const int &rId);

    /**
     * @brief ����������ת�ĺ���
     * @details �ú������ڵ�����ʹ�ã���ʱ�̸�����������ת״̬
     * @param dt ��������Ҫ����Ĳ���������ʱ��
     * */
    virtual void doRotation(float dt);

    ~TowerBase() override;

    /**
     * @brief ��ȡ�������ĳɱ�
     * @details �������Ͼ�ҪǮ����
     * @return ������Ҫ�ĳɱ���������
     * */
    virtual int getTowerGradeCost();

    /**
     * @brief ���ø���������Ĺ���Ŀ��
     * @param pVictimEntity ����Ŀ�꣬һ���˺�ʵ��
     * */
    virtual void setAtkTarget(VictimEntityBase *pVictimEntity);

    /**
     * @brief ��ʾ�������ȼ���־
     * @details ����Ǯ���ˣ�����ʾ�Ǹ������ļ�ͷ
     * @todo �������Ҫ�İ���̫���׻�����
     */
    virtual void showGradeMark();

    /**
     * @brief ���ؿ������ȼ���־
     */
    virtual void hideGradeMark();

    /**
     * @brief ����������ϰ����Ƿ��ڹ�����Χ
     * @param rPos ����Ŀ��λ��
     * @return true �ڹ�����Χ�ڣ����򷵻�false
     */
    virtual bool isInAtkRange(const Vec2 &rPos);

    /**
     * @brief ������
     */
    virtual void upGrade();

protected:
    /**
     * @brief ������������ִ��
     * @extends Entity
     * @details ����һЩ������Ĵ��������ø������������ִ�к���
     * @details ��ס���������һ��Ҫ���¶��ϵ���
     * @details ���ø����Ĳ������������������������Ϊ���ַ�������ʹ��Ĭ�ϵ���������
     * @param rSDeadImageFile ��������֡����·��
     */
    virtual void deadAction(const std::string &rSDeadImageFile = "") override;

    /**
     * @brief ��鹥��Ŀ��
     * @details ���ڵ�����ʹ�õĵ��Ⱥ���
     * @param rDt ����ʱ��
     */
    virtual void checkAtkTarget(float dt);

    /**
     * @brief ѡ�񹥻�Ŀ��
     * @details Ŀǰ�ķ����Ǳ��������������ҵ���һ�����Ϸ�ΧҪ��Ĺ�����й���
     */
    virtual void chooseAtkTarget();

    /**
     * @brief ��鹥��Ŀ���Ƿ���˷�Χ
     * @details �����ж�ָ���Ĺ���Ŀ��_pAtkTarget�Ƿ񳬳��˷�Χ
     */
    virtual void checkTargetIsOutOfRange();

    /**
     * @brief ��������Ŀ��
     * @details ���ó����ǵ�����Ŀ�곬����Χ�󣬾ͷ�������Ŀ��
     * @todo ���Թ���ʦ��æ����������Ŀ���ֳ����ڷ�Χ��Ƿ��ܽ��й���
     */
    virtual void missAtkTarget();

    /**
     * @brief ��Ӫ��������
     * @details ѡ����Ȼ�Ǹ���һ�ڰ�
     * @param dt ����ʱ��
     * @details ���Ҳ�ǵ�����ʹ�õĺ���
     */
    virtual void fire(float dt);

    /**
     * @brief �����ڶ����ʼ������
     * @details ������ʱ���������������и߼������ĳ�ʼ�������õ��õ�һ����
     */
    virtual void initTower();

    /**
     * @brief ������һ���ʼ������
     * @details ��������ID��ʼ����ʵ��
     * @details ��Ȼ����ĸ������֣�һ��һ�׵�
     * @param rId ����ID��
     */
    virtual bool init(const int &rId);

    /**
     * @brief ������������ʾ
     * @details ע����ǣ����������������ֻ��ע��������Ķ���
     * @see ���ӵ��Ķ�����ʾ�뿴fire()����
     */
    virtual void fireAction();

    /**
     * @brief �������ӵ���id
     */
    CC_SYNTHESIZE_PASS_BY_REF(int, _iBulletId, IBulletId);

    /**
     * @brief �ӵ�������Χ
     */
    CC_SYNTHESIZE_PASS_BY_REF(int, _iAtkRange, IAtkRange);

    /**
     * @brief ���Ĺ������
     * @details ����֮���ʱ����
     */
    CC_SYNTHESIZE_PASS_BY_REF(double, _iAtkInterval, IAtkInterval);

    /**
     * @brief �������ĳɱ�����
     */
    CC_SYNTHESIZE_PASS_BY_REF(std::string, _sUpgradeCost, SUpgradeCose);

    /**
     * @brief ���ļ�����
     */
    CC_SYNTHESIZE_PASS_BY_REF(int, _iUpgradeCount, IUpgradeCount);

    /**
     * @brief �Ƿ���ת
     */
    CC_SYNTHESIZE_PASS_BY_REF(bool, _bIsRotation, BIsRotation);

    /**
     * @brief �������������ѳɱ�
     */
    CC_SYNTHESIZE_PASS_BY_REF(int, _iCreateCost, ICreateCost);

    /**
     * @brief ����Ŀ���Ƿ��Ѿ�ѡ���˹���Ŀ��
     */
    CC_SYNTHESIZE_PASS_BY_REF(bool, _bIsHaveAtkTarget, IsHaveAtkTarget);

protected:
    /**
     * @brief �ȼ���־
     */
    Sprite *_pGradeMark = nullptr;

    /**
     * @brief �������
     */
    Sprite *_pTowerPanel = nullptr;

    /**
     * @brief ����Ŀ��
     */
    VictimEntityBase *_pAtkTarget = nullptr;
};

#endif /* defined(__CarrotFantasy__TowerBase__) */
