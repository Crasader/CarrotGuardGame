#pragma once

#include "BulletAnchor.h"
#include "VictimEntityBase.h"
#include "MonsterManager.h"
#include "MonsterBase.h"
#include "BarrierManager.h"
#include "BarrierBase.h"



bool BulletAnchor::init(const int & rId, VictimEntityBase *rVictimEntity)
{
	bool bRet = false;
	do
	{
		//ȷ���ӵ�����ĳɹ���ʼ����
		CC_BREAK_IF(!BulletBase::init(rId, rVictimEntity));

		bRet = true;
	} while (0);
	return bRet;
}

BulletAnchor * BulletAnchor::create(const int & rId, VictimEntityBase *rVictimEntity)
{
	//�����ڴ棻
	BulletAnchor * pBullet = new BulletAnchor();
	if (pBullet && pBullet->init(rId, rVictimEntity))
	{
		//��ʼ���ɹ��������Զ��ͷţ�
		pBullet->autorelease();
		return pBullet;
	}
	//����ɾ������
	CC_SAFE_DELETE(pBullet);
	return nullptr;
}

void BulletAnchor::doAction()
{
	//�ӵ���ͣ����׼(��ת��׼);
	getSprite()->runAction(RepeatForever::create(RotateBy::create(0.7, 360)));
}

