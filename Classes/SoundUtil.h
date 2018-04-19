/** @Copyright   �����ܲ�
*   @author      �½���
*   @date        2018/3/2
*   @brief       ����������
*/
#pragma once
#ifndef SOUND_UTIL_H
#define SOUND_UTIL_H
#include "CommonDefine.h"
class SoundUtil : public Ref
{
public:
    //����ģʽ������
    CREATE_INSTANCE_FUNCTION(SoundUtil);

    DESTROY_INSTANCE_FUNCTION();

    /**
    @brief ���ű�������
    @param bgSound ��������·��
    */
    void playBackgroundSound(const std::string &bgSound);

    /**
    @brief ������Ч����
    @param efSound ��Ч����·��
    */
    void playEffectSound(const std::string &efSound);

    /**
    @brief ���á���ȡ���������Ƿ��
    */
    bool getIsBackgroundSoundOpen() { return _bIsBackgroundSoundOpen; }
    void setIsBackgroundSoundOpen(const bool &_bIsOpen)
    {
        _bIsBackgroundSoundOpen = _bIsOpen;
        _bIsOpen ? playBackgroundSound(BACKGROUNDSOUND) : stopBackgroundSound(); //�ٴε��ò��Žӿ�
    }

    /**
    @brief ���á���ȡ��Ч�����Ƿ��
    */
    bool getIsEffectSoundOpen() { return _bIsEffectSoundOpen; }
    void setIsEffectSoundOpen(const bool& _bIsOpen) { _bIsEffectSoundOpen = _bIsOpen; }

    /**
    @brief ֹͣ���ű�������
    */
    void stopBackgroundSound();

protected:
    bool init()
    {
        return true;
    }

protected:
    std::string formerBgMusic = ""; //֮ǰ�ı�������

    bool _bIsBackgroundSoundOpen;  //���������Ƿ��
    bool _bIsEffectSoundOpen;  //��Ч��Ч�Ƿ��
    bool _bIsBackgroundSoundPlaying; //���������Ƿ����ڲ����У������龰�л��ᵼ���ظ���ͷ����
};
#endif //SOUND_UTIL_H