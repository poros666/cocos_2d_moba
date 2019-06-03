//该文件内的所有setposition的时候都应该加上player的位置，否则会显示错误，
//介于角色类还未完全实现，暂时搁置此问题
#include "ShopLayer.h"

cocos2d::Layer* ShopLayer::createLayer(Hero* owner)
{
	auto layer = new(std::nothrow)ShopLayer();
	if (layer && layer->init(owner)) {
		layer->autorelease();
		return layer;
	}
	CC_SAFE_DELETE(layer);
	return nullptr;
}
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in StartSceneScene.cpp\n");
}

bool ShopLayer::init(Hero* owner)
{
	if (!Layer::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto ShopBackground = MenuItemImage::create(
		"shop/shopbackground1.jpg",
		"shop/shopbackground1.jpg"
	);
	if (ShopBackground == nullptr ||
		ShopBackground->getContentSize().width <= 0 ||
		ShopBackground->getContentSize().height < +0)
	{
		problemLoading("'shop/shopbackground1.jpg' and 'shop/shopbackground1.jpg'");
	}
	else 
	{
		ShopBackground->setPosition(Vec2(origin.x + visibleSize.width*3 /4 +50, origin.y+460));
	}
	auto background = Menu::create(ShopBackground, NULL);
	background->setPosition(Vec2::ZERO);
	this->addChild(background, 1);


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
	auto layer = EquipmentLayer::createLayer(owner);
	this->addChild(layer, 5000);
	layer->setVisible(true);

	auto menu = Menu::create(ShopEsc,NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu,1);
	return true;

}

void ShopLayer::menuEscCallback(cocos2d::Ref* pSender)
{
	this->removeFromParentAndCleanup(true);
}


