#include "EquipmentShowLayer.h"
int g_SellTimes=0;
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


void EquipmentShowLayer::updateEquipment(Hero* owner)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
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
	auto menu = Menu::create( EmptyOne, EmptyTwo, EmptyThree, EmptyFour, EmptyFive, EmptySix,
		NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 6+2*g_SellTimes);
	auto iter = owner->equipment.begin();
	for (int i = 0; iter != owner->equipment.end(); iter++, i++) {
		int temp = *iter;
		switch (temp)
		{
		case 11: {
			auto sprite = Sprite::create("equipment/swordone.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 7 + 2 * g_SellTimes);
			break;
		}case 12: {
			auto sprite = Sprite::create("equipment/swordtwo.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 7 + 2 * g_SellTimes);
			break;
		}case 13: {
			auto sprite = Sprite::create("equipment/swordthree.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 7 + 2 * g_SellTimes) ;
			break;
		}case 14: {
			auto sprite = Sprite::create("equipment/swordfour.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 7 + 2 * g_SellTimes);
			break;
		}case 21: {
			auto sprite = Sprite::create("equipment/shoeone.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 7 + 2 * g_SellTimes);
			break;
		}case 22: {
			auto sprite = Sprite::create("equipment/shoetwo.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 7 + 2 * g_SellTimes);
			break;
		}case 23: {
			auto sprite = Sprite::create("equipment/shoethree.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 7 + 2 * g_SellTimes);
			break;
		}case 24: {
			auto sprite = Sprite::create("equipment/shoefour.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 7 + 2 * g_SellTimes);
			break;
		}case 31: {
			auto sprite = Sprite::create("equipment/armorone.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 7 + 2 * g_SellTimes);
			break;
		}case 32: {
			auto sprite = Sprite::create("equipment/armortwo.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 7 + 2 * g_SellTimes);
			break;
		}case 33: {
			auto sprite = Sprite::create("equipment/armorthree.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 7 + 2 * g_SellTimes);
			break;
		}case 34: {
			auto sprite = Sprite::create("equipment/armorfour.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 7 + 2 * g_SellTimes);
			break;
		}case 41: {
			auto sprite = Sprite::create("equipment/recoveryone.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 7 + 2 * g_SellTimes);
			break;
		}case 42: {
			auto sprite = Sprite::create("equipment/recoverytwo.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 7 + 2 * g_SellTimes);
			break;
		}case 43: {
			auto sprite = Sprite::create("equipment/recoverythree.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 7 + 2 * g_SellTimes);
			break;
		}case 44: {
			auto sprite = Sprite::create("equipment/recoveryfour.jpg");
			sprite->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 125, origin.y + 660 - i * 80));
			this->addChild(sprite, 7 + 2 * g_SellTimes);
			break;
		}

		default:
			break;
		}
	}
}

void EquipmentShowLayer::menuSellOneCallback(Ref* pSender, Hero* owner)
{
	auto max = owner->equipment.size();
	if (max <= 0) {
		return;
	}
	auto iter = owner->equipment.begin();
	for (int i = 0;iter!=owner->equipment.end();i++) {
		if (i == 0) {
			deleteProperty(*iter, owner);
			iter=owner->equipment.erase(iter);
			g_SellTimes++;
		}
		else {
			iter++;
		}
	}
	updateEquipment(owner);
}

void EquipmentShowLayer::menuSellTwoCallback(Ref* pSender, Hero* owner)
{
	auto max = owner->equipment.size();
	if (max <= 1) {
		return;
	}
	auto iter = owner->equipment.begin();
	for (int i = 0; iter != owner->equipment.end(); i++) {
		if (i == 1) {

			deleteProperty(*iter, owner);
			iter = owner->equipment.erase(iter);
			g_SellTimes++;
		}
		else {
			iter++;
		}
	}
	updateEquipment(owner);
}

void EquipmentShowLayer::menuSellThreeCallback(Ref* pSender, Hero* owner)
{
	auto max = owner->equipment.size();
	if (max <= 2) {
		return;
	}
	auto iter = owner->equipment.begin();
	for (int i = 0; iter != owner->equipment.end(); i++) {
		if (i == 2) {

			deleteProperty(*iter, owner);
			iter = owner->equipment.erase(iter);
			g_SellTimes++;
		}
		else {
			iter++;
		}
	}
	updateEquipment(owner);
}

void EquipmentShowLayer::menuSellFourCallback(Ref* pSender, Hero* owner)
{
	auto max = owner->equipment.size();
	if (max <= 3) {
		return;
	}
	auto iter = owner->equipment.begin();
	for (int i = 0; iter != owner->equipment.end(); i++) {
		if (i == 3) {

			deleteProperty(*iter, owner);
			iter = owner->equipment.erase(iter);
			g_SellTimes++;
		}
		else {
			iter++;
		}
	}
	updateEquipment(owner);
}

void EquipmentShowLayer::menuSellFiveCallback(Ref* pSender, Hero* owner)
{
	auto max = owner->equipment.size();
	if (max <= 4) {
		return;
	}
	auto iter = owner->equipment.begin();
	for (int i = 0; iter != owner->equipment.end(); i++) {
		if (i == 4) {

			deleteProperty(*iter, owner);
			iter = owner->equipment.erase(iter);
			g_SellTimes++;
		}
		else {
			iter++;
		}
	}
	updateEquipment(owner);
}

void EquipmentShowLayer::menuSellSixCallback(Ref* pSender, Hero* owner)
{
	auto max = owner->equipment.size();
	if (max <= 5) {
		return;
	}
	auto iter = owner->equipment.begin();
	for (int i = 0; iter != owner->equipment.end(); i++) {
		if (i ==5) {

			deleteProperty(*iter, owner);
			iter = owner->equipment.erase(iter);
			g_SellTimes++;
		}
		else {
			iter++;
		}
	}
	updateEquipment(owner);
}


void EquipmentShowLayer::menuEscCallback(cocos2d::Ref* pSender)
{
	this->removeFromParentAndCleanup(true);
}


void EquipmentShowLayer::deleteProperty(int number, Hero* owner)
{
	switch (number)
	{
	case 11: {
		owner->setAtk(owner->getAtk()-20);
		break;
	}case 12: {
		owner->setAtk(owner->getAtk() - 50);
		break;
	}case 13: {
		owner->setAtk(owner->getAtk() - 90);
		break;

	}case 14: {
		owner->setAtk(owner->getAtk() - 150);
		break;

	}case 21: {
		owner->setMoveSpeed(owner->getMoveSpeed() - 30);
		break;

	}case 22: {
		owner->setMoveSpeed(owner->getMoveSpeed() - 45);
		break;

	}case 23: {
		owner->setMoveSpeed(owner->getMoveSpeed() - 60);
		break;

	}case 24: {
		owner->setMoveSpeed(owner->getMoveSpeed() - 90);
		break;

	}case 31: {
		owner->setHealthPoints(owner->getHealthPoints() - 200);
		owner->setInitHealthPointsLimit(owner->getInitHealthPointsLimit() - 200);
		break;

	}case 32: {
		owner->setHealthPoints(owner->getHealthPoints() - 500);
		owner->setInitHealthPointsLimit(owner->getInitHealthPointsLimit() - 500);
		break;

	}case 33: {
		owner->setHealthPoints(owner->getHealthPoints() - 900);
		owner->setInitHealthPointsLimit(owner->getInitHealthPointsLimit() - 900);
		break;

	}case 34: {
		owner->setHealthPoints(owner->getHealthPoints() - 2000);
		owner->setInitHealthPointsLimit(owner->getInitHealthPointsLimit() - 2000);
		break;

	}case 41: {
		owner->setManaPoints(owner->getManaPoints() - 200);
		owner->setInitManaPointsLimit(owner->getInitManaPointsLimit() - 200);
		break;

	}case 42: {
		owner->setManaPoints(owner->getManaPoints() - 500);
		owner->setInitManaPointsLimit(owner->getInitManaPointsLimit() - 500);
		break;

	}case 43: {
		owner->setManaPoints(owner->getManaPoints() - 900);
		owner->setInitManaPointsLimit(owner->getInitManaPointsLimit() - 900);
		break;

	}case 44: {
		owner->setManaPoints(owner->getManaPoints() - 2000);
		owner->setInitManaPointsLimit(owner->getInitManaPointsLimit() - 2000);
		break;

	}
	default:
		break;
	}
}

