//
//BulletStar.cpp
//CarrotFantasy
//
//Created by ������ on 18-4-11
//
//
#include "BulletStar.h"
#include "VictimEntityBase.h"
#include "MonsterManager.h"
#include "MonsterBase.h"
#include "BarrierManager.h"
#include "BarrierBase.h"

bool BulletStar::init(const int & rId, VictimEntityBase *rVictimEntity)
{
	bool bRet = false;
	do
	{
		//��֤�ӵ�����ĳ�ʼ���ɹ���
		CC_BREAK_IF(!BulletBase::init(rId, rVictimEntity));

		bRet = true;
	} while (0);
	return bRet;
}

BulletStar * BulletStar::create(const int & rId, VictimEntityBase *rVictimEntity)
{
	//�����ڴ���ӵ�ָ�룻
	BulletStar * pBullet = new BulletStar();
	if (pBullet && pBullet->init(rId, rVictimEntity))
	{		//��ʼ���ɹ��������Զ��ͷţ�
		pBullet->autorelease();
		return pBullet;
	}
	//���ɹ���ɾ������
	CC_SAFE_DELETE(pBullet);
	return nullptr;
}

void BulletStar::doAction()
{
	//�ӵ���ͣ����׼(��ת��׼);
	getSprite()->runAction(RepeatForever::create(RotateBy::create(0.7, 360)));
}

void BulletStar::doMove() 
{
	//�������Ŀ���Ѿ��������Ӹ��ڵ���ɾȥ���������������أ�
	if (_pAtkTarget->getIsDead())
	{
		removeFromParent();
		setIsDead(true);
		return;
	}
	doAction();

	Animation * pAnimation = Animation::create();
	//�߸��������������δ�����
	for (int i = 1; i < 7; i++)
	{
		std::string SpriteFrameName = StringUtils::format("PStar-1%d.png", i);
		pAnimation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(SpriteFrameName));
	}
	//���ö����ӳ�ʱ�䣻
	pAnimation->setDelayPerUnit(0.05);
	//����һ�μ��ɣ�
	pAnimation->setLoops(1);

	auto deadActionCF = CallFunc::create([=]()
	{

		Rect rect = Rect(_pAtkTarget->getPositionX() - 100, _pAtkTarget->getPositionY() - 100, 200, 200);
		//����Ķ���֡��������0��
		if (_pAtkTarget->getAnimationFrameCount() != 0)
		{
			//��ȡ����vector��
			Vector<MonsterBase *>  MonsterVector = Vector<MonsterBase *>(MonsterManager::getInstance()->getMonsterVec());
			for (auto mIter = MonsterVector.begin(); mIter != MonsterVector.end();)
			{
				MonsterBase * pMonster = (MonsterBase *)(*mIter);
				//�������ཻ��������Ƿ���У�
				if (rect.intersectsRect(pMonster->getBoundingBox()))
				{
					//���У������˺���
					pMonster->beHurt(getAtkPro());
				}
				//�����ˣ�
				if (pMonster->getIHp() <= 0 || pMonster->getIsDead())
				{
					/*mIter = (auto)*/
					//�����
					MonsterVector.eraseObject(pMonster);
				}
				else
				{
					++mIter;
				}
			}
		}
		else//Ϊ0�����ϰ���Ķ���֡����
		{
			Vector<BarrierBase *>  BarrierVector = Vector<BarrierBase *>(BarrierManager::getInstance()->getBarrierVec());
			for (auto bIter = BarrierVector.begin(); bIter != BarrierVector.end();)
			{
				BarrierBase * pBarrier = (BarrierBase *)(*bIter);
				if (rect.intersectsRect(pBarrier->getBoundingBox()))
				{
					//���У������˺���
					pBarrier->beHurt(getAtkPro());
				}
				//������
				if (pBarrier->getIHp() <= 0 || pBarrier->getIsDead())
				{
					/*bIter =(auto)*/ 
					//�����
					BarrierVector.eraseObject(pBarrier);
				}
				else
				{
					++bIter;
				}
			}
		}
		deadAction(_sName);
	});
	//�ƶ������ꣻ
	Vec2 MovetoPosition = _pAtkTarget->getPosition() - this->getPosition();
	//�ƶ��ľ��룻
	float MoveDistance = this->getPosition().distance(_pAtkTarget->getPosition());
	//ִ�ж�����
	getSprite()->runAction(Sequence::create(MoveBy::create(MoveDistance / _iSpeed, MovetoPosition), Animate::create(pAnimation), deadActionCF, NULL));
}

