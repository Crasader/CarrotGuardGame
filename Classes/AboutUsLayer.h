/**
 * @brief ���ó����Ĺ�������ͼ��
 * @todo ��Ȼ��д���ǵ�������
 * @version 0.9Alpha
 * @author �½���
 * @date 20180411
 * */
#ifndef ABOUTUS_LAYER_H
#define ABOUTUS_LAYER_H

#include "CommonDefine.h"

class AboutUsLayer : public Layer
{
public:
    CREATE_FUNC(AboutUsLayer);

protected:
    /**
     * @brief ��ʼ������
     * */
    bool init() override;

    /**
     * @brief ������������
     * @details ����ʵ�ʴ����ͼ��һ�пɼ�����ĺ���
     * */
    virtual void createBg();
};

#endif //ABOUTUS_LAYER_H
