//
//  CountDownLayer.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-13.
//  û���������Ͽ�
//
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

	virtual void registerNoTouch();

private:
	int i = 0;
	Sprite * countDownSprite;
    Sprite* effPosSprites = nullptr;
    Sequence* _pFadeSequence = nullptr;


	void Num1(float t);
	void Num2(float t);
	void Num3(float t);
	void GameGo(float t);
	void Circle();
	void runArrow1(float t);
	void runArrow2(float t);
	void runArrow3(float t);
	void clearArrow(float t);
	void childDisappear(float t);

    void initEffectPosBlink();
    void effectPosBlink(float t);
};
#endif/* defined(__CarrotFantasy__CountDownLayer__)*/