//
//  ScoreAndControlLayer.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-13.
//
//
#pragma once
#ifndef __CarrotFantasy__ScoreAndControlLayer__
#define __CarrotFantasy__ScoreAndControlLayer__

#include "CommonDefine.h"
/**
 *  ScoreAndControllerLayer use show money,control pause game,back to theme and select level
 */

class ScoreAndControllerLayer: public Layer
{
public:
    
    CREATE_FUNC(ScoreAndControllerLayer);
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
	* @datails ��ͣ��ť�����ٰ�ť���˵���ť
	*/
    virtual void createTopPanel();
    /**
	* @brief ����������
	* @details ��屳������Ǯ��ʾ��ǩ���ڼ���������ʾ����ͣ��ǩ��ʾ
	* @ask ��ͣ��Ϸ�󣬶��������ʾ�ġ���ͣ�С���ôûд����������
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
	* @brief ���������ı�
	*/
    virtual void monsterBatchChange(Ref *pData);
    /**
	* @brief ���ù���������Ŀ
	*/
    virtual void setMonsterBatchCount(const int &rIMonsterBatchIndex);
    /**
	* @brief ���ý�Ǯ��Ŀ
	*/
    virtual void setMoneyNum(const int &rIMoneyNum);
    /**
	* @brief �м���
	*/
    virtual void onExit()override;
    
private:
    //��������������
    Node *_pMonsterBatchIndex = nullptr;
    //��Ǯ��ǩ��
    Node *_pMoneyLabel = nullptr;
    //�Ƿ��ѡ��˵���
    bool _bIsOpenChooseMenu = false;
    //�Ƿ������٣�
    bool _bIsOpenSpeedUp = false;
    //�Ƿ���ͣ��
    bool _bIsPause = false;
    //�˵�ѡ����ָ�룻
    MenuItemSprite *_pChooseItem = nullptr;

};

#endif /* defined(__CarrotFantasy__ScoreAndControlLayer__) */