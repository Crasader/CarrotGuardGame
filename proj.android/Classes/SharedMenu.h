//
//  SharedMenu.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-13.
//
//
#pragma once
#ifndef __CarrotFantasy__SharedMenu__
#define __CarrotFantasy__SharedMenu__

#include "cocos2d.h"
using namespace cocos2d;

class SharedMenu : public Node
{
public:

	CREATE_FUNC(SharedMenu);

protected:
	/**
	* @brief ȷ�ϴ����˵���
	*/
	virtual bool init();
	/**
	* @brief ��������˵���
	* @details ���������ˡ�΢����΢��
	*/
	virtual void createMenu();
};

#endif /* defined(__CarrotFantasy__SharedMenu__) */