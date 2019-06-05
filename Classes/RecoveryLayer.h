#pragma once
#include"cocos2d.h"
#include"Hero.h"
USING_NS_CC;
class RecoveryLayer :public cocos2d::Layer
{
public:
	static cocos2d::Layer* createLayer(Hero* owner);
	virtual bool init(Hero* owner);
	void menuWeaponOneCallback(cocos2d::Ref* pSender, Hero* owner);
	void menuWeaponTwoCallback(cocos2d::Ref* pSender, Hero* owner);
	void menuWeaponThreeCallback(cocos2d::Ref* pSnender, Hero* owner);
	void menuWeaponFourCallback(cocos2d::Ref* pSender, Hero* owner);
	void menuEscCallback(cocos2d::Ref* pSender);

};
