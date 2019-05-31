//该文件内的所有setposition的时候都应该加上player的位置，否则会显示错误，
//介于角色类还未完全实现，暂时搁置此问题
#include "ShopLayer.h"
#include"EquipmentLayer.h"
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
		ShopEsc->getContentSize().height <=0)
	{
		problemLoading("'shop/shopbackground.jpg' and 'shop/shopbackground.jpg'");
	}
	else
	{
		ShopEsc->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 -175, origin.y + 775));
	}
	auto ShopWatch = MenuItemImage::create(
		"shop/shopwatch.jpg",
		"shop/shopwatch.jpg",
		CC_CALLBACK_1(ShopLayer::menuEquipmentCallback,this)
	);
	if (ShopWatch == nullptr ||
		ShopWatch->getContentSize().width<=0||
		ShopWatch->getContentSize().height<=0)
	{
		problemLoading("'shop/shopwatch.jpg' and 'shop/shopwatch.jpgg'");
	}
	else
	{
		ShopWatch->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4, origin.y + 775));
	}
	auto menu = Menu::create(ShopBackground,ShopEsc,ShopWatch,NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu,1);
	return true;

}

void ShopLayer::menuEscCallback(cocos2d::Ref* pSender)
{
	this->removeFromParentAndCleanup(true);
}

void ShopLayer::menuEquipmentCallback(cocos2d::Ref* pSender)
{
	auto layer = EquipmentLayer::createLayer();
	this->addChild(layer, 50);
	layer->setVisible(true);
}



