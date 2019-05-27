#pragma once
#include "cocos2d.h"
#include "OneMapScene.h"
class StatusLayer :public cocos2d::Layer
{
public:
	static cocos2d::Layer* creatLayer();
	virtual bool init();
	CREATE_FUNC(StatusLayer);
};