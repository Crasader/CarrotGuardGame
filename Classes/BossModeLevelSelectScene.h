#pragma once
/**
 * @brief Bossģʽѡ�񳡾�
 * @author �½���
 * @date 20180419
 */

#ifndef BOSSMODE_LEVELSELECT_SCENE_H
#define BOSSMODE_LEVELSELECT_SCENE_H

#include "CommonDefine.h"

class BossModeLevelSelectScene : public Scene
{
public:
    CREATE_FUNC(BossModeLevelSelectScene);

    ~BossModeLevelSelectScene()override;

protected:
    bool init()override;

    void onEnter()override;

private:
    Layer * _pBMLevelSelectLayer = nullptr;
};
#endif //BOSSMODE_LEVELSELECT_SCENE_H
