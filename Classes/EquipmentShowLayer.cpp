#include "EquipmentShowLayer.h"

cocos2d::Layer* EquipmentShowLayer::createLayer(Hero* owner)
{
	auto layer = new(std::nothrow)EquipmentShowLayer();
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
bool EquipmentShowLayer::init(Hero* owner)
{
	if (!Layer::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto ShowBackground = MenuItemImage::create("show.jpg", "show.jpg");
	ShowBackground->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 + 50, origin.y + 470));
	auto background = Menu::create(ShowBackground, NULL);
	background->setPosition(Vec2::ZERO);
	this->addChild(background, 1);
	auto ShowEsc = MenuItemImage::create(
		"shop/shopesc.jpg",
		"shop/shopesc.jpg",
		CC_CALLBACK_1(EquipmentShowLayer::menuEscCallback, this)
	);
	if (ShowEsc == nullptr ||
		ShowEsc->getContentSize().width <= 0 ||
		ShowEsc->getContentSize().height <= 0)
	{
		problemLoading("'shop/shopbackground.jpg' and 'shop/shopbackground.jpg'");
	}
	else
	{
		ShowEsc->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 175, origin.y + 775));
	}
	auto EmptyOne = MenuItemImage::create("equipment/empty.png", "equipment/empty.png");
	EmptyOne->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660));
	auto EmptyTwo = MenuItemImage::create("equipment/empty.png", "equipment/empty.png");
	EmptyTwo->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 580));
	auto EmptyThree = MenuItemImage::create("equipment/empty.png", "equipment/empty.png");
	EmptyThree->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 500));
	auto EmptyFour = MenuItemImage::create("equipment/empty.png", "equipment/empty.png");
	EmptyFour->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 420));
	auto EmptyFive = MenuItemImage::create("equipment/empty.png", "equipment/empty.png");
	EmptyFive->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 340));
	auto EmptySix = MenuItemImage::create("equipment/empty.png", "equipment/empty.png");
	EmptySix->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 260));
	auto SellOne = MenuItemImage::create("equipment/sell.png", "equipment/sell.png", CC_CALLBACK_1(EquipmentShowLayer::menuSellOneCallback,this,owner));
	SellOne->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4, origin.y + 660));
	auto SellTwo = MenuItemImage::create("equipment/sell.png", "equipment/sell.png", CC_CALLBACK_1(EquipmentShowLayer::menuSellTwoCallback, this, owner));
	SellTwo->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4, origin.y + 580));
	auto SellThree = MenuItemImage::create("equipment/sell.png", "equipment/sell.png", CC_CALLBACK_1(EquipmentShowLayer::menuSellThreeCallback, this, owner));
	SellThree->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4, origin.y + 500));
	auto SellFour = MenuItemImage::create("equipment/sell.png", "equipment/sell.png", CC_CALLBACK_1(EquipmentShowLayer::menuSellFourCallback, this, owner));
	SellFour->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4, origin.y + 420));
	auto SellFive = MenuItemImage::create("equipment/sell.png", "equipment/sell.png", CC_CALLBACK_1(EquipmentShowLayer::menuSellFiveCallback, this, owner));
	SellFive->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4, origin.y + 340));
	auto SellSix = MenuItemImage::create("equipment/sell.png", "equipment/sell.png", CC_CALLBACK_1(EquipmentShowLayer::menuSellSixCallback, this, owner));
	SellSix->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4, origin.y + 260));


	auto menu = Menu::create(ShowEsc,EmptyOne,EmptyTwo,EmptyThree,EmptyFour,EmptyFive,EmptySix, 
		SellOne,SellTwo,SellThree,SellFour,SellFive,SellSix,
		NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 2);

	auto iter = owner->equipment.begin();
	for (int i = 0; iter != owner->equipment.end(); iter++, i++) {
		int temp = *iter;
		switch (temp)
		{
		case 11:{
			auto sprite = Sprite::create("equipment/swordone.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660-i*80));
			this->addChild(sprite,3);
			break;
		}case 12:{
			auto sprite = Sprite::create("equipment/swordtwo.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite,3);
			break;
		}case 13:{
			auto sprite = Sprite::create("equipment/swordthree.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 3);
			break;
		}case 14:{
			auto sprite = Sprite::create("equipment/swordfour.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 3);
			break;
		}case 21: {
			auto sprite = Sprite::create("equipment/shoeone.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 3);
			break;
		}case 22: {
			auto sprite = Sprite::create("equipment/shoetwo.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 3);
			break;
		}case 23: {
			auto sprite = Sprite::create("equipment/shoethree.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 3);
			break;
		}case 24: {
			auto sprite = Sprite::create("equipment/shoefour.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 3);
			break;
		}case 31: {
			auto sprite = Sprite::create("equipment/armorone.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 3);
			break;
		}case 32: {
			auto sprite = Sprite::create("equipment/armortwo.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 3);
			break;
		}case 33: {
			auto sprite = Sprite::create("equipment/armorthree.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 3);
			break;
		}case 34: {
			auto sprite = Sprite::create("equipment/armorfour.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 3);
			break;
		}case 41: {
			auto sprite = Sprite::create("equipment/recoveryone.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 3);
			break;	
		}case 42: {
			auto sprite = Sprite::create("equipment/recoverytwo.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 3);
			break;
		}case 43: {
			auto sprite = Sprite::create("equipment/recoverythree.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 3);
			break;
		}case 44: {
			auto sprite = Sprite::create("equipment/recoveryfour.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 3);
			break;
		}
				 
		default:
			break;
		}
	}
	return true;
}

void EquipmentShowLayer::menuSellOneCallback(Ref* pSender, Hero* owner)
{
	auto max = owner->equipment.size();
	if (max <= 0) {
		return;
	}

}

void EquipmentShowLayer::menuSellTwoCallback(Ref* pSender, Hero* owner)
{
}

void EquipmentShowLayer::menuSellThreeCallback(Ref* pSender, Hero* owner)
{
}

void EquipmentShowLayer::menuSellFourCallback(Ref* pSender, Hero* owner)
{
}

void EquipmentShowLayer::menuSellFiveCallback(Ref* pSender, Hero* owner)
{
}

void EquipmentShowLayer::menuSellSixCallback(Ref* pSender, Hero* owner)
{
}

void EquipmentShowLayer::menuEscCallback(cocos2d::Ref* pSender)
{
	this->removeFromParentAndCleanup(true);
}
