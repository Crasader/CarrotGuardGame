#pragma once
#ifndef  SPRITES_LAYER_H
#define SPRITES_LAYER_H

#include "CommonDefine.h"
class SpritesLayer : public Layer
{
public:
    CREATE_FUNC(SpritesLayer);
    virtual ~SpritesLayer();
protected:
    /*
    @brief  ��ʼ������
    */
    virtual bool init();
    /*
    @brief ������̬�����ᶯ�ľ���
    */
    virtual void createStaticSprites();
    /*
    @brief ������̬�ľ���
    */
    virtual void createDynamicSprites();
    /*
    @brief �����м���Ǹ����ܲ�
    */
    virtual void createCarrot();
    /*
    @brief �ܲ��Ϸ��Ǹ��ᶯ��Ҷ���˶�
    @param dt  //TODO
    */
    virtual void leafAction(float dt);

private:
    Node * _pCarrotAll = nullptr;
    const Size _VisibleSize = Director::getInstance()->getVisibleSize();
};

#endif // ! SPRITES_LAYER_H
