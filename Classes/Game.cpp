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
	auto hero = Hero::creatWithHeroTypes(HeroTypeTest);
	hero->setPosition(Vec2(visibleSize.width / 2 - 100, visibleSize.height / 2 - 100));
	this->addChild(hero, 2);
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
	creep1->setPosition(Vec2(visibleSize.width / 2+delta, visibleSize.height / 2+delta));
	this->addChild(creep1, 2);
}

void Game::update(float delta)
{
	//Ѫ��������������ʵʱ����

}
