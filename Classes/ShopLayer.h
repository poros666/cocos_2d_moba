#pragma once
#include"cocos2d.h"
USING_NS_CC;
class ShopLayer :public cocos2d::Layer {
public:
	static cocos2d::Layer* createLayer();
	virtual bool init();
	void menuEscCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(ShopLayer);
};
