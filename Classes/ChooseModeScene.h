#pragma once
#include "cocos2d.h"
#include "StartScene.h"
#include "Music.h"
#include "ChooseHeroScene.h"
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
	CREATE_FUNC(ChooseModeScene);
};
