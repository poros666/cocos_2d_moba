//此处的setposition一样需要在之后加入角色坐标之后进行修改

#include "EquipmentLayer.h"

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
	if (!Layer::init()) {
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto SwordOne = MenuItemImage::create(
		"equipment/swordone.png",
		"equipment/swoedone.png",
		CC_CALLBACK_1(EquipmentLayer::menuSwordOneCallback, this)
	);
	if (SwordOne == nullptr ||
		SwordOne->getContentSize().width <= 0 ||
		SwordOne->getContentSize().height <= 0)
	{
		problemLoading("'equipment/swoedone.png' and 'equipment/swoedone.png'");
	}
	else
	{
		SwordOne->setPosition(Vec2(origin.x + visibleSize.width * 3 / 4 - 175, origin.y + 575));
	}
	//添加其他物品





	//
	auto menu = Menu::create(SwordOne, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 2);
	return true;

}

void EquipmentLayer::menuSwordOneCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->end();
}
