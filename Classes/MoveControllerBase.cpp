//
//  MoveControllerBase.cpp
//  CarrotFantasy
//
//  Created by ������ on 18-4-9.
//  
//

#include "MoveControllerBase.h"
#include "MapUtil.h"
#include "GameManager.h"

#define STEP 10.0

bool MoveControllerBase::init(MonsterBase *pMonster)
{
    if (!Node::init())
    {
        return false;
    }
	//�󶨹���
    setMonster(pMonster);

    _iMonsterSpeed = _pMonster->getISpeed();
    _pMonster->addChild(this);

    //��ʼ���˶��켣
    auto Points = MapUtil::getInstance()->getMovePoses();
    _pMapPoints = new std::vector<Vec2>();
    //����ÿ����
    //Ҫ΢��������ƶ��㣬��Ϊ�����С��һ�˶�����̬��Ҫ��һЩ
    for (auto &Point : Points)
    {
        Vec2 t_point;
        if (_pMonster->getILevel() == 1) t_point.x = Point.x + _pMonster->getContentSize().width / 2 - 15;
        if (_pMonster->getILevel() == 2) t_point.x = Point.x + 30;
        if (_pMonster->getILevel() == 3) t_point.x = Point.x + 40;
        t_point.y = Point.y - 5;
        _pMapPoints->push_back(t_point);
    }
    _pMonster->setPosition(*_pMapPoints->begin());

    listenerMonster(STEP / _pMonster->getISpeed());

    return true;
}

MoveControllerBase *MoveControllerBase::create(MonsterBase *pMonster)
{
    auto aMonster = new MoveControllerBase();
    if (aMonster->init(pMonster))
    {
        aMonster->autorelease();
        return aMonster;
    }
    CC_SAFE_DELETE(aMonster);
    return nullptr;
}

void MoveControllerBase::setMonster(MonsterBase *pMonster)
{
    _pMonster = pMonster;
}

