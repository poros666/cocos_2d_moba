#include "WeaponLayer.h"

cocos2d::Layer* WeaponLayer::createLayer(Hero* owner)
{
	auto layer = new(std::nothrow)WeaponLayer();
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

bool WeaponLayer::init(Hero* owner)
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
			CC_CALLBACK_1(WeaponLayer::menuWeaponOneCallback, this,owner)
		);
		if (BuyOne == nullptr ||
			BuyOne->getContentSize().width <= 0 ||
			BuyOne->getContentSize().height <= 0)
		{
			problemLoading("'equipment/swordone.png' and 'equipment/swordone.png'");
		}
		else
		{
			BuyOne->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 +275, origin.y + 660));
		}
	//weapontwo
		auto BuyTwo = MenuItemImage::create(
			"equipment/buy.png",
			"equipment/buy.png",
			CC_CALLBACK_1(WeaponLayer::menuWeaponTwoCallback, this,owner)
		);
		if (BuyTwo == nullptr ||
			BuyTwo->getContentSize().width <= 0 ||
			BuyTwo->getContentSize().height <= 0)
		{
			problemLoading("'equipment/swordone.png' and 'equipment/swordone.png'");
		}
		else
		{
			BuyTwo->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 +275, origin.y + 527));
		}
	//three
		auto BuyThree = MenuItemImage::create(
			"equipment/buy.png",
			"equipment/buy.png",
			CC_CALLBACK_1(WeaponLayer::menuWeaponThreeCallback, this,owner)
		);
		if (BuyThree == nullptr ||
			BuyThree->getContentSize().width <= 0 ||
			BuyThree->getContentSize().height <= 0)
		{
			problemLoading("'equipment/swordone.png' and 'equipment/swordone.png'");
		}
		else
		{
			BuyThree->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 +275, origin.y + 393));
		}
	//four
		auto BuyFour = MenuItemImage::create(
			"equipment/buy.png",
			"equipment/buy.png",
			CC_CALLBACK_1(WeaponLayer::menuWeaponFourCallback, this,owner)
		);
		if (BuyFour == nullptr ||
			BuyFour->getContentSize().width <= 0 ||
			BuyFour->getContentSize().height <= 0)
		{
			problemLoading("'equipment/swordone.png' and 'equipment/swordone.png'");
		}
		else
		{
			BuyFour->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 +275, origin.y + 260));
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
			Esc->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 100, origin.y + 160));
		}
	//
		//·ÅÖÃÎäÆ÷Í¼Æ¬ºÍÃèÊö
			auto WeaponOne = MenuItemImage::create("equipment/swordone.jpg", "equipment/swordone.jpg");
			WeaponOne->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660));
			auto DescribeOne = MenuItemImage::create("equipment/Dswordone.png", "equipment/Dswordone.png");
			DescribeOne->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 50, origin.y + 660));
	
			auto WeaponTwo = MenuItemImage::create("equipment/swordtwo.jpg", "equipment/swordtwo.jpg");
			WeaponTwo->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 527));
			auto DescribeTwo = MenuItemImage::create("equipment/Dswordtwo.png", "equipment/Dswordtwo.png");
			DescribeTwo->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 50, origin.y + 527));
	
			auto WeaponThree = MenuItemImage::create("equipment/swordthree.jpg", "equipment/swordthree.jpg");
			WeaponThree->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 393));
			auto DescribeThree = MenuItemImage::create("equipment/Dswordthree.png", "equipment/Dswordthree.png");
			DescribeThree->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 50, origin.y + 393));
		
			auto WeaponFour = MenuItemImage::create("equipment/swordfour.jpg", "equipment/swordfour.jpg");
			WeaponFour->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 260));
			auto DescribeFour = MenuItemImage::create("equipment/Dswordfour.png", "equipment/Dswordfour.png");
			DescribeFour->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 50, origin.y + 260));
		




		auto menu = Menu::create(BuyOne, BuyTwo, BuyThree, BuyFour,
			WeaponOne,WeaponTwo,WeaponThree,WeaponFour,
			DescribeOne,DescribeTwo,DescribeThree,DescribeFour,
			NULL);
		menu->setPosition(Vec2::ZERO);
		this->addChild(menu, 3);
		
		;

		return true;
	
}

void WeaponLayer::menuWeaponOneCallback(cocos2d::Ref* pSender,  Hero* owner)
{
	owner->setAtk(owner->getAtk() + 20);
}

void WeaponLayer::menuWeaponTwoCallback(cocos2d::Ref* pSender, Hero* owner)
{
	owner->setAtk(owner->getAtk() + 50);
}

void WeaponLayer::menuWeaponThreeCallback(cocos2d::Ref* pSnender, Hero* owner)
{
	owner->setAtk(owner->getAtk() + 90);
}

void WeaponLayer::menuWeaponFourCallback(cocos2d::Ref* pSender, Hero* owner)
{
	owner->setAtk(owner->getAtk() + 150);
	;
}

void WeaponLayer::menuEscCallback(cocos2d::Ref* pSender)
{
	this->removeFromParentAndCleanup(true);
}
