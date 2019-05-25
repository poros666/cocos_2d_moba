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
	auto BackItem = MenuItemImage::create(
		"BackNormal.jpg",
		"BackSelected.jpg",
		CC_CALLBACK_1(OneMapScene::menuBackCallback, this)
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
	auto ShopItem = MenuItemImage::create(
		"ShopItem.png",
		"ShopItem.png",
		CC_CALLBACK_1(OneMapScene::menuShopCallback, this)
	);
	if (ShopItem == nullptr ||
		ShopItem->getContentSize().width <= 0 ||
		ShopItem->getContentSize().height<=0)
	{
		problemLoading("'ShopItem.png'");
	}
	else
	{
		float x = origin.x + visibleSize.width / 2 + 610;
		float y = origin.y + visibleSize.height / 2 + 370;
		ShopItem->setPosition(Vec2(x, y));
	}
	auto menu = Menu::create(BackItem,ShopItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 100);

	//创建瓦片地图
	_tileMap=TMXTiledMap::create("temmap/filemap.tmx");
	_tileMap->setAnchorPoint(Vec2(0,0));
	_tileMap->setPosition(Point(-3500,0));
	_tileMap->setTag(1000);
	this->addChild(_tileMap);
	_collidable = _tileMap->getLayer("collidable");
	

	return true;
}

void OneMapScene::menuBackCallback(cocos2d::Ref* pSender)//按按钮返回主菜单
{
	Director::getInstance()->popScene();
}

void OneMapScene::menuShopCallback(cocos2d::Ref* pSender)
{
}

void OneMapScene::setPlayerPosition(cocos2d::Vec2 position)
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

cocos2d::Vec2 OneMapScene::tileCoordFromPosition(cocos2d::Vec2 position)
{
	int x = position.x / _tileMap->getTileSize().width;
	int y =
		((_tileMap->getMapSize().height * _tileMap->getTileSize().height) - position.y) /
		_tileMap->getTileSize().height;
	return cocos2d::Vec2(x,y);
}

bool OneMapScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	log("onTouchBegan");
	return false;
}

void OneMapScene::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
	log("onTouchMoved");
}

void OneMapScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
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

