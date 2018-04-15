//
//  BulletBase.cpp
//  CarrotFantasy
//
//  Created by ������ on 18-4-10.
//  ���ʺž��ǲ�����
//   idmap��ʲô
//

#include "BulletBase.h"
#include "BulletManager.h"
#include "VictimEntityBase.h"

BulletBase *BulletBase::create(const int &rIId, VictimEntityBase *rVictimEntity)
{
	//�ӵ�ָ�룻
	auto pBullet = new BulletBase();
	//��ʼ���ɹ��Ļ����������Զ��ͷţ�
	if (pBullet && pBullet->init(rIId, rVictimEntity)) pBullet->autorelease();
	//��ʼ�����ɹ���ɾ������
	else CC_SAFE_DELETE(pBullet);
	return pBullet;
}

bool BulletBase::init(const int &rId, VictimEntityBase *rVictimEntity)
{
	bool bRet = false;

	do
	{
		//��ʼ��ʵ�����Ͷ�̬ʵ�幫�����ࣻ
		CC_BREAK_IF(!Entity::init(rId, BULLETCSVFILE));
		CC_BREAK_IF(!DynamicPropertyInterface::init(rId, BULLETCSVFILE));
		//�ӵ�����״̬��
		_iAtkState = CsvUtil::getInstance()->getInt(_iId, en_AtkState, BULLETCSVFILE);
		//�ӵ����ࣻ
		_iBulletType = CsvUtil::getInstance()->getInt(_iId, en_BulletType, BULLETCSVFILE);
		//����������Ŀ��
		_iDeadActCount = CsvUtil::getInstance()->getInt(_iId, en_DeadActCount, BULLETCSVFILE);
		//�����Զ����ӣ�
		CC_SAFE_RETAIN(rVictimEntity);
		//���ù���Ŀ��Ϊ������ʵ�壻
		_pAtkTarget = rVictimEntity;
		//����
		_IdMap = new std::set<int>();
		//���ҳ�ʼ����ʱ��ֱ�������������(ע��)�Լ�
		BulletManager::getInstance()->addBullet(this);

		bRet = true;
	} while (0);

	return  bRet;
}

void BulletBase::doAction(const float &rDt)
{
	switch (_iBulletType)
	{
	case en_NormalBullet:
	case en_GunBullet:
	{
		std::vector<std::string> tAnimationFiles;
		for (int i = 1; i <= _IAnimationFrameCount; ++i)
			//��Ӷ�����·��������ͳһ����
			tAnimationFiles.push_back(_sModelName + StringUtils::format("%d", i) + PHOTOPOSTFIX);
		//����·�����������ӵ����˶�������
		createDynamicEntityAnimation(tAnimationFiles);
		//��Ӿ���֡��
		_pAnimation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(_sModelName + "1" + PHOTOPOSTFIX));
		//�����ӳ�ʱ�䣻
		_pAnimation->setDelayPerUnit(rDt);
		//����������
		getSprite()->runAction(Animate::create(_pAnimation));
		break;
	}
	case en_NoDisspper:
	{
		//�ظ��������úͽǶȵ�����
		getSprite()->runAction(RepeatForever::create(RotateBy::create(0.7, 360)));
		break;
	}
	default:
		break;
	}
}

void BulletBase::doMove() 
{
	//�������Ŀ���Ѿ����ˣ��ǾʹӸ��ڵ���ɾȥ������¼�����󷵻أ�
	if (_pAtkTarget->getIsDead())
	{
		removeFromParent();
		setIsDead(true);
		return;
	}
	//���û���Ļ��������ӳ�ʱ�䲢����������
	doAction(0.2f);
	//����
	//��ķ����ʽ�Ѿ����⣬����ע�Ͱ�
	auto deadActionCF = CallFunc::create([=]()
	{
		if (_iBulletType == en_NormalBullet || _iBulletType == en_GunBullet || _iBulletType == en_StarBullet) {
			if (_pAtkTarget != nullptr && !_pAtkTarget->getIsDead())
				_pAtkTarget->beHurt(getAtkPro());
			this->setPosition(_pAtkTarget->getPosition());
		}
		deadAction(_sName);
	});
	//�ƶ�λ�ã�
	Vec2 MovetoPosition;
	//�ƶ����룻
	float MoveDistance;
	switch (_iBulletType)
	{
	case en_NormalBullet:
	case en_GunBullet:
		//�ƶ�������ڹ���Ŀ�������ȥ���ӵ������ꣻ
		MovetoPosition = _pAtkTarget->getPosition() - this->getPosition();
		//������룬���ɶ���
		MoveDistance = this->getPosition().distance(_pAtkTarget->getPosition());
		break;
	case en_NoDisspper:
	{
		//б�� Hypotenuse��

		float Hypotenuse = Vec2::ZERO.distance(Director::getInstance()->getVisibleSize());
		//���Ǻ��������ꣻ
		MovetoPosition = Vec2(Hypotenuse * sin(this->getRotation() * M_PI / 180), Hypotenuse * cos(this->getRotation() * M_PI / 180));
		//���ù��ɶ��������
		MoveDistance = MovetoPosition.distance(this->getPosition());
		break;
	}
	default:
		break;
	}
	//�ӵ����䣻
	//����
	//�����������ʲô������
	this->runAction(Sequence::create(MoveBy::create(MoveDistance / _iSpeed, MovetoPosition), deadActionCF, NULL));
}

AtkProperty BulletBase::getAtkPro()
{
	AtkProperty tAtkProperty;
	//��������
	tAtkProperty._enAtkState = _iAtkState;
	//��������
	tAtkProperty._iAtk = getIAtk();
	//����ʱ���趨��
	tAtkProperty._iDuration = CsvUtil::getInstance()->getInt(_iId, en_Duration, BULLETCSVFILE);
	tAtkProperty._iBulletsType = _iBulletType;
	return tAtkProperty;
}

void BulletBase::deadAction(const std::string &rSDeadImageFile)
{
	CC_SAFE_DELETE(_IdMap);
	//������������·������ִ������������
	Entity::deadAction(rSDeadImageFile);
}

std::set<int>& BulletBase::getIdMap()
{
	return *_IdMap;
}