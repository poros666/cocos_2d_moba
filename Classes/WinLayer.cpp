#include "WinLayer.h"
#include"HelloWorldScene.h"
cocos2d::Layer* WinLayer::createLayer()
{
	auto layer = new(std::nothrow)WinLayer();
	if (layer && layer->init()) {
		layer->autorelease();
		return layer;
	}
	CC_SAFE_DELETE(layer);
	return nullptr;
}

bool WinLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto victoryItem = MenuItemImage::create("victory/victory.jpg", "victory/victory.jpg");
	victoryItem->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
	auto returnItem = MenuItemImage::create("victory/return.png", "victory/return.png",CC_CALLBACK_1(WinLayer::menuReturnCallback,this));
	returnItem->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+600));
	auto menu = Menu::create(victoryItem, returnItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 10);
	return true;
}

void WinLayer::menuReturnCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->end();
}
