/**
 * @brief Bossģʽ�ؿ�ѡ����ͼ��
 * @author �½���
 * @date 20180419
 */
#include "CommonDefine.h"
#include "ui/UIPageView.h"

using namespace ui;

#pragma once
#ifndef BOSSMODE_LEVELSELECT_LATER_H
#define BOSSMODE_LEVELSELECT_LAYER_H

class BossModeLevelSelectLayer : public Layer
{
public:
    /**
     * @brief ����ģʽ�õ�������
     */
    CREATE_FUNC(BossModeLevelSelectLayer);

    /**
     * @brief ��������
     */
    ~BossModeLevelSelectLayer() override;

protected:
    /**
     * @brief ��ʼ������
     */
    virtual bool init();

    virtual void loadSource();

    /**
     * @brief ���عؿ���ť
     * @details �����м���Щ�ؿ�������ͼ����ʵҲ�Ǹ���ȥ��Ϸ����İ�ť
     */
    virtual void loadBossLevelButton();

    /**
    * @brief ���ز˵��ȹ����԰����ĺ���
    * @ps //TODO �Ժ���ܻ������һ��ͷ�ļ������ٴ������϶�
    * */
    virtual void loadMenuItem();

    /**
    * @brief ��ȡĳ���ؿ���ͨ�����
    * @param rLevelIndex �ؿ�������
    * @return ����һ��tuple����һ����ͨ��������Ҳ�����ܲ�������ʲô���ܲ������ܲ�֮��ģ��ڶ������Ƿ��������е��ϰ���
    * */
    virtual std::tuple<int, bool> getLevelData(const int& rLevelIndex);

    /**
    * @brief �л�����Ϸ����ĺ���
    * */
    virtual void changeToGameScene();

    /**
    * @brief ������Դ
    * @details ��ʵ���Ǽ������йؿ���ͨ�����ݣ�����һ��������
    * */
    virtual void loadData();

    /**
     * @brief ���ÿ������Ĵ�Boss�Ƿ񱻽�����
     * @details ����ʼ����������
     * @details ֻ��ÿ�������ǰ�˹ض�ͨ���ˣ���Ӧ����Ĵ�Boss�ű�����
     */
    void checkThemeUnlocked();

private:
    int _iCurLevelIndex = 0; //Ŀǰҳ��

    MenuItemSprite* _pStartBtn = nullptr; //��ʼ��ť

    Sprite* _pLockedBtn = nullptr; //��������

    Sprite* _pBossDetailsSprite = nullptr; //�������龫�飬�����кܶຢ��

    std::map<int, bool>* _pCheckLockedMap = nullptr; //����ͨ�������ϣ��

    ValueMap _DataValueMap;
};


#endif //BOSSMODE_LEVELSELECT_LAYER_H
