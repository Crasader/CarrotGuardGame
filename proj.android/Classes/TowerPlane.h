/**
 * @brief �ɻ�������
 * @extends TowerBase
 * @details �ɻ�����������ת������ֱ�ߴ�͸����
 * @authors �½��� x ������
 * @date 20180412
 * */

#pragma once
#ifndef __CarrotFantasy__TowerPlane__
#define __CarrotFantasy__TowerPlane__

#include "TowerBase.h"

class TowerPlane : public TowerBase
{

    int const rId = 34;

    /**
      * @brief ��д��ʼ������
      * @extends TowerBase
      * */
    virtual bool init();

    /**
     * @brief ��д����Ĺ�������
     * @param dt ������Ҫ�������õ��ĵ���ʱ��
     * @details �ɻ�û���ӵ���������ĺ����ǵ����ӵ��࣬�������ķ����������ã���Ҫ��д
     * @details ������ľ�����Ϸ�߼�д������
     * @see Ȼ��ʵ�ʵĹ���Ч����attack()������ʵ��
     */
    virtual void fire(float dt);


    Sprite *_doAnimationSprite;

public:
    /**
     * @brief �ɻ�ʵ�ʵĹ���Ч������
     * @details ��fire���õķɻ�ʵ�ʹ���Ч���ĺ���
     * @todo ������ͳһ
     * */
    void attack();

    CREATE_FUNC(TowerPlane);
};

#endif /* defined(__CarrotFantasy__TowerPlane__) */