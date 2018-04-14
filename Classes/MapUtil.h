/**
 * @brief ��Ϸ������ͼ������
 * @details ��Ϸ������Щ�ط��ǹ����ƶ���·�ߣ���Щ���ϰ����Щ�ǿ��Է��������ĵط�����Ҫ�����ͼ���������ͳ�����
 * @author �½���
 * @date 20180413
 * */

#pragma once
#ifndef __CarrotFantasy__MapUtil__
#define __CarrotFantasy__MapUtil__

#include "CommonDefine.h"

class MapUtil : public Ref
{
public:
    /**
     * @brief �������ģʽ
     * @details ����cocos��ĺ�
     */
CREATE_INSTANCE_FUNCTION(MapUtil);

    DESTROY_INSTANCE_FUNCTION();

    /**
     * @brief ��ȡ�����ò�������ǰ�ؿ�����Ƭ��ͼ
     * @details �ô�������Ƭ��ͼ�����ݳ�ʼ��ʵ����������������ĳ�ʼ������
     * @param pTiledMap ��ǰ�ؿ���Ƭ��ͼ
     * */
    virtual void setAndAnalyzeCurrentLevelTiledMap(TMXTiledMap *pTiledMap);

    /**
     * @brief ��ȡ�����ƶ�·��
     * @return ������ƶ�·��ÿ�������������
     */
    virtual std::vector<Vec2> getMovePoses();

    /**
     * @brief ��ȡ�ϰ���λ��
     * @return һ��Ԫ��������ÿ��Ԫ���һ��������ָʾ�ϰ�����ַ������ڶ����������ϰ���ľ�������
     */
    virtual std::vector<std::pair<std::string, Rect>> getBarrierPoses();

    /**
     * @brief ��ȡ�ܹ���������������
     * @return һ���洢��������
     * @details ֮���Է��ظ���������������Ϊ��Щ�ϰ������ر����ģ�����������û�а취���������ϰ���
     */
    virtual std::vector<Rect> getEffectTowerPoses();

    /**
     * @brief ��ȥ�ϰ�������
     * @details ����˵���ϰ��ﱻ������ˣ���λ�þͿ����ˣ���û���ϰ��������棬��ʱ���ͼ��Ҫ��̬ˢ��
     * @param �ϰ����λ������
     * @todo �����Ͳ�����ȥ��???
     */
    virtual void removeBarrierRect(const Vec2 &rPos);

protected:
    /**
     * @brief ������ͼ�б����ָ�벢�����ڴ�
     * @brief ��ֱ�ӽг�ʼ������������... by Chen
     * @return true ����ɹ������򷵻�false
     */
    virtual bool init();

    /**
     * @brief �����ͼ
     */
    virtual void clearMap();

    /**
     * @brief ���β��
     * @details 1-��ͼ�ļ���������Ч����λ����һ����С��һ�ľ��п����ģ�����������ֻ�ܷ���һ��С�����У���ʱ��Ҫ��־��α��һ����С���飬�����ڶ�Ӧ��������
     * @details 2-�ϰ������󣬴�ʱ���Է��������ˣ����ϰ�����ʱ��ռ�ݵķ�Χ�Ƚϴ���ʱ����Ҫ���һ����С����
     */
    virtual void rectTransVec(const Rect &rRect);

private:
    /**
     * @brief ��ͼָ��
     */
    TMXTiledMap *_pTildeMap = nullptr;

    /**
     * @brief ������ƶ��켣����������
     * @details ���������·�������Ϸ�
     * */
    std::map<int, Vec2> *_pMovePosMap = nullptr;

    std::vector<std::pair<std::string, Rect>> *_pBarrierPosMap = nullptr; //�ϰ���λ������

    std::vector<Rect> *_pEffectTowerRectVec = nullptr; //�������Է��õ���������

private:

    Size _gridSize; //������

private:

    virtual ~MapUtil();

};


#endif /* defined(__CarrotFantasy__MapUtil__) */
