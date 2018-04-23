//
//  TowerArrow.cpp
//  CarrotFantasy
//
//  Created by ������ on 18-4-23.
//
//
#include "TowerArrow.h"
#include "VictimEntityBase.h"
#include "BulletFactory.h"

bool TowerArrow::init()
{
    bool bRet = false;
    do
    {
        //ȷ�����Ļ����ʼ��
        CC_BREAK_IF(!TowerBase::init(rId));

        bRet = true;
    } while (0);
    return bRet;
}
void TowerArrow::fire(float dt) {
    if (!_pAtkTarget || _pAtkTarget->getIsDead()) return; //����Ŀ��û�˵Ļ��Ͳ�ҪϹ������

    fireAction(); //�������𶯻�����

                  //�����ӵ�����ʾ����������
    auto createBulletCF = CallFunc::create([=]()
    {
        if (!_pAtkTarget) return;
        BulletFactory::createArrowBullets(_iBulletId, this, _pAtkTarget);
    });

    //�����ӵ����̶���
    this->runAction(Sequence::create(DelayTime::create(_iAtkInterval), createBulletCF, NULL));
}
