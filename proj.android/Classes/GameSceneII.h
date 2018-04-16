/**
 * @brief ��Ϸ���� II
 * @details �����ó�������ʱ���ȡ��
 * @author �½���
 * */

#ifndef GAMESCENEII_H
#define GAMESCENEII_H

#include "SceneBase.h"

class EntityLayerBase;

class Carrot;

class GameSceneII : public SceneBase
{
public:

    CREATE_FUNC(GameSceneII);

    ~GameSceneII() override;

    //virtual Carrot* getCarrot();

    //virtual void clickChooseItem();
protected:

    bool init() override;

    virtual void createLayers();

    virtual void addLayers();

    void onEnter() override;

    void onExit() override;

    virtual void preLoadSource();

    virtual void unLoadSource();

    //virtual void collisionUpDate(float dt);

    virtual void createBarriers();

    virtual void clearAllManager();

    virtual void registerGameEvent();

    //virtual void showGameEndLayer(Ref *pData);

    virtual void startBuildMonster(Ref *pData);

private:

    /**
    *  gamescene�����߸�ͼ�㣺tiledMapLayer��barrierLayer��BulletsLayer��MonsterLayer��TowersLayer��ScoreAndControllerLayer��OptLayer
    */

    std::vector<std::string> *_pSourceVec = nullptr; //������Դ��֯��һ������

    Layer *_pTiledMapLayer = nullptr; //��ͼͼ��

    EntityLayerBase *_pBarriersLayer = nullptr; //�ϰ���ͼ��

    EntityLayerBase *_pBulletsLayer = nullptr;  //�ӵ�ͼ��

    EntityLayerBase *_pMonsterLayer = nullptr; //����ͼ��

    EntityLayerBase *_pTowersLayer = nullptr; //����ͼ��

    Layer *_pScoreAndControllerLayer = nullptr; //�����Ϳ�����ͼ��

    Layer *_pOptLayer = nullptr; //����ͼ��?

    Carrot *_pCarrot = nullptr; //�ܲ�

    int _iSourceCount = 0; //TODO ����θĽ���
};

#endif //GAMESCENEII_H
