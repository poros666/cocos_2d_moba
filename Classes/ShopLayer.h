//该文件内的所有setposition的时候都应该加上player的位置，否则会显示错误，
//介于角色类还未完全实现，暂时搁置此问题
#pragma once
#include"cocos2d.h"

USING_NS_CC;
class ShopLayer :public cocos2d::Layer {
public:
	static cocos2d::Layer* createLayer();
	virtual bool init();
	void menuEscCallback(cocos2d::Ref* pSender);
	void menuEquipmentCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(ShopLayer);
};
