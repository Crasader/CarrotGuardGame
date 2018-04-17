//
//  TowerFireBottle.cpp
//  CarrotFantasy
//
//  Created by ������ on 18-4-12.
//  
//
#include "TowerFireBottle.h"
#include "MonsterManager.h"
#include "MonsterBase.h"
#include "BarrierManager.h"
#include "BarrierBase.h"
#include "TowerManager.h"
#include "SoundUtil.h"

bool TowerFireBottle::init()
{
    bool bRet = false;
    do
    {
        CC_BREAK_IF(!TowerBase::init(rId));

        _doActionSprite = Sprite::create();
        addChild(_doActionSprite, -100);

        bRet = true;
    } while (0);
    return bRet;
}

void TowerFireBottle::chooseAtkTarget()
{

    auto tMonsterVec = MonsterManager::getInstance()->getMonsterVec();

    for (auto &iterMonster : tMonsterVec)
    {
        if (isInAtkRange(iterMonster->getPosition()))
        {
            fireAction();
            setAtkTarget(iterMonster);
            break;
        }
    }
}

void TowerFireBottle::fire(float dt)
{
    if (!_pAtkTarget || _pAtkTarget->getIsDead()) return;

    //�ȴ���������ӵ�(�ϸ�˵�ǻ�)����
    Animation *pAnimation = Animation::create();
    for (int i = 1; i <= 2; i++)
    {
        //_sModelNameʵ�����Ѿ������˸������ĵȼ�
        std::string SpriteFrameName = "P" + _sModelName + StringUtils::format("%d.png", i);
        pAnimation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(SpriteFrameName));
    }
    pAnimation->setDelayPerUnit(0.05);
    pAnimation->setLoops(1); //��Ϊʹ���˵����������ÿ�ε���֮����һ�ξͿ�����

    SoundUtil::getInstance()->playEffectSound("Music/Towers/FireBottle.mp3"); //���ſ�������

    //����һ���Ӿ���������ʾ���𶯻�
    _doActionSprite->setVisible(true);
    //ֻҪy��䶯�Ϳ�����
    _doActionSprite->setScaleY(
            this->getPosition().distance(_pAtkTarget->getPosition()) / _doActionSprite->getContentSize().height);
    _doActionSprite->setPosition((this->getPosition() + _pAtkTarget->getPosition()) / 2 - this->getPosition());
    //��ĽǶ�Ҫ��������Թ���ĽǶ���һ�µģ�������ͬ���Ĺ�ʽ�Ϳ�����
    _doActionSprite->setRotation(90 - 180 * (_pAtkTarget->getPosition() - this->getPosition()).getAngle() / M_PI);
    _doActionSprite->runAction(Animate::create(pAnimation)); //��Ӫ��������!!!

    //������������
    AtkProperty atk;
    atk._enAtkState = 1;
    atk._iAtk = int(_iBulletId * 0.8);
    atk._iDuration = 0;

    //����������������˻���
    Animation *pHurtAction = Animation::create();
    pHurtAction->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PFBottle01.png"));
    pHurtAction->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PFBottle02.png"));
    pHurtAction->setDelayPerUnit(0.06);
    pHurtAction->setLoops(1);

    Rect rect = Rect(_pAtkTarget->getPositionX() - 60, _pAtkTarget->getPositionY() - 60, 120, 120); //ȷ���������飬������ײ���

    if (_pAtkTarget->getAnimationFrameCount() != 0) //�ж��֡��˵���Ǹ�����
    {
        for (auto &mIter : MonsterManager::getInstance()->getMonsterVec())
        {
            MonsterBase *pMonster = (MonsterBase *) mIter;
            //ΪʲôҪ�������������ײ�أ���Ϊ����Ͱ�Ĺ��������Χ�����й���Ч��
            if (rect.intersectsRect(pMonster->getBoundingBox())) //����������ײ���ͼ�������
            {
                pMonster->beHurt(atk);
                Sprite *pMonsterHurt = Sprite::create();
                pMonster->addChild(pMonsterHurt); //��ײ���Ĺ��޻��һ�����˾���

                CallFunc *pClear = CallFunc::create([=]()
                                                    { pMonsterHurt->removeFromParentAndCleanup(true); });
                pMonsterHurt->runAction(Sequence::create(Animate::create(pHurtAction), pClear, nullptr)); //���˾�����ʾ����
            }
            if (pMonster->getIHp() <= 0 || pMonster->getIsDead()) //û���˾Ͳ�Ҫ������
            {
                break;
            }
        }
    }
    else //�����Ǹ��ϰ���
    {
        //ͬ���Ĵ���ʽ
        for (auto &bIter : BarrierManager::getInstance()->getBarrierVec())
        {
            BarrierBase *pBarrier = (BarrierBase *) bIter;
            if (rect.intersectsRect(pBarrier->getBoundingBox()))
            {
                pBarrier->beHurt(atk);
                Sprite *pBarrierHurt = Sprite::create();
                pBarrier->addChild(pBarrierHurt);
                CallFunc *pClear = CallFunc::create([=]()
                                                    { pBarrierHurt->removeFromParentAndCleanup(true); });
                pBarrierHurt->runAction(Sequence::create(Animate::create(pHurtAction), pClear, nullptr));
            }
            if (pBarrier->getIHp() <= 0 || pBarrier->getIsDead())
            {
                break;
            }
        }
    }
}

void TowerFireBottle::missAtkTarget()
{
    CC_SAFE_RELEASE_NULL(_pAtkTarget);
    _doActionSprite->setVisible(false);
}
