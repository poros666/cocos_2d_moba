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
extern std::list<Creep*> targetCreep;
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
		/*
		case CreepTypeMelee:
			creepFramName = Creep_melee;
			creep->initHealthPointsLimit = 10;
			//...
			break;
		*/
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

	int hp;
	hp -= (int)(atk * armorPoints);//护甲计算公式在这里调整

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
