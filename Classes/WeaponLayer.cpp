#include "WeaponLayer.h"

cocos2d::Layer* WeaponLayer::createLayer()
{
	return WeaponLayer::create();
}
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in StartSceneScene.cpp\n");
}

bool WeaponLayer::init()
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
			CC_CALLBACK_1(WeaponLayer::menuWeaponOneCallback, this)
		);
		if (BuyOne == nullptr ||
			BuyOne->getContentSize().width <= 0 ||
			BuyOne->getContentSize().height <= 0)
		{
			problemLoading("'equipment/swordone.png' and 'equipment/swordone.png'");
		}
		else
		{
			BuyOne->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 +275, origin.y + 600));
		}
	//weapontwo
		auto BuyTwo = MenuItemImage::create(
			"equipment/buy.png",
			"equipment/buy.png",
			CC_CALLBACK_1(WeaponLayer::menuWeaponTwoCallback, this)
		);
		if (BuyTwo == nullptr ||
			BuyTwo->getContentSize().width <= 0 ||
			BuyTwo->getContentSize().height <= 0)
		{
			problemLoading("'equipment/swordone.png' and 'equipment/swordone.png'");
		}
		else
		{
			BuyTwo->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 +275, origin.y + 467));
		}
	//three
		auto BuyThree = MenuItemImage::create(
			"equipment/buy.png",
			"equipment/buy.png",
			CC_CALLBACK_1(WeaponLayer::menuWeaponThreeCallback, this)
		);
		if (BuyThree == nullptr ||
			BuyThree->getContentSize().width <= 0 ||
			BuyThree->getContentSize().height <= 0)
		{
			problemLoading("'equipment/swordone.png' and 'equipment/swordone.png'");
		}
		else
		{
			BuyThree->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 +275, origin.y + 333));
		}
	//four
		auto BuyFour = MenuItemImage::create(
			"equipment/buy.png",
			"equipment/buy.png",
			CC_CALLBACK_1(WeaponLayer::menuWeaponFourCallback, this)
		);
		if (BuyFour == nullptr ||
			BuyFour->getContentSize().width <= 0 ||
			BuyFour->getContentSize().height <= 0)
		{
			problemLoading("'equipment/swordone.png' and 'equipment/swordone.png'");
		}
		else
		{
			BuyFour->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 +275, origin.y + 200));
		}
	//Esc
		auto Esc = MenuItemImage::create(
			"equipment/esc.png",
			"equipment/esc.png",
			CC_CALLBACK_1(WeaponLayer::menuEscCallback, this)
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
			auto WeaponOne = MenuItemImage::create("equipment/swordone.png", "equipment/swordone.png");
			WeaponOne->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 600));
			auto DescribeOne = MenuItemImage::create("equipment/swordone.png", "equipment/swordone.png");
			DescribeOne->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 50, origin.y + 600));
	
			auto WeaponTwo = MenuItemImage::create("equipment/swordone.png", "equipment/swordone.png");
			WeaponTwo->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 467));
			auto DescribeTwo = MenuItemImage::create("equipment/swordone.png", "equipment/swordone.png");
			DescribeTwo->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 50, origin.y + 467));
	
			auto WeaponThree = MenuItemImage::create("equipment/swordone.png", "equipment/swordone.png");
			WeaponThree->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 333));
			auto DescribeThree = MenuItemImage::create("equipment/swordone.png", "equipment/swordone.png");
			DescribeThree->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 50, origin.y + 333));
		
			auto WeaponFour = MenuItemImage::create("equipment/swordone.png", "equipment/swordone.png");
			WeaponFour->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 200));
			auto DescribeFour = MenuItemImage::create("equipment/swordone.png", "equipment/swordone.png");
			DescribeFour->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 50, origin.y + 200));
		




		auto menu = Menu::create(BuyOne, BuyTwo, BuyThree, BuyFour,Esc,
			WeaponOne,WeaponTwo,WeaponThree,WeaponFour,
			DescribeOne,DescribeTwo,DescribeThree,DescribeFour,
			NULL);
		menu->setPosition(Vec2::ZERO);
		this->addChild(menu, 3);
		
		;

		return true;
	
}

void WeaponLayer::menuWeaponOneCallback(cocos2d::Ref* pSender)
{

}

void WeaponLayer::menuWeaponTwoCallback(cocos2d::Ref* pSender)
{
}

void WeaponLayer::menuWeaponThreeCallback(cocos2d::Ref* pSnender)
{
}

void WeaponLayer::menuWeaponFourCallback(cocos2d::Ref* pSender)
{
}

void WeaponLayer::menuEscCallback(cocos2d::Ref* pSender)
{
	this->removeFromParentAndCleanup(true);
}
