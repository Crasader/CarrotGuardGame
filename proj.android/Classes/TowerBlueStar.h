/**
 * @brief ��ɫ����������
 * @extends TowerBase
 * @details ��ɫ����û����ת(�����Ҫ�ڳ�ʼ������ע��������)�����ж�������
 * @authors �½��� x ������
 * @date 20180409
 * */

#pragma once

#ifndef __CarrotFantasy__TowerBlueStar__
#define __CarrotFantasy__TowerBlueStar__

#include "TowerBase.h"

class TowerBlueStar : public TowerBase
{

    int const rId = 19;

    /**
     * @brief ��д��ʼ������
     * @extends TowerBase
     * @details ��д����ΪҪע����ת����������ɫ����û����תЧ��
     */
    virtual bool init();

    /**
     * @brief ��д��ɫ���ǿ��ں���
     * @details ����һ�¿����Ъʱ��
     * @todo
     */
    virtual void fire(float dt);

public:

    CREATE_FUNC(TowerBlueStar);
};

#endif /* defined(__CarrotFantasy__TowerBlueStar__) */