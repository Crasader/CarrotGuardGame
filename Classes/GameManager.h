#pragma once
/**
 * @brief ��Ϸ������
 * @details ����Ŀǰ�Ƚϼ��ߣ�ֻ���ṩһЩ��Ϸ�Ĳ�������
 * @author �½���
 * @date 20180410
 * @version 1.2
 * @update 1.2 �������ͳ�ƹ��ܽ�������
 * @update 1.1 ���BOSSģʽ���и���
 */

#ifndef __CarrotFantasy__GameManager__
#define __CarrotFantasy__GameManager__

#include "CommonDefine.h"

class GameManager :public Ref
{
public:

	CREATE_INSTANCE_FUNCTION(GameManager);

	DESTROY_INSTANCE_FUNCTION();

    /**
     * @brief �����û�����
     * @details  �����ؿ������ݸ��µ��û������ļ�����
     * @since 1.2
     */
    void updateUserStatistics();
protected:
	/*
	* @brief ����ͣ�����ڸ�����
	*/
	virtual bool init();

	CC_SYNTHESIZE_PASS_BY_REF(int, _iCarrotHp, ICarrotHp);

	CC_SYNTHESIZE_PASS_BY_REF(int, _iMonsterBatch, IMonsterBatch);

	CC_SYNTHESIZE_PASS_BY_REF(bool, _bIsPause, IsPause);

    CC_SYNTHESIZE_PASS_BY_REF(GameType, _gmCurrGameType, CurrGameType);

    /**
     * @brief ��Ϸ�Ƿ�Ӯ��
     * @details ��������ͳ��
     * @since 1.2
     */
    CC_SYNTHESIZE_PASS_BY_REF(bool, _bIsWin, IsWin); 

    /**
     * @brief BOSSģʽ�µ�ʣ��ʱ��
     * @details ֻ��BOSSģʽ������
     * @since 1.1
     */
    CC_SYNTHESIZE_PASS_BY_REF(int, _iTime, ICurrTime);

    /**
     * @brief BOSSģʽ�µ�BOSS����ֵ
     * @details ֻ��BOSSģʽ������
     * @since 1.1
     */
    CC_SYNTHESIZE_PASS_BY_REF(int, _iBossHp, IBossHp);

    /**
     * @brief ���Ӽ�����
     * @datils ���ڸ����û���ʷ����
     * @details �ڳ�ʼ�������������
     * @since 1.2
     */
    void addObserver();
    
    ~GameManager();

    /**
    * @brief ���±��ιؿ������ӽ�Ǯ��
    * @details ��������ͳ���õ�
    * @since 1.2
    * @param pData Ҫ���ӵĽ�Ǯ
    */
    void updateIncreasedMoney(Ref *pData);

    /**
    * @brief ����һ��������Ĺ���
    * @details ��������ͳ���õ�
    * @since 1.2
    */
    void addOneEliminatedMonster(Ref *pData);

    /**
    * @brief ����һ���������BOSS
    * @details ��������ͳ���õ�
    * @since 1.2
    */
    void addOneEliminatedBoss(Ref *pData);

    /**
    * @brief ����һ����������ϰ���
    * @details ��������ͳ���õ�
    * @since 1.2
    */
    void addOneClearedBarrier(Ref *pData);

private:

	GameManager() {}

	GameManager(const GameManager&) = delete;

	GameManager &operator=(const GameManager&) = delete;


    int _iIncreasedMoney; //���ιؿ������ӵĽ�Ǯ
    int _iEliminatedMonster; //���ιؿ�������������
    int _iEliminatedBoss; //���ιؿ�����BOSS����
    int _iClearedBarriers; //���ιؿ�����ϰ�������
};

#endif /* defined(__CarrotFantasy__GameManager__) */
