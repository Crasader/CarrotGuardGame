/**
* @brief ̫���ְ�������
* @extends TowerBase
* @details ̫���ְֲ�������תЧ�������з�Χ����Ч��
* @authors �½��� x ������
* @date 20180412
* */
#pragma once
#ifndef __CarrotFantasy__TowerSun__
#define __CarrotFantasy__TowerSun__

#include "TowerBase.h"

class TowerSun : public TowerBase
{
private:

    const int rId = 22;

    /**
     * @brief ��д����ĳ�ʼ������
     * @details Ҫע����ת��������
     * @see ��ʱ����ػ�ת
     */
    virtual bool init();

    /**
     * @brief ��д������
     * @details ������������������
     * @param dt ������Ҫ������Ĳ���
     */
    virtual void fire(float dt);

    //����ִ�о��飻
    Sprite *_doAnimationSprite;

    /**
     * @brief ̫���ְ�ʵ�ʵĹ���Ч������
     * @details ��fire���õ�̫��ʵ�ʹ���Ч���ĺ���
     * @todo ������ͳһ
     * */
    void attack();

public:

    CREATE_FUNC(TowerSun);
};

#endif /* defined(__CarrotFantasy__TowerSun__) */