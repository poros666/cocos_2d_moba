//���ļ��ڵ�����setposition��ʱ��Ӧ�ü���player��λ�ã��������ʾ����
//���ڽ�ɫ�໹δ��ȫʵ�֣���ʱ���ô�����
#pragma once
#include"cocos2d.h"
#include"EquipmentLayer.h"
#include"Hero.h"
USING_NS_CC;
class ShopLayer :public cocos2d::Layer {
public:
	static cocos2d::Layer* createLayer(Hero* owner);
	virtual bool init(Hero* owner);
	void menuEscCallback(cocos2d::Ref* pSender);
};
