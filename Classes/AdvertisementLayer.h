/**
* @brief ���ͼ��
* @version 0.9Alpha
* @author �½���
* @details ̰�����£����°汾
* */
#ifndef AD_LAYER_H
#define AD_LAYER_H

#include "CommonDefine.h"

class AdvertisementLayer : public Layer
{
public:
    CREATE_FUNC(AdvertisementLayer);
    ~AdvertisementLayer()override;

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

    /**
     * @brief �����
     * @details ÿ��һ��ʱ�任����棬�Ĵ���������¶��
     */
    virtual void changeAdImg();

    /**
     * @brief ���Ź������
     */
    virtual void createAdMusic();

    void createAd1();
    void createAd2();
    void createAd3();
    void createAd4();
    void createAd5();
    void createAd6();
    void createAd7();
    void createAd8();
};

#endif //AD_LAYER_H
