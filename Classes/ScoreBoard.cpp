#include"ScoreBoard.h"
USING_NS_CC;
extern Hero* MyHero;
extern Hero* OtherHero;
Layer* ScoreBoard::createLayer()
{
	auto layer= ScoreBoard::create();
	return layer;
}
bool ScoreBoard::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto sprite = Sprite::create("Scoreboard.jpg");
	sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(sprite,1);
	string Myinformation="You:";
	char temp[10];
	sprintf(temp, "%d", MyHero->getLevel());
	string Level = temp;
	Myinformation +=  "  Level:"+Level;
	sprintf(temp, "%d", MyHero->getGold());
	string Gold = temp;
	Myinformation += "  Gold:" + Gold;
	auto Mylabel = Label::createWithTTF(Myinformation, "fonts/Marker Felt.ttf", 40);
	float x = origin.x + visibleSize.width / 2;
	float y = origin.y + visibleSize.height / 2 +Mylabel->getContentSize().height;
	// position the label on the center of the screen
	Mylabel->setPosition(Vec2(x, y));
	this->addChild(Mylabel, 1);
	string Enemyinformation = "Enemy:";
	sprintf(temp, "%d", OtherHero->getLevel());
	Level = temp;
	Enemyinformation += "  Level:" + Level;
	sprintf(temp, "%d", OtherHero->getGold());
	Gold = temp;
	Enemyinformation += "  Gold:" + Gold;
	auto Enemylabel = Label::createWithTTF(Enemyinformation, "fonts/Marker Felt.ttf", 40);
	x = origin.x + visibleSize.width / 2;
	y = origin.y + visibleSize.height / 2 - Enemylabel->getContentSize().height;
	// position the label on the center of the screen
	Enemylabel->setPosition(Vec2(x, y));
	this->addChild(Enemylabel, 1);
}
