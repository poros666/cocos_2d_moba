//此处的setposition一样需要在之后加入角色坐标之后进行修改

#include "EquipmentLayer.h"
#include"WeaponLayer.h"
#include"ShoeLayer.h"
#include"ArmorLayer.h"
#include"RecoveryLayer.h"
cocos2d::Layer* EquipmentLayer::createLayer()
{
	return EquipmentLayer::create();
}
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in StartSceneScene.cpp\n");
}
bool EquipmentLayer::init()
{
	if (!Layer::init()) 
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto Weapon = MenuItemImage::create(
		"shop/weapon.png",
		"shop/weapon.png", 
		CC_CALLBACK_1(EquipmentLayer::menuWeaponCallback,this)
	);
	if (Weapon == nullptr ||
		Weapon->getContentSize().width <= 0 ||
		Weapon->getContentSize().height <= 0)
	{
		problemLoading("'shop/weapon.png' and 'shop/weapon.png'");
	}
	else
	{
		Weapon->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 -200, origin.y + 660));
	}
	//添加其他目录
	auto Shoe = MenuItemImage::create(
		"shop/shoe.png",
		"shop/shoe.png",
		CC_CALLBACK_1(EquipmentLayer::menuShoeCallback, this)
	);
	if (Shoe == nullptr ||
		Shoe->getContentSize().width <= 0 ||
		Shoe->getContentSize().height <= 0)
	{
		problemLoading("'shop/shoe.png' and 'shop/shoe.png'");
	}
	else
	{
		Shoe->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4-200, origin.y + 527));
	}

	auto Armor = MenuItemImage::create(
		"shop/armor.png",
		"shop/armor.png",
		CC_CALLBACK_1(EquipmentLayer::menuArmorCallback, this)
	);
	if (Armor == nullptr ||
		Armor->getContentSize().width <= 0 ||
		Armor->getContentSize().height <= 0)
	{
		problemLoading("'shop/armor.png' and 'shop/armor.png'");
	}
	else
	{
		Armor->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 -200, origin.y + 393));
	}

	auto Recovery = MenuItemImage::create(
		"shop/recovery.png",
		"shop/recovery.png",
		CC_CALLBACK_1(EquipmentLayer::menuRecoveryCallback, this)
	);
	if (Recovery == nullptr ||
		Recovery->getContentSize().width <= 0 ||
		Recovery->getContentSize().height <= 0)
	{
		problemLoading("'shop / recovery.png' and 'shop / recovery.png'");
	}
	else
	{
		Recovery->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4-200 , origin.y + 260));
	}

	//
	auto menu = Menu::create(Weapon,Shoe,Armor,Recovery,NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 2);
	return true;

}

void EquipmentLayer::menuWeaponCallback(cocos2d::Ref* pSender)
{
	auto layer=WeaponLayer::createLayer();
	this->addChild(layer, 60);
	layer->setVisible(true);
}

void EquipmentLayer::menuShoeCallback(cocos2d::Ref* pSender)
{
	auto layer = ShoeLayer::createLayer();
	this->addChild(layer, 60);
	layer->setVisible(true);
}

void EquipmentLayer::menuArmorCallback(cocos2d::Ref* pSender)
{
	auto layer = ArmorLayer::createLayer();
	this->addChild(layer, 60);
	layer->setVisible(true);
}

void EquipmentLayer::menuRecoveryCallback(cocos2d::Ref* pSender)
{
	auto layer = RecoveryLayer::createLayer();
	this->addChild(layer, 60);
	layer->setVisible(true);
}
