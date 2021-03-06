//
//  CommonDefine.h
//   newCardDefence
//
//  Created by 何泓兵 on 18-3-30
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

class VictimEntityBase;  //受害实体基类
class MonsterBase;//怪物基类
class BarrierBase;//屏障基类
class BulletBase;//子弹基类
class TowerBase;//塔防基类

using MonsterVec = Vector<MonsterBase *>;
using BarrierVec = Vector<BarrierBase *>;
using BulletVec = Vector<BulletBase *>;
using TowerVec = Vector<TowerBase *>;

//宏定义创建新实例；
//如果创建成功并且调用init方法初始化成功;
//将对象加入到自动释放池中，并返回；
//否则，创建对象失败，释放对象；
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
//宏定义销毁新实例；
#define DESTROY_INSTANCE_FUNCTION()\
static void destroyInstance()\
{\
    CC_SAFE_RELEASE_NULL(_gInstance);\
}
//宏定义通知；
#define NOTIFY cocos2d::NotificationCenter::getInstance()
#define NOTIFICATION_CENTER cocos2d::NotificationCenter::getInstance()
//枚举公有属性；
enum CsvPublicProperty
{
    en_Name = 1,
    en_ModelName,
    en_Value,
    en_AnimationCount,//动画数；
    en_Level
};
//枚举塔的属性；
enum CsvTowerProperty
{
    en_Range = 6,//范围大小；
    en_Space,
    en_BulletId, //子弹编号；
    en_UpGradeCost,//升级成本；
    en_TowerBase,
    en_IsRotation,  //取消；
    en_CreateCost  //创建成本；
};
//枚举受伤属性；
enum CsvVictimProperty
{
    en_Hp = 6,//基础生命值；
    en_Speed,//速度；
    en_Atk,//攻击力；
};

enum CsvBulletProperty
{
    en_AtkState = 6,
    en_Duration = 9,
    en_BulletType,//子弹类型；
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
    en_Poison = en_Normal << 3,//毒；
};

/**
 * @brief 攻击属性
 * */
class AtkProperty
{
public:
    /**
     * @brief 攻击类型
     * @details 包含普通伤害、减速伤害、停止伤害、毒性伤害
     * @see 详情看上一个AtkState
     * */
    int _enAtkState = 0;

    /**
     * @brief 攻击持续时间
     * */
    int _iDuration = 0;

    /**
     * @brief 该攻击的伤害值
     * @details 伤害值有多少，怪物的生命值就掉多少
     * */
    int _iAtk = 0;

    /**
     * @brief 子弹类型
     * */
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

//关卡状态
#define LEVEL_LOCK 0
#define LEVEL_UNLOCK_BUT_NO_PASS 1
#define LEVEL_STAR1 2
#define LEVEL_STAR2 3
#define LEVEL_STAR3 4

//关卡障碍物状态
#define BARRIERS_ALL_CLEARED 1
#define BARRIERS_NOT_ALL_CLEAR 0

#endif 
