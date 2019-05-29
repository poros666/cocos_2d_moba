#include"Game.h"
int a = 0;
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
	this->scheduleUpdate();
	this->schedule(schedule_selector(Game::CreepsPrint),1,-1,2);
	this->schedule(schedule_selector(Game::test), 1);
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
	Myhero = Hero::creatWithHeroTypes(HeroTypeTest);
	Myhero->setPosition(Vec2(visibleSize.width / 2 - 100, visibleSize.height / 2 - 100));
	this->addChild(Myhero, 2);
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
	creep1->setPosition(Vec2(visibleSize.width / 2+a*10, visibleSize.height / 2));
	this->addChild(creep1, 2);
	a++;
}

void Game::update(float delta)
{
	//血条蓝条经验条的实时更新




	//英雄死亡监测
	if (Myhero->getHealthPoints() <= 0)
	{
		this->unscheduleUpdate();
		Game::HeroDie();
	}
}
void Game::HeroDie()
{
	Myhero->die();
	this->scheduleOnce(schedule_selector(Game::recreateHero), 1.0f);
}
void Game::recreateHero(float delta)
{
	Myhero->setVisible(true);
	Myhero->setHealthPoints(Myhero->getInitHealthPointsLimit());
	this->scheduleUpdate();
}
void Game::test(float delta)
{
	if (Myhero != nullptr)
	{
		Myhero->setHealthPoints(Myhero->getHealthPoints() - 3);
	}
}