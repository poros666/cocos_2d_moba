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
#include"Skill.h"
#include"ScoreBoard.h"
#include "EquipmentShowLayer.h"
#include"SocketClient.h"
#include"SocketServer.h"
#include<list>

USING_NS_CC;
class Game :public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene(SocketServer* server, SocketClient* client,char buf[1024]);
	virtual bool init(SocketServer* server, SocketClient* client,char buf[1024]);
	void MapLayerPrint();
	void ShopLayerPrint();
	void menuShopCallback(cocos2d::Ref* pSender);
	void ShowPrint();
	void menuShowCallback(cocos2d::Ref* pSender);
	void HeroPrint();
	void CreepsPrint(float delta);
	void FieldPrint(float delta);
	void StatusLayerPrint();
	void TowerPrint();
	void ScoreBoardPrint();
	void ScoreBoardRelesed();
	void SetHpBar();
	void UpdateHpBar(float delta);
	void SetManaBar();
	void UpdateManaBar(float delta);
	void SetExpBar();
	void UpdateExpBar(float delta);
	virtual void onEnter();
	void initKeyListener(Hero* hero);
	void initMouseListener(Hero* hero);
	bool clickToAttack(Hero* owner);
	
	

	SocketServer* Socketserver;
	SocketClient* Socketclient;
private:
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Rect rect = Director::getInstance()->getOpenGLView()->getVisibleRect();
	bool isGamming = true;


	ProgressTimer* HpBarProgress;
	ProgressTimer* ManaBarProgress;
	ProgressTimer* ExpBarProgress;
	EventListenerTouchOneByOne *Mouselistener;
	EventListenerKeyboard* keylistener;
	Skill* skillQ;
	Skill* skillW;
	Skill* skillE;
	Skill* skillR;
};