#include "LoadingScene.h"
#include "SoundUtil.h"
#include "GameScene.h"


bool LoadingScene::init()
{
    bool bRet = false;
    do {
        CC_BREAK_IF(!Scene::init());

        //������createWithSpriteFrameName
        //��Ϊû�м��ص�������
        auto aBg = Sprite::create(LOADINGSOURCE); //bug fixed

        aBg->setPosition(VisibleRectUtil::center());
        addChild(aBg);

        bRet = true;
    } while (0);
    return bRet;
}

void LoadingScene::onEnter()
{
    Scene::onEnter();
    SoundUtil::getInstance()->stopBackgroundSound(); //������س�����ʱ��ֹͣ��������
    NOTIFY->addObserver(this, callfuncO_selector(LoadingScene::loadSourceFinishedCallBack), "loadFinished", nullptr);

    _pGameScene = GameScene::create();
    _pGameScene->retain();
}

void LoadingScene::onExit()
{
    NOTIFY->removeAllObservers(this);
    CC_SAFE_RELEASE_NULL(_pGameScene);
    Scene::onExit();
}

void LoadingScene::loadSourceFinishedCallBack(Ref *pData)
{
    //�����л�����Ϸ����
    auto aTransScene = TransitionFade::create(0.2f, dynamic_cast<Scene*>(pData));
    Director::getInstance()->replaceScene(aTransScene);
}
