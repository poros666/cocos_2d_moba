#pragma once
#include"cocos2d.h"
USING_NS_CC;
class WinLayer :public cocos2d::Layer
{
public:
	static cocos2d::Layer* createLayer();
	virtual bool init();
	void menuReturnCallback(cocos2d::Ref* pSender);
};