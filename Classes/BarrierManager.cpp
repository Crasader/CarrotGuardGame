//
//  BarrierManager.cpp
//  CarrotFantasy
//
//  Created by ������ on 18-4-7.
//  TODO
//

#include "BarrierManager.h"
#include "BarrierBase.h"
#include "SceneManager.h"

BarrierManager *BarrierManager::_gInstance;

BarrierManager::BarrierManager()
{}

BarrierManager::~BarrierManager()
{
    CC_SAFE_DELETE(_pBarrierVec);
}


bool BarrierManager::init()
{
    bool bRet = false;

    do
    {
        _pBarrierVec = new Vector<BarrierBase *>(); //newһ�������������ڴ棻
        registerBarrierDeadEvent(); //ע���¼�

        bRet = true;
    } while (0);

    return bRet;
}

Vector<BarrierBase *> &BarrierManager::getBarrierVec()
{
    return *_pBarrierVec;
}

void BarrierManager::addBarrier(BarrierBase *pBarrier)
{
    //ע���ϰ�������
    if (_pBarrierVec) _pBarrierVec->pushBack(pBarrier); //��������
    _funcAddBarrierToLayer(pBarrier); //����ͼ��
}

void BarrierManager::setFuncAddBarrierToLayer(const std::function<void(Entity *)> &rFuncAddBarrierToLayer)
{
    _funcAddBarrierToLayer = rFuncAddBarrierToLayer;
}

void BarrierManager::registerBarrierDeadEvent()
{
    //ע���ϰ��ﱻ����֮��Ĵ��������ñ����removeBarrierFromManager����������
	//�����ַ���"BarrierDead"���������Ϻ�������
    NOTIFY->addObserver(this, callfuncO_selector(BarrierManager::removeBarrierFromManager), "BarrierDead", nullptr);
}


void BarrierManager::removeBarrierFromManager(Ref *pBarrier)
{
    //�ϰ����������̣�
    if (!(_pBarrierVec && _pBarrierVec->size())) return;
    _pBarrierVec->eraseObject(reinterpret_cast<BarrierBase *>(pBarrier)); //�������ҵ���ɾ��

    //����ϰ���ȫ����������
    //���޸�һ��ͨ������
	//TODO��û��֪ͨ������������
    if (!_pBarrierVec->size())
    {
        //����֪ͨ��Ϣ
        auto aThemeIndex = SceneManager::getInstance()->getCurrentPageIndex() + 1;
        auto aLevelIndex = SceneManager::getInstance()->getCurrentLevelIndex() + 1;
        auto aLevelData = std::make_tuple(1, 1, aThemeIndex, aLevelIndex);
        //����Ϣ�㲥��ȥ
        NOTIFY->postNotification(LEVELDATACHANGE, reinterpret_cast<Ref *>(&aLevelData));
    }
}

void BarrierManager::clearManager()
{
    _pBarrierVec->clear();
}

void BarrierManager::clearBeAtkLockState()
{
    //������
	//TODO����ô��ȫ�����ϰ��ﶼ���״̬���˷�ʱ�䣻
    for (auto &iterBarrier : *_pBarrierVec)
        iterBarrier->setAtkTarget(false);
}
