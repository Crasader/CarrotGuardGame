/**
* @brief ��ê������
* @extends TowerBase
* @details ��ê����������תЧ��������Ϲ������êЧ��
* @authors �½��� x ������
* @date 20180412
* */
#pragma once

#include "TowerBase.h"

class TowerAnchor : public TowerBase
{
private:
    Sprite *_doActionSprite;
    int const rId = 37;

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
    void fire(float dt);


public:
    CREATE_FUNC(TowerAnchor);
};
