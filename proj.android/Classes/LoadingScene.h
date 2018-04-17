/**
* @brief ������Ϸ����
* @details ��Ϸ����ǰ��Ҫ������Դ����ʱ��Ҫ������Ϸ����
* @author �½���
* @date 20180412
* */

#include"CommonDefine.h"

//class GameSceneII;
class GameScene;

class LoadingScene : public Scene
{
public:
    /**
    * @brief ������
    * @details cocos2d-x�Դ���
    */
    CREATE_FUNC(LoadingScene);
    
protected:
    /**
    * @brief ��ʼ������
    */
    bool init()override;

    /**
    * @brief ���������ʱ����õĺ���
    */
    void onEnter()override;

    /**
    * @brief �����˳���ʱ����õĺ���
    */
    void onExit()override;

    /**
    * @brief GameScene�ļ�����Դ������ɺ󣬻�ص��ú��������л�����Ϸ����
    */
    virtual void loadSourceFinishedCallBack(Ref *pData);

protected:
    GameScene * _pGameScene = nullptr;
};
#pragma once
