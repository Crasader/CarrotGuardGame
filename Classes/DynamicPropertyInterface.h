/**
 * @brief ��̬ʵ�幫������
 * @details ��Ϸ���������ƶ���ʵ�嶼Ҫ���ɸ��࣬��������ɶ�̬��һЩ����
 * @authors ������ x �½���
 * @version 0.90 Beta
 * */

#pragma once
#ifndef __CarrotFantasy__DynamicPropertyInterface__
#define __CarrotFantasy__DynamicPropertyInterface__

#include "CommonDefine.h"

class DynamicPropertyInterface
{
public:

	virtual ~DynamicPropertyInterface();

protected:
	/**
	 * @brief ������̬ʵ����˶�����
	 * @param rAnimationFiles �˶���������֡��·������
	 */
	virtual void createDynamicEntityAnimation(const std::vector<std::string> &rAnimationFiles);

	/**
	 * @brief ��ʼ������
	 * @details ��Id��CSV����ļ�����ʼ����ʵ�������ʼ���ٶȡ�������
	 * @param rId ʵ��Id��ʵ�����Ƕ�Ӧ����ĳһ��
	 * @param rSCsvFileName ���ڶ�ȡ���ݵ�CSV����ļ�
	 * @return true ��ʼ���ɹ������򷵻�false
	 */
	virtual bool init(const int &rId, const std::string &rSCsvFileName);

	/**
	 * @brief �ƶ�����
	 * @details ?�麯����������붨�������Լ����ƶ�����
	 * @param rDt ���Ⱥ�����Ҫ��һ������
	 */
	virtual void doAction(const float &rDt) = 0;

	/**
	 * @brief ��̬ʵ���ٶ�
	 */
	CC_SYNTHESIZE_PASS_BY_REF(unsigned int, _iSpeed, ISpeed);
	/**
	 * @brief �˺�ֵ
	 */
	CC_SYNTHESIZE_PASS_BY_REF(int, _iAtk, IAtk);

protected:

	Animation * _pAnimation = nullptr;

};

#endif /* defined(__CarrotFantasy__DynamicEntityBase__) */
