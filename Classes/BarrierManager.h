/**
 * @brief �ϰ��������
 * @details ������Ϸ�����е��ϰ������ע�ᡢȥ���ȵȲ���
 * @authors ������ x �½���
 * @date 20180408
 * */
#pragma once
#ifndef __CarrotFantasy__BarrierManager__
#define __CarrotFantasy__BarrierManager__

#include "CommonDefine.h"

class Entity;

class BarrierManager : public Ref
{
public:
	/**
	 * @brief ��������
	 * @details ���ģʽ�еĵ���ģʽ
	 * @see ��Դ��cocos�ĺ�
	 */
	CREATE_INSTANCE_FUNCTION(BarrierManager);

	DESTROY_INSTANCE_FUNCTION();

	/**
     * @brief ��ȡ�ϰ�������
     * @return �ϰ�������������
	 */
	BarrierVec &getBarrierVec();

	/**
	 * @brief ������������ϰ��ﵽͼ��Ĵ�����
	 * @param rFuncAddBarrierToLayer ��������ϰ��ﵽͼ��ĺ���
	 */
	virtual void setFuncAddBarrierToLayer(const std::function<void(Entity*)> &rFuncAddBarrierToLayer);

	/**
	 * @brief ��������������״̬
	 */
	virtual void clearBeAtkLockState();

	/**
	 * @brief �������
	 */
	virtual void clearManage();

protected:

	/**
	 * @brief ����һ����Ԫ���ϰ������
	 * */

	friend class BarrierBase;

	/**
	 * @brief ���(ע��)�ϰ���
	 * @param pBarrier Ҫע����ϰ������
	 */
	virtual void addBarrier(BarrierBase *pBarrier);

	/**
	 * @brief ��ʼ������
	 * @return true ��ʼ���ɹ������򷵻�false
	 */
	virtual bool init();

	/**
	 * @brief ע���ϰ��ﱻ�ɵ��¼�
	 */
	virtual void registerBarrierDeadEvent();

	/**
	 * @brief ��manager��ɾȥָ�����ϰ���
	 */
	virtual void removeBarrierFromManager(Ref *pBarrier);

private:
	//����vector��
	BarrierVec *_pBarrierVec = nullptr; //�����ϰ����õ�����

	std::function<void(Entity*)> _funcAddBarrierToLayer;

private:

	BarrierManager();

	virtual ~BarrierManager();

	BarrierManager(const BarrierManager &) = delete;

	BarrierManager &operator=(const BarrierManager &) = delete;
};

#endif /* defined(__CarrotFantasy__BarrierManager__) */