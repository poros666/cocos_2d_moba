#pragma once
#include "Creeps.h"
#include "Hero.h"
#include"Tower.h"
#include"StatusLayer.h"
#include"OneMapLayer.h"
#include"ChooseHeroScene.h"
#include"ChooseModeScene.h"
#include"cocos2d.h"
#include"ShopLayer.h"
USING_NS_CC;
class Game :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void MapLayerPrint();
	void ShopLayerPrint();
	void menuShopCallback(cocos2d::Ref* pSender);
	void HeroPrint();
	void recreateHero(float delta);
	void test(float delta);
	void CreepsPrint(float delta);
	void StatusLayerPrint();
	void TowerPrint();
	virtual void update(float delta);
	void HeroDie();
	void SetHpBar();
	void UpdateHpBar(float delta);
	void SetManaBar();
	void UpdateManaBar(float delta);
	CREATE_FUNC(Game);
private:
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Rect rect = Director::getInstance()->getOpenGLView()->getVisibleRect();
	bool isGamming = true;
	Hero* Myhero;
	ProgressTimer* HpBarProgress;
	ProgressTimer* ManaBarProgress;
};