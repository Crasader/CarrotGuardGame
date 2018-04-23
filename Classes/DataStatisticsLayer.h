/**
 * @brief ���ó���������ͳ��ͼ��
 * @details ʲôͨ����Ŀ�������Ŀ֮���
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

    /**
     * @brief ������ͼ��ı���
     */
    void createBg();

    /**
     * @brief ��ȡ�û�ͨ������
     */
    void loadData();

    /**
     * @brief �������־���
     */
    void createNumSprite();

    //ð��ģʽͨ����Ŀ
    int _iAdventureModeClearance; 
    
    //���عؿ�ͨ����Ŀ
    int _iCrypticModeClearance; 
    
    //BOSSģʽͨ����Ŀ
    int _iBossModeClearance;
    
    //�ܽ�Ǯ
    int _iTotalMoney;
    
    //����������Ŀ
    int _iTotalBoss;
    
    //����BOSS��Ŀ
    int _iTotalMonster;
    
    //����ϰ�����Ŀ
    int _iTotalBarriers;
};

#endif //DATASTATISTICS_H
