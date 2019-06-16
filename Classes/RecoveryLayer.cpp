#include "RecoveryLayer.h"

cocos2d::Layer* RecoveryLayer::createLayer(Hero* owner)
{
	auto layer = new(std::nothrow)RecoveryLayer();
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


bool RecoveryLayer::init(Hero* owner)
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
		CC_CALLBACK_1(RecoveryLayer::menuWeaponOneCallback, this,owner)
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
		CC_CALLBACK_1(RecoveryLayer::menuWeaponTwoCallback, this,owner)
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
		CC_CALLBACK_1(RecoveryLayer::menuWeaponThreeCallback, this,owner)
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
		CC_CALLBACK_1(RecoveryLayer::menuWeaponFourCallback, this,owner)
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
	}
	//
		//·ÅÖÃÎäÆ÷Í¼Æ¬ºÍÃèÊö
	auto RecoveryOne = MenuItemImage::create("equipment/recoveryone.jpg", "equipment/recovery.jpg");
	RecoveryOne->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660));
	auto DescribeOne = MenuItemImage::create("equipment/Drecoveryone.png", "equipment/Drecoveryone.png");
	DescribeOne->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 50, origin.y + 660));
	auto PriceOne = MenuItemImage::create("equipment/100.png", "equipment/100.png");
	PriceOne->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 210, origin.y + 660));
	auto RecoveryTwo = MenuItemImage::create("equipment/recoverytwo.jpg", "equipment/recoverytwo.jpg");
	RecoveryTwo->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 527));
	auto DescribeTwo = MenuItemImage::create("equipment/Drecoverytwo.png", "equipment/Drecoverytwo.png");
	DescribeTwo->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 50, origin.y + 527));
	auto PriceTwo = MenuItemImage::create("equipment/300.png", "equipment/300.png");
	PriceTwo->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 210, origin.y + 527));
	auto RecoveryThree = MenuItemImage::create("equipment/recoverythree.jpg", "equipment/recoverythree.jpg");
	RecoveryThree->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 393));
	auto DescribeThree = MenuItemImage::create("equipment/Drecoverythree.png", "equipment/Drecoverythree.png");
	DescribeThree->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 50, origin.y + 393));
	auto PriceThree = MenuItemImage::create("equipment/500.png", "equipment/500.png");
	PriceThree->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 210, origin.y + 393));
	auto RecoveryFour = MenuItemImage::create("equipment/recoveryfour.jpg", "equipment/recoveryfour.jpg");
	RecoveryFour->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 260));
	auto DescribeFour = MenuItemImage::create("equipment/Drecoveryfour.png", "equipment/Drecoveryfour.png");
	DescribeFour->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 50, origin.y + 260));
	auto PriceFour = MenuItemImage::create("equipment/999.png", "equipment/999.png");
	PriceFour->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 210, origin.y + 260));





	auto menu = Menu::create(BuyOne, BuyTwo, BuyThree, BuyFour, 
		RecoveryOne, RecoveryTwo, RecoveryThree, RecoveryFour,
		DescribeOne, DescribeTwo, DescribeThree, DescribeFour,
		PriceOne, PriceTwo, PriceThree, PriceFour,
		NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 3);

	;

	return true;
}

void RecoveryLayer::menuWeaponOneCallback(cocos2d::Ref* pSender, Hero* owner)
{
	int money = owner->getGold();
	if (money >= 100 && owner->equipment.size() < 6) {
		owner->setGold(money - 100);
		owner->setInitManaPointsLimit(owner->getInitManaPointsLimit() + 200);
		owner->setManaPoints(owner->getManaPoints() + 200);
		owner->equipment.push_back(41);
	}

}

void RecoveryLayer::menuWeaponTwoCallback(cocos2d::Ref* pSender, Hero* owner)
{
	int money = owner->getGold();
	if (money >= 300 && owner->equipment.size() < 6) {
		owner->setGold(money - 300);
		owner->setInitManaPointsLimit(owner->getInitManaPointsLimit() + 500);
		owner->setManaPoints(owner->getManaPoints() + 500);
		owner->equipment.push_back(42);
	}
}

void RecoveryLayer::menuWeaponThreeCallback(cocos2d::Ref* pSnender, Hero* owner)
{
	int money = owner->getGold();
	if (money >= 500 && owner->equipment.size() < 6) {
		owner->setGold(money - 500);
		owner->setInitManaPointsLimit(owner->getInitManaPointsLimit() + 900);
		owner->setManaPoints(owner->getManaPoints() + 900);
		owner->equipment.push_back(43);
	}
}

void RecoveryLayer::menuWeaponFourCallback(cocos2d::Ref* pSender, Hero* owner)
{
	int money = owner->getGold();
	if (money >= 999 && owner->equipment.size() < 6) {
		owner->setGold(money - 999);
		owner->setInitManaPointsLimit(owner->getInitManaPointsLimit() + 2000);
		owner->setManaPoints(owner->getManaPoints() + 2000);
		owner->equipment.push_back(44);
	}

}

void RecoveryLayer::menuEscCallback(cocos2d::Ref* pSender)
{
	this->removeFromParentAndCleanup(true);
}
