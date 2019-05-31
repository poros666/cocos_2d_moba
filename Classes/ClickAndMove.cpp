#include "ClickAndMove.h"

USING_NS_CC;

enum
{
	kTagSprite = 1,
};

ClickAndMoveCase::ClickAndMoveCase()
{
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(ClickAndMoveCase::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(ClickAndMoveCase::onTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	sprite = Sprite::create("Zample.png");
	sprite->setPosition(Vec2(size.width / 2, size.height / 2));
	this->addChild(sprite);

	auto layer = LayerColor::create(Color4B(255, 255, 0, 255));
	addChild(layer, -1);

	addChild(sprite, 0, kTagSprite);
	sprite->setPosition(20, 150);

	sprite->runAction(JumpTo::create(4, Vec2(300, 48), 100, 4));

	layer->runAction(RepeatForever::create(
		Sequence::create(
			FadeIn::create(1),
			FadeOut::create(1),
			nullptr)
	));
}

bool ClickAndMoveCase::onTouchBegan(Touch* touch, Event* event)
{
	return true;
}

void ClickAndMoveCase::onTouchEnded(Touch* touch, Event* event)
{
	auto location = touch->getLocation();

	auto s = getChildByTag(kTagSprite);
	s->stopAllActions();
	s->runAction(MoveTo::create(1, Vec2(location.x, location.y)));
	float o = location.x - s->getPosition().x;
	float a = location.y - s->getPosition().y;
	float at = (float)CC_RADIANS_TO_DEGREES(atanf(o / a));

	if (a < 0)
	{
		if (o < 0)
			at = 180 + fabs(at);
		else
			at = 180 - fabs(at);
	}

	s->runAction(RotateTo::create(1, at));
}
/*ÈËÎïĞı×ª*/