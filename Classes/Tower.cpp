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
extern std::list<Creep*> FieldCreep;
extern Sprite* bombsp1;

Tower* Tower::creatWithTowerTypes(TowerTypes towerType,bool pending) {
	Tower* tower = new (std::nothrow)Tower();
	
	std::string filename1 = Tower_test;

	//通过switch根据type来初始化数值
	if (pending) {
		switch (towerType)
		{

		case TowerTypeTest:
			tower->setTowerType(towerType);
			filename1 = Tower_test;
			tower->setInitHealthPointsLimit(100);
			tower->setHealthPoints(100);
			tower->SetHpBar();
			tower->setRewardExp(300);
			tower->setRewardMoney(200);
			tower->setAtkDistance(1000);
			tower->setAtk(10);
			tower->UpdateAttack1();
			//...
			break;

		case TowerTypeT1:
			tower->setTowerType(towerType);
			filename1 = Tower_1;
			tower->setInitHealthPointsLimit(1000);
			tower->setHealthPoints(1000);
			tower->setAtk(100);
			tower->setAtkDistance(150);
			tower->setAtkSpeeds(1);
			tower->SetHpBar();
			tower->setRewardExp(300);
			tower->setRewardMoney(200);
			tower->UpdateAttack1();
			//...
			break;
		case TowerTypeT2:
			tower->setTowerType(towerType);
			filename1 = Tower_1;
			tower->setInitHealthPointsLimit(1200);
			tower->setHealthPoints(1200);
			tower->setAtk(120);
			tower->setAtkDistance(150);
			tower->setAtkSpeeds(1);
			tower->SetHpBar();
			tower->setRewardExp(300);
			tower->setRewardMoney(200);
			tower->UpdateAttack1();
			//...
			break;
		case TowerTypeT3:
			tower->setTowerType(towerType);
			filename1 = Tower_1;
			tower->setInitHealthPointsLimit(1400);
			tower->setHealthPoints(1400);
			tower->setAtk(140);
			tower->setAtkDistance(150);
			tower->setAtkSpeeds(1);
			tower->SetHpBar();
			tower->setRewardExp(300);
			tower->setRewardMoney(200);
			tower->UpdateAttack1();
			//...
			break;
		case TowerTypeBase:
			tower->setTowerType(towerType);
			filename1 = Base_1;
			tower->setInitHealthPointsLimit(1500);
			tower->setHealthPoints(1500);
			tower->setAtk(0);
			tower->setAtkDistance(0);
			tower->setAtkSpeeds(0);
			tower->SetHpBar();
			tower->setRewardExp(300);
			tower->setRewardMoney(200);
			tower->UpdateAttack1();
			//...
			break;
		default:
			break;
		}
	}
	else {
		switch (towerType)
		{

		case TowerTypeTest:
			tower->setTowerType(towerType);
			filename1 = Tower_test;
			tower->setInitHealthPointsLimit(100);
			tower->setHealthPoints(100);
			tower->SetHpBar();
			tower->setRewardExp(300);
			tower->setRewardMoney(200);
			tower->setAtkDistance(1000);
			tower->setAtk(10);
			tower->UpdateAttack2();
			//...
			break;

		case TowerTypeT1:
			tower->setTowerType(towerType);
			filename1 = Tower_1;
			tower->setInitHealthPointsLimit(1000);
			tower->setHealthPoints(1000);
			tower->setAtk(100);
			tower->setAtkDistance(150);
			tower->setAtkSpeeds(1);
			tower->SetHpBar();
			tower->setRewardExp(300);
			tower->setRewardMoney(200);
			tower->UpdateAttack2();
			//...
			break;
		case TowerTypeT2:
			tower->setTowerType(towerType);
			filename1 = Tower_1;
			tower->setInitHealthPointsLimit(1200);
			tower->setHealthPoints(1200);
			tower->setAtk(120);
			tower->setAtkDistance(150);
			tower->setAtkSpeeds(1);
			tower->SetHpBar();
			tower->setRewardExp(300);
			tower->setRewardMoney(200);
			tower->UpdateAttack2();
			//...
			break;
		case TowerTypeT3:
			tower->setTowerType(towerType);
			filename1 = Tower_1;
			tower->setInitHealthPointsLimit(1400);
			tower->setHealthPoints(1400);
			tower->setAtk(140);
			tower->setAtkDistance(150);
			tower->setAtkSpeeds(1);
			tower->SetHpBar();
			tower->setRewardExp(300);
			tower->setRewardMoney(200);
			tower->UpdateAttack2();
			//...
			break;
		case TowerTypeBase:
			tower->setTowerType(towerType);
			filename1 = Base_1;
			tower->setInitHealthPointsLimit(1500);
			tower->setHealthPoints(1500);
			tower->setAtk(0);
			tower->setAtkDistance(0);
			tower->setAtkSpeeds(0);
			tower->SetHpBar();
			tower->setRewardExp(300);
			tower->setRewardMoney(200);
			tower->UpdateAttack2();
			//...
			break;
		default:
			break;
		}
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

void Tower::UpdateAttack1()
{
	this->schedule(schedule_selector(Tower::Attack1), 1, -1, 0);
}

void Tower::UpdateAttack2()
{
	this->schedule(schedule_selector(Tower::Attack2), 1, -1, 0);
}

void Tower::Attack1(float)
{
	if (OtherCreep.size() > 0) {
		for (auto iter = OtherCreep.begin(); iter != OtherCreep.end();) {
			auto ocreep = *iter;
			iter++;
			if (this->newAttackRect()->containsPoint(ocreep->getPosition()) && ocreep->getHealthPoints()) {

				//这里加攻击动画
				bombsp1->setPosition(ocreep->getPosition());
				bombsp1->runAction(Animate::create(AnimationCache::getInstance()->getAnimation("bomb")));
				this->runAction(Animate::create(AnimationCache::getInstance()->getAnimation("Mecha_shoot")));


				ocreep->setHealthPoints(ocreep->getHealthPoints() - this->getAtk());
				if (ocreep->getHealthPoints() <= 0) {
					//死亡动画
					OtherCreep.erase(OtherCreep.begin());
					ocreep->die();
				}
				return;
			}
		}
	}
	if (this->newAttackRect()->containsPoint(OtherHero->getPosition()) && OtherHero->getHealthPoints() > 0) {
		
		//攻击动画

		this->runAction(Animate::create(AnimationCache::getInstance()->getAnimation("Mecha_shoot")));

		OtherHero->setHealthPoints(OtherHero->getHealthPoints() - this->getAtk());
		if (OtherHero->getHealthPoints() <= 0) {
			//死亡动画
			OtherHero->die();
		}
		return;
	}
}

void Tower::Attack2(float)
{
	if (targetCreep.size() > 0) {
		for (auto iter = targetCreep.begin(); iter != targetCreep.end();) {
			auto ocreep = *iter;
			iter++;
			if (this->newAttackRect()->containsPoint(ocreep->getPosition()) && ocreep->getHealthPoints()) {
				//攻击动画
				this->setFlipX(true);
				this->runAction(Animate::create(AnimationCache::getInstance()->getAnimation("Mecha_shoot")));

				ocreep->setHealthPoints(ocreep->getHealthPoints() - this->getAtk());
				if (ocreep->getHealthPoints() <= 0) {
					//死亡动画
					targetCreep.erase(targetCreep.begin());
					ocreep->die();
				}
				return;
			}
		}
	}
	if (this->newAttackRect()->containsPoint(Myhero->getPosition()) && Myhero->getHealthPoints() > 0) {
		//攻击动画
		this->setFlipX(true);
		this->runAction(Animate::create(AnimationCache::getInstance()->getAnimation("Mecha_shoot")));

		Myhero->setHealthPoints(Myhero->getHealthPoints() - this->getAtk());
		if (Myhero->getHealthPoints() <= 0) {
			//死亡动画
			Myhero->die();
		}
		return;
	}
}

Rect* Tower::newRect()
{
	return new Rect(this->getPositionX() - 100, this->getPositionY() - 100, 200, 200);
}
