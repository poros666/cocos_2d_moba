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
		//�������5v5��ͼ����еĻ�; 
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
	//����Ӣ�۵ĺ���
	Myhero = Hero::creatWithHeroTypes(HeroTypeTest);
	Myhero->setPosition(Vec2(visibleSize.width / 2 - 100, visibleSize.height / 2 - 100));
	this->addChild(Myhero, 2);
}


void Game::TowerPrint()
{
	//�������ĺ���
	auto tower = Tower::creatWithTowerTypes(TowerTypeTest);
	tower->setPosition(Vec2(visibleSize.width / 2 + 100, visibleSize.height / 2 + 100));
	this->addChild(tower, 2);
}


void Game::CreepsPrint(float delta)
{
	//���ɱ��ĺ���

	auto creep1 = Creep::creatWithCreepTypes(CreepTypeTest);
	creep1->setPosition(Vec2(visibleSize.width / 2+a*10, visibleSize.height / 2));
	this->addChild(creep1, 2);
	a++;
}

void Game::update(float delta)
{
	//Ѫ��������������ʵʱ����




	//Ӣ���������
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