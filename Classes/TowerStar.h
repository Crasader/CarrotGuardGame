/**
 * @brief ��ͨ����������
 * @extends TowerBase
 * @details ��ͨ���ǲ�������תЧ�������и���������Χ����Ч��
 * @authors �½��� x ������
 * @date 20180412
 * */
#pragma once
#ifndef __CarrotFantasy__TowerStar__
#define __CarrotFantasy__TowerStar__
#include "TowerBase.h"
class TowerStar :public TowerBase {

	int const rId = 13;
	/**
	 * @brief ��д����ĳ�ʼ������
	 * @details Ҫע����ת��������
	 * @see ��ʱ����ػ�ת
	 */
	virtual bool init();
	/**
	 * @brief ��д����Ŀ�����
	 * @details ���������������ӵ������Թ����߼������ӵ���ʵ�֣��������Ҫд�����attack()������ʵ�ֹ����߼�
	 */
	virtual void fire(float dt);

public:

	CREATE_FUNC(TowerStar);
};
#endif /* defined(__CarrotFantasy__TowerStar__) */