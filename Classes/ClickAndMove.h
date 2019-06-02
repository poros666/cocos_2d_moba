#pragma once
#include "Creeps.h"
#include "Hero.h"
#include"Tower.h"
#include"StatusLayer.h"
#include"OneMapLayer.h"
#include"ChooseHeroScene.h"
#include"ChooseModeScene.h"
#include"cocos2d.h"



class ClickAndMoveCase : public cocos2d::Layer
{
public:
	CREATE_FUNC(ClickAndMoveCase);

	ClickAndMoveCase();
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
private:
	Size size;//不能用auto关键字
	Sprite* sprite;
};