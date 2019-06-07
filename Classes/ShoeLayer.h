#pragma once
#include"cocos2d.h"
#include"Hero.h"
USING_NS_CC;
class ShoeLayer :public cocos2d::Layer
{
public:
	static cocos2d::Layer* createLayer(Hero* owner);
	virtual bool init(Hero* owner);
	void menuShoeOneCallback(cocos2d::Ref* pSender, Hero* owner);
	void menuShoeTwoCallback(cocos2d::Ref* pSender, Hero* owner);
	void menuShoeThreeCallback(cocos2d::Ref* pSnender, Hero* owner);
	void menuShoeFourCallback(cocos2d::Ref* pSender, Hero* owner);
	void menuEscCallback(cocos2d::Ref* pSender);

};