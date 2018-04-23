/**
 * @brief �з�ʵ�����
 * @details ��������ϰ�����Ĺ�ͬ���࣬�����װ���������ֵз���Ĺ�ͬ����
 * @extends �̳���Entity
 * @see Entity����Ϸ��һ���˶�ʵ��Ĺ�������
 * @authors �½��� x ������
 * @date 20180411
 * @update ע��ȫ�¸��£����������û�п�����ȫ�°汾
 * */
#pragma once
#ifndef VICTIMENTITY_BASE_H
#define VICTIMENTITY_BASE_H

#include "Entity.h"

class HpSlot;

class VictimEntityBase : public Entity
{
public:

    virtual ~VictimEntityBase();

    /**
     * @brief �з�ʵ�屻(�ӵ�)�˺���Ĵ�����
     * @param rBeHurtValue ��������
     * @details ��������������
     */
    virtual void beHurt(const AtkProperty tBeHurtValue);

    /**
     * @brief ���������Ĺ���Ŀ��
     * @details ѡ��ĳ�����������������ר�Ŵ��������
     * @param rBisAtkTarget �Ƿ�ѡ������
     */
    virtual void setAtkTarget(const bool& rBisAtkTarget);

    /**
     * @brief ��֪�Ƿ�ѡ����
     * @return �����Ƿ���˺��з�ʵ�屻���ѡ����
     */
    virtual bool getAtkTarget() const
    {
        return _bIsAtkTarget;
    };

    /**
     * @brief ���øõз�ʵ����������Ƿ�ɼ�
     * @param rBIsVisible �Ƿ�����Ϊ�ɼ�
     * @see �����Ϸ�Ķ�֪��������������Ļ��������۹�һ��ͻ���ʧ�ˣ������Ҫдһ�����������������۵Ŀɼ���
     * */
    virtual void hpSlotVisible(const bool& rBIsVisible);

protected:
    /**
     * @brief �ر�������
     * @todo ��������ûɶ�ã���д��ɶ
     * */
    virtual void closeHpSlot(float dt);

    /**
     * @brief ���õз�ʵ���Ƿ�����Ϊ����Ŀ�꣬�������������Ĺ���Ŀ��ָ����
     */
    virtual void checkAtkTarget(float dt);

    /**
     * @brief ��ʼ������
     * @param rIId ʵ��ID
     * @param rSCsvFileName CSV����·��
     * @see ��ʱ����ؼ�鹥��Ŀ��
     */
    virtual bool init(const int& rIId, const std::string& rSCsvFileName);

    /**
     * @brief ����������־����
     */
    virtual void createLockFlagAnimate();

    /**
     * @brief �Ѿ��������ֵ��۰󶨲�����
     */
    virtual void createHpSlotSprite();

    /**
     * @brief �Ѿ������������Ŀ��󶨲�����
     */
    virtual void createLockAtkSprite();

    /**
     * @brief ִ����������
     * @details ��ʵ�ǹ�doDead()�������õ�
     */
    virtual void deadAction(const std::string& rSDeadImageFile = "") override;

    /**
     * @brief ���˶�������������
     */
    //virtual void behurtAction() = 0;
    /**
     * @brief �з�ʵ���hp
     */
CC_SYNTHESIZE_PASS_BY_REF(int, _iHp, IHp);
    /**
    * @brief �ܹ�����״̬
    */
CC_SYNTHESIZE_PASS_BY_REF(int, _iState, IState);
    /**
    * @brief �ܹ���״̬����ʱ��
    * @details һ�㶼�Ƕ��Թ�����
    */
CC_SYNTHESIZE_PASS_BY_REF(float, _fSlowDuration, FSlowDuration); //����Ǽ��ٹ���
CC_SYNTHESIZE_PASS_BY_REF(float, _fStopDuration, fStopDuration); //�����ֹͣ����
CC_SYNTHESIZE_PASS_BY_REF(float, _fPoisonDuration, fPoisonDuration); //������ж�����
CC_SYNTHESIZE_PASS_BY_REF(float, _fSlowAndShrinkDuration, fSlowAndShrinkDuration); //�����Ģ����������С�Ҽ���

CC_SYNTHESIZE_PASS_BY_REF(float, _iBulletStateType, IBulletStateType);
    /**
    *  @brief �����۹ر�ʱ��
    */
    const int _iHpCloseTime = 3;

private:

    bool _bHpSlotExsit = false;

    /**
    * @brief �����۾���
    */
    HpSlot* _pHpSlot = nullptr;
    /**
    * @brief ����������־����
    */
    Sprite* _pLockAtkTarget = nullptr;
    /**
    * @brief ������־����
    */
    Animate* _pLockFlagAnimate = nullptr;

    /**
    * @brief ��־�ܺ����ǹ���Ŀ��
    */
    bool _bIsAtkTarget = false;

    Vec2 _Pos;

    Size _Size;
};

#endif
