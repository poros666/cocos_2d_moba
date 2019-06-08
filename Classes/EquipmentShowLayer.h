#pragma once
#include"cocos2d.h"
#include"Hero.h"
USING_NS_CC;
class EquipmentShowLayer :public cocos2d::Layer {
public:
	static cocos2d::Layer* createLayer(Hero* owner);
	virtual bool init(Hero* owner);
	void menuSellOneCallback(Ref* pSender, Hero* owner);
	void menuSellTwoCallback(Ref* pSender, Hero* owner);
	void menuSellThreeCallback(Ref* pSender, Hero* owner);
	void menuSellFourCallback(Ref* pSender, Hero* owner);
	void menuSellFiveCallback(Ref* pSender, Hero* owner);
	void menuSellSixCallback(Ref* pSender, Hero* owner);
	void deleteProperty(int number,Hero* owner);
	void updateEquipment(Hero* owner);
	void menuEscCallback(cocos2d::Ref* pSender);
};