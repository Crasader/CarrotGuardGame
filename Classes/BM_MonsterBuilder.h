/**
* @brief Bossģʽ�еĹ��ﲨ������
* @details ע�⣬ֻ֧��Bossģʽ
* @details ��Ϸ������һ������ӿ�����Ĺ�������
* @author �½���
* @date 20180414
* */

#ifndef BM_MONSTERBUILDER_H
#define BM_MONSTERBUILDER_H

#include "CommonDefine.h"

class BM_MonsterBuilder : public Node
{
public:
    CREATE_FUNC(BM_MonsterBuilder);


protected:
    /**
     * @brief ��ʼ������
     * @return true ��ʼ���ɹ�
     * @return false ��ʼ��ʧ��
     * */
    bool init() override;

    /**
     * @brief ��㱻���õ�ʱ��ʹ�õĺ���
     * */
    void onEnter() override;

    /**
     * @brief ����һ������
     * @details �����������õĺ�������
     * @param t ��������Ҫ�Ĳ��������ȵļ��ʱ��
     * */
    void createMonsters(float t);

    /**
     * @brief ���ù��﹤����������
     * @details createMonsters�����õ�ʵ�����ɹ���ĺ���
     * */
    void monsterFactoryControl();

    /**
     * @brief ��ʼ����ʱ��������ɹ��ﴴ������
     * */
    void createCMonsterAnimation();

    /**
     * @brief ��ȡ��ǰ�ؿ��������ź͹ؿ����
     * @details ����ʼ���������ã�Ϊ�����ɶ�Ӧ�ؿ��ض���BOSS
     */
    void loadData();

    ~BM_MonsterBuilder() override;

protected:
    float _fDelayTime; //ÿһ��������ֵļ��ʱ��
    int _iCurrNumber; //��ǰ������ֵ���Ŀ
    int _iTotalNumber; //��������Ŀ
    Animation* _createMonsterAnimation; //���ɶ���

    int _iCurrTheme = 1; //Ŀǰ����
    int _iCurrLevel = 1; //Ŀǰ�ؿ�
    /**************|FBI Warning|*************/
    /**Ҫע��Boss�ؿ��ı����ÿ�������13~16��**/
    /***************************************/

    static const int DELAY_TIME = 8.5;

    int _iFirstMonsterType; //��һ��С�ֵ�����
    int _iSecondMonsterType; //�ڶ���С�ֵ�����
    int _iBossType; //��BOSS������
};

#endif //BM_MONSTERBUILDER_H
