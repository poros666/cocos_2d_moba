//�˴���setpositionһ����Ҫ��֮������ɫ����֮������޸�

#pragma once
#include"cocos2d.h"
#include"Hero.h"
USING_NS_CC;
class EquipmentLayer :public cocos2d::Layer
{
public:
	static cocos2d::Layer* createLayer(Hero* owner);
	virtual bool init(Hero* owner);
	void menuWeaponCallback(cocos2d::Ref* pSender,Hero* owner);
	void menuShoeCallback(cocos2d::Ref* pSender,Hero* owner);
	void menuArmorCallback(cocos2d::Ref* pSender,Hero* owner);
	void menuRecoveryCallback(cocos2d::Ref* pSender,Hero* owner);
};
