#include"Game.h"
Scene* Game::createScene()
{
	return Game::create();
}

bool Game::init()
{
	if (!Scene::init())
	{
		return false;
	}
	MapLayerPrint();
	HeroPrint();
	StatusLayerPrint();
	TowerPrint();
	this->schedule(schedule_selector(Game::CreepsPrint),30,-1,10);
	
	return true;
}
void Game::MapLayerPrint()
{
	//if (UserDefault::getInstance()->getBoolForKey(SINGLE))
	//{
		auto layer = OneMapLayer::CreateLayer();
	//}
	//else 
	//{ 
		//这里加载5v5地图如果有的话; 
	//}
	this->addChild(layer, 0);
}
void Game::StatusLayerPrint()
{
	auto layer = StatusLayer::createLayer();
	this->addChild(layer,3);
}

void Game::HeroPrint()
{
	//生成英雄的函数
	auto hero = Hero::creatWithHeroTypes(HeroTypeTest);
	hero->setPosition(Vec2(visibleSize.width / 2 - 100, visibleSize.height / 2 - 100));
	this->addChild(hero, 2);
}


void Game::TowerPrint()
{
	//放置塔的函数
	auto tower = Tower::creatWithTowerTypes(TowerTypeTest);
	tower->setPosition(Vec2(visibleSize.width / 2 + 100, visibleSize.height / 2 + 100));
	this->addChild(tower, 2);
}


void Game::CreepsPrint(float delta)
{
	//生成兵的函数
	auto creep1 = Creep::creatWithCreepTypes(CreepTypeTest);
	creep1->setPosition(Vec2(visibleSize.width / 2+delta, visibleSize.height / 2+delta));
	this->addChild(creep1, 2);
}

void Game::update(float delta)
{
	//血条蓝条经验条的实时更新

}
