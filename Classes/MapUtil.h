
//
//  MapUtil.h
//  CarrotFantasy
//
//  Created by ������ on 18-4-7.
//  ̫�࿴������û��ע����
//
#pragma once
#ifndef __CarrotFantasy__MapUtil__
#define __CarrotFantasy_r_MapUtil__

#include "CommonDefine.h"

class MapUtil : public Ref
{
public:
	/*
	* @brief �������ģʽ
	* @details ����cocos��ĺ�
	*/
	CREATE_INSTANCE_FUNCTION(MapUtil);

	DESTROY_INSTANCE_FUNCTION();
	/*
	* @brief ���õ�ǰ�����ƽ�̵�ͼ
	*/
	virtual void setCurrentLevelTiledMap(TMXTiledMap *pTiledMap);
	/*
	* @brief ��ȡ�ƶ�λ��
	*/
	virtual std::vector<Vec2> getMovePoses();
	/*
	* @brief ��ȡ�ϰ���λ��
	*/
	virtual std::vector<std::pair<std::string, Rect>> getBarrierPoses();
	/*
	* @brief ��ȡЧ������λ��
	*/
	virtual std::vector<Rect> getEffectTowerPoses();
	/*
	* @brief ɾȥ�ϰ���
	* @param �ϰ����λ������
	*/
	virtual void removeBarrierRect(const Vec2 &rPos);

protected:
	/*
	* @brief ������ͼ�б����ָ�벢�����ڴ�
	* @return true ����ɹ������򷵻�false
	*/
	virtual bool init();
	/*
	* @brief �����ͼ
	*/
	virtual void clearMap();
	/*
	* @Rect����תVec
	*/
	virtual void rectTransVec(const Rect &rRect);

private:
	/*
	* @brief ��ͼָ��
	*/
	TMXTiledMap *_pTildeMap = nullptr;

	std::map<int, Vec2> *_pMovePosMap = nullptr;

	std::vector<std::pair<std::string, Rect>> *_pBarrierPosMap = nullptr;

	std::vector<Rect> *_pEffectTowerRectVec = nullptr;

private:

	Size _gridSize;
	Size _mapSize;

private:

	virtual ~MapUtil();

};


#endif /* defined(__CarrotFantasy__MapUtil__) */
