/**
 * @brief ������Ͳ������
 * @extends TowerBase
 * @details ������Ͳ������ת�����з��䶾ҩ���ܣ����Ҷ�ҩ���Գ���һ��ʱ��
 * @authors �½��� x ������
 * @date 20180412
 * */
#pragma once 
#include "TowerBase.h"
class TowerPin :public TowerBase
{
protected:
	int const rId = 28;
	/**
	* @brief ����Ĺ���Ч��
	*/
	void fire(float dt);
	/**
	* @brief ȷ�����Ļ���init����ʵ��
	*/
	virtual bool init();
public:

	CREATE_FUNC(TowerPin);
};