void BulletAnchor::doMove() 
{
	//�������Ŀ���Ѿ��������Ӹ��ڵ���ɾȥ���������������أ�
	if (_pAtkTarget->getIsDead())
	{
		removeFromParent();
		setIsDead(true);
		return;
	}
	//��׼��
	doAction();

	Animation * pAnimation = Animation::create();
	//�߸��������������δ�����
	for (int i = 1; i < 7; i++)
	{
		std::string SpriteFrameName = StringUtils::format("PAnchor-1%d.png", i);
		pAnimation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(SpriteFrameName));
	}
	//���ö����ӳ�ʱ�䣻
	pAnimation->setDelayPerUnit(0.05);
	//����һ�μ��ɣ�
	pAnimation->setLoops(1);

	auto deadActionCF = CallFunc::create([=]() 
	{
		//��ȡ�ϰ���������
		auto BarrierVector = BarrierManager::getInstance()->getBarrierVec();
		//��ȡ�ϰ���������С��
		auto  size = BarrierVector.size();
		if (size > 0)
		{
			//ê�Ķ��ϰ��﹥���Ǿ���������Եģ�
			int num1 = rand() % size;
			int num2 = rand() % size;
			int num3 = rand() % size;
			//����ê������ϰ���Ĺ���Ŀ�ꣻ
			//auto barrierPoint = (BarrierVector.at(num1))->getPosition();
			auto barrierPoint1 = (BarrierVector.at(num1))->getPosition();
			auto barrierPoint2 = (BarrierVector.at(num2))->getPosition();
			auto barrierPoint3 = (BarrierVector.at(num3))->getPosition();
			//�������ϰ�����������������
			MoveTo * move1 = MoveTo::create(2.5f, barrierPoint1);
			MoveTo * move2 = MoveTo::create(2.0f, barrierPoint2);
			MoveTo * move3 = MoveTo::create(1.5f, barrierPoint3);
			//����������ת�������ǶȲ�ͬ��
			RotateBy * rotate1 = RotateBy::create(0.05f, 30);
			RotateBy * rotate2 = RotateBy::create(0.05f, 35);
			RotateBy * rotate3 = RotateBy::create(0.05f, 25);
			//���ö�����������
			RepeatForever * rep1 = RepeatForever::create(rotate1);
			RepeatForever * rep2 = RepeatForever::create(rotate2);
			RepeatForever * rep3 = RepeatForever::create(rotate3);

			//��������֡
			std::string SpriteFrameName = StringUtils::format("PAnchor%d2.png", getILevel());
			SpriteFrame * fileName = SpriteFrameCache::getInstance()->getSpriteFrameByName(SpriteFrameName);
			//�����ȼ����ʱ���ڵ���������ê��
			auto Anchor1 = Sprite::createWithSpriteFrame(fileName);
			auto Anchor2 = Sprite::createWithSpriteFrame(fileName);
			auto Anchor3 = Sprite::createWithSpriteFrame(fileName);

			auto layer = Director::getInstance()->getRunningScene()->getChildByTag(1);
			//�ȼ�Ϊ1ʱֻ��һ������ê��
			if (getILevel() == 1)
			{
				Anchor1->setPosition(_pAtkTarget->getPosition());
				layer->addChild(Anchor1);

				auto dieCf = CallFunc::create([=]() 
				{
					//����ê��������ϰ����˺���
					BarrierVector.at(num1)->beHurt(getAtkPro());
					//���к���գ�
					Anchor1->removeFromParentAndCleanup(true);
				});
				//��ת������
				Anchor1->runAction(rep1);
				//����ê������������
				Anchor1->runAction(Sequence::create(move1, Animate::create(pAnimation), dieCf, NULL));
			}
			//��������ê��
			if (getILevel() == 2)
			{
				Anchor1->setPosition(_pAtkTarget->getPosition());
				layer->addChild(Anchor1);
				Anchor2->setPosition(_pAtkTarget->getPosition());
				layer->addChild(Anchor2);

				auto dieCf1 = CallFunc::create([=]() {
					BarrierVector.at(num1)->beHurt(getAtkPro());
					Anchor1->removeFromParentAndCleanup(true);
				});
				auto dieCf2 = CallFunc::create([=]() {
					BarrierVector.at(num2)->beHurt(getAtkPro());
					Anchor2->removeFromParentAndCleanup(true);
				});
				Anchor1->runAction(rep1);
				Anchor2->runAction(rep2);
				Anchor1->runAction(Sequence::create(move1, Animate::create(pAnimation), dieCf1, NULL));
				Anchor2->runAction(Sequence::create(move2, Animate::create(pAnimation), dieCf2, NULL));
			}
			//��������ê��
			if (getILevel() == 3)
			{
				Anchor1->setPosition(_pAtkTarget->getPosition());
				layer->addChild(Anchor1);
				Anchor2->setPosition(_pAtkTarget->getPosition());
				layer->addChild(Anchor2);
				Anchor3->setPosition(_pAtkTarget->getPosition());
				layer->addChild(Anchor3);

				auto dieCf1 = CallFunc::create([=]() {
					BarrierVector.at(num1)->beHurt(getAtkPro());
					Anchor1->removeFromParentAndCleanup(true);
				});
				auto dieCf2 = CallFunc::create([=]() {
					BarrierVector.at(num2)->beHurt(getAtkPro());
					Anchor2->removeFromParentAndCleanup(true);
				});
				auto dieCf3 = CallFunc::create([=]() {
					BarrierVector.at(num3)->beHurt(getAtkPro());
					Anchor3->removeFromParentAndCleanup(true);
				});
				Anchor1->runAction(rep1);
				Anchor2->runAction(rep2);
				Anchor3->runAction(rep3);
				Anchor1->runAction(Sequence::create(move1, Animate::create(pAnimation), dieCf1, NULL));
				Anchor2->runAction(Sequence::create(move2, Animate::create(pAnimation), dieCf2, NULL));
				Anchor3->runAction(Sequence::create(move3, Animate::create(pAnimation), dieCf3, NULL));
			}
		}

		Rect rect = Rect(_pAtkTarget->getPositionX() - 100, _pAtkTarget->getPositionY() - 100, 200, 200);
		for (auto mIter = MonsterManager::getInstance()->getMonsterVec().begin(); mIter != MonsterManager::getInstance()->getMonsterVec().end(); mIter++)
		{
			MonsterBase * pMonster = (MonsterBase *)(*mIter);
			if (rect.intersectsRect(pMonster->getBoundingBox()))
			{//���У������˺���
				pMonster->beHurt(getAtkPro());
			}
			//�����ˣ�
			if (pMonster->getIHp() <= 0 || pMonster->getIsDead())
			{
				//Ϊʲôֱ��break��
				break;
			}
		}
		for (auto bIter = BarrierManager::getInstance()->getBarrierVec().begin(); bIter != BarrierManager::getInstance()->getBarrierVec().end(); bIter++)
		{
			BarrierBase * pBarrier = (BarrierBase *)(*bIter);
			if (rect.intersectsRect(pBarrier->getBoundingBox()))
			{
				//���У������˺���
				pBarrier->beHurt(getAtkPro());
			}
			if (pBarrier->getIHp() <= 0 || pBarrier->getIsDead())
			{
				//������
				//TODO��Ϊʲô�������
				//BarrierVector.eraseObject(pBarrier);�ǲ���Ӧ�ü���䣻
				break;
			}
		}
		deadAction(_sName);

	});
	//�Ǵ�͸�������ƶ����ꣻ
	Vec2 MovetoPosition = _pAtkTarget->getPosition() - this->getPosition();
	//�ƶ����룻
	float MoveDistance = this->getPosition().distance(_pAtkTarget->getPosition());
	//ִ�ж�����
	getSprite()->runAction(Sequence::create(MoveBy::create(MoveDistance / _iSpeed, MovetoPosition), Animate::create(pAnimation), deadActionCF, NULL));

}
