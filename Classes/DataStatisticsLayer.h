/**
 * @brief ���ó���������ͳ��ͼ��
 * @details ʲôͨ����Ŀ�������Ŀ֮���
 * @todo ��Ҫ����һ���ļ����洢�û������ݣ�����ȸ���һ��
 * @version 0.9Alpha
 * @author �½���
 * @date 20180411
 * */
#ifndef DATASTATISTICS_H
#define DATASTATISTICS_H

#include "CommonDefine.h"

class DataStatLayer : public Layer
{
public:
    CREATE_FUNC(DataStatLayer);

protected:
    bool init() override;

    void createBg();
};

#endif //DATASTATISTICS_H
