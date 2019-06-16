#pragma once
#include"cocos2d.h"
#include"Hero.h"
class ScoreBoard :public cocos2d::Layer
{
public:
	static cocos2d::Layer* createLayer();
	virtual bool init();
	CREATE_FUNC(ScoreBoard);
};