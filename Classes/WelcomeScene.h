/**
* @brief
* @details
* @extends
* @see
* @authors �½���
* @date 20180315
* */
#pragma once
#ifndef WELCOME_SCENE_H
#define WELCOME_SCENE_H

#include "CommonDefine.h"

class WelcomeScene :public Scene
{
public:
    CREATE_FUNC(WelcomeScene);
    virtual ~WelcomeScene();
protected:
    virtual bool init();
    virtual void onEnter()override;
    virtual void showMenu();

	/**
	* @brief ��Ƶ������ɵĻص�����
	*/
	void videoPlayOverCallback();
	/**
	* @brief ��Ƶ��ʾ����
	*/
	void showVideo();
	/**
	* @brief ��Ƶ����״̬��ֻ����android��iosƽ̨��Ч
	*/
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)  
	void videoEventCallback(Ref* sender, cocos2d::experimental::ui::VideoPlayer::EventType eventType);
#endif 
private:
    Layer * _pSpritesLayer = nullptr;
    Layer *_pMenuLayer = nullptr;
};

#endif // !WELCOME_SCENE_H
