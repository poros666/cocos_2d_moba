#include"ArmorLayer.h"
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in StartSceneScene.cpp\n");
}

cocos2d::Layer* ArmorLayer::createLayer(Hero* owner)
{
	auto layer = new(std::nothrow)ArmorLayer();
	if (layer && layer->init(owner)) {
		layer->autorelease();
		return layer;
	}
	CC_SAFE_DELETE(layer);
	return nullptr;
}

bool ArmorLayer::init(Hero* owner)
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
		CC_CALLBACK_1(ArmorLayer::menuArmorOneCallback, this,owner)
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
		CC_CALLBACK_1(ArmorLayer::menuArmorTwoCallback, this,owner)
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
		CC_CALLBACK_1(ArmorLayer::menuArmorThreeCallback, this,owner)
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
		CC_CALLBACK_1(ArmorLayer::menuArmorFourCallback, this,owner)
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
		CC_CALLBACK_1(ArmorLayer::menuEscCallback, this)
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
	auto ArmorOne = MenuItemImage::create("equipment/armorone.jpg", "equipment/armorone.jpg");
	ArmorOne->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660));
	auto DescribeOne = MenuItemImage::create("equipment/Darmorone.png", "equipment/Darmorone.png");
	DescribeOne->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 50, origin.y + 660));

	auto ArmorTwo = MenuItemImage::create("equipment/armortwo.jpg", "equipment/armortwo.jpg");
	ArmorTwo->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 527));
	auto DescribeTwo = MenuItemImage::create("equipment/Darmortwo.png", "equipment/Darmortwo.png");
	DescribeTwo->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 50, origin.y + 527));

	auto ArmorThree = MenuItemImage::create("equipment/armorthree.jpg", "equipment/armorthree.jpg");
	ArmorThree->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 393));
	auto DescribeThree = MenuItemImage::create("equipment/Darmorthree.png", "equipment/Darmorthree.png");
	DescribeThree->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 50, origin.y + 393));

	auto ArmorFour = MenuItemImage::create("equipment/armorfour.jpg", "equipment/armorfour.jpg");
	ArmorFour->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 260));
	auto DescribeFour = MenuItemImage::create("equipment/Darmorfour.png", "equipment/Darmorfour.png");
	DescribeFour->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 50, origin.y + 260));





	auto menu = Menu::create(BuyOne, BuyTwo, BuyThree, BuyFour, 
		ArmorOne, ArmorTwo, ArmorThree, ArmorFour,
		DescribeOne, DescribeTwo, DescribeThree, DescribeFour,
		NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 3);

	;

	return true;
}

void ArmorLayer::menuArmorOneCallback(cocos2d::Ref* pSender, Hero* owner)
{
	int money = owner->getGold();
	if (money >= 300 && owner->equipment.size() < 6) {
		owner->setGold(money - 300);
		owner->setInitHealthPointsLimit(owner->getInitHealthPointsLimit() + 200);
		owner->setHealthPoints(owner->getHealthPoints() + 200);
		owner->equipment.push_back("ArmorOne");
	}
}

void ArmorLayer::menuArmorTwoCallback(cocos2d::Ref* pSender, Hero* owner)
{
	int money = owner->getGold();
	if (money >= 700 && owner->equipment.size() < 6) {
		owner->setGold(money - 700);
		owner->setInitHealthPointsLimit(owner->getInitHealthPointsLimit() + 500);
		owner->setHealthPoints(owner->getHealthPoints() + 500);
		owner->equipment.push_back("ArmorTwo");
	}

}

void ArmorLayer::menuArmorThreeCallback(cocos2d::Ref* pSnender, Hero* owner)
{
	int money = owner->getGold();
	if (money >= 1500 && owner->equipment.size() < 6) {
		owner->setGold(money - 1500);
		owner->setInitHealthPointsLimit(owner->getInitHealthPointsLimit() + 900);
		owner->setHealthPoints(owner->getHealthPoints() + 900);
		owner->equipment.push_back("ArmorThree");
	}

}

void ArmorLayer::menuArmorFourCallback(cocos2d::Ref* pSender, Hero* owner)
{
	int money = owner->getGold();
	if (money >= 3000 && owner->equipment.size() < 6) {
		owner->setGold(money - 3000);
		owner->setInitHealthPointsLimit(owner->getInitHealthPointsLimit() + 2000);
		owner->setHealthPoints(owner->getHealthPoints() + 2000);
		owner->equipment.push_back("ArmorFour");
	}
}

void ArmorLayer::menuEscCallback(cocos2d::Ref* pSender)
{
	this->removeFromParentAndCleanup(true);
}
