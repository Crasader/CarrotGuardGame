/**
 * @brief �������Ĳ˵���
 * @details ��Ϸ�����н������������Ĳ˵�
 * @authors ������ x �½���
 * @date 20180413
 * */
#pragma once
#ifndef __CarrotFantasy__TowerOptBtn__
#define __CarrotFantasy__TowerOptBtn__

#include "cocos2d.h"

class TowerBase;

using namespace cocos2d;

class TowerOptBtn : public Node
{
public:

    CREATE_FUNC(TowerOptBtn);

    TowerOptBtn();

    virtual ~TowerOptBtn();

    /**
     * @brief ��������ѡ��
     */
    virtual void hideTowerOpt();

    /**
     * @brief ��ʾ����ѡ��
     */
    virtual void showTowerOpt();

    /**
     * @brief �������ڼ���Ǯ�������ĺ���
     * @details �����������GameScene������õ�
     * @param rFuncCheckMoney ���ڼ���Ǯ�������ĺ���
     */
    virtual void setFuncCheckMoney(const std::function<int()> &rFuncCheckMoney);

    /**
     * @brief �������Ĳ˵���
     * @details ����յ�ʱ��ʾ�Ĳ˵�
     * @see ��ʾ������������ͼ��
     */
    virtual void createTowerMenu();

    /**
    * @brief �������չʾ�Ĳ˵�
    * @details չʾ����������ť������������İ�ť
    */
    virtual void gradeTowerMenu(TowerBase *touchTower);

    /**
    * @brief չʾ�����˵�
    * @details �����˵���λ��ѡ��
    * @see ����������ѧ����
    */
    virtual void showCreateMenu();

    /**
    * @brief ���ش����˵�
    */
    virtual void hideCreateMenu();

protected:
    /**
     * @brief
     * @details ��ʱ����ر仯����
     */
    virtual bool init();

    /**
     * @brief �����˵������
     * @details ���ڳ�ʼ���������õĴ����˵����
     */
    virtual void createMenuAndItems();

    /**
    * @brief ��̫�����ڸ���
    */
    virtual void ChangingItem(float dt);

protected:
    bool _bKeySpVisible; //�˵�֮ĸ�Ƿ���ʾ��
    Sprite *_pKeySp; //�˵�֮ĸ

    Menu *_pCreateMenu1; //����յغ�˵��ĵ�һ�в˵�
    Menu *_pCreateMenu2; //����յغ�˵��ĵڶ��в˵�
    Menu *_pGradeMenu; //���������������������߲���Ĳ˵�
    Sprite *_pTowerRangeSp; //����������Ǹ�������Ϊ���ĵĻ�ɫȦȦ

    std::function<int()> _funcCheckMoney;

    /**
     * @brief �������������ڵ�������Ъ�Լ���Ǯ����������
     * @details ����Ǯ���㹻��ʱ��������Ԫ��(����)��ʸ���״̬
     */
    Vector<MenuItemSprite *> *_pCreateTowerItemSpVec = nullptr;
    Vector<MenuItemSprite *> *_pGradeTowerItemSpVec = nullptr;
};


#endif /* defined(__CarrotFantasy__TowerOptBtn__) */