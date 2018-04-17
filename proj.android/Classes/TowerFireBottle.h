/**
 * @brief ������Ͳ������
 * @extends TowerBase
 * @details ������Ͳ������ת��������߹��ܣ�һ������ĳ�������Χ�Ĺ���Ҳ���յ�����
 *
 * @authors �½��� x ������
 * @date 20180412
 * */

#pragma once
#ifndef __CarrotFantasy__TowerFireBottle__
#define __CarrotFantasy__TowerFireBottle__
#include "TowerBase.h"

class TowerFireBottle :public TowerBase {
protected:
	/**
	* @brief ��д��ʼ������
	* @see �����������鲢��������
	*/
	virtual bool init();

	/**
	 * @brief ��д��ȡ����Ŀ�꺯��
	 * @details ��Ϊ������Ͳһ��ȡ��Ŀ��������������������ķ����������ã���Ҫ��д
	 */
	void  chooseAtkTarget();

	/**
	 * @brief ʧȥ����Ŀ��
	 * @todo �븸��ûʲô���𣬿���ȥ����
	 */
	void missAtkTarget();

	/**
	 * @brief ��д����Ĺ�������
	 * @details ������Ͳû���ӵ���������ĺ����ǵ����ӵ��࣬�������ķ����������ã���Ҫ��д
	 * @details ������ľ�����Ϸ�߼�д������
	 * @see �������޵����˶���������ʵ�֣���Ϊ����������޻��ฺ��Ļ�Ҫһ�����ж��ӵ����ͣ���ʵ�Ӵ��˹���ǿ�ȣ��������ֺ�
	 */
	void fire(float dt);

	const int rId = 16;
	//�������飻
	Sprite * _doActionSprite;

public:

	CREATE_FUNC(TowerFireBottle);

};
#endif/* defined(__CarrotFantasy__TowerFireBottle__)*/