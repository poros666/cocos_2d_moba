#pragma once
#include "cocos2d.h"
#include "Hero.h"
class OneMapLayer : public cocos2d::Layer
{
	cocos2d::TMXLayer* _collidable;
	cocos2d::Sprite* _player;
	cocos2d::TMXTiledMap* _tileMap;
	public:
		static cocos2d::Layer* CreateLayer();
		virtual bool init();
		void menuBackCallback(cocos2d::Ref* pSender);
		void menuShopCallback(cocos2d::Ref* pSender);
		void setPlayerPosition(cocos2d::Vec2 position);
		cocos2d::Vec2 tileCoordFromPosition(cocos2d::Vec2 position);
		void setViewPointCenter(cocos2d::Vec2 position);
		void UpdateViewPointCenter(float delat);
		virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
		virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
		virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
		CREATE_FUNC(OneMapLayer);
};