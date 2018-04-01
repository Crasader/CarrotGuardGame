#include "SceneManager.h"

bool SceneManager::init()
{
    bool bRet = false;
    do
    {
        registerChangeSceneEvent(); //ע������¼�
        bRet = true;
    } while (0);
    return bRet;
}

void SceneManager::initWelcomeScene()
{
    currentScene = en_WelcomeScene;
    auto currScene = std::make_tuple(currentScene, 0);
    changeScene(currScene); //�����Լ��ĺ���������ӭ����
}

void SceneManager::unRegisterChangeSceneEvent()
{
    NOTIFICATION_CENTER->removeAllObservers(this);
}

void SceneManager::changeScene(const std::tuple<SceneType, int>& changingScene)
{
    Director::getInstance()->getScheduler()->setTimeScale(1);
    auto tSceneType = std::get<0>(changingScene);
    if(tSceneType == en_GameScene)
    {

    }
}
