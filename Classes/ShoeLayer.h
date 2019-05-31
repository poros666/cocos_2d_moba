#pragma once
#include"cocos2d.h"
USING_NS_CC;
class ShoeLayer :public cocos2d::Layer
{
public:
	static cocos2d::Layer* createLayer();
	virtual bool init();
	void menuShoeOneCallback(cocos2d::Ref* pSender);
	void menuShoeTwoCallback(cocos2d::Ref* pSender);
	void menuShoeThreeCallback(cocos2d::Ref* pSnender);
	void menuShoeFourCallback(cocos2d::Ref* pSender);
	void menuEscCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(ShoeLayer);
};