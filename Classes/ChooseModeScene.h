#pragma once
#include "cocos2d.h"
#include "StartScene.h"
#include "Music.h"
#include "ChooseHeroScene.h"
#include"SocketClient.h"
#include"SocketServer.h"
#define OFF_LINE "offline"
#define SINGLE "1v1"

class ChooseModeScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void menuBackCallback(Ref* pSender);
	void startGameCallback(Ref* pSender);
	void modeSetCallback(Ref* pSender);
	void mapSetCallback(Ref* pSender);
	void createCallback(Ref* pSender);
	void joinCallback(Ref* pSender);
	void start(SocketServer* server, SocketClient* client);
	CREATE_FUNC(ChooseModeScene);
public:
	SocketClient* client;
	SocketServer* server;
};
