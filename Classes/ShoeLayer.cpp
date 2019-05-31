#include "ShoeLayer.h"

cocos2d::Layer* ShoeLayer::createLayer()
{
	return ShoeLayer::create();
}
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in StartSceneScene.cpp\n");
}

bool ShoeLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//weapon one
	auto BuyOne = MenuItemImage::create(
		"equipment/buy.png",
		"equipment/buy.png",
		CC_CALLBACK_1(ShoeLayer::menuShoeOneCallback, this)
	);
	if (BuyOne == nullptr ||
		BuyOne->getContentSize().width <= 0 ||
		BuyOne->getContentSize().height <= 0)
	{
		problemLoading("'equipment/swordone.png' and 'equipment/swordone.png'");
	}
	else
	{
		BuyOne->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 275, origin.y + 600));
	}
	//weapontwo
	auto BuyTwo = MenuItemImage::create(
		"equipment/buy.png",
		"equipment/buy.png",
		CC_CALLBACK_1(ShoeLayer::menuShoeTwoCallback, this)
	);
	if (BuyTwo == nullptr ||
		BuyTwo->getContentSize().width <= 0 ||
		BuyTwo->getContentSize().height <= 0)
	{
		problemLoading("'equipment/swordone.png' and 'equipment/swordone.png'");
	}
	else
	{
		BuyTwo->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 275, origin.y + 467));
	}
	//three
	auto BuyThree = MenuItemImage::create(
		"equipment/buy.png",
		"equipment/buy.png",
		CC_CALLBACK_1(ShoeLayer::menuShoeThreeCallback, this)
	);
	if (BuyThree == nullptr ||
		BuyThree->getContentSize().width <= 0 ||
		BuyThree->getContentSize().height <= 0)
	{
		problemLoading("'equipment/swordone.png' and 'equipment/swordone.png'");
	}
	else
	{
		BuyThree->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 275, origin.y + 333));
	}
	//four
	auto BuyFour = MenuItemImage::create(
		"equipment/buy.png",
		"equipment/buy.png",
		CC_CALLBACK_1(ShoeLayer::menuShoeFourCallback, this)
	);
	if (BuyFour == nullptr ||
		BuyFour->getContentSize().width <= 0 ||
		BuyFour->getContentSize().height <= 0)
	{
		problemLoading("'equipment/swordone.png' and 'equipment/swordone.png'");
	}
	else
	{
		BuyFour->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 275, origin.y + 200));
	}
	//Esc
	auto Esc = MenuItemImage::create(
		"equipment/esc.png",
		"equipment/esc.png",
		CC_CALLBACK_1(ShoeLayer::menuEscCallback, this)
	);
	if (Esc == nullptr ||
		Esc->getContentSize().width <= 0 ||
		Esc->getContentSize().height <= 0)
	{
		problemLoading("'equipment/esc.png' and 'equipment/esc.png'");
	}
	else
	{
		Esc->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 100, origin.y + 100));
	}
	//
		//·ÅÖÃÎäÆ÷Í¼Æ¬ºÍÃèÊö
	auto ShoeOne = MenuItemImage::create("equipment/swordone.png", "equipment/swordone.png");
	ShoeOne->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 600));
	auto DescribeOne = MenuItemImage::create("equipment/swordone.png", "equipment/swordone.png");
	DescribeOne->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 50, origin.y + 600));

	auto ShoeTwo = MenuItemImage::create("equipment/swordone.png", "equipment/swordone.png");
	ShoeTwo->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 467));
	auto DescribeTwo = MenuItemImage::create("equipment/swordone.png", "equipment/swordone.png");
	DescribeTwo->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 50, origin.y + 467));

	auto ShoeThree = MenuItemImage::create("equipment/swordone.png", "equipment/swordone.png");
	ShoeThree->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 333));
	auto DescribeThree = MenuItemImage::create("equipment/swordone.png", "equipment/swordone.png");
	DescribeThree->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 50, origin.y + 333));

	auto ShoeFour = MenuItemImage::create("equipment/swordone.png", "equipment/swordone.png");
	ShoeFour->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 200));
	auto DescribeFour = MenuItemImage::create("equipment/swordone.png", "equipment/swordone.png");
	DescribeFour->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 50, origin.y + 200));





	auto menu = Menu::create(BuyOne, BuyTwo, BuyThree, BuyFour, Esc,
		ShoeOne, ShoeTwo, ShoeThree, ShoeFour,
		DescribeOne, DescribeTwo, DescribeThree, DescribeFour,
		NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 3);

	;

	return true;
}

void ShoeLayer::menuShoeOneCallback(cocos2d::Ref* pSender)
{
}

void ShoeLayer::menuShoeTwoCallback(cocos2d::Ref* pSender)
{
}

void ShoeLayer::menuShoeThreeCallback(cocos2d::Ref* pSnender)
{
}

void ShoeLayer::menuShoeFourCallback(cocos2d::Ref* pSender)
{
}

void ShoeLayer::menuEscCallback(cocos2d::Ref* pSender)
{
	this->removeFromParentAndCleanup(true);
}
