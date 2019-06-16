#include "ChooseModeScene.h"
#include"Game.h"
USING_NS_CC;
using namespace CocosDenshion;
Scene* ChooseModeScene::createScene()
{
	return ChooseModeScene::create();
}
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
bool ChooseModeScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//模式选择菜单
	auto modeItem = MenuItemImage::create("Bottom/Mode.jpg","Bottom/Mode.jpg");
	modeItem->setPosition(modeItem->getScaleX()+160,visibleSize.height/2+60);
	auto ModeonlineItem = MenuItemImage::create("Bottom/Online.jpg","Bottom/Online.jpg");
	auto ModeofflineItem = MenuItemImage::create("Bottom/Offline.jpg", "Bottom/Offline.jpg");
	auto modeToggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(ChooseModeScene::modeSetCallback,this), ModeofflineItem,ModeonlineItem,NULL );
	modeToggleMenuItem->setPosition(modeItem->getScaleX() + 160, visibleSize.height / 2 - 60);
	//地图选择菜单
	auto mapItem = MenuItemImage::create("Bottom/Map.jpg", "Bottom/Map.jpg");
	mapItem->setPosition(visibleSize.width-160, visibleSize.height / 2 + 60);
	auto MapSingleItem = MenuItemImage::create("Bottom/1V1.jpg", "Bottom/1V1.jpg");
	auto MapTeamItem = MenuItemImage::create("Bottom/5V5.jpg", "Bottom/5V5.jpg");
	auto mapToggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(ChooseModeScene::mapSetCallback, this), MapSingleItem, MapTeamItem, NULL);
	mapToggleMenuItem->setPosition(visibleSize.width - 160, visibleSize.height / 2 - 60);



	//生成返回键
	auto backItem = MenuItemImage::create(
		"Bottom/BackNormal.jpg",
		"Bottom/BackSelected.jpg",
		CC_CALLBACK_1(ChooseModeScene::menuBackCallback, this));

	if (backItem == nullptr ||
		backItem->getContentSize().width <= 0 ||
		backItem->getContentSize().height <= 0)
	{
		problemLoading("'BackNormal.jpg' and 'BackSelected.jpg'");
	}
	else
	{
		float x = origin.x + 130;
		float y = origin.y + visibleSize.height - 45;
		backItem->setPosition(Vec2(x, y));
	}
	//生成开始键
	auto startItem = MenuItemImage::create(
		"Bottom/StartNormal.jpg",
		"Bottom/StartSelected.jpg",
		CC_CALLBACK_1(ChooseModeScene::startGameCallback, this));
	if (startItem == nullptr ||
		startItem->getContentSize().width <= 0 ||
		startItem->getContentSize().height <= 0)
	{
		problemLoading("'StartNormal.png' and 'StartSelected.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width / 2;
		float y = origin.y + visibleSize.height / 2 - 240;
		startItem->setPosition(Vec2(x, y));
	}
	auto menu = Menu::create(mapItem,mapToggleMenuItem,modeItem,modeToggleMenuItem,startItem,backItem,NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	auto sprite = Sprite::create("ChooseModeBackGround.jpg");
	if (sprite == nullptr)
	{
		problemLoading("'ChooseModeBackGround.jpg'");
	}
	else
	{
		// position the sprite on the center of the screen
		sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

		// add the sprite as a child to this layer
		this->addChild(sprite, 0);
	}
	//获取用户设置
	UserDefault* defualts = UserDefault::getInstance();
	if (defualts->getBoolForKey(OFF_LINE, true))
	{
		modeToggleMenuItem->setSelectedIndex(0);
	}
	else
	{
		modeToggleMenuItem->setSelectedIndex(1);
	}
	if (defualts->getBoolForKey(SINGLE, true))
	{
		mapToggleMenuItem->setSelectedIndex(0);
	}
	else
	{
		mapToggleMenuItem->setSelectedIndex(1);
	}
	return true;
}

void ChooseModeScene::menuBackCallback(Ref* pSender)//按返回键返回主菜单
{
	auto scene = StartScene::createScene();
	auto reScene = TransitionFadeDown::create(0.8f, scene);
	Director::getInstance()->pushScene(reScene);
	if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY, true))
	{
		SimpleAudioEngine::getInstance()->playEffect("Botton.wav");
	}
}

void ChooseModeScene::startGameCallback(Ref* pSender)
{
	auto scene = ChooseHeroScene::createScene();
	auto reScene = TransitionFadeUp::create(0.8f, scene);
	Director::getInstance()->pushScene(reScene);
	if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY, true))
	{
		SimpleAudioEngine::getInstance()->playEffect("Botton.wav");
	}
}

void ChooseModeScene::modeSetCallback(Ref* pSender)
{
	auto modeToggleMenuItem = (MenuItemToggle*)pSender;
	UserDefault* defualts = UserDefault::getInstance();
	if (modeToggleMenuItem->getSelectedIndex() == 1)
	{
		defualts->setBoolForKey(OFF_LINE, false);
	}
	else
	{
		defualts->setBoolForKey(OFF_LINE, true);
	}
	if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY, true))
	{
		SimpleAudioEngine::getInstance()->playEffect("Botton.wav");
	}
}
void ChooseModeScene::mapSetCallback(Ref* pSender)
{
	auto mapToggleMenuItem = (MenuItemToggle*)pSender;
	UserDefault* defualts = UserDefault::getInstance();
	if (mapToggleMenuItem->getSelectedIndex() == 1)
	{
		defualts->setBoolForKey(SINGLE, false);
	}
	else
	{
		defualts->setBoolForKey(SINGLE, true);
	}
	if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY, true))
	{
		SimpleAudioEngine::getInstance()->playEffect("Botton.wav");
	}
}