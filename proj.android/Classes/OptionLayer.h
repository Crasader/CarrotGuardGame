/**
 * @brief ���ó�������Ϸ����ͼ��
 * @details �����������ء���Ч���صȵ�
 * @author �½���
 * @date 20180411
 * **/

#ifndef OPTIONLAYER_H
#define OPTIONLAYER_H

#include "CommonDefine.h"

class OptionLayer : public Layer
{
public:
    CREATE_FUNC(OptionLayer);
protected:
    bool init() override;
    /**
     * @brief ����ͼ����Դ������ͼ����
     * */
    virtual void loadSource();
};

#endif //OPTIONLAYER_H
