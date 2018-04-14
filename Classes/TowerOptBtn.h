//
//  TowerOptBtn.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-13.
//  �е��£�ע�Ϳ��ܴ�������
//
#pragma once
#ifndef __CarrotFantasy__TowerOptBtn__
#define __CarrotFantasy__TowerOptBtn__

#include "cocos2d.h"
class TowerBase;
using namespace cocos2d;

class TowerOptBtn : public Node
{
public:

	CREATE_FUNC(TowerOptBtn);

	TowerOptBtn();

	virtual ~TowerOptBtn();
	/**
	* @brief ��������ѡ��
	*/
	virtual void hideTowerOpt();
	/**
	* @brief ��ʾ����ѡ��
	*/
	virtual void showTowerOpt();
	/**
	* @brief ����ҵ����ú���
	*/
	virtual void setFuncCheckMoney(const std::function<int()> &rFuncCheckMoney);
	/**
	* @brief �������Ĳ˵���
	* @details ����յ�ʱ��ʾ�Ĳ˵�
	* @see ��ʾ������������ͼ��
	*/
	virtual void createTowerMenu();
	/**
	* @brief �������չʾ�Ĳ˵�
	* @details ����������ť������������İ�ť
	*/
	virtual void gradeTowerMenu(TowerBase* touchTower);
	/**
	* @brief չʾ�����˵�
	* @details �����˵���λ��ѡ��
	* @see ����������ѧ����
	*/
	virtual void showCreateMenu();
	/**
	* @brief ���ش����˵�
	*/
	virtual void hideCreateMenu();
protected:
	/**
	* @brief 
	* @details ��ʱ����ر仯����
	*/
	virtual bool init();
	/**
	* @brief ������������Ժ�Ķ�����ʾ
	*/
	virtual void createMenuAndItems();
	/**
	* @brief ��̫�����ڸ���
	*/
	virtual void ChangingItem(float dt);

protected:
	bool _bKeySpVisible;
	Sprite* _pKeySp;
	Menu* _pCreateMenu1;
	Menu* _pCreateMenu2;
	Menu* _pGradeMenu;
	Sprite* _pTowerRangeSp;

	std::function<int()> _funcCheckMoney;

	Vector<MenuItemSprite *> *_pCreateTowerItemSpVec = nullptr;
	Vector<MenuItemSprite *> *_pGradeTowerItemSpVec = nullptr;
};


#endif /* defined(__CarrotFantasy__TowerOptBtn__) */