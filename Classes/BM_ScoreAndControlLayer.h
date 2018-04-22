/**
  * @brief BOSSģʽ����Ϸ�˵���
  * @author �½���
  * @date 20180420
 */

#pragma once
#ifndef BM_SCOREANDCONTROL_LAYER_H
#define BM_SCOREANDCONTROL_LAYER_H

#include "CommonDefine.h"
/**
*  BM_ScoreAndControllerLayer use show money,control pause game,back to theme and select level
*/

class BM_ScoreAndControllerLayer : public Layer
{
public:

    CREATE_FUNC(BM_ScoreAndControllerLayer);
    /**
     * @brief ���˲˵���ť����ͣ
    */
    virtual void setPauseFlagIsClose();
    /**
     * @brief ���ѡ����Ŀ
    */
    virtual void clickChooseItem();

protected:
    /**
     * @brief ȷ��ͼ��init����ʵ��
    */
    virtual bool init();
    /**
     * @brief �����������
     * @datails ��ͣ��ť���˵���ť
     * @details ע��BOSSģʽ�����м��٣���Ϊ���ģʽ�Ͼ��Ǽ�ʱ��
    */
    virtual void createTopPanel();

    /**
     * @brief �����ײ����
     * @details ��ʱ�����
     * @details �ǵ�BOSSģʽ���м�ʱ����Ӵ
     */
    virtual void createBottomPanel();

    /**
     * @brief ����������
     * @details ��屳������Ǯ��ʾ��ǩ���ڼ���������ʾ����ͣ��ǩ��ʾ
     * @ask //todo ��ͣ��Ϸ�󣬶��������ʾ�ġ���ͣ�С���ôûд����������
     */
    virtual void loadBg();



    CC_SYNTHESIZE(int, _iMoney, CurMoney);
    /**
     * @brief ע��֪ͨ�¼�
    */
    virtual void registerNotifyEvent();
    /**
     * @brief �ر�ע��֪ͨ�¼�
    */
    virtual void unRegisterNotifyEvent();
    /**
     * @brief ��Ǯ��Ŀ�仯
     */
    virtual void moneyChange(Ref *pData);

    /**
     * @brief ��BOSSѪ�������˱仯
     * @details ���ڸ����Ϸ����BOSS��Ѫ��
     * @param dt ������Ҫ����Ĳ���
     * @version 1.2
     * @update 1.2 ɾ��֪ͨ����Ϊ���ڼ���
     */
    virtual void bossHpChanged(float dt);

    /**
     * @brief ��ʱ����ʱ�䷢���˱仯
     * @details ��������ʹ�ã�ÿһ�����һ�Σ����ڶ�ʱ��ʱ��ı仯
     * @param dt ������Ҫ����Ĳ��������ʱ��
     */
    virtual void timeChange(float dt); 

    /**
     * @brief ���ý�Ǯ��Ŀ
     */
    virtual void setMoneyNum(const int &rIMoneyNum);
    /**
     * @brief �м���
     */

    virtual void loadData();

    void onExit()override;

    virtual void createNumSprite();

private:
    //BOSSѪ��������
    ProgressTimer * pBossHpBar = nullptr;

    //��Ǯ��ǩ��
    Node *_pMoneyLabel = nullptr;
    //�Ƿ��ѡ��˵���
    bool _bIsOpenChooseMenu = false;
    //�Ƿ���ͣ��
    bool _bIsPause = false;
    //�˵�ѡ����ָ�룻
    MenuItemSprite *_pChooseItem = nullptr;
    //ʱ�����־���
    Node *_pTimeSp = nullptr;

    //��ǰ�ؿ���ʱ
    /*Ŀǰ�汾���������Layer�����Ƽ�ʱ���ɣ���ȡֱ�Ӵ�csv�Ƕ���ȡ*/
    int _iTimeLimit;

    int _iBossTotalHp;
    int _iBossCurrHp;
};

#endif /* defined(BM_SCOREANDCONTROL_LAYER_H) */