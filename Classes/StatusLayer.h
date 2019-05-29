#pragma once
#include "cocos2d.h"
#include "OneMapScene.h"
#include "Hero.h"
class StatusLayer :public cocos2d::Layer
{
public:
	static cocos2d::Layer* creatLayer();
	virtual bool init();
	virtual void update(float dt);
	void setHPprogress(int initHealthPointsLimit,int healthPoints);
	CREATE_FUNC(StatusLayer);
};