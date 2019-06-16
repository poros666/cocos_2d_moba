//////////////////
/*
Ðì±þ²ý
5.27
ver2
*/
#include<Tower.h>
#include"Hero.h"
#include"Creeps.h"
#include"Game.h"
using namespace cocos2d;
extern Hero* LeftHero;
extern Hero* RightHero;
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

	//Í¨¹ýswitch¸ù¾ÝtypeÀ´³õÊ¼»¯ÊýÖµ
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
			tower->schedule(schedule_selector(Tower::update));
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
			tower->schedule(schedule_selector(Tower::update));

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
			tower->schedule(schedule_selector(Tower::update));

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
			tower->schedule(schedule_selector(Tower::update));

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
			tower->schedule(schedule_selector(Tower::update));

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
			tower->schedule(schedule_selector(Tower::update));

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
			tower->schedule(schedule_selector(Tower::update));

			//...
			break;
		case TowerTypeT2:
			tower->setTowerType(towerType);
			filename1 = Tower_1;
			tower->setInitHealthPointsLimit(1200);
			tower->setHealthPoints(1200);
			tower->setAtk(120);
			tower->setAtkDistance(1500);
			tower->setAtkSpeeds(1);
			tower->SetHpBar();
			tower->setRewardExp(300);
			tower->setRewardMoney(200);
			tower->UpdateAttack2();
			tower->schedule(schedule_selector(Tower::update));

			//...
			break;
		case TowerTypeT3:
			tower->setTowerType(towerType);
			filename1 = Tower_1;
			tower->setInitHealthPointsLimit(1400);
			tower->setHealthPoints(1400);
			tower->setAtk(140);
			tower->setAtkDistance(1500);
			tower->setAtkSpeeds(1);
			tower->SetHpBar();
			tower->setRewardExp(300);
			tower->setRewardMoney(200);
			tower->UpdateAttack2();
			tower->schedule(schedule_selector(Tower::update));

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
			tower->schedule(schedule_selector(Tower::update));

			//...
			break;
		default:
			break;
		}
	}
	tower->scheduleUpdate();
	const std::string& filename = filename1;
	
	if (tower && tower->initWithFile(filename)) {//ÅÐ¶Ïtower¶ÔÏóÊÇ·ñÉú³É³É¹¦
		tower->autorelease();//¼ÓÈëÄÚ´æÊÍ·Å³ØÖÐ£¬²»»áÁ¢¼´ÊÍ·Åcreep¶ÔÏó
		return tower;
	}
	CC_SAFE_DELETE(tower);
	return nullptr;
}

bool Tower::hurt(float atk) {

	int hp = getHealthPoints();
	hp -= atk;


	if (hp <= 0) {
		//die();//ËÀÍöÅÐ¶¨¿ÉÒÔÐ´µ½ÕâÀïÒ²¿ÉÒÔÍ¨¹ýhurtº¯Êý·µ»ØµÄboolÖµÔÙµ÷ÓÃdie();
		hp = 0;
	}
	setHealthPoints(hp);

	return false;
}

void Tower::die() {

	bombsp1->setPosition(this->getPosition());
	bombsp1->runAction(Animate::create(AnimationCache::getInstance()->getAnimation("bomb")));
	this->setAtk(0);
	this->setVisible(false);
	//this->removeFromParent();
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
	if (this->newAttackRect()->containsPoint(RightHero->getPosition())) {

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

				//ÕâÀï¼Ó¹¥»÷¶¯»­
				bombsp1->setPosition(ocreep->getPosition());
				bombsp1->runAction(Animate::create(AnimationCache::getInstance()->getAnimation("fireBall_explosion")));
				this->runAction(Animate::create(AnimationCache::getInstance()->getAnimation("Mecha_shoot")));
				ocreep->hurt(atk);
				return;
			}
		}
	}
	if (this->newAttackRect()->containsPoint(RightHero->getPosition()) && RightHero->getHealthPoints() > 0) {
		bombsp1->setPosition(RightHero->getPosition());
		bombsp1->runAction(Animate::create(AnimationCache::getInstance()->getAnimation("fireBall_explosion")));
		this->runAction(Animate::create(AnimationCache::getInstance()->getAnimation("Mecha_shoot")));
		RightHero->hurt(atk);
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
				//¹¥»÷¶¯»­
				this->setFlipX(true);
				bombsp1->setPosition(ocreep->getPosition());
				bombsp1->runAction(Animate::create(AnimationCache::getInstance()->getAnimation("fireBall_explosion")));
				this->runAction(Animate::create(AnimationCache::getInstance()->getAnimation("Mecha_shoot")));

				ocreep->hurt(atk);
				return;
			}
		}
	}
	if (this->newAttackRect()->containsPoint(LeftHero->getPosition()) && LeftHero->getHealthPoints() > 0) {
		//¹¥»÷¶¯»­
		this->setFlipX(true);
		bombsp1->setPosition(LeftHero->getPosition());
		bombsp1->runAction(Animate::create(AnimationCache::getInstance()->getAnimation("fireBall_explosion")));
		this->runAction(Animate::create(AnimationCache::getInstance()->getAnimation("Mecha_shoot")));
		LeftHero->hurt(atk);
		return;
	}
}


Rect* Tower::newRect()
{
	return new Rect(this->getPositionX() - 100, this->getPositionY() - 100, 200, 200);
}

