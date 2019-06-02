#include "RecoveryLayer.h"

cocos2d::Layer* RecoveryLayer::createLayer()
{
	return RecoveryLayer::create();
}
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in StartSceneScene.cpp\n");
}


bool RecoveryLayer::init()
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
		CC_CALLBACK_1(RecoveryLayer::menuWeaponOneCallback, this)
	);
	if (BuyOne == nullptr ||
		BuyOne->getContentSize().width <= 0 ||
		BuyOne->getContentSize().height <= 0)
	{
		problemLoading("'equipment/swordone.png' and 'equipment/swordone.png'");
	}
	else
	{
		BuyOne->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 275, origin.y + 660));
	}
	//weapontwo
	auto BuyTwo = MenuItemImage::create(
		"equipment/buy.png",
		"equipment/buy.png",
		CC_CALLBACK_1(RecoveryLayer::menuWeaponTwoCallback, this)
	);
	if (BuyTwo == nullptr ||
		BuyTwo->getContentSize().width <= 0 ||
		BuyTwo->getContentSize().height <= 0)
	{
		problemLoading("'equipment/swordone.png' and 'equipment/swordone.png'");
	}
	else
	{
		BuyTwo->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 275, origin.y + 527));
	}
	//three
	auto BuyThree = MenuItemImage::create(
		"equipment/buy.png",
		"equipment/buy.png",
		CC_CALLBACK_1(RecoveryLayer::menuWeaponThreeCallback, this)
	);
	if (BuyThree == nullptr ||
		BuyThree->getContentSize().width <= 0 ||
		BuyThree->getContentSize().height <= 0)
	{
		problemLoading("'equipment/swordone.png' and 'equipment/swordone.png'");
	}
	else
	{
		BuyThree->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 275, origin.y + 393));
	}
	//four
	auto BuyFour = MenuItemImage::create(
		"equipment/buy.png",
		"equipment/buy.png",
		CC_CALLBACK_1(RecoveryLayer::menuWeaponFourCallback, this)
	);
	if (BuyFour == nullptr ||
		BuyFour->getContentSize().width <= 0 ||
		BuyFour->getContentSize().height <= 0)
	{
		problemLoading("'equipment/swordone.png' and 'equipment/swordone.png'");
	}
	else
	{
		BuyFour->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 275, origin.y + 260));
	}
	//Esc
	/////
	/*
	auto Esc = MenuItemImage::create(
		"equipment/esc.png",
		"equipment/esc.png",
		CC_CALLBACK_1(RecoveryLayer::menuEscCallback, this)
	);
	if (Esc == nullptr ||
		Esc->getContentSize().width <= 0 ||
		Esc->getContentSize().height <= 0)
	{
		problemLoading("'equipment/esc.png' and 'equipment/esc.png'");
	}
	else
	{
		Esc->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 100, origin.y + 160));
	}*/
	//////
	//
		//��������ͼƬ������
	auto RecoveryOne = MenuItemImage::create("equipment/recoveryone.jpg", "equipment/recovery.jpg");
	RecoveryOne->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660));
	auto DescribeOne = MenuItemImage::create("equipment/Drecoveryone.png", "equipment/Drecoveryone.png");
	DescribeOne->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 50, origin.y + 660));

	auto RecoveryTwo = MenuItemImage::create("equipment/recoverytwo.jpg", "equipment/recoverytwo.jpg");
	RecoveryTwo->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 527));
	auto DescribeTwo = MenuItemImage::create("equipment/Drecoverytwo.png", "equipment/Drecoverytwo.png");
	DescribeTwo->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 50, origin.y + 527));

	auto RecoveryThree = MenuItemImage::create("equipment/recoverythree.jpg", "equipment/recoverythree.jpg");
	RecoveryThree->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 393));
	auto DescribeThree = MenuItemImage::create("equipment/Drecoverythree.png", "equipment/Drecoverythree.png");
	DescribeThree->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 50, origin.y + 393));

	auto RecoveryFour = MenuItemImage::create("equipment/recoveryfour.jpg", "equipment/recoveryfour.jpg");
	RecoveryFour->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 260));
	auto DescribeFour = MenuItemImage::create("equipment/Drecoveryfour.png", "equipment/Drecoveryfour.png");
	DescribeFour->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 50, origin.y + 260));





	auto menu = Menu::create(BuyOne, BuyTwo, BuyThree, BuyFour, 
		RecoveryOne, RecoveryTwo, RecoveryThree, RecoveryFour,
		DescribeOne, DescribeTwo, DescribeThree, DescribeFour,
		NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 3);

	;

	return true;
}

void RecoveryLayer::menuWeaponOneCallback(cocos2d::Ref* pSender)
{
}

void RecoveryLayer::menuWeaponTwoCallback(cocos2d::Ref* pSender)
{
}

void RecoveryLayer::menuWeaponThreeCallback(cocos2d::Ref* pSnender)
{
}

void RecoveryLayer::menuWeaponFourCallback(cocos2d::Ref* pSender)
{
}

void RecoveryLayer::menuEscCallback(cocos2d::Ref* pSender)
{
	this->removeFromParentAndCleanup(true);
}
