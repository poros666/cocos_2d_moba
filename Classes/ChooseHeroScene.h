#pragma once
#include"cocos2d.h"
#include "ChooseModeScene.h"
#include"Music.h"
#include"OneMapLayer.h"
#include"Game.h"
class ChooseHeroScene : public cocos2d::Scene 
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	void menuEliteChoosedCallBack(cocos2d::Ref* pSender);
	void menuExecuChoosedCallBack(cocos2d::Ref* pSender);
	void menuMunaraChoosedCallBack(cocos2d::Ref* pSender);
	void menuBackCallback(Ref* pSender);
	void menuOneMapChoosedCallBack(cocos2d::Ref* pSender);
	CREATE_FUNC(ChooseHeroScene);
};