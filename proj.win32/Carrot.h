#pragma once
#ifndef __CarrotFantasy__Carrot__
#define __CarrotFantasy__Carrot__

#include "Entity.h"

class Carrot :public Entity
{

public:

	CREATE_FUNC(Carrot);

	virtual Rect getBoundingBox()const;

	virtual ~Carrot();

protected:

	virtual bool init();
	/**
	* @brief ҡ�ζ�����գ�۶���
	* @param iImageFirstNumber ����ͼƬ
	* @param iImageCount ͼƬ��
	*/
	ActionInterval * doShakeOrBlink(int iImageFirstNumber, int iImageCount);
	/*
	* @brief ��������
	*/
	virtual void doAction(float t);
	/*
	* @brief �ܲ�������
	*/
	virtual void CarrotBeHurt(Ref * pRef);
	/*
	* @brief ע����ܲ������¼�
	*/
	virtual void registerCarrotTouchEvent();
	/*
	* @brief ��������ֵ
	*/
	Sprite * _HpSprite;

	CC_SYNTHESIZE_PASS_BY_REF(int, iHp, IHP);

};

#endif /* defined(__CarrotFantasy__Carrot__) */