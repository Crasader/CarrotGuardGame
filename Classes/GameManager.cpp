//
//  GameManager.cpp
//  CarrotFantasy
//
//  Created by ������ on 18-4-8.
//
//

#include "GameManager.h"

GameManager* GameManager::_gInstance;


void GameManager::updateIncreasedMoney(Ref* pData)
{
    int increasedMoney = *(reinterpret_cast<int*>(pData));
    if (increasedMoney < 0) //��Ǯ�˾Ͳ��������!
        return; 
    _iIncreasedMoney += increasedMoney;
}

void GameManager::addOneEliminatedMonster(Ref* pData)
{
    _iEliminatedMonster++;
}

void GameManager::addOneEliminatedBoss(Ref* pData)
{
    _iEliminatedBoss++;
}

void GameManager::addOneClearedBarrier(Ref* pData)
{
    _iClearedBarriers++;
}


void GameManager::updateUserStatistics()
{
    auto* postVec = new std::vector<std::tuple<StatisticType, int>>();
    if (_gmCurrGameType == en_Adventure)
    {
        postVec->push_back(std::make_tuple(en_Stat_Adventure, 1));
    }
    else
    {
        postVec->push_back(std::make_tuple(en_Stat_BossMode, 1));
    }

    //���ӵĽ�Ǯ
    postVec->push_back(std::make_tuple(en_Stat_Money, _iIncreasedMoney));
    //����Ĺ���
    postVec->push_back(std::make_tuple(en_Stat_MonsterAttack, _iEliminatedMonster));
    //�����BOSS
    postVec->push_back(std::make_tuple(en_Stat_BossAttack, _iEliminatedBoss));
    //������ϰ��� 
    postVec->push_back(std::make_tuple(en_Stat_BarrierClear, _iClearedBarriers));

    NOTIFICATION_CENTER->postNotification(STATDATACHANGE, reinterpret_cast<Ref*>(postVec));


    //����
    _gmCurrGameType = en_Adventure;
    _bIsWin = false;
    _iIncreasedMoney = _iClearedBarriers = _iEliminatedBoss = _iEliminatedMonster = 0;
}

bool GameManager::init()
{
    _bIsPause = _bIsWin = false;
    _iTime = _iIncreasedMoney = _iClearedBarriers = _iEliminatedBoss = _iEliminatedMonster = _iBossHp = 0;
    _gmCurrGameType = en_Adventure; //Ĭ��Ϊð��ģʽ

    addObserver(); //�ǵ�Ҫ��Ӽ�����
    return true;
}

void GameManager::addObserver()
{
    //ע���Ǯ�����¼�����
    NOTIFICATION_CENTER->addObserver(this, callfuncO_selector(GameManager::updateIncreasedMoney), "moneyChange",
                                     nullptr);
    //ע���ϰ��������¼�����
    NOTIFICATION_CENTER->addObserver(this, callfuncO_selector(GameManager::addOneClearedBarrier), "BarrierDead",
                                     nullptr);
    //ע��BOSS�����¼�����
    NOTIFICATION_CENTER->addObserver(this, callfuncO_selector(GameManager::addOneEliminatedBoss), "BossDead", nullptr);
    //ע����������¼�����
    NOTIFICATION_CENTER->addObserver(this, callfuncO_selector(GameManager::addOneEliminatedMonster), "MonsterDead",
                                     nullptr);
}

GameManager::~GameManager()
{
    NOTIFICATION_CENTER->removeAllObservers(this);
}
