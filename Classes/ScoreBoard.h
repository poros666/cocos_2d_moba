#pragma once
#include"cocos2d.h"
#include"Hero.h"
class ScoreBoard :public cocos2d::Layer
{
public:
	static cocos2d::Layer* createLayer(Hero* Myhero);
	virtual bool init();
	static void Print(Hero* Myhero);
	CREATE_FUNC(ScoreBoard);
};