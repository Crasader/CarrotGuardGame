//
//  CommonDefine.h
//   newCardDefence
//
//  Created by ������ on 18-3-30
//  
//

#pragma once
#ifndef COMMON_DEFINE_H
#define COMMON_DEFINE_H

#include"cocos2d.h"
#include"VisibleRect.h"
#include"CommonSource.h"
#include"CsvUtil.h"

using namespace cocos2d;

class VictimEntityBase;  //�ܺ�ʵ�����
class MonsterBase;//�������
class BarrierBase;//���ϻ���
class BulletBase;//�ӵ�����
class TowerBase;//��������

using MonsterVec = Vector<MonsterBase *>;
using BarrierVec = Vector<BarrierBase *>;
using BulletVec = Vector<BulletBase *>;
using TowerVec = Vector<TowerBase *>;

//�궨�崴����ʵ����
//��������ɹ����ҵ���init������ʼ���ɹ�;
//��������뵽�Զ��ͷų��У������أ�
//���򣬴�������ʧ�ܣ��ͷŶ���
#define CREATE_INSTANCE_FUNCTION(__CLASS__) \
private:\
    static __CLASS__ *_gInstance;\
public:\
static __CLASS__* getInstance()\
{\
    if(!_gInstance)\
    {\
        _gInstance = new __CLASS__();\
        if(_gInstance && _gInstance->init())\
        {\
            _gInstance->autorelease();\
            _gInstance->retain();\
        }\
        else\
        {\
            CC_SAFE_DELETE(_gInstance);\
        }\
    }\
    return _gInstance;\
}
//�궨��������ʵ����
#define DESTROY_INSTANCE_FUNCTION()\
static void destroyInstance()\
{\
    CC_SAFE_RELEASE_NULL(_gInstance);\
}
//�궨��֪ͨ��
#define NOTIFY cocos2d::NotificationCenter::getInstance()
#define NOTIFICATION_CENTER cocos2d::NotificationCenter::getInstance()
//ö�ٹ������ԣ�
enum CsvPublicProperty
{
    en_Name = 1,
    en_ModelName,
    en_Value,
    en_AnimationCount,//��������
    en_Level
};
//ö���������ԣ�
enum CsvTowerProperty
{
    en_Range = 6,//��Χ��С��
    en_Space,
    en_BulletId, //�ӵ���ţ�
    en_UpGradeCost,//�����ɱ���
    en_TowerBase,
    en_IsRotation,  //ȡ����
    en_CreateCost  //�����ɱ���
};
//ö���������ԣ�
enum CsvVictimProperty
{
    en_Hp = 6,//��������ֵ��
    en_Speed,//�ٶȣ�
    en_Atk,//��������
};

enum CsvBulletProperty
{
    en_AtkState = 6,
    en_Duration = 9,
    en_BulletType,//�ӵ����ͣ�
    en_DeadActCount
};

enum CsvBossProperty
{
    en_BossName = 1,
    en_BossModelName,
    en_BossValue,
    en_BossAnimationCount,
    en_BossLevel,
    en_BossHp,
    en_BossSpeed,
    en_BossAtk,
    en_BossTime
};

/**
 * @breif �û�����ö��
 * @details ʲôͨ��������ͳ��֮���
 * @author �½���
 */
enum StatisticType
{
    en_Stat_Adventure,
    en_Stat_Cryptic,
    en_Stat_BossMode,
    en_Stat_Money,
    en_Stat_BossAttack,
    en_Stat_MonsterAttack,
    en_Stat_BarrierClear
};

/**
Atk State
*/
enum AtkState
{
    en_Normal = 1,
    en_Slow = en_Normal << 1,
    en_Stop = en_Normal << 2,
    en_Poison = en_Normal << 3,//����
};
//�����ԣ�
class AtkProperty
{
public:
    int _enAtkState = 0;
    int _iDuration = 0;
    int _iAtk = 0;
    int _iBulletsType = 0;
};

//SceneType
enum SceneType
{
    en_WelcomeScene,
    en_GameSettingScene,
    en_GameHelpScene,
    en_ThemeSelectScene,
    en_LevelSelectScene,
    en_GameScene,
    en_BossModeScene
};

//TowerType
enum TowerType
{
    en_StarTower,
    en_CloverTower,
    en_GreenTower,
    en_ShitTower,
    en_BallTower,
    en_FireBottleTower,
    en_BlueStarTower,
    en_SunTower,
    en_PinTower,
    en_RocketTower,
    en_SnowTower,
    en_PlaneTower,
    en_AnchorTower
};

//MonsterType
enum MonsterType
{
    en_Land_Pink = 1,
    en_Land_Star,
    en_Land_Nima,
    en_Fly_Yellow,
    en_Fly_Blue,
    en_Fat_Green,
    en_Land_Boss_Pink,
    en_Land_Boss_Star,
    en_Land_Boss_Nima,
    en_Fly_Boss_Yellow,
    en_Fly_Boss_Blue,
    en_Fat_Boss_Green,
    en_Big_Oldboss,
    en_Fat_Oldboss,
    en_Fly_Oldboss,
    en_Land_Oldboss,
    en_Boss_Big,
    en_Boss_Woowala = 19, //bug fixed �������
    en_Boss_PinkyNinja,
    en_Boss_TwistyFork,
    en_Boss_FlyDevils,
    en_Boss_Cyclops,
    en_Boss_Popbowling,
    en_Boss_Gremlins,
    en_Boss_Sadgeezer,
    en_Boss_FireFeet,
    en_Boss_Unicorn,
    en_Boss_DarkAngle,
    en_Boss_FatMummy,
    en_Boss_ConchKing,
    en_Boss_Hotstar,
    en_Boss_DrOctopus,
    en_Boss_HugeChela
};

//BulletType
enum BulletType
{
    en_NormalBullet = 1,
    en_NoDisspper,
    en_GunBullet,
    en_StarBullet
};

//BarrierType
enum BarrierType
{
    en_CloudType,
    en_BalloonType,
    en_StoneType,
    en_TreeType
};

enum GameEndType
{
    en_GameWin,
    en_GameLose
};

enum GameType
{
    en_Adventure, //ð��ģʽ
    en_BossMode //Bossģʽ
};

//�ؿ�״̬
#define LEVEL_LOCK 0
#define LEVEL_UNLOCK_BUT_NO_PASS 1
#define LEVEL_STAR1 2
#define LEVEL_STAR2 3
#define LEVEL_STAR3 4

//�ؿ��ϰ���״̬
#define BARRIERS_ALL_CLEARED 1
#define BARRIERS_NOT_ALL_CLEAR 0

#endif 
