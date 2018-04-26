#include "BulletCuttle.h"

void BulletCuttle::doAction()
{
    for (int i = 1; i <= 2; ++i)
    {
        std::string SpriteFrameName = _sModelName + StringUtils::format("%d.png", i);
        _pAnimation->addSpriteFrame(SpriteFrameCache::getInstance()->getSpriteFrameByName(SpriteFrameName));
    }
    //�����ӳ�ʱ�䣻
    _pAnimation->setDelayPerUnit(0.05);
    //����ִ�У�һֱ�е������
    _pAnimation->setLoops(-1);
    //���ж�����
    getSprite()->runAction(Animate::create(_pAnimation));
}

void BulletCuttle::doMove()
{
    setRotation(_iRotation);
    doAction();

    float Hypotenuse = Vec2::ZERO.distance(Director::getInstance()->getVisibleSize());
    //Vec2 MovetoPosition = Vec2(Hypotenuse * sin(this->getRotation() * M_PI / 180), Hypotenuse * cos(this->getRotation() * M_PI / 180));
    Vec2 MovetoPosition = Vec2(Hypotenuse * sin(this->getRotation() * M_PI / 180), Hypotenuse * cos(this->getRotation() * M_PI / 180));
    float MoveDistance = MovetoPosition.distance(this->getPosition());

    //ִ�ж�����
    this->runAction(Sequence::create(MoveBy::create(2000 / _iSpeed, MovetoPosition), nullptr));
    
}

bool BulletCuttle::init(const int& rId, VictimEntityBase* rVictimEntity, const int& rotation)
{
    bool bRet = false;
    do
    {
        //��֤�ӵ�����ĳ�ʼ���ɹ���
        CC_BREAK_IF(!BulletBase::init(rId, rVictimEntity));
        _iRotation = rotation;

        bRet = true;
    }
    while (0);
    return bRet;
}

BulletCuttle* BulletCuttle::create(const int& rId, VictimEntityBase* rVictimEntity, const int& rotation)
{
    //�����ڴ���ӵ�ָ�룻
    BulletCuttle* pBullet = new BulletCuttle();
    //��ʼ���ɹ���
    if (pBullet->init(rId, rVictimEntity, rotation))
    {
        //�����Զ��ͷţ�
        pBullet->autorelease();
        return pBullet;
    }
    //���ɹ���ɾ������
    CC_SAFE_DELETE(pBullet);
    return nullptr;
}
