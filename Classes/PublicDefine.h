//
//   publicConfig.h
//   newCardDefence
//
//  Created by ������ on 18-3-30
//  
//


#pragma once
#ifndef newCardDefence_publicDefine_h
#define newCardDefence_publicDefine_h

#include"cocos2d.h"
#include"VisibleRect.h"
#include"PublicSourcesDefine.h"
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
#define CREATE_INSTANCE_FUNC(__CLASS__) \
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
#define DESTROY_INSTANCE_FUNC()\
static void destroyInstance()\
{\
    CC_SAFE_RELEASE_NULL(_gInstance);\
}
//�궨��֪ͨ��
#define NOTIFY cocos2d::NotificationCenter::getInstance()
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

class AtkProperty
{
public:
	int _enAtkState = 0;
	int _iDuration = 0;
	int _iAtk = 0;
	int _iButtltType = 0;
};

//SceneType
enum SceneType
{
	en_WelcomeScene,
	en_GameSettingScene,
	en_GameHelpScene,
	en_PageSelectScene,
	en_LevelSelectScene,
	en_GameScene

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

#endif