//�˴���setpositionһ����Ҫ��֮������ɫ����֮������޸�

#pragma once
#include"cocos2d.h"
USING_NS_CC;
class EquipmentLayer :public cocos2d::Layer
{
public:
	static cocos2d::Layer* createLayer();
	virtual bool init();
	void menuSwordOneCallback(cocos2d::Ref* pSender);
	CREATE_FUNC(EquipmentLayer);
};
