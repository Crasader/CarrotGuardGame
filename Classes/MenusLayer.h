#pragma once
#ifndef MENUS_LAYER_H

#define MENUS_LAYER_H

#include "CommonDefine.h"

class MenusLayer : public Layer
{
public:
    CREATE_FUNC(MenusLayer);
protected:
    /*
    @brief ��ʼ������
    */
    virtual bool init();

    /*
    @brief ����Ŀ¼��ť
    */
    virtual void createMenuItems();
};

#endif // MENUS_LAYER_H
