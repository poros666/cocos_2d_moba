#include"StatusLayer.h"
USING_NS_CC;

Layer* StatusLayer::creatLayer()
{
	auto layer = StatusLayer::create();
	return layer;
}
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in StartSceneScene.cpp\n");
}

bool StatusLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object

	auto settingItem = MenuItemImage::create(
		"Bottom/SettingsNormal.jpg",
		"Bottom/SettingsSelected.jpg"
		);
	if (settingItem == nullptr ||
		settingItem->getContentSize().width <= 0 ||
		settingItem->getContentSize().height <= 0)
	{
		problemLoading("'SettingsNormal.png' and 'SettingsSelected.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width / 2;
		float y = origin.y ;
		settingItem->setPosition(Vec2(x, y));
	};
	this->addChild(settingItem, 1);
	return true;
}