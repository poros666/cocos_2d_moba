#include"ScoreBoard.h"
USING_NS_CC;
extern Hero* LeftHero;
extern Hero* RightHero;
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
	sprite->setScaleX(1.3);
	sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(sprite,1);
	string Leftinformation="Left:";
	char temp[10];
	sprintf(temp, "%d", LeftHero->getLevel());
	string Level = temp;
	Leftinformation +=  "  Level:"+Level;
	sprintf(temp, "%d", LeftHero->getGold());
	string Gold = temp;
	Leftinformation += "  Gold:" + Gold;
	sprintf(temp, "%d", RightHero->getDeath());
	string Kill = temp;
	Leftinformation += "  Kill:" + Kill;
	sprintf(temp, "%d", LeftHero->getDeath());
	string Death = temp;
	Leftinformation += "  Death:" + Death;
	auto Leftlabel = Label::createWithTTF(Leftinformation, "fonts/Marker Felt.ttf", 40);
	float x = origin.x + visibleSize.width / 2;
	float y = origin.y + visibleSize.height / 2 +Leftlabel->getContentSize().height;
	// position the label on the center of the screen
	Leftlabel->setPosition(Vec2(x, y));
	this->addChild(Leftlabel, 1);
	string Rightinformation = "Right:";
	sprintf(temp, "%d", RightHero->getLevel());
	Level = temp;
	Rightinformation += "  Level:" + Level;
	sprintf(temp, "%d", RightHero->getGold());
	Gold = temp;
	Rightinformation += "  Gold:" + Gold;
	Rightinformation += "  Kill:" + Death;
	Rightinformation += "  Death:" + Kill;
	auto Rightlabel = Label::createWithTTF(Rightinformation, "fonts/Marker Felt.ttf", 40);
	x = origin.x + visibleSize.width / 2;
	y = origin.y + visibleSize.height / 2 - Rightlabel->getContentSize().height;
	// position the label on the center of the screen
	Rightlabel->setPosition(Vec2(x, y));
	this->addChild(Rightlabel, 1);
}
