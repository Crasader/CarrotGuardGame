#pragma once
//
//  DynamicPropertyInterFace.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-7.
//  @details ��̬���Խ���
//

#ifndef __CarrotFantasy__DynamicPropertyInterFace__
#define __CarrotFantasy__DynamicPropertyInterFace__

#include "CommonDefine.h"

class DynamicPropertyInterFace
{
public:

	virtual ~DynamicPropertyInterFace();

protected:
	/*
	* @brief ������̬ʵ�嶯��
	*/
	virtual void createDynamicEntityAnimation(const std::vector<std::string> &rAnimationFiles);
	/*
	* @brief ��ȡ���������ٶ�
	* @return true ��ȡ�ɹ������򷵻�false
	*/
	virtual bool init(const int &rId, const std::string &rSCsvFileName);
	/*
	* @brief �ƶ�����
	*/
	virtual void doAction(const float &rDt) = 0;
	/*
	* @brief ��̬ʵ���ٶ�
	*/
	CC_SYNTHESIZE_PASS_BY_REF(unsigned int, _iSpeed, ISpeed);
	/*
	* @brief �ӵ�������
	*/
	CC_SYNTHESIZE_PASS_BY_REF(int, _iAtk, IAtk);

protected:

	Animation * _pAnimation = nullptr;

};

#endif /* defined(__CarrotFantasy__DynamicEntityBase__) */
