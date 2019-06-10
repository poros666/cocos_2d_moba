//////////////////
/*
徐炳昌
5.27
ver2
*/
#include<Tower.h>
#include"Hero.h"
#include"Creeps.h"
#include"Game.h"
using namespace cocos2d;
extern Hero* Myhero;
extern Hero* OtherHero;
extern Tower* Tower1;
extern Tower* Tower2;
extern Tower* Base1;
extern Tower* Base2;
extern std::list<Creep*> targetCreep;
extern std::list<Creep*> OtherCreep;
Tower* Tower::creatWithTowerTypes(TowerTypes towerType) {
	Tower* tower = new (std::nothrow)Tower();
	
	std::string filename1 = Tower_test;

	//通过switch根据type来初始化数值
	switch (towerType)
	{
	case TowerTypeTest:
		filename1 = Tower_test;
		tower->setInitHealthPointsLimit(100);
		tower->setHealthPoints(100);
		tower->SetHpBar();
		tower->setRewardExp(300);
		tower->setRewardMoney(200);
		tower->setAtkDistance(1000);
		tower->setAtk(10);
		//...
		break;
		
	case TowerTypeT1:
		filename1 = Tower_1;
		tower->setInitHealthPointsLimit(1000);
		tower->setHealthPoints(1000);
		tower->setAtk(100);
		tower->setAtkDistance(150);
		tower->setAtkSpeeds(1);
		tower->SetHpBar();
		//...
		break;
	case TowerTypeT2:
		filename1 = Tower_1;
		tower->setInitHealthPointsLimit(1200);
		tower->setHealthPoints(1200);
		tower->setAtk(120);
		tower->setAtkDistance(150);
		tower->setAtkSpeeds(1);
		tower->SetHpBar();
		//...
		break;
	case TowerTypeT3:
		filename1 = Tower_1;
		tower->setInitHealthPointsLimit(1400);
		tower->setHealthPoints(1400);
		tower->setAtk(140);
		tower->setAtkDistance(150);
		tower->setAtkSpeeds(1);
		tower->SetHpBar();
		//...
		break;
	case TowerTypeBase:
		filename1 = Base_1;
		tower->setInitHealthPointsLimit(1500);
		tower->setHealthPoints(1500);
		tower->setAtk(0);
		tower->setAtkDistance(0);
		tower->setAtkSpeeds(0);
		tower->SetHpBar();
		//...
		break;
	default:
		break;
	}

	const std::string& filename = filename1;

	if (tower && tower->initWithFile(filename)) {//判断tower对象是否生成成功
		tower->autorelease();//加入内存释放池中，不会立即释放creep对象
		return tower;
	}
	CC_SAFE_DELETE(tower);
	return nullptr;
}

bool Tower::hurt(float atk) {

	int hp = getHealthPoints();
	hp -= atk;


	if (hp <= 0) {
		//die();//死亡判定可以写到这里也可以通过hurt函数返回的bool值再调用die();
		return true;
	}
	setHealthPoints(hp);

	return false;
}

void Tower::die() {
	this->setAtk(0);
	this->setVisible(false);
}


void Tower::win() {
	//
}
void Tower::SetHpBar()
{
	auto Healthbar = Sprite::create("healthbar.dds");
	HpBarProgress = ProgressTimer::create(Healthbar);
	HpBarProgress->setScale(0.08, 0.3);
	auto size = HpBarProgress->getContentSize();
	float x = this->x_position + 30;
	float y = this->y_position + 60;
	HpBarProgress->setPosition(Vec2(x, y));
	HpBarProgress->setType(ProgressTimer::Type::BAR);
	HpBarProgress->setMidpoint(Vec2(0, 0));
	HpBarProgress->setBarChangeRate(Vec2(1, 0));
	HpBarProgress->setPercentage(100 * this->getHealthPoints() / this->getInitHealthPointsLimit());
	this->addChild(HpBarProgress, 4, "HpBarProgress");
	this->schedule(schedule_selector(Tower::UpdateHpBar));
}
void Tower::update(float dt)
{
	if (this->getHealthPoints() <= 0) {
		die();
	}
}
void Tower::UpdateHpBar(float delta)
{
	float percentage = 100 * this->getHealthPoints() / this->getInitHealthPointsLimit();
	if (percentage <= 0)
	{
		percentage = 0;
		this->unschedule(schedule_selector(Tower::UpdateHpBar));
	}
	HpBarProgress->setPercentage(percentage);
}

Rect* Tower::newAttackRect()
{
	return	new Rect(this->getPositionX() - this->getAtkDistance(), this->getPositionY() - this->getAtkDistance(), 2*this->getAtkDistance(), 2*this->getAtkDistance());
}

bool Tower::checkHeroInRect()
{
	if (this->newAttackRect()->containsPoint(OtherHero->getPosition())) {

		return true;
	}
	return false;
}

bool Tower::checkCreepInRect(std::list<Creep*>::iterator iter)
{
	auto a = *iter;
	auto x = this->newAttackRect();
	auto y = a->getPosition();
	if (this->newAttackRect()->containsPoint(a->getPosition())) {

		return true;
	}
	
	return false;
}

void Tower::Attack1()
{
	if (OtherCreep.size() > 0) {
		auto ocreep = *OtherCreep.begin();
		if (this->newAttackRect()->containsPoint(ocreep->getPosition()) && ocreep->getHealthPoints()) {
			ocreep->setHealthPoints(ocreep->getHealthPoints() - this->getAtk());
			if (ocreep->getHealthPoints() <= 0) {
				OtherCreep.erase(OtherCreep.begin());
				ocreep->die();
			}
			return;
		}
	}
	if (this->newAttackRect()->containsPoint(Myhero->getPosition()) && Myhero->getHealthPoints()>0){
		Myhero->setHealthPoints(Myhero->getHealthPoints() - this->getAtk());
		if (Myhero->getHealthPoints() <= 0) {
			Myhero->die();
		}
		return;
	}
}

void Tower::Attack2()
{
	if (targetCreep.size() > 0) {
		auto ocreep = *targetCreep.begin();
		if (this->newAttackRect()->containsPoint(ocreep->getPosition()) && ocreep->getHealthPoints()) {
			ocreep->setHealthPoints(ocreep->getHealthPoints() - this->getAtk());
			if (ocreep->getHealthPoints() <= 0) {
				targetCreep.erase(targetCreep.begin());
				ocreep->die();
			}
			return;
		}
	}
	if (this->newAttackRect()->containsPoint(OtherHero->getPosition()) && OtherHero->getHealthPoints() > 0) {
		OtherHero->setHealthPoints(OtherHero->getHealthPoints() - this->getAtk());
		if (OtherHero->getHealthPoints() <= 0) {
			OtherHero->die();
		}
		return;
	}
}
