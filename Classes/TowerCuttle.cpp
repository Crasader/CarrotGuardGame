//
//  TowerCuttle.cpp
//  CarrotFantasy
//
//  Created by ������ on 18-4-19.
//  
//
#include "TowerCuttle.h"
#include "MonsterBase.h"
#include "BarrierBase.h"
#include "MonsterManager.h"
#include "BarrierManager.h"
#include "SoundUtil.h"
#include "BulletBase.h"
#include "CsvUtil.h"


bool TowerCuttle::init()
{
	bool bRet = false;
	do
	{
		//ȷ�����Ļ����ʼ��
		CC_BREAK_IF(!TowerBase::init(rId));
		//������û����תЧ������Ҫע��������
		unschedule(schedule_selector(TowerCuttle::doRotation));

		_doAnimationSprite = Sprite::create();
		//����ͼ�㲻�ɼ���
		_doAnimationSprite->setVisible(false);
		addChild(_doAnimationSprite);

		bRet = true;
	} while (0);
	return bRet;
}
void TowerCuttle::fire(float dt) {
	if (!_pAtkTarget || _pAtkTarget->getIsDead()) return;

	//��������Ч������
	Animation * pAnimation = Animation::create();
	for (int i = 1; i <= 3; i++) {
		std::string SpriteFrameName = "P" + _sModelName + StringUtils::format("1%d.png", i);
		pAnimation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(SpriteFrameName));
	}
	pAnimation->setDelayPerUnit(0.03);
	pAnimation->setLoops(1); //ѭ��һ�β��žͿ����ˣ�ѭ���Ĺ����ǵ������Ǳߵ�


	//����Ч����������
	_doAnimationSprite->setVisible(true);

	//�ӵ���������
	BulletDoAction();

	//���Ź�������
	SoundUtil::getInstance()->playEffectSound("Music/Towers/Cuttle.mp3");


	CallFunc * pCallFunc = CallFunc::create([=]() {
		attack();
		_doAnimationSprite->setVisible(false);
	});

	_doAnimationSprite->runAction(Sequence::create(Animate::create(pAnimation),pCallFunc, NULL));
}
void TowerCuttle::attack()
{
	atk._enAtkState = 1;
	atk._iAtk = _iBulletId;
	atk._iDuration = 0;

	/*************************************************************/
	/**-----------------------������Ϸ���߼�-----------------------**/
	/*************************************************************/

	//���˶�������
	Animation * pHurtAction = Animation::create();
	for (int i = 1; i < 4; i++)
	{
		std::string hurtSpriteName = StringUtils::format("PCuttle0%d.png", i);
		pHurtAction->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(hurtSpriteName));
	}
	pHurtAction->setDelayPerUnit(0.03);
	pHurtAction->setLoops(1);

	Rect rect;
	//todo �����ΧӦ�����ļ���Ϊ׼
	if (getIId() == 40) { rect = Rect(this->getPositionX() - 100, this->getPositionY() - 100, 200, 200); }
	if (getIId() == 41) { rect = Rect(this->getPositionX() - 120, this->getPositionY() - 120, 240, 240); }
	if (getIId() == 42) { rect = Rect(this->getPositionX() - 140, this->getPositionY() - 140, 280, 280); }

	//�ȼ�����
	Vector<MonsterBase *>  MonsterVector = Vector<MonsterBase *>(MonsterManager::getInstance()->getMonsterVec());
	for (int i = 0; i < MonsterVector.size(); i++)
	{
		MonsterBase * pMonster = (MonsterBase *)(MonsterVector.at(i));
		if (rect.intersectsRect(pMonster->getBoundingBox())) //��ײ���
		{
			pMonster->beHurt(atk);
			//������ʾ���˶��������˾�������
			Sprite * pMonsterHurt = Sprite::create();
			pMonster->addChild(pMonsterHurt);
			//���˾�����ʾ����
			CallFunc * pClear = CallFunc::create([=]() 
			{ pMonsterHurt->removeFromParentAndCleanup(true); });
			pMonsterHurt->runAction(Sequence::create(Animate::create(pHurtAction), pClear, nullptr));
		}
		if (pMonster->getIHp() <= 0 || pMonster->getIsDead())
		{
			MonsterVector.eraseObject(pMonster);
		}
	}

	//�ټ���ϰ���
	Vector<BarrierBase *> BarrierVector = Vector<BarrierBase *>(BarrierManager::getInstance()->getBarrierVec());
	for (int i = 0; i < BarrierVector.size(); i++)
	{
		BarrierBase * pBarrier = (BarrierBase *)(MonsterVector.at(i));
		if (rect.intersectsRect(pBarrier->getBoundingBox()))
		{
			pBarrier->beHurt(atk);
			Sprite * pBarrierHurt = Sprite::create();
			pBarrier->addChild(pBarrierHurt);
			CallFunc * pClear = CallFunc::create([=]() 
			{ pBarrierHurt->removeFromParentAndCleanup(true); });
			pBarrierHurt->runAction(Sequence::create(Animate::create(pHurtAction), pClear, NULL));
		}
		if (pBarrier->getIHp() <= 0 || pBarrier->getIsDead())
		{
			BarrierVector.eraseObject(pBarrier);
		}

	}

}

void TowerCuttle::BulletDoAction()
{
	//�����ӵ���������
	Animation * pAnimation2 = Animation::create();
	for (int i = 1; i <= 2; i++)
	{
		std::string SpriteFrameName = "P" + _sModelName + StringUtils::format("%d.png", i);
		pAnimation2->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(SpriteFrameName));
	}
	pAnimation2->setDelayPerUnit(0.1);
	pAnimation2->setLoops(1);

	_doAnimationSprite->runAction(Sequence::create(Animate::create(pAnimation2),  NULL));
}

void TowerCuttle::bulletMoveToFar()
{

	atk._enAtkState = 1;
	atk._iAtk = _iBulletId;
	atk._iDuration = 0;

	if (_pAtkTarget->getIsDead())
	{
		//�������Ŀ���Ѿ��������Ӹ��ڵ���ɾȥ���������������أ�
		removeFromParent();
		setIsDead(true);
		return;
	}
	BulletDoAction();

	auto deadActionCF = CallFunc::create([=]()
	{
		//�������Ŀ����ڲ�û������������
		if (_pAtkTarget != nullptr && !_pAtkTarget->getIsDead())
			_pAtkTarget->beHurt(atk);
		//ִ������������
		deadAction(_sName);
	});
	//��ͨ�Ĺ��������Ǵ�͸������
	Vec2 MovetoPosition = _pAtkTarget->getPosition() - this->getPosition();
	float MoveDistance = this->getPosition().distance(_pAtkTarget->getPosition());
	this->runAction(Sequence::create(MoveBy::create(MoveDistance / _iSpeed, MovetoPosition), deadActionCF, NULL));
	//TODO:_iSpeed��֪����ô����
}
