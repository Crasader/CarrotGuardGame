#include "SoundUtil.h"
#include "SimpleAudioEngine.h"

void SoundUtil::playBackgroundSound(const std::string & bgSound)
{
    if (!_bIsBackgroundSoundOpen)
        return; //����������ֿ���û�д򿪣�������

    //����SimpleAudioEngine�������֣�����Ϊѭ������
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic(bgSound.c_str(), true);
}

void SoundUtil::playEffectSound(const std::string &efSound)
{
    if (!_bIsEffectSoundOpen)
        return; //�����Ч����û�д򿪣�������

    //����SimpleAudioEngine�������֣���ѭ������
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(efSound.c_str());
}

void SoundUtil::stopBackgroundSound()
{
    CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
}

