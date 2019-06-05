#include"ScoreBoard.h"
USING_NS_CC;
Layer* ScoreBoard::createLayer(Hero* Myhero)
{
	auto layer= ScoreBoard::create();
	ScoreBoard::Print(Myhero);
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
	auto sprite = Sprite::create("HelloWorld.png");
	sprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(sprite,1);
}
void ScoreBoard::Print(Hero* Myhero)
{
	;
}