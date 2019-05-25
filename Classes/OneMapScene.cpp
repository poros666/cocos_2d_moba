//1v1场景制作
//姚凯楠
//v0.1
#include "StartScene.h"
#include "OneMapScene.h"
USING_NS_CC;
Scene* OneMapScene::CreateScene()
{
	return OneMapScene::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
bool OneMapScene::init()
{
	if (!Scene::init())//判断初始化是否成功
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//生成按钮 返回主界面
	auto backItem = MenuItemImage::create(
		"BackNormal.jpg",
		"BackSelected.jpg",
		CC_CALLBACK_1(OneMapScene::menuBackCallback, this));
	if (backItem == nullptr ||
		backItem->getContentSize().width <= 0 ||
		backItem->getContentSize().height <= 0)
	{
		problemLoading("'BackNormal.jpg' and 'BackSelected.jpg'");
	}
	else
	{
		float x = origin.x + visibleSize.width / 2 - 520;
		float y = origin.y + visibleSize.height / 2 + 360;
		backItem->setPosition(Vec2(x, y));
	}
	auto menu = Menu::create(backItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 5);

	//创建瓦片地图
	auto map = TMXTiledMap::create("mapresource/1v1map.tmx");
	map->setAnchorPoint(Vec2(0,0));
	map->setPosition(Point(-2000, 0));
	map->setTag(1000);
	this->addChild(map,10);


	return true;
}

void OneMapScene::menuBackCallback(cocos2d::Ref* pSender)//按按钮返回主菜单
{
	Director::getInstance()->popScene();
}
