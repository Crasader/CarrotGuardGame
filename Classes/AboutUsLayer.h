/**
 * @brief ���ó����Ĺ�������ͼ��
 * @todo ��Ȼ��д���ǵ�������
 * @version 0.9Alpha
 * @author �½���
 * @date 20180411
 * */
#ifndef MYGAME_ABOUTUSLAYER_H
#define MYGAME_ABOUTUSLAYER_H

#include "CommonDefine.h"

class AboutUsLayer : public Layer
{
public:
    CREATE_FUNC(AboutUsLayer);

protected:
    bool init() override;

    virtual void createBg();
};

#endif //MYGAME_ABOUTUSLAYER_H
