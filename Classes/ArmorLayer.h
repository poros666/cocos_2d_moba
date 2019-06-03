#pragma once
#include"cocos2d.h"
#include"Hero.h"
USING_NS_CC;

class ArmorLayer :public cocos2d::Layer
{
public:
	static cocos2d::Layer* createLayer(Hero* owner);
	virtual bool init(Hero* owner);
	void menuArmorOneCallback(cocos2d::Ref* pSender, Hero* owner);
	void menuArmorTwoCallback(cocos2d::Ref* pSender, Hero* owner);
	void menuArmorThreeCallback(cocos2d::Ref* pSnender, Hero* owner);
	void menuArmorFourCallback(cocos2d::Ref* pSender, Hero* owner);
	void menuEscCallback(cocos2d::Ref* pSender);
};
