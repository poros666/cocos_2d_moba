#pragma once
#include "cocos2d.h"
#include "StatusLayer.h"
class OneMapScene : public cocos2d::Scene
{
	cocos2d::TMXLayer* _collidable;
	cocos2d::Sprite* _player;
	cocos2d::TMXTiledMap* _tileMap;
	public:
		static cocos2d::Scene* CreateScene();
		virtual bool init();
		void menuBackCallback(cocos2d::Ref* pSender);
		void menuShopCallback(cocos2d::Ref* pSender);
		void setPlayerPosition(cocos2d::Vec2 position);
		cocos2d::Vec2 tileCoordFromPosition(cocos2d::Vec2 position);
		void setViewPointCenter(cocos2d::Vec2 position);
		virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
		virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
		virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
		CREATE_FUNC(OneMapScene);
};