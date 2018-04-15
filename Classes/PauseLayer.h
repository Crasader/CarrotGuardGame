//
//  PauseLayer.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-13.
//
//
#pragma once
#ifndef __CarrotFantasy__PauseLayer__
#define __CarrotFantasy__PauseLayer__

#include "CommonDefine.h"

class PauseLayer :public Layer
{
public:

	CREATE_FUNC(PauseLayer);
	/**
	* @brief ��ͣͼ��(�ر�)
	*/
	virtual void setFuncFlagPauseLayerIsClose(const std::function<void()> & rFuncFlagPauseLayerIsClose);

protected:
	/**
	* @brief ȷ��ͼ�����init
	* @details ������ɫͼ�㣬�����˵��ͷ���˵����رմ����¼�
	*/
	virtual bool init();
	/**
	* @brief ����ͣ
	*/
	virtual void onEnter()override;
	/**
	* @brief �м���
	*/
	virtual void onExit()override;
	/**
	* @brief �����˵���
	* @details ������Ϸ�����¿�ʼ���˳���Ϸ
	*/
	virtual void createMenu();
	/**
	* @brief ��������˵�
	*/
	virtual void createSharedMenu();
	/**
	* @brief �رմ����¼�
	*/
	virtual void closeTouchEvent();

	std::function<void()> _funcFlagPauseLayerIsClose;
};

#endif /* defined(__CarrotFantasy__PauseLayer__) */