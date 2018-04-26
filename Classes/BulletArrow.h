#pragma once

#ifndef BULLET_ARROW_H
#define BULLET_ARROW_H
#include "BulletBase.h"
#include "BulletFactory.h"

class BulletArrow : public BulletBase
{
    friend class BulletFactory;
protected:
    /**
    * @brief
    */
    void doAction();
    /**
    * @brief ����ӵ����ƶ�
    */
    void doMove()override;
    /**
    * @brief ��֤�ӵ������init����ʵ��
    */
    virtual bool init(const int &rId, VictimEntityBase *rVictimEntity, const int& rotation);
    /**
    * @breif �ӵ�����
    */
    static BulletArrow * create(const int &rId, VictimEntityBase *rVictimEntity, const int& rotation);

    int _iRotation;
};

#endif
