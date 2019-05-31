#include"StatusLayer.h"
USING_NS_CC;

Layer* StatusLayer::createLayer()
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

	auto timeItem = Sprite::create("time.dds");
	if (timeItem == nullptr ||
		timeItem->getContentSize().width <= 0 ||
		timeItem->getContentSize().height <= 0)
	{
		problemLoading("'time.dds'");
	}
	else
	{
		timeItem->setScale(0.5, 0.5);
		auto size = timeItem->getContentSize();
		float x = origin.x + visibleSize.width /2;
		float y =visibleSize.height-size.height/4;
		timeItem->setPosition(Vec2(x, y));
	};
	this->addChild(timeItem, 1);
	auto skillLable= Sprite::create("skillLable.dds");
	if (skillLable == nullptr ||
		skillLable->getContentSize().width <= 0 ||
		skillLable->getContentSize().height <= 0)
	{
		problemLoading("'skillLable.dds'");
	}
	else
	{
		auto size = skillLable->getContentSize();
		float x = origin.x + visibleSize.width / 2;
		float y = size.height / 2+30;
		skillLable->setPosition(Vec2(x, y));
	};
	this->addChild(skillLable, 1);
	auto emptyHealthbar = Sprite::create("emptybar.dds");
	if (emptyHealthbar == nullptr ||
		emptyHealthbar->getContentSize().width <= 0 ||
		emptyHealthbar->getContentSize().height <= 0)
	{
		problemLoading("'emptyHealthbar.dds'");
	}
	else
	{
		emptyHealthbar->setScaleX(0.5);
		auto size = emptyHealthbar->getContentSize();
		float x = origin.x + visibleSize.width / 2;
		float y = size.height / 4;
		emptyHealthbar->setPosition(Vec2(x, y));
	};
	this->addChild(emptyHealthbar, 1);

	auto emptyManabar = Sprite::create("emptybar.dds");
	if (emptyManabar == nullptr ||
		emptyManabar->getContentSize().width <= 0 ||
		emptyManabar->getContentSize().height <= 0)
	{
		problemLoading("'emptyManabar.dds'");
	}
	else
	{
		emptyManabar->setScale(0.5,0.5);
		auto size = emptyManabar->getContentSize();
		float x = origin.x + visibleSize.width / 2;
		float y = size.height / 4-10;
		emptyManabar->setPosition(Vec2(x, y));
	};
	this->addChild(emptyManabar, 1);
	/*auto Manabar = Sprite::create("Manabar.dds");
	if (Manabar == nullptr ||
		Manabar->getContentSize().width <= 0 ||
		Manabar->getContentSize().height <= 0)
	{
		problemLoading("'Manabar.dds'");
	}
	else
	{
		Manabar->setScale(0.5, 0.5);

		auto size = Manabar->getContentSize();
		float x = origin.x + visibleSize.width / 2;
		float y =size.height/2-6;
		Manabar->setPosition(Vec2(x, y));
	};
	this->addChild(Manabar, 2);*/
	return true;
}
void StatusLayer::update(float dt)
{

}
/*void StatusLayer::setHPprogress(int initHealthPointsLimit, int healthPoints)
{
	

}
*/