#include "ShoeLayer.h"

cocos2d::Layer* ShoeLayer::createLayer(Hero* owner)
{
	auto layer = new(std::nothrow)ShoeLayer();
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

bool ShoeLayer::init(Hero* owner)
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
		CC_CALLBACK_1(ShoeLayer::menuShoeOneCallback, this,owner)
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
		CC_CALLBACK_1(ShoeLayer::menuShoeTwoCallback, this,owner)
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
		CC_CALLBACK_1(ShoeLayer::menuShoeThreeCallback, this,owner)
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
		CC_CALLBACK_1(ShoeLayer::menuShoeFourCallback, this,owner)
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
		Esc->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 100, origin.y + 160));
	}
	//
		//��������ͼƬ������
	auto ShoeOne = MenuItemImage::create("equipment/shoeone.jpg", "equipment/shoeone.jpg");
	ShoeOne->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660));
	auto DescribeOne = MenuItemImage::create("equipment/Dshoeone.png", "equipment/Dshoeone.png");
	DescribeOne->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 50, origin.y + 660));
	auto PriceOne = MenuItemImage::create("equipment/100.png", "equipment/100.png");
	PriceOne->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 210, origin.y + 660));
	auto ShoeTwo = MenuItemImage::create("equipment/shoetwo.jpg", "equipment/shoetwo.jpg");
	ShoeTwo->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 527));
	auto DescribeTwo = MenuItemImage::create("equipment/Dshoetwo.png", "equipment/Dshoetwo.png");
	DescribeTwo->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 50, origin.y + 527));
	auto PriceTwo = MenuItemImage::create("equipment/300.png", "equipment/300.png");
	PriceTwo->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 210, origin.y + 527));
	auto ShoeThree = MenuItemImage::create("equipment/shoethree.jpg", "equipment/shoethree.jpg");
	ShoeThree->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 393));
	auto DescribeThree = MenuItemImage::create("equipment/Dshoethree.png", "equipment/Dshoethree.png");
	DescribeThree->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 50, origin.y + 393));
	auto PriceThree = MenuItemImage::create("equipment/500.png", "equipment/500.png");
	PriceThree->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 210, origin.y + 393));
	auto ShoeFour = MenuItemImage::create("equipment/shoefour.jpg", "equipment/shoefour.jpg");
	ShoeFour->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 260));
	auto DescribeFour = MenuItemImage::create("equipment/Dshoefour.png", "equipment/Dshoefour.png");
	DescribeFour->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 50, origin.y + 260));
	auto PriceFour = MenuItemImage::create("equipment/999.png", "equipment/999.png");
	PriceFour->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 210, origin.y + 260));





	auto menu = Menu::create(BuyOne, BuyTwo, BuyThree, BuyFour,
		ShoeOne, ShoeTwo, ShoeThree, ShoeFour,
		DescribeOne, DescribeTwo, DescribeThree, DescribeFour,
		PriceOne, PriceTwo, PriceThree, PriceFour,
		NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 3);

	;

	return true;
}

void ShoeLayer::menuShoeOneCallback(cocos2d::Ref* pSender, Hero* owner)
{
	int money = owner->getGold();
	if (money >= 100 && owner->equipment.size() < 6) {
		owner->setGold(money - 100);
		owner->setMoveSpeed(owner->getMoveSpeed() + 30);
		owner->equipment.push_back(21);
	}

}

void ShoeLayer::menuShoeTwoCallback(cocos2d::Ref* pSender, Hero* owner)
{
	int money = owner->getGold();
	if (money >= 300 && owner->equipment.size() < 6) {
		owner->setGold(money - 300);
		owner->setMoveSpeed(owner->getMoveSpeed() + 45);
		owner->equipment.push_back(22);
	}
}

void ShoeLayer::menuShoeThreeCallback(cocos2d::Ref* pSnender, Hero* owner)
{
	int money = owner->getGold();
	if (money >= 500 && owner->equipment.size() < 6) {
		owner->setGold(money - 500);
		owner->setMoveSpeed(owner->getMoveSpeed() + 60);
		owner->equipment.push_back(23);
	}
}

void ShoeLayer::menuShoeFourCallback(cocos2d::Ref* pSender, Hero* owner)
{
	int money = owner->getGold();
	if (money >= 999 && owner->equipment.size() < 6) {
		owner->setGold(money - 999);
		owner->setMoveSpeed(owner->getMoveSpeed() + 90);
		owner->equipment.push_back(24);
	}
}

void ShoeLayer::menuEscCallback(cocos2d::Ref* pSender)
{
	this->removeFromParentAndCleanup(true);
}
