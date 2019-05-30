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
	this->schedule(schedule_selector(Game::CreepsPrint),1,-1,0);
	this->schedule(schedule_selector(Game::test), 1);
	return true;
}
void Game::MapLayerPrint()
{
	//if (UserDefault::getInstance()->getBoolForKey(SINGLE))
	//{
		auto Maplayer = OneMapLayer::CreateLayer();
	//}
	//else 
	//{ 
		//这里加载5v5地图如果有的话; 
	//}
	this->addChild(Maplayer, 0 ,"MapLayer");
}
void Game::StatusLayerPrint()
{
	auto Statuslayer = StatusLayer::createLayer();
	this->addChild(Statuslayer,3,"StatusLayer");
}

void Game::HeroPrint()
{
	//生成英雄的函数
	Myhero = Hero::creatWithHeroTypes(HeroTypeTest);
	Myhero->setPosition(Vec2(visibleSize.width / 2 - 100, visibleSize.height / 2 - 100));
	this->addChild(Myhero, 2);
	SetHpBar();
	SetManaBar();
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

void Game::SetHpBar()
{
	auto Healthbar = Sprite::create("healthbar.dds");
	HpBarProgress = ProgressTimer::create(Healthbar);
	HpBarProgress->setScale(0.5, 0.5);
	auto size = HpBarProgress->getContentSize();
	float x = visibleSize.width / 2;
	float y =size.height-7;
	HpBarProgress->setPosition(Vec2(x,y));
	HpBarProgress->setType(ProgressTimer::Type::BAR);
	HpBarProgress->setMidpoint(Vec2(0, 0));
	HpBarProgress->setBarChangeRate(Vec2(1, 0));
	HpBarProgress->setPercentage(100);
	this->addChild(HpBarProgress,4,"HpBarProgress");
	this->schedule(schedule_selector(Game::UpdateHpBar));
}
void Game::UpdateHpBar(float delta)
{
	float percentage = 100*Myhero->getHealthPoints() / Myhero->getInitHealthPointsLimit();
	if (percentage <= 0)
	{
		percentage = 0;
		this->unschedule(schedule_selector(Game::UpdateHpBar));
	}
	HpBarProgress->setPercentage(percentage);
}
void Game::SetManaBar()
{
	auto ManaBar = Sprite:: create("manabar.dds");
	ManaBarProgress = ProgressTimer::create(ManaBar);
	ManaBarProgress->setScale(0.5, 0.5);
	auto size = ManaBarProgress->getContentSize();
	float x = visibleSize.width / 2;
	float y = size.height/2-6;
	ManaBarProgress->setPosition(Vec2(x, y));
	ManaBarProgress->setType(ProgressTimer::Type::BAR);
	ManaBarProgress->setMidpoint(Vec2(0, 0));
	ManaBarProgress->setBarChangeRate(Vec2(1, 0));
	ManaBarProgress->setPercentage(100);
	this->addChild(ManaBarProgress, 4, "ManaBarProgress");
	this->schedule(schedule_selector(Game::UpdateManaBar));
}
void Game::UpdateManaBar(float delta)
{
	float percentage = 100 * Myhero->getManaPoints() / Myhero->getInitManaPointsLimit();
	if (percentage <= 0)
	{
		percentage = 0;
		this->unschedule(schedule_selector(Game::UpdateManaBar));
	}
	ManaBarProgress->setPercentage(percentage);
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
	this->schedule(schedule_selector(Game::UpdateHpBar));
	this->schedule(schedule_selector(Game::UpdateManaBar));

}
void Game::test(float delta)
{
	if (Myhero != nullptr)
	{
		Myhero->setHealthPoints(Myhero->getHealthPoints() - 10+Myhero->getHealthRecoverPoints());
	}
}