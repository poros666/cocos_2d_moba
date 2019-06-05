//1v1³¡¾°ÖÆ×÷
//Ò¦¿­éª
//v0.1
#include "StartScene.h"
#include "OneMapLayer.h"
#include "Creeps.h"
#include "Tower.h"
#include "StatusLayer.h"
USING_NS_CC;
Layer* OneMapLayer::CreateLayer()
{
	return OneMapLayer::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}
bool OneMapLayer::init()
{
	if (!Layer::init())//ÅÐ¶Ï³õÊ¼»¯ÊÇ·ñ³É¹¦
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	
	//Éú³É°´Å¥ ·µ»ØÖ÷½çÃæ
	auto BackItem = MenuItemImage::create(
		"BackNormal.jpg",
		"BackSelected.jpg",
		CC_CALLBACK_1(OneMapLayer::menuBackCallback, this)
	);
	if (BackItem == nullptr ||
		BackItem->getContentSize().width <= 0 ||
		BackItem->getContentSize().height <= 0)
	{
		problemLoading("'BackNormal.jpg' and 'BackSelected.jpg'");
	}
	else
	{
		float x = origin.x + visibleSize.width / 2 - 520;
		float y = origin.y + visibleSize.height / 2 + 360;
		BackItem->setPosition(Vec2(x, y));
	}
	
	auto menu = Menu::create(BackItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 100);

	//´´½¨ÍßÆ¬µØÍ¼
	_tileMap=TMXTiledMap::create("temmap/filemap.tmx");
	_tileMap->setAnchorPoint(Vec2(0,0));
	_tileMap -> setPosition(Vec2(0, 0));
	_tileMap->setTag(1000);
	this->addChild(_tileMap,-1);
	_collidable = _tileMap->getLayer("collidable");
	
	///success1
	/*
	auto creep1 = Creep::create("creep_test.png");
	creep1->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(creep1, 500);
	*/
	//success2
	this->schedule(schedule_selector(OneMapLayer::UpdateViewPointCenter));
	return true;
}

void OneMapLayer::menuBackCallback(cocos2d::Ref* pSender)//°´°´Å¥·µ»ØÖ÷²Ëµ¥
{
	Director::getInstance()->popScene();
}






void OneMapLayer::setPlayerPosition(cocos2d::Vec2 position)
{
	Vec2 tileCoord = this->tileCoordFromPosition(position);
	int tileGid = _collidable->getTileGIDAt(tileCoord);
	if (tileGid > 0)
	{
		Value prop = _tileMap->getPropertiesForGID(tileGid);
		ValueMap propValueMap = prop.asValueMap();

		std::string collision = propValueMap["collidable"].asString();

		if (collision == "true")
		{
			CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("crash.wav");
			return;
		}
	}
	_player->setPosition(position);
}

cocos2d::Vec2 OneMapLayer::tileCoordFromPosition(cocos2d::Vec2 position)
{
	int x = position.x / _tileMap->getTileSize().width;
	int y =
		((_tileMap->getMapSize().height * _tileMap->getTileSize().height) - position.y) /
		_tileMap->getTileSize().height;
	return cocos2d::Vec2(x,y);
}


//将视角与人物锁定，并且不超过地图显示范围
void OneMapLayer::setViewPointCenter(cocos2d::Vec2 position)
{
	Size visibleSize = Director::getInstance()->getVisibleSize();
	int x = MAX(position.x, visibleSize.width / 2);
	int y = MAX(position.y, visibleSize.height / 2);

	x = MIN(x, (_tileMap->getMapSize().width * _tileMap->getTileSize().width)
		- visibleSize.width / 2);
	y = MIN(y, (_tileMap->getMapSize().height * _tileMap->getTileSize().height)
		- visibleSize.height / 2);
	Vec2 pointA = Vec2(visibleSize.width / 2, visibleSize.height / 2);
	Vec2 pointB = Vec2(x, y);
	Vec2 offSet = pointA - pointB;
	this->setPosition(offSet);
}
void OneMapLayer::UpdateViewPointCenter(float delat)
{
	setViewPointCenter(this->getChildByName("Myhero")->getPosition());
}











bool OneMapLayer::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	log("onTouchBegan");
	return false;
}

void OneMapLayer::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
	log("onTouchMoved");
}

void OneMapLayer::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	log("onTouchEnded");
	Vec2 touchLocation = touch->getLocation();

	Vec2 playerPos = _player->getPosition();
	Vec2 diff = touchLocation - playerPos;
	if (abs(diff.x) > abs(diff.y))
	{
		if (diff.x > 0)
		{
			playerPos.x += _tileMap->getTileSize().width;
			_player->runAction(FlipX::create(false));
		}
		else
		{
			playerPos.x -= _tileMap->getTileSize().width;
			_player->runAction(FlipX::create(false));
		}
	}
	else
	{
		if (diff.y > 0)
		{
			playerPos.y += _tileMap->getTileSize().height;
			_player->runAction(FlipX::create(false));
		}
		else
		{
			playerPos.y -= _tileMap->getTileSize().height;
			_player->runAction(FlipX::create(false));
		}
	}
	this->setPlayerPosition(playerPos);

}

