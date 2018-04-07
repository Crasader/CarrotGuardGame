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

#include "CommonDefine.h"
#include "cocos2d.h"

class Entity :public Node
{
public:
	/*
	*@ ��������
	*@ author ������
	*/
	virtual ~Entity();

public:
	static unsigned long ID;
	/*
	* @��ȡmID��
	* @brief mIDΪ��ʽ�鿴initʵ���Ƿ����óɹ���
	*/
	unsigned int getmID();
	/*
	* @brief ����initʵ�����Բ������Ƿ����óɹ���
	* @return true ���óɹ�����������ʧ�ܣ�
	*/
	virtual bool init(const int &rId, const std::string &rSCsvFileName);
	/*
	* @brief ��ȡԭͼ��С��
	*/
	virtual const Size &getContentSize()const;
	/*
	*@brief ʵ���Ѿ���������Ҫִ�еĺ���
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
	*  @brief ��ȡ����Ĵ�С��Դ
	*  @see �����С�������
	*  @return Rect ���õľ���
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
	*  @brief ʵ�� id
	*/
	CC_SYNTHESIZE_PASS_BY_REF(int, _iId, IId);
	/*
	*  @brief ʵ����
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
	*  Entity �ȼ�
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
