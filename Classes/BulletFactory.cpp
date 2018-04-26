//
//  BulletFactory.cpp
//  CarrotFantasy
//
//  Created by ������ on 18-4-10.
//
//

#include "BulletFactory.h"
#include "BulletBase.h"
#include "VictimEntityBase.h"
#include "TowerBase.h"
#include "BulletCuttle.h"


BulletBase *BulletFactory::createBullet(const int &rBulletId, TowerBase* rTower, VictimEntityBase *rVictimEntity)
{
	auto cache = SpriteFrameCache::getInstance();
	//ͨ��plist�и�png��ȡ����֡��
	cache->addSpriteFramesWithFile("Themes/Towers/TBottle-hd.plist", "Themes/Towers/TBottle-hd.png");
	cache->addSpriteFramesWithFile("Themes/Towers/TFan-hd.plist", "Themes/Towers/TFan-hd.png");
	cache->addSpriteFramesWithFile("Themes/Towers/TShit-hd.plist", "Themes/Towers/TShit-hd.png");
	//���ӵ����ഴ���ӵ������˹���Ŀ���id������
	auto pBullet = BulletBase::create(rBulletId, rVictimEntity);
	//�����ӵ��������ķ�����ת��
	pBullet->setRotation(90 - 180 * (rVictimEntity->getPosition() - rTower->getPosition()).getAngle() / M_PI);
	//������ӵ���Ҫ��pos�Ա��ܶ���
	if (pBullet->getIBulletType() == en_GunBullet) 
	{
		pBullet->setPosition(rTower->getPosition() + Vec2(36 * sin(pBullet->getRotation() * M_PI / 180), 36 * cos(pBullet->getRotation() * M_PI / 180)));
	}
	//�����������ӵ��Ͳ������ã�ֱ�ӻ�ȡ����λ�ü��ɣ�
	else 
	{
		pBullet->setPosition(rTower->getPosition());
	}
	//�ӵ���������
	pBullet->doMove();

	return pBullet;
}

void BulletFactory::createCuttleBullets(const int& rCuttleBulletId, TowerBase* rTower, VictimEntityBase *rVictimEntity)
{
    auto cache = SpriteFrameCache::getInstance();
    //ͨ��plist�и�png��ȡ����֡��
    cache->addSpriteFramesWithFile("Themes/Towers/TCuttle-hd.plist", "Themes/Towers/TCuttle-hd.png");

    int cuttleBulletsNum;
    switch (rCuttleBulletId)
    {
        case 25: cuttleBulletsNum = 4; break;
        case 26: cuttleBulletsNum = 8; break;
        case 27: cuttleBulletsNum = 12; break;
    }

    for(int i = 0; i < cuttleBulletsNum; i++)
    {
        auto pBullet = BulletCuttle::create(rCuttleBulletId, rVictimEntity,360 / cuttleBulletsNum * i);
        //�����ӵ��������ķ�����ת��
        //pBullet->setRotation(90 - 180 * (rVictimEntity->getPosition() - rTower->getPosition()).getAngle() / M_PI);
        pBullet->setPosition(rTower->getPosition());
        //�ӵ���������
        pBullet->doMove();
    }
}

void BulletFactory::createArrowBullets(const int& rArrowBulletId, TowerBase* rTower, VictimEntityBase *rVictimEntity)
{
    auto cache = SpriteFrameCache::getInstance();
    //ͨ��plist�и�png��ȡ����֡��
    cache->addSpriteFramesWithFile("Themes/Towers/TCuttle-hd.plist", "Themes/Towers/TCuttle-hd.png");

    int arrowBulletsNum;
    switch (rArrowBulletId)
    {
    case 31: arrowBulletsNum = 2; break;
    case 32: arrowBulletsNum = 3; break;
    case 33: arrowBulletsNum = 5; break;
    }

    for (int i = 0; i < arrowBulletsNum; i++)
    {
        auto pBullet = BulletCuttle::create(rArrowBulletId, rVictimEntity, 90 - 180 * (rVictimEntity->getPosition() - rTower->getPosition()).getAngle() / M_PI - 10 * (arrowBulletsNum / 2) + 10 * i);
        //�����ӵ��������ķ�����ת��
        //pBullet->setRotation(90 - 180 * (rVictimEntity->getPosition() - rTower->getPosition()).getAngle() / M_PI);
        pBullet->setPosition(rTower->getPosition());
        //�ӵ���������
        pBullet->doMove();
    }
}