//
//  LevelSelectScene.h
//  newCardDefence
//
//  Created by ������ on 18-3-30.
//
//
#pragma once
#ifndef __newCardDefence__PageSelectScene__
#define __newCardDefence__PageSelectScene__

#include "CommonDefine.h"


class PageSelectScene : public Scene
{
public:

	CREATE_FUNC(PageSelectScene);

	virtual ~PageSelectScene();

protected:

	virtual bool init();

	virtual void onEnter()override;

private:

	Layer *_pPageViewLayer = nullptr;//ҳ��鿴ͼ�㣻

	Layer *_pMenuPanelLayer = nullptr;//�˵����ͼ�㣻

	Layer *_pPageTurningLayer = nullptr;//ҳ��ת��ͼ�㣻

};

#endif /* defined(__newCardDefence__LevelSelectScene__) */
