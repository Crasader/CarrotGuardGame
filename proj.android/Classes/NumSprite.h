/**
 * @brief ���־���
 * @authors ���������½���
 * */
#pragma once
#ifndef __CarrotFantasy__NumSprite__
#define __CarrotFantasy__NumSprite__

#include "CommonDefine.h"

class NumSprite
{
public:
	/**
	 * @brief ��̬���������ڴ������־���
	 * @param rsNum ����Ҫ�ĸ����ֵľ��飬��ʹ��Ǹ����ֽ�ȥ(���ִ�Ҳ��Ŷ��
	 * @param rsImage ���ĸ�ͼ������и�
	 * @author ������
	 */
	static Node *createNum(const std::string &rSNum, const std::string &rSImage);

	/**
	 * @brief ��̬���������ڴ���б�ܾ���
	 * @details ��һЩ������Ҫ�õ�б�ܣ�������������������������������ڴ���б�ܾ���
	 * @param rsImage ���ĸ�ͼ������и�
	 * @author �½���
	 */
	static Sprite *createSprit(const std::string &rsImage);
};

#endif /* defined(__CarrotFantasy__NumSprite__) */