#include"ChooseHeroScene.h"
USING_NS_CC;
using namespace CocosDenshion;
Scene* ChooseHeroScene::createScene()
{
	return ChooseHeroScene::create();
}
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
bool ChooseHeroScene::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//Éú³ÉºóÒáµÄÍ¼±ê
	auto EliteItem = MenuItemImage::create(
		"Character Model  res/SaurianElite_0001.png",
		"Character Model  res/SaurianElite_0001.png",
		CC_CALLBACK_1(ChooseHeroScene::menuEliteChoosedCallBack,this));
	if (EliteItem == nullptr ||
		EliteItem->getContentSize().width <= 0 ||
		EliteItem->getContentSize().height <= 0)
	{
		problemLoading("'BackNormal.jpg' and 'BackSelected.jpg'");
	}
	else
	{
		float x = origin.x + visibleSize.width / 2;
		float y = origin.y + visibleSize.height / 2;
		EliteItem->setPosition(Vec2(x, y));
	}

	auto ExecuItem = MenuItemImage::create(
		"Character Model  res/desertExecutioner_0001.png",
		"Character Model  res/desertExecutioner_0001.png",
		CC_CALLBACK_1(ChooseHeroScene::menuExecuChoosedCallBack, this));
	if (ExecuItem == nullptr ||
		ExecuItem->getContentSize().width <= 0 ||
		ExecuItem->getContentSize().height <= 0)
	{
		problemLoading("'BackNormal.jpg' and 'BackSelected.jpg'");
	}
	else
	{
		float x = origin.x + visibleSize.width / 2+200;
		float y = origin.y + visibleSize.height / 2;
		ExecuItem->setPosition(Vec2(x, y));
	}

	auto MunaraItem = MenuItemImage::create(
		"Character Model  res/desertMunra_0001.png",
		"Character Model  res/desertMunra_0001.png",
		CC_CALLBACK_1(ChooseHeroScene::menuMunaraChoosedCallBack, this));
	if (MunaraItem == nullptr ||
		MunaraItem->getContentSize().width <= 0 ||
		MunaraItem->getContentSize().height <= 0)
	{
		problemLoading("'BackNormal.jpg' and 'BackSelected.jpg'");
	}
	else
	{
		MunaraItem->setScale(2);
		float x = origin.x + visibleSize.width / 2 - 200;
		float y = origin.y + visibleSize.height / 2;
		MunaraItem->setPosition(Vec2(x, y));
	}
	//Éú³É½øÈë1v1µØÍ¼µÄÍ¼±ê
	auto OneMapItem = MenuItemImage::create(
		"EnterOneMap.png",
		"EnterOneMap.png",
		CC_CALLBACK_1(ChooseHeroScene::menuOneMapChoosedCallBack, this));
	if (OneMapItem == nullptr ||
		OneMapItem->getContentSize().width <= 0 ||
		OneMapItem->getContentSize().height <= 0)
	{
		problemLoading("'EnterOneMap.png' and 'EnterOneMap.png'");
	}
	else
	{

		float x = origin.x + visibleSize.width / 4;
		float y = origin.y + visibleSize.height / 2;
		OneMapItem->setPosition(Vec2(x, y));
	}

	//Éú³É·µ»Ø¼ü
	auto backItem = MenuItemImage::create(
		"Bottom/BackNormal.jpg",
		"Bottom/BackSelected.jpg",
		CC_CALLBACK_1(ChooseHeroScene::menuBackCallback, this));

	if (backItem == nullptr ||
		backItem->getContentSize().width <= 0 ||
		backItem->getContentSize().height <= 0)
	{
		problemLoading("'BackNormal.jpg' and 'BackSelected.jpg'");
	}
	else
	{
		float x = origin.x+130;
		float y = origin.y + visibleSize.height-45;
		backItem->setPosition(Vec2(x, y));
	}
	//

	auto menu = Menu::create(backItem,EliteItem,ExecuItem, MunaraItem, OneMapItem,NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	auto sprite = Sprite::create("SettingBackGround.png");
	if (sprite == nullptr)
	{
		problemLoading("'SettingBackGround.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

		// add the sprite as a child to this layer
		this->addChild(sprite, 0);
	}
	return true;
}
void ChooseHeroScene::menuEliteChoosedCallBack(cocos2d::Ref* pSender)
{
	UserDefault::getInstance()->setBoolForKey("Elite", true);
	UserDefault::getInstance()->setBoolForKey("Execu", false);
	UserDefault::getInstance()->setBoolForKey("Munara", false);
	auto scene = Game::createScene();
	auto reScene = TransitionFadeDown::create(0.8f, scene);
	Director::getInstance()->pushScene(reScene);
	if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY, true))
	{
		SimpleAudioEngine::getInstance()->playEffect("Botton.wav");
	}
}
void ChooseHeroScene::menuExecuChoosedCallBack(cocos2d::Ref* pSender)
{
	UserDefault::getInstance()->setBoolForKey("Elite", false);
	UserDefault::getInstance()->setBoolForKey("Execu", true);
	UserDefault::getInstance()->setBoolForKey("Munara", false);
	auto scene = Game::createScene();
	auto reScene = TransitionFadeDown::create(0.8f, scene);
	Director::getInstance()->pushScene(reScene);
	if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY, true))
	{
		SimpleAudioEngine::getInstance()->playEffect("Botton.wav");
	}
}
void ChooseHeroScene::menuMunaraChoosedCallBack(cocos2d::Ref* pSender)
{
	UserDefault::getInstance()->setBoolForKey("Elite", false);
	UserDefault::getInstance()->setBoolForKey("Execu", false);
	UserDefault::getInstance()->setBoolForKey("Munara", true);
	auto scene = Game::createScene();
	auto reScene = TransitionFadeDown::create(0.8f, scene);
	Director::getInstance()->pushScene(reScene);
	if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY, true))
	{
		SimpleAudioEngine::getInstance()->playEffect("Botton.wav");
	}
}
void ChooseHeroScene::menuBackCallback(Ref* pSender)//°´·µ»Ø¼ü·µ»ØÖ÷²Ëµ¥
{
	auto scene = ChooseModeScene::createScene();
	auto reScene = TransitionFadeDown::create(0.8f, scene);
	Director::getInstance()->pushScene(reScene);
	if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY, true))
	{
		SimpleAudioEngine::getInstance()->playEffect("Botton.wav");
	}
}

void ChooseHeroScene::menuOneMapChoosedCallBack(cocos2d::Ref* pSender)
{
	auto scene = Game::createScene();
	auto reScene = TransitionFadeDown::create(0.8f, scene);
	Director::getInstance()->pushScene(reScene);
	if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY, true))
	{
		SimpleAudioEngine::getInstance()->playEffect("Botton.wav");
	}
}
