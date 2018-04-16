/**
 * @brief ������������
 * @extends TowerBase
 * @details ������Ͳ��������ת�����з���������
 *
 * @authors �½��� x ������
 * @date 20180412
 * */

#pragma once
#ifndef __CarrotFantasy__TowerBall__
#define __CarrotFantasy__TowerBall__

#include "TowerBase.h"

class TowerBall : public TowerBase
{
protected:
    /**
      * @brief ��д��ʼ������
      * @extends TowerBase
      * @details ��д����ΪҪע����ת��������������û����תЧ��
      * */
    virtual bool init();

    /**
      * @brief ��д��ȡ����Ŀ�꺯��
      * @details ��Ϊ������һ��ȡ��Ŀ��������������������ķ����������ã���Ҫ��д
      * @see ������Ͳ����һ��Ҫ��д
      */
    void chooseAtkTarget();

    /**
     * @brief ��д����Ĺ�������
     * @details ������û���ӵ���������ĺ����ǵ����ӵ��࣬�������ķ����������ã���Ҫ��д
     * @details ������ľ�����Ϸ�߼�д������
     * @see �������޵����˶���������ʵ�֣���Ϊ����������޻��ฺ��Ļ�Ҫһ�����ж��ӵ����ͣ���ʵ�Ӵ��˹���ǿ�ȣ��������ֺ�
     */
    void fire(float dt);

    /**
     * @brief ʧȥ����Ŀ��
     * @todo ���д�ĺû��Ǹ���д�úã�ֵ����ȶ
     */
    void missAtkTarget();

    const int rId = 10;
    //�������飻
    Sprite *_doActionSprite;

public:

    CREATE_FUNC(TowerBall);

};

#endif/* defined (__CarrotFantasy__TowerBall__)*/