void MoveControllerBase::listenerMonster(float t)
{
    if (_pMonster->getIHp() <= 0 || _pMonster->getIsDead())
        return; //�����Ͻ�����

    erasePoint(); //�����ɹ켣����ʵ�ǽ��߹���·�ų����켣·��

    //��ȡ�˶�����ʣ��켣�ĵ�һ������
    Vec2 pot = *_pMapPoints->begin();

    //����ʣ��켣�ĵ�һ������x������
    //ȷ������Ŀǰ����������
    _pMonster->setIsLeft(pot.x < _pMonster->getPositionX());

    //��ʼ�˶�
    MoveBy *pStep;
    if (_pMonster->getPositionX() == pot.x) //��ǰx�������һx������ͬ
    {
        if (_pMonster->getPositionY() <= pot.y) //����ǰy����С����һy����
        {
            pStep = MoveBy::create(t, Vec2(0, STEP)); //��������
        }
        else //����
        {
            pStep = MoveBy::create(t, Vec2(0, -STEP)); //��������
        }
    }
    else //���򣬵�ǰx���겻ͬ����һx����
    {
        if (_pMonster->getPositionX() <= pot.x)
        {
            pStep = MoveBy::create(t, Vec2(STEP, 0)); //����
        }
        else
        {
            pStep = MoveBy::create(t, Vec2(-STEP, 0)); //����
        }
    }

    auto pMoveCall = CallFuncN::create([=](Node *pSender)
                                       {
                                           this->listenerMonster(STEP / _pMonster->getISpeed());
                                       });
    Sequence *seq = Sequence::create(pStep, pMoveCall, NULL);

    if (!_pMonster->getIsLeft()) //����˶���������
    {
        _pMonster->getSprite()->setRotationSkewY(0); //���淭ת����
    }
    else //��������˶���������
    {
        _pMonster->getSprite()->setRotationSkewY(180); //���淭ת����
    }

    //��ȡ�����ܹ���״̬
    int MonsterState = _pMonster->getIState();
    int State_Slow = MonsterState & 2;
    int State_Stop = MonsterState & 4;
    int State_Poison = MonsterState & 8;

    //���������ܵ����ٵ�ʱ����
    if (State_Slow && _pMonster->getFSlowDuration() > 0)
    {
        _pMonster->setISpeed(_iMonsterSpeed / 3);
        float StateTime = _pMonster->getFSlowDuration() - t; //����һ�¹����ܼ��ٹ�������ʱ�䣬ֱ�Ӽ�ȥ����ʱ�伴��
        if (StateTime < 0) StateTime = 0; //��Ϊ�����ˣ��Ǿ�����
        _pMonster->setFSlowDuration(StateTime);

        //����һ���Ӿ��飬������ʾ�����ƶ����趯��
        Sprite *pTemp = Sprite::create();
        pTemp->setPosition(_pMonster->getContentSize().width / 2, 40);
        _pMonster->getSprite()->addChild(pTemp);

        //����һ������
        Animation *pAnimation = AnimationMaker((int) _pMonster->getIBulletStateType(), t);
        auto pCallFunc = CallFunc::create([=]()
                                          {
                                              pTemp->removeFromParentAndCleanup(true);
                                              if (_pMonster->getFSlowDuration() <= 0)
                                              {
                                                  _pMonster->setISpeed(_iMonsterSpeed); //�ָ�ԭ�����ٶ�
                                                  _pMonster->setIState(_pMonster->getIState() & 13); //�ָ�ԭ����״̬
                                              }
                                          });
        Sequence *pSequence = Sequence::create(Animate::create(pAnimation), pCallFunc, nullptr);
        pTemp->runAction(pSequence);
    }

	//���������ܵ����ٱ�С��ʱ����(Ģ��)
	if (State_Slow && _pMonster->getFSlowDuration() > 0)
	{
		_pMonster->setISpeed(_iMonsterSpeed / 3);
		float StateTime = _pMonster->getFSlowDuration() - t; //����һ�¹����ܼ��ٹ�������ʱ�䣬ֱ�Ӽ�ȥ����ʱ�伴��
		if (StateTime < 0) StateTime = 0; //��Ϊ�����ˣ��Ǿ�����
		_pMonster->setFSlowDuration(StateTime);

		_pMonster->setContentSize(Size(_pMonster->getContentSize().width / 3, _pMonster->getContentSize().height / 3));

		//����һ���Ӿ��飬������ʾ�����ƶ����趯��
		Sprite *pTemp = Sprite::create();
		pTemp->setPosition(_pMonster->getContentSize().width / 2, 40);
		_pMonster->getSprite()->addChild(pTemp);

		//����һ������
		Animation *pAnimation = AnimationMaker((int)_pMonster->getIBulletStateType(), t);
		auto pCallFunc = CallFunc::create([=]()
		{
			pTemp->removeFromParentAndCleanup(true);
			if (_pMonster->getFSlowDuration() <= 0)
			{
				_pMonster->setISpeed(_iMonsterSpeed); //�ָ�ԭ�����ٶ�
				_pMonster->setIState(_pMonster->getIState() & 13); //�ָ�ԭ����״̬
			}
		});
		Sequence *pSequence = Sequence::create(Animate::create(pAnimation), pCallFunc, nullptr);
		pTemp->runAction(pSequence);
	}

    //���������ܵ����Թ�����ʱ����
    if (State_Poison && _pMonster->getfPoisonDuration() > 0)
    {
        float StateTime = _pMonster->getfPoisonDuration() - t; //����һ�¹����ܼ��ٹ�������ʱ�䣬ֱ�Ӽ�ȥ����ʱ�伴��
        if (StateTime < 0) StateTime = 0; //��Ϊ�����ˣ��Ǿ�����
        _pMonster->setfPoisonDuration(StateTime);

        AtkProperty atk;
        atk._enAtkState = 1;
        atk._iAtk = 2;
        atk._iDuration = 0;

        //����һ���Ӿ��飬������ʾ�����ж�����
        Sprite *pTemp = Sprite::create();
        pTemp->setPosition(_pMonster->getContentSize().width / 2, 40);
        _pMonster->getSprite()->addChild(pTemp);
        Animation *pAnimation = AnimationMaker(6, t);
        auto pCallFunc = CallFunc::create([=]()
                                          {
                                              if (!_pMonster->getIsDead()) _pMonster->beHurt(atk); //�ָ������Ĺ�������
                                              if (_pMonster->getfPoisonDuration() <= 0)
                                              {
                                                  _pMonster->setIState(_pMonster->getIState() & 7);
                                              }
                                              pTemp->removeFromParentAndCleanup(true);
                                          });
        pTemp->runAction(Sequence::create(Animate::create(pAnimation), pCallFunc, NULL));
    }

    //���������ܵ�ֹͣ������ʱ����
    if (State_Stop && _pMonster->getfStopDuration() > 0)
    {
        float StateTime = _pMonster->getfStopDuration() - t;
        if (StateTime < 0) StateTime = 0;
        _pMonster->setfStopDuration(StateTime);
        Sprite *pTemp = Sprite::create();
        pTemp->setPosition(_pMonster->getContentSize().width / 2, 40);
        _pMonster->getSprite()->addChild(pTemp);
        Animation *pAnimation = AnimationMaker(_pMonster->getIBulletStateType(), t);
        auto pCallFunc = CallFunc::create([=]()
                                          {
                                              if (_pMonster->getfStopDuration() <= 0)
                                              {
                                                  _pMonster->setIState(_pMonster->getIState() & 11);
                                              }
                                              this->listenerMonster(STEP / _pMonster->getISpeed());
                                              pTemp->removeFromParentAndCleanup(true);
                                          });
        pTemp->runAction(Sequence::create(Animate::create(pAnimation), pCallFunc, NULL));
        return;
    }
    _pMonster->runAction(seq);
}

