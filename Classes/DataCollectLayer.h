/**
* @brief �ɾͻ���ͼ����
* @details �ɾ���ʾ��ͼ��ͼ��
* @authors ������
* @date 20180408
* */
#pragma once
#ifndef __CarrotFantasy__DataCollectLayer__
#define __CarrotFantasy__DataCollectLayer__

#include "cocos2d.h"

using namespace cocos2d;

class DataCollectLayer : public Layer
{
public:

	CREATE_FUNC(DataCollectLayer);

protected:
	/*
	* @brief �ɾͻ���ͼ�����
	*/
	virtual bool init();
	/*
	* @brief �ֹ󣬳ɾͻ���ͼ���㿴��������𼸸����ﰡ
	*/
	virtual void loadSource();

};

#endif /* defined(__CarrotFantasy__DataCollectLayer__) */