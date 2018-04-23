/**
* @brief ��Ϸ��ʼǰ�ľ���ͼ����
* @details ���õ���ʱ���������﷽��꾫�鶯�����ɽ��������յ���ʾ����
* @authors ������
* @date 20180413
* */
#ifndef __CarrotFantasy__CountDownLayer__
#define __CarrotFantasy__CountDownLayer__
#pragma once
#include "cocos2d.h"
using namespace cocos2d;
class  CountDownLayer :public Layer
{
public:
	virtual bool init();

	CREATE_FUNC(CountDownLayer);

protected:
	/**
	* @brief ע�ᴥ����Ч
	* @details ���óɱ�������
	* @see ����ʱ��ʼʱ������Ч
	*/
	virtual void registerNoTouch();

private:
	int i = 0;
	Sprite * countDownSprite;
    Sprite* effPosSprites = nullptr;
    Sequence* _pFadeSequence = nullptr;

	/**
	* @brief ����ʱ��ʼ��Ϸ
	*/
	void Num1(float t);//3
	void Num2(float t);//2
	void Num3(float t);//1
	void GameGo(float t);//��ʼ
	/**
	* @brief ��ʼ��Ϸ����Ч
	* @details ѭ��ת������
	*/
	void Circle();
	/**
	* @brief ���������ʼ���������ɫָʾ�귽��ľ���
	*/
	void runArrow1(float t);
	void runArrow2(float t);
	void runArrow3(float t);


	//void clearArrow(float t);
	/**
	* @brief ������ӽ��
	* @details ����֪ͨ���ԷŹ�����
	*/
	void childDisappear(float t);
	/**
	* @brief ��ʼ���ɽ��������յص���˸Ч����Ч����
	*/
    void initEffectPosBlink();
	/**
	* @brief ��װ
	*/
    void effectPosBlink(float t);
};
#endif/* defined(__CarrotFantasy__CountDownLayer__)*/