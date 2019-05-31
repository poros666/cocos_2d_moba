#pragma once
#include"cocos2d.h"
USING_NS_CC;
class RecoveryLayer :public cocos2d::Layer
{
public:
	static cocos2d::Layer* createLayer();
	virtual bool init();
	void menuWeaponOneCallback(cocos2d::Ref* pSender);
	void menuWeaponTwoCallback(cocos2d::Ref* pSender);
	void menuWeaponThreeCallback(cocos2d::Ref* pSnender);
	void menuWeaponFourCallback(cocos2d::Ref* pSender);
	void menuEscCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(RecoveryLayer);
};
