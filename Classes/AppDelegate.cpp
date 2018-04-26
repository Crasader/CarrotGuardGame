//
//  AppDelegate.cpp
//  CarrotFantasy
//
//  Created by �½��� on 18-4-8.
//
//  
#include "AppDelegate.h"
#include "SceneManager.h"
#include "CsvUtil.h"
#include "Config.h"
#include "GameSceneII.h"
#include "SoundUtil.h"
USING_NS_CC;

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate()
{
    SceneManager::destroyInstance();
    Config::getInstance()->saveSoundConfig(); //�����������ã����ùܹؿ�����
    Config::destroyInstance();
    SoundUtil::destroyInstance();
    unLoadSource();
}

void AppDelegate::initGLContextAttrs() //bug fixed
{
    // set OpenGL context attributes: red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8 };

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if (!glview)
    {
        glview = GLViewImpl::create("Carrot Fantasy 1.0 Alpha Created By Chen Jianzhang & He Hongbing");
        director->setOpenGLView(glview);
    }
    glview->setDesignResolutionSize(960, 640, ResolutionPolicy::EXACT_FIT);


    // turn on display FPS
    //    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
    preLoadSource();
    Config::getInstance()->setSoundConfig();

    SceneManager::getInstance()->initWelcomeScene();

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
    auto pCurScene = Director::getInstance()->getRunningScene();
    if ((pCurScene != NULL) && pCurScene->getName() == "GameScene")
    {
        auto pGameScene = dynamic_cast<GameSceneII*>(pCurScene); //TODO ��ʱ�����
        if (!pGameScene->getChildByName("CoundDown") && !pGameScene->getChildByName("GameEnd"))
            dynamic_cast<GameSceneII*>(pCurScene)->clickChooseItem(); //����ѡ��˵�
    }
    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

void AppDelegate::preLoadSource()
{
    //�ȼ��ػ�ӭ�������Դ
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Themes/scene/mainscene1-hd.plist", "Themes/scene/mainscene1-hd.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Themes/scene/mainscene0-hd.plist", "Themes/scene/mainscene0-hd.png");
    //    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Themes/scene/themescene1-hd.plist", "Themes/scene/themescene1-hd.png");
    //    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Themes/Items/Items00-hd.plist", "Themes/Items/Items00-hd.png");
    
    //����һ������ļ�
    auto pCsvUtil = CsvUtil::getInstance();
    pCsvUtil->addFileData(BARRIERCSVFILE);
    pCsvUtil->addFileData(TOWERCSVFILE);
    pCsvUtil->addFileData(MONSTERCSVFILE);
    pCsvUtil->addFileData(BULLETCSVFILE);
    pCsvUtil->addFileData(LEVELCSVFILE);
    pCsvUtil->addFileData(BOSSCSVFILE);
}


void AppDelegate::unLoadSource()
{
    SpriteFrameCache::getInstance()->removeSpriteFrames();
    CsvUtil::destroyInstance();
}






