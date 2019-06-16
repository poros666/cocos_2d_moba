//ÉèÖÃ²Ëµ¥³¡¾°
//ÈÎ¶¬³¿
//version 0.5
//time 5/21
#include"SettingsScene.h"
USING_NS_CC;
using namespace CocosDenshion;
Scene* SettingsScene::createScene()
{
	return SettingsScene::create();
}
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
bool SettingsScene::init()
{
	if (!Scene::init())//ÅÐ¶Ï³õÊ¼»¯ÊÇ·ñ³É¹¦
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//Éú³É·µ»Ø°´Å¥
	auto backItem = MenuItemImage::create(
		"Bottom/EXIT.png",
		"Bottom/EXIT.png",
		CC_CALLBACK_1(SettingsScene::menuBackCallback, this));

	if (backItem == nullptr ||
		backItem->getContentSize().width <= 0 ||
		backItem->getContentSize().height <= 0)
	{
		problemLoading("'EXIT.png' and 'EXIT.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width /2;
		float y = origin.y + visibleSize.height / 2 - 240;
		backItem->setPosition(Vec2(x, y));
	}
	auto bgmItem = MenuItemImage::create("Bottom/BGM.jpg","Bottom/BGM.jpg");
	if (bgmItem == nullptr ||
		bgmItem->getContentSize().width <= 0 ||
		bgmItem->getContentSize().height <= 0)
	{
		problemLoading("'BGM.jpg'");
	}
	else
	{
		float x = origin.x + visibleSize.width / 2-60;
		float y = origin.y + visibleSize.height / 2 +120;
		bgmItem->setPosition(Vec2(x, y));
	}
	auto bottonItem = MenuItemImage::create("Bottom/Botton.jpg", "Bottom/Botton.jpg");
	if (bottonItem == nullptr ||
		bottonItem->getContentSize().width <= 0 ||
		bottonItem->getContentSize().height <= 0)
	{
		problemLoading("'Botton.jpg'");
	}
	else
	{
		float x = origin.x + visibleSize.width / 2-60;
		float y = origin.y + visibleSize.height / 2 ;
		bottonItem->setPosition(Vec2(x, y));
	}
	auto BGMonItem = MenuItemImage::create("Bottom/MUSICON.png","Bottom/MUSICON.png");
	auto BGMoffItem = MenuItemImage::create("Bottom/MUSICOFF.png","Bottom/MUSICOFF.png");
	auto BGMToggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(SettingsScene::BGMsetBottomCallback,this),BGMonItem,BGMoffItem,NULL);
	BGMToggleMenuItem->setPosition(Vec2(bgmItem->getPositionX()+180,bgmItem->getPositionY()));
	auto SoundonItem = MenuItemImage::create("Bottom/MUSICON.png", "Bottom/MUSICON.png");
	auto SoundoffItem = MenuItemImage::create("Bottom/MUSICOFF.png", "Bottom/MUSICOFF.png");
	auto SoundToggleMenuItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(SettingsScene::SoundsetBottomCallback, this), SoundonItem, SoundoffItem, NULL);
	SoundToggleMenuItem->setPosition(Vec2(bottonItem->getPositionX()+180, bottonItem->getPositionY()));
	auto menu = Menu::create(SoundToggleMenuItem,BGMToggleMenuItem,bgmItem, bottonItem, backItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	//ÉèÖÃ±³¾°Í¼Æ¬
	auto sprite = Sprite::create("transitionDoor.png");
	if (sprite == nullptr)
	{
		problemLoading("'transitionDoor.png'");
	}
	else
	{
		// position the sprite on the center of the screen
		sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

		// add the sprite as a child to this layer
		this->addChild(sprite, 0);
	}
	//»ñÈ¡ÓÃ»§ÉèÖÃ
	UserDefault* defualts = UserDefault::getInstance();
	if (defualts->getBoolForKey(MUSIC_KEY,true))
	{
		BGMToggleMenuItem->setSelectedIndex(0);
	}
	else
	{
		BGMToggleMenuItem->setSelectedIndex(1);
	}
	if (defualts->getBoolForKey(SOUND_KEY,true))
	{
		SoundToggleMenuItem->setSelectedIndex(0);
	}
	else
	{
		SoundToggleMenuItem->setSelectedIndex(1);
	}
	return true;
}

void SettingsScene::menuBackCallback(Ref* pSender)//°´·µ»Ø¼ü·µ»ØÖ÷²Ëµ¥
{
	auto scene = StartScene::createScene();
	auto reScene = TransitionFadeUp::create(0.8f, scene);
	Director::getInstance()->pushScene(reScene);
	if (UserDefault::getInstance()->getBoolForKey(SOUND_KEY, true))
	{
		SimpleAudioEngine::getInstance()->playEffect("Botton.wav");
	}
}
void SettingsScene::BGMsetBottomCallback(Ref* pSender)
{
	auto BGMToggleMenuItem = (MenuItemToggle*)pSender;
	UserDefault* defualts = UserDefault::getInstance();
	if (defualts->getBoolForKey(SOUND_KEY)) 
	{
		SimpleAudioEngine::getInstance()->playEffect("Botton.wav");
	}
	if (BGMToggleMenuItem->getSelectedIndex() == 1)
	{
		defualts->setBoolForKey(MUSIC_KEY,false);
		SimpleAudioEngine::getInstance()->stopBackgroundMusic("MyBGM.mp3'");
	}
	else
	{
		defualts->setBoolForKey(MUSIC_KEY,true);
		SimpleAudioEngine::getInstance()->playBackgroundMusic("MyBGM.mp3");
	}
}
void SettingsScene::SoundsetBottomCallback(Ref* pSender)
{
	auto SoundToggleItem= (MenuItemToggle*)pSender;
	UserDefault* defualts = UserDefault::getInstance();
	
	if (SoundToggleItem->getSelectedIndex() == 1)
	{
		defualts->setBoolForKey(SOUND_KEY,false);
	}
	else
	{
		defualts->setBoolForKey(SOUND_KEY,true);
		SimpleAudioEngine::getInstance()->playEffect("Botton.wav");
	}
}