void MoveControllerBase::erasePoint()
{
    if (_pMapPoints->size() == 1)
    {
        return;
    }

    if (_pMonster->getPosition() == *_pMapPoints->begin()) //�Ѿ�����ת���
    {
        if (GameManager::getInstance()->getCurrGameType() == en_Adventure)
        {
            //�����ð��ģʽ��ֱ�Ӳ�������
            _pMapPoints->erase(_pMapPoints->begin());

        }
        else
        {
            //�����bossģʽ������ѭ��
            auto tmp = *(_pMapPoints->begin());
            _pMapPoints->erase(_pMapPoints->begin());
            _pMapPoints->push_back(tmp);
            return; //�������䲻��ִ����
        }

        //��������ʣ��Ĺ켣ֻʣ����һ������
        //��Ϊ�Ź����Ѿ��������ܲ����꣬��������ײ
        if (_pMapPoints->size() == 1)
        {
            NOTIFY->postNotification("CarrotHurt", _pMonster); //�ܲ���ҧһ��
            NOTIFY->postNotification("MonsterDead", _pMonster); //�������ҵ�
            _pMonster->setIsDead(true);
            _pMonster->removeFromParentAndCleanup(true);
        }
    }
}

MoveControllerBase::~MoveControllerBase()
{
    CC_SAFE_DELETE(_pMapPoints);
}

Animation *MoveControllerBase::AnimationMaker(int iBulletType, float t)
{
    Animation *pAnimation = Animation::create();
    if (iBulletType == 1)
    {
        //�����٣�
        pAnimation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PShit-11.png"));
        pAnimation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PShit-12.png"));
        pAnimation->setDelayPerUnit(t / 2);
    }
    else if (iBulletType == 5)
    {
        //�����Ǽ��٣�
        pAnimation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PBStar-21.png"));
        pAnimation->setDelayPerUnit(t);
    }
    else if (iBulletType == 15 || iBulletType == 30 || iBulletType == 45)
    {
        //�������٣�
        pAnimation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PSnow01.png"));
        pAnimation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PSnow02.png"));
        pAnimation->setDelayPerUnit(t / 2);
    }
    else if (iBulletType == 6)
    {
        //�Ŷ�����٣�
        pAnimation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PPin01.png"));
        pAnimation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PPin02.png"));
        pAnimation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PPin03.png"));
        pAnimation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName("PPin04.png"));
        pAnimation->setDelayPerUnit(t / 4);
    }
    pAnimation->setLoops(1);
    return pAnimation;
}
