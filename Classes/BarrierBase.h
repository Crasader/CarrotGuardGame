/**
 * @brief �ϰ������
 * @details ˵���ǻ��࣬��ʵ���Ѿ���װ���ϰ���һ�еĹ�����
 * @author ������
 * @co_author �½���
 * @date 20180408
 * */
#pragma once
#ifndef __CarrotFantasy__BarrierBase__
#define __CarrotFantasy__BarrierBase__


#include "VictimEntityBase.h"

class BarrierBase :public VictimEntityBase
{

public:

	/**
	 * @brief ��̬���������������ϰ������
	 * @method ���ģʽ�еĹ���ģʽ
	 * */
	static BarrierBase * create(const int &rId);

	/**
	 * @brief ����һ����Ԫ���ϰ��﹤��
	 * @details �Ͼ��ϰ��﹤�����������ϰ���������ϰ���������໥����ģ����߻�Ϊ��Ԫ
	 * @todo Ϊ�˴��밲ȫ�����Բ�����Ԫ
	 * */
	friend class BarrierFactory;

protected:
	/**
	 * @brief ��ʼ������
	 * @details ���ڸ�����ID����ʼ��ʵ��
	 * @param rId �ϰ���ID
	 * @details ���������create�������ã����ڹ���ģʽ���������еĳ�ʼ���׶δ�����
	 * */
	virtual bool init(const int &rId);

	/**
	 * @brief ��������
	 * @extends VictimEntityBase
	 * @details ���ݸ������ļ�·����������������������һЩ�������
	 * @details ʵ���������û���Լ�ʵ�����������������������ø����Ĭ����������
	 * @param rSDeadImageFile ��������֡·��
	 * */
	virtual void deadAction(const std::string &rSDeadImageFile = "");
};

#endif /* defined(__CarrotFantasy__BarrierBase__) */
