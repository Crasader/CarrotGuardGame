/**
 * @brief ѩ��������
 * @extends TowerBase
 * @details ������Ͳ��������תЧ�������ж�������
 * @authors �½��� x ������
 * @date 20180412
 * */
#pragma once
#ifndef __CarrotFantasy__TowerSnow__
#define __CarrotFantasy__TowerSnow__

#include "TowerBase.h"

class TowerSnow : public TowerBase
{

    const int rId = 31;

    /**
     * @brief ��д����ĳ�ʼ������
     * @details ��Ϊѩ��û����ת���ã�����Ҫע����������
     * @see ��ʱ����ػ�ת
     * @see �����������鲢��������
     */
    virtual bool init();

    /**
     * @brief ��д������
     * @see ʵ���Ͽ����ʵ�ʺ����������attack()����
     */
    virtual void fire(float dt);

    //����ʱ������������
    Sprite *_doAnimationSprite;

    /**
     * @brief ʵ�ʿ���Ч������
     * */
    void attack();

public:

    CREATE_FUNC(TowerSnow);
};

#endif /* defined(__CarrotFantasy__TowerSnow__) */