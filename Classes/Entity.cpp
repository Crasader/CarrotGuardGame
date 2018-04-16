//
//  Entity.cpp
//  newCardDefence
//
//  Created by ������ on 18-4-6.
//  ���ڲ������⣻
//

#include "Entity.h"
#include "CommonSource.h"

unsigned long Entity::ID = 0;
Entity::~Entity()
{
	CC_SAFE_RELEASE_NULL(_pSprite);
	//��ȫɾ�����飻
}

bool Entity::init(const int &rId, const std::string &rSCsvFileName)
{
	bool bRet = false;
	do
	{
		initProperty(rId, rSCsvFileName);
		++ID;
		_myID = ID;
		bRet = true;
	} while (0);

	return bRet;
}

const Size &Entity::getContentSize()const
{
	return _pSprite->getContentSize();
}


void Entity::initProperty(const int &rId, const std::string &rSCsvFileName)
{
	auto pCsvUtil = CsvUtil::getInstance();

	_iId = rId;
	auto pData = pCsvUtil->getRowData(rId, rSCsvFileName);

	//��ȡ��һ�У�Ҳ����ʵ�������(Name)
	_sName = pData.at(en_Name);
	//��ȡ�ڶ��У�Ҳ����ʵ���ģ������(ModelName)
	_sModelName = pData.at(en_ModelName);
	//��ȡ�����У�Ҳ����ʵ���ֵ(Value)
	_iValue = atoi(pData.at(en_Value).c_str());
	//��ȡ�����У�Ҳ����ʵ�嶯����֡��(AnimationFrameCount)
	_IAnimationFrameCount = pCsvUtil->getInt(rId, en_AnimationCount, rSCsvFileName);
	//��ȡ�����У�Ҳ����ʵ��ĵȼ�(Level)
	_iLevel = pCsvUtil->getInt(_iId, en_Level, rSCsvFileName);
	_bIsDead = false;
	std::string sSpriteName;

	if (_IAnimationFrameCount) sSpriteName = _sModelName + "1" + PHOTOPOSTFIX;
	else sSpriteName = _sModelName + PHOTOPOSTFIX;

	//�þ���֡�������飻
	bindSprite(Sprite::createWithSpriteFrameName(sSpriteName));
}

void Entity::bindSprite(cocos2d::Sprite *pSprite)
{
	if (_pSprite) //����Ѿ����˾��飬��Ҫ���н��
	{
		_pSprite->stopAllActions(); //ֹͣһ�л
		removeChild(_pSprite);
	}
	CC_SAFE_RELEASE_NULL(_pSprite);
	_pSprite = pSprite;
	CC_SAFE_RETAIN(_pSprite);
	addChild(_pSprite);
}

Sprite* Entity::getSprite()
{
	return _pSprite;
}


void Entity::doDead() //����ܵ��õ���������
{
	//����Ҳ��������
    //���˵�Ȼ����Ǯ�� by Jeza
	NOTIFY->postNotification("moneyChange", reinterpret_cast<Ref*>(&_iValue));
	setIsDead(true);
	_pSprite->stopAllActions();
	deadAction(); //������������
}

void Entity::deadAction(const std::string &rSDeadImageFile)
{

	auto sDeadImageFile = rSDeadImageFile;
	//��������ָ�룻
	auto pAnimation = Animation::create();
	//��ȡ����֡����
	auto pSpriteFrameCache = SpriteFrameCache::getInstance();
	if (sDeadImageFile.empty()) //������Ϊ���ַ���
	{
	    //����Ĭ����������
        //ÿ�������������������������
		if (1 == _iLevel) sDeadImageFile = "air0";
		else if (2 == _iLevel) sDeadImageFile = "air1";
		else if (3 == _iLevel) sDeadImageFile = "air2";
		for (int index = 1; index <= _IAnimationFrameCount; ++index)
			pAnimation->addSpriteFrame(pSpriteFrameCache->getSpriteFrameByName(sDeadImageFile + StringUtils::format("%d", index) + PHOTOPOSTFIX));

	}
	else
	{
	    //TODO Ҫ��������Ĭ�ϵĲ���������ʲô
		for (int i = 1; i <= 2; i++)
			//��Ӿ��黺��(������Ӿ��黺�棩
			pAnimation->addSpriteFrame(pSpriteFrameCache->getSpriteFrameByName(sDeadImageFile + StringUtils::format("%02d", i) + PHOTOPOSTFIX));
	}

	pAnimation->setLoops(1); //ֻ����һ�ξ�����
	pAnimation->setDelayPerUnit(0.1f);
	//���Ϊʲô������
    //����һ���������У������������ź�ִ��ȥ�����麯��
	_pSprite->runAction(Sequence::create(Animate::create(pAnimation), CallFunc::create([this]() {this->removeFromParent(); }), NULL));
}

Rect Entity::getBoundingBox()const
{
	//��ȡ���ꣻ
	auto tPos = getPosition();
	//��ȡ����ԭͼ��С��
	auto tSize = _pSprite->getContentSize();
	//�����ê�㴦���е�
	return Rect(tPos.x - tSize.width / 2, tPos.y - tSize.height / 2, tSize.width, tSize.height);
}

unsigned int Entity::getmID()
{
	return _myID;
}
