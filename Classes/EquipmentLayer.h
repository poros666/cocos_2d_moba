//�˴���setpositionһ����Ҫ��֮������ɫ����֮������޸�

#pragma once
#include"cocos2d.h"

USING_NS_CC;
class EquipmentLayer :public cocos2d::Layer
{
public:
	static cocos2d::Layer* createLayer();
	virtual bool init();
	void menuWeaponCallback(cocos2d::Ref* pSender);
	void menuShoeCallback(cocos2d::Ref* pSender);
	void menuArmorCallback(cocos2d::Ref* pSender);
	void menuRecoveryCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(EquipmentLayer);
};
