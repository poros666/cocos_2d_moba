#pragma once
#include"cocos2d.h"
#include "ChooseModeScene.h"
#include"Music.h"
#include"OneMapLayer.h"
#include"Game.h"
#include"SocketClient.h"
#include"SocketServer.h"
class ChooseHeroScene : public cocos2d::Scene 
{
public:
	static cocos2d::Scene* createScene(SocketServer* server, SocketClient* client);
	virtual bool init(SocketServer* server, SocketClient* client);
	void menuEliteChoosedCallBack(cocos2d::Ref* pSender);
	void menuExecuChoosedCallBack(cocos2d::Ref* pSender);
	void menuMunaraChoosedCallBack(cocos2d::Ref* pSender);
	void menuBackCallback(Ref* pSender);
	SocketServer* Socketserver;
	SocketClient* Socketclient;
};