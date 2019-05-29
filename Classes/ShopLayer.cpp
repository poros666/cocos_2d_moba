#include "ShopLayer.h"

cocos2d::Layer* ShopLayer::createLayer()
{
	return ShopLayer::create();
}
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in StartSceneScene.cpp\n");
}

bool ShopLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	auto ShopBackground = MenuItemImage::create(
		"shop/shopbackground.jpg",
		"shop/shopbackground.jpg"
	);
	if (ShopBackground == nullptr ||
		ShopBackground->getContentSize().width <= 0 ||
		ShopBackground->getContentSize().height < +0)
	{
		problemLoading("'shop/shopbackground.jpg' and 'shop/shopbackground.jpg'");
	}
	else 
	{
		ShopBackground->setPosition(Vec2(origin.x + visibleSize.width*3 /4 +50, origin.y+400));
	}


	auto ShopEsc = MenuItemImage::create(
		"shop/shopesc.jpg",
		"shop/shopesc.jpg",
		CC_CALLBACK_1(ShopLayer::menuEscCallback,this)
	);
	if (ShopEsc == nullptr ||
		ShopEsc->getContentSize().width <= 0 ||
		ShopEsc->getContentSize().height < +0)
	{
		problemLoading("'shop/shopbackground.jpg' and 'shop/shopbackground.jpg'");
	}
	else
	{
		ShopEsc->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 -175, origin.y + 775));
	}
	auto menu = Menu::create(ShopBackground,ShopEsc,NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu,1);
	return true;

}

void ShopLayer::menuEscCallback(cocos2d::Ref* pSender)
{
	this->removeFromParentAndCleanup(true);
}

