/**
* @brief ��Ϸ�С��������ǡ��������������ʾ��
* @authors ������
* @date 20180408
* */
#pragma once
#ifndef __CarrotFantasy__DesignLayer__
#define __CarrotFantasy__DesignLayer__

#include "cocos2d.h"

using namespace cocos2d;

class DesignLayer : public Layer
{
public:

	CREATE_FUNC(DesignLayer);

protected:
	/*
	* @brie �����ʾ���ߵ�ͼ��
	*/
	virtual bool init();
	/*
	* @brief ��ʾ���ߵ�ͼ��
	*/
	virtual void loadSource();

};

#endif /* defined(__CarrotFantasy__DesignLayer__) */
