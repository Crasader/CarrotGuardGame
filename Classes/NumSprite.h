//
//  NumSprite.h
//  CarrotFantasy
//
//  Created by ������ on 18-3-30.
//
//
#pragma once
#ifndef __CarrotFantasy__NumSprite__
#define __CarrotFantasy__NumSprite__

#include "CommonDefine.h"

class NumSprite
{
public:
	/*
	*@brief ��̬���������ڴ������־���
	*@param rsNum ����Ҫ�ĸ����ֵľ��飬��ʹ��Ǹ����ֽ�ȥ(���ִ�Ҳ��Ŷ��
	*@param rsImage ���ĸ�ͼ������и�
	*@author ������
	*/
	static Node *createNum(const std::string &rSNum, const std::string &rSImage);
};

#endif /* defined(__CarrotFantasy__NumSprite__) */