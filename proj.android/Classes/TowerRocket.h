/**
 * @brief ���������
 * @extends TowerBase
 * @details �������������ת��������ֱ�ߴ�͸�͹���
 *
 * @authors �½��� x ������
 * @date 20180412
 * */
#pragma once
#ifndef __CarrotFantasy__TowerRocket__
#define __CarrotFantasy__TowerRocket__
#include "TowerBase.h"
class TowerRocket :public TowerBase {

	int const rId = 25;

	/**
     * @brief ��д��ʼ������
     * @extends TowerBase
     * @todo ��ʵû�б�Ҫд��
     * */
	virtual bool init();

	/**
     * @brief ��д����Ĺ�������
     * @details ������ľ�����Ϸ�߼�д������
     * @todo ��������ӵ��ģ��о�û�б�Ҫд��
     */
	virtual void fire(float dt);

public:

	CREATE_FUNC(TowerRocket);
};
#endif /* defined(__CarrotFantasy__TowerRocket__) */