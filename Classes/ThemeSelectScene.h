/**
 * @brief ѡ������ҳ��
 * @authors ������
 * @co_author �½���
 * */
#pragma once
#ifndef PAGESELECT_SCENE_H
#define PAGESELECT_SCENE_H

#include "CommonDefine.h"


class PageSelectScene : public Scene
{
public:

	CREATE_FUNC(PageSelectScene);

	~PageSelectScene()override;

protected:

	/**
	 * @brief ��ʼ������
	 * */
	bool init() override;

	/**
	 * @brief
	 * */
	void onEnter() override;

private:

	Layer *_pPageViewLayer = nullptr; //����鿴ͼ�㣬Ҳ�����м��ǿ�

	Layer *_pMenuPanelLayer = nullptr; //�˵����ͼ�㣬Ҳ���Ƕ����ǿ�

	Layer *_pPageTurningLayer = nullptr; //ҳ��ת��ͼ�㣻

};

#endif //PAGESELECT_SCENE_H
