#pragma once
#include "cocos2d.h"
#include "OneMapLayer.h"
#include "Hero.h"
class StatusLayer :public cocos2d::Layer
{
public:
	static cocos2d::Layer* createLayer();
	virtual bool init();
	virtual void update(float dt);
	void setHPprogress(int initHealthPointsLimit,int healthPoints);
	CREATE_FUNC(StatusLayer);
};