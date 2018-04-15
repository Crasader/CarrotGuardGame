//
//  VictimBase.cpp
//  CarrotFantasy
//
//  Created by ������ x �½��� on 18-4-12.
//
//

#include "VictimEntityBase.h"
#include "HpSlot.h"
#include "TowerManager.h"
#include "TowerBase.h"
#include "SoundUtil.h"


VictimEntityBase::~VictimEntityBase()
{
    CC_SAFE_RELEASE_NULL(_pLockAtkTarget);
    CC_SAFE_RELEASE_NULL(_pHpSlot);
    CC_SAFE_RELEASE_NULL(_pLockFlagAnimate);
}

bool VictimEntityBase::init(const int &rIId, const std::string &rSCsvFileName)
{
    bool bRet = false;
    do
    {
        CC_BREAK_IF(!Entity::init(rIId, rSCsvFileName));
        _iHp = CsvUtil::getInstance()->getInt(_iId, en_Hp, rSCsvFileName);
        _iState = en_Normal;
        _fSlowDuration = 0;
        _fStopDuration = 0;
        _fPoisonDuration = 0;
        _Pos = getPosition();
        _Size = getContentSize();
        this->schedule(schedule_selector(VictimEntityBase::checkAtkTarget));
        bRet = true;
    } while (0);

    return bRet;
}

void VictimEntityBase::beHurt(const AtkProperty tBeHurtValue)
{
    if (this->getIsDead())return; //���з�����������

    //Ŀǰ�з�ʵ��ı�����״̬����
    _iState |= tBeHurtValue._enAtkState;
    _iBulletStateType = tBeHurtValue._iBulletsType;

    //���ݹ������Ե�����
    //���ù���״̬�ĳ���ʱ��
    switch (tBeHurtValue._enAtkState)
    {
        case en_Slow:
            _fSlowDuration = tBeHurtValue._iDuration;
            break;
        case en_Stop:
            _fStopDuration = tBeHurtValue._iDuration;
            break;
        case en_Poison:
            _fPoisonDuration = tBeHurtValue._iDuration;
            break;
        default:
            break;
    }
    auto tIHp = getIHp() - tBeHurtValue._iAtk; //����ֵ����

    //�ܵ��µĹ�����������Ҫ��ʾ�����¼�ʱ
    if (tIHp > 0)
    {
        unschedule(schedule_selector(VictimEntityBase::closeHpSlot));
        if (!_bHpSlotExsit)
        {
            hpSlotVisible(!_bHpSlotExsit);
            _bHpSlotExsit = true;
        }
        _pHpSlot->setVisible(true);
        schedule(schedule_selector(VictimEntityBase::closeHpSlot), _iHpCloseTime);
        setIHp(tIHp);
        _pHpSlot->setHp(getIHp());
 //       behurtAction(); //TODO �������ûɶ��
    }

    else if (tIHp <= 0)
    {
        doDead(); //ִ����������
    }
}

void VictimEntityBase::closeHpSlot(float dt)
{
    _pHpSlot->setVisible(false);
}

void VictimEntityBase::deadAction(const std::string &rSDeadImageFile)
{
    auto tValue = std::make_tuple(getPosition(), _iValue);
    NOTIFY->postNotification("monsterDeadMoney", reinterpret_cast<Ref *>(&tValue)); //��������֪ͨ���Ը��½�Ǯ
    if (_pHpSlot) _pHpSlot->removeFromParent(); //����������ʾ���ر������۵���ʾ
    if (_pLockAtkTarget) _pLockAtkTarget->removeFromParent(); //��������ʶ��ʾ���ر�������ʶ����ʾ
    Entity::deadAction(); //ִ��ʵ����������
}

void VictimEntityBase::createHpSlotSprite()
{
    _pHpSlot = HpSlot::create(this);
    _pHpSlot->retain();
    auto tPos = getPosition();
    auto tSpriteSize = getContentSize();
    auto tSlotSize = _pHpSlot->getContentSize();
    _pHpSlot->setPosition(Vec2(-tSlotSize.width / 2 - 3, tSpriteSize.height / 2 - 12));
    addChild(_pHpSlot);
}

void VictimEntityBase::createLockAtkSprite()
{
    createLockFlagAnimate();
    _pLockAtkTarget = Sprite::createWithSpriteFrame(
            SpriteFrameCache::getInstance()->getSpriteFrameByName("point01.png"));
    CC_SAFE_RETAIN(_pLockAtkTarget);
    _pLockAtkTarget->setPosition(Vec2(0, _Pos.y + _Size.height / 2 + 12));
    addChild(_pLockAtkTarget, 2);
}

void VictimEntityBase::createLockFlagAnimate()
{
    auto pAnimation = Animation::create();
    auto pSpriteFrameCache = SpriteFrameCache::getInstance();
    for (int i = 1; i <= 3; ++i)
        pAnimation->addSpriteFrame(pSpriteFrameCache->getSpriteFrameByName(StringUtils::format("point0%d.png", i)));
    pAnimation->setLoops(-1);
    pAnimation->setDelayPerUnit(0.1f);
    _pLockFlagAnimate = Animate::create(pAnimation);
    _pLockFlagAnimate->retain();
}

void VictimEntityBase::setAtkTarget(const bool &rBisAtkTarget)
{
    _bIsAtkTarget = rBisAtkTarget;
    if (_bIsAtkTarget)
    {
        if (!_pLockAtkTarget) createLockAtkSprite();
        _pLockAtkTarget->runAction(_pLockFlagAnimate); //_pLockAtkTarget��_pLockFlagAnimate��ʽ�����˶�
        _pLockAtkTarget->setVisible(true); //����Ϊ�ɼ�״̬
        SoundUtil::getInstance()->playEffectSound(SELECTVICTIMENTITYBASE); //������Ч
    }
    else
    {
        if (!_pLockAtkTarget) return;
        _pLockAtkTarget->stopAllActions(); //ֹͣһ�л
        _pLockAtkTarget->setVisible(false); //����Ϊ���ɼ�
    }
}

void VictimEntityBase::hpSlotVisible(const bool &rBIsVisible)
{
    if (rBIsVisible) createHpSlotSprite();
    else _pHpSlot->setVisible(rBIsVisible);
}

void VictimEntityBase::checkAtkTarget(float dt)
{
    auto tTowerVec = TowerManager::getInstance()->getTowerVec();
    if (_bIsAtkTarget)
    {
        for (auto &towerItem : tTowerVec)
        {
            if (towerItem->isInAtkRange(this->getPosition())) //���Ǵ��ڹ�����Χ
            {
                towerItem->setAtkTarget(this); //�����������
                towerItem->setIsHaveAtkTarget(true);
            }
        }
    }
}

