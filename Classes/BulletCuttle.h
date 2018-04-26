#pragma once

#ifndef BULLET_CUTTLE_H
#define BULLET_CUTTLE_H
#include "BulletBase.h"
#include "BulletFactory.h"

class BulletCuttle : public BulletBase
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
    static BulletCuttle * create(const int &rId, VictimEntityBase *rVictimEntity, const int& rotation);

    int _iRotation;
};

#endif
