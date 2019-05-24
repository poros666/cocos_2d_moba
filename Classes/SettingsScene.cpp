//���ò˵�����
//�ζ���
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
	if (!Scene::init())//�жϳ�ʼ���Ƿ�ɹ�
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	//���ɷ��ذ�ť
	auto backItem = MenuItemImage::create(
		"BackNormal.jpg",
		"BackSelected.jpg",
		CC_CALLBACK_1(SettingsScene::menuBackCallback, this));

	if (backItem == nullptr ||
		backItem->getContentSize().width <= 0 ||
		backItem->getContentSize().height <= 0)
	{
		problemLoading("'BackNormal.jpg' and 'BackSelected.jpg'");
	}
	else
	{
		float x = origin.x + visibleSize.width /2;
		float y = origin.y + visibleSize.height / 2 - 240;
		backItem->setPosition(Vec2(x, y));
	}
	auto bgmItem = MenuItemImage::create("BGM.jpg","BGM.jpg");
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
	auto bottonItem = MenuItemImage::create("Botton.jpg", "Botton.jpg");
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

	auto menu = Menu::create(bgmItem, bottonItem, backItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	//���ñ���ͼƬ
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

void SettingsScene::menuBackCallback(Ref* pSender)//�����ؼ��������˵�
{
	auto scene = StartScene::createScene();
	auto reScene = TransitionFadeUp::create(0.8f, scene);
	Director::getInstance()->pushScene(reScene);
	SimpleAudioEngine::getInstance()->playEffect("Botton.wav");
}
void SettingsScene::BGMsetBottomCallback(Ref* pSender)
{

}