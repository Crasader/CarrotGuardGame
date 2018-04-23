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
#include "BulletFactory.h"


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
    if (!_pAtkTarget || _pAtkTarget->getIsDead()) return; //����Ŀ��û�˵Ļ��Ͳ�ҪϹ������

    fireAction(); //�������𶯻�����

                  //�����ӵ�����ʾ����������
    auto createBulletCF = CallFunc::create([=]()
    {
        if (!_pAtkTarget) return;
        BulletFactory::createCuttleBullets(_iBulletId, this, _pAtkTarget);
    });

    //�����ӵ����̶���
    this->runAction(Sequence::create(DelayTime::create(0.15), createBulletCF, NULL));
}
