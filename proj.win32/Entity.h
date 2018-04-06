#pragma once
//
//  Entity.h
//  newCardDefence
//
//  Created by ������ on 18-4-6
//
//

#ifndef __newCardDefence__Entity__
#define __newCardDefence__Entity__

#include "PublicDefine.h"

class Entity :public Node
{
public:
	/*
	*@ ��������
	*/
	virtual ~Entity();

public:
	static unsigned long ID;
	/*
	* @��ȡmID��
	*/
	unsigned int getmID();

	virtual bool init(const int &rId, const std::string &rSCsvFileName);
	/*
	* @brief ��ȡԭͼ��С��
	*/
	virtual const Size &getContentSize()const;
	/*
	*@brief ���м����ĸ�ʵ���Ѿ�����
	*/
	virtual void doDead()final;


	/*
	*  
	*  @brief ÿ��ʵ����Ҫ��һ��Sprite��������ʾ��
	*  @param pSprite ��һ���󶨾��飻
	*/
	virtual void bindSprite(Sprite *pSprite);
	/*
	* @brief ��ȡ�󶨾��飻
	*/
	virtual Sprite *getSprite();

	/*
	*  @brief ��ȡ����Ĵ�С��Դ��
	*  @return Rect �����С������ϣ�
	*/
	virtual Rect getBoundingBox()const;

protected:
	/*
	*  @brief ����������
	*  @param rSDeadImageFile ��������ͼƬ�ļ��ַ�����
	*/
	virtual void deadAction(const std::string &rSDeadImageFile = "");

	/*
	* @brief initʵ������
	* @param rId
	* @param rSCsvFileName csv�ļ���
	* @return: ��
	*/
	virtual void initProperty(const int &rId, const std::string &rSCsvFileName);
	/*
	*  @brief Entity id
	*/
	CC_SYNTHESIZE_PASS_BY_REF(int, _iId, IId);
	/*
	*  @brief Entity name
	*/
	CC_SYNTHESIZE_PASS_BY_REF(std::string, _sName, SName);
	/*
	*  @brief ʵ��󶨾���ģ��ͼ���ļ�����
	*/
	CC_SYNTHESIZE_PASS_BY_REF(std::string, _sModelName, SModelName);
	/*
	*  Entity values
	*/
	CC_SYNTHESIZE_PASS_BY_REF(int, _iValue, IValue);
	/*
	*  flag Entity is dead
	*/
	CC_SYNTHESIZE_PASS_BY_REF(bool, _bIsDead, IsDead);
	/**
	*  @brief ����֡��
	*/
	CC_SYNTHESIZE_PASS_BY_REF(int, _IAnimationFrameCount, AnimationFrameCount);
	/**
	*  Entity level
	*/
	CC_SYNTHESIZE_PASS_BY_REF(int, _iLevel, ILevel);
private:
	/**
	*  @brief ͼƬ���飬ʹ�ð󶨾��鲢��þ���
	*/
	Sprite *_pSprite = nullptr;

	unsigned long _myID;

};

#endif /* defined(__newCardDefence__Entity__) */
