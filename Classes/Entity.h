/**
 * @brief ʵ�����
 * @details ��Ϸ������һ�л��Ʒ�Ĺ�������
 * @todo  CC_SYNTHESIZE_PASS_BY_REF �����ͱ��������úͻ�ȡ������������û��ͳһ����Ҫ�����޲�
 * @authors ������ x �½���
 * @date 20180406
 * */
#pragma once
#ifndef __newCardDefence__Entity__
#define __newCardDefence__Entity__

#include "CommonDefine.h"
#include "cocos2d.h"

class Entity : public Node
{
public:
    /**
    *@brief ��������
    *@author ������
    **/
    virtual ~Entity();

public:
    static unsigned long ID;

    /**
    * @��ȡmID��
    * @brief mIDΪ��ʽ�鿴initʵ���Ƿ����óɹ���
    */
    unsigned int getmID();

    /**
     * @brief ��ʼ������
     * @details ��ȡCSV����ļ���Ӧ���У���ʼ���ö���
     * @param rId ��ʵ���id����ʵ���Ǳ���Ӧ����
     * @param rSCsvFileName ��ʵ�������ı���ļ�
     * @see ʵ����ͦ���֣�ͬ��id��ʵ�岻һ����ͬ�����͵�
     * @return true ���óɹ�����������ʧ�ܣ�
     */
    virtual bool init(const int &rId, const std::string &rSCsvFileName);

    /**
     * @brief ��ȡ�þ��鷶Χ��С��
     */
    virtual const Size &getContentSize() const;

    /**
     *@brief ʵ���Ѿ���������Ҫִ�еĺ���
     */
    virtual void doDead() final;

    /**
     *
     *  @brief ÿ��ʵ����Ҫ��һ��Sprite��������ʾ��
     *  @param pSprite ���󶨵ľ��飻
     */
    virtual void bindSprite(Sprite *pSprite);

    /**
     * @brief ��ȡ�󶨾��飻
     */
    virtual Sprite *getSprite();

    /**
     *  @brief ��ȡ����Ĵ�С
     *  @see �����С�������
     *  @return Rect ���õľ���
     */
    Rect getBoundingBox() const override;

protected:
    /**
     *  @brief ����������
     *  @param rSDeadImageFile ��������ͼƬ�ļ��ַ�����������Ĭ�ϲ�������ζ��ʹ��Ĭ�ϵ���������
     *  @details ��ס���������һ��Ҫ���¶��ϵ���
     */
    virtual void deadAction(const std::string &rSDeadImageFile = "");

    /**
     * @brief ��ʼ��ʵ�������
     * @details
     * @param rId ʵ���Ӧ��Id�ţ����Ǳ���ļ�����
     * @param rSCsvFileName csv�ļ���
     * @return: ��
     */
    virtual void initProperty(const int &rId, const std::string &rSCsvFileName);
    /**
    *  @brief ʵ�� id
    */
CC_SYNTHESIZE_PASS_BY_REF(int, _iId, IId);
    /**
    *  @brief ʵ����
    */
CC_SYNTHESIZE_PASS_BY_REF(std::string, _sName, SName);
    /**
    *  @brief ʵ��󶨾���ģ��ͼ���ļ�����
    */
CC_SYNTHESIZE_PASS_BY_REF(std::string, _sModelName, SModelName);
    /**
    *  Entity values
    */
CC_SYNTHESIZE_PASS_BY_REF(int, _iValue, IValue);
    /**
    *  flag Entity is dead
    */
CC_SYNTHESIZE_PASS_BY_REF(bool, _bIsDead, IsDead);
    /**
    *  @brief ����֡��
    */
CC_SYNTHESIZE_PASS_BY_REF(int, _IAnimationFrameCount, AnimationFrameCount);
    /**
    *  Entity �ȼ�
    */
CC_SYNTHESIZE_PASS_BY_REF(int, _iLevel, ILevel);
private:
    /**
    *  @brief ͼƬ���飬ʹ�ð󶨾��鲢��þ���
    */
    Sprite *_pSprite = nullptr;

    unsigned long _myID;

};

#endif /* defined(__newCardDefence__Entity__) */
