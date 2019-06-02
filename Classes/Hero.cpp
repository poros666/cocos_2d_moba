//////////////////
/*
徐炳昌
5.27
ver1
*/
#include"Hero.h"
using namespace cocos2d;


 Hero* Hero::creatWithHeroTypes(HeroTypes heroType) {
	Hero* hero = new (std::nothrow)Hero();
	
	std::string filename1 = Hero_test;

	//通过switch根据type来初始化数值
	switch (heroType)
	{
	case HeroTypeTest:
		filename1 = Hero_test;
		hero->setInitHealthPointsLimit(100);
		hero->setHealthPoints(100);
		hero->setHealthRecoverPoints(1);
		hero->setInitManaPointsLimit(10);
		hero->setManaPoints(10);
		hero->SetHpBar();
		hero->SetManaBar();
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

	if (hero && hero->initWithFile(filename)) {//判断tower对象是否生成成功
		hero->autorelease();//加入内存释放池中，不会立即释放creep对象
		return hero;
	}
	CC_SAFE_DELETE(hero);
	
	return nullptr;
}

bool Hero::hurt(float atk) {

	int hp;
	hp -= (int)(atk * armorPoints);//护甲计算公式在这里调整

	if (hp <= 0) {
		//die();//死亡判定可以写到这里也可以通过hurt函数返回的bool值再调用die();
		return true;
	}
	setHealthPoints(hp);

	return false;
}

void Hero::addExp(int exp) {
	int nowExp=getExp();
	bool lvlup = false;
	int lvl = getLevel();
	int expLimitOfThisLevel = LEVEL_UP_LIMIT_BASE * lvl;

	if (nowExp + exp > expLimitOfThisLevel) {
		lvlup=true;
		setExp(nowExp + exp - expLimitOfThisLevel);
	}

	if (lvlup) {
		lvl++;
		setLevel(lvl);
	}
}

void Hero::die() 
{
	//不知道涉及什么先不写
	//rdc:播放死亡动画,挪回初始位置？

}

void Hero::SetHpBar()
{
	auto Healthbar = Sprite::create("healthbar.dds");
	HpBarProgress = ProgressTimer::create(Healthbar);
	HpBarProgress->setScale(0.1, 0.5);
	auto size = HpBarProgress->getContentSize();
	float x = this->x_position+50;
	float y = this->y_position+120;
	HpBarProgress->setPosition(Vec2(x, y));
	HpBarProgress->setType(ProgressTimer::Type::BAR);
	HpBarProgress->setMidpoint(Vec2(0, 0));
	HpBarProgress->setBarChangeRate(Vec2(1, 0));
	HpBarProgress->setPercentage(100 * this->getHealthPoints() / this->getInitHealthPointsLimit());
	this->addChild(HpBarProgress, 4, "HpBarProgress");
	this->schedule(schedule_selector(Hero::UpdateHpBar));
}
void Hero::UpdateHpBar(float delta)
{
	float percentage = 100 * this->getHealthPoints() / this->getInitHealthPointsLimit();
	if (percentage <= 0)
	{
		percentage = 0;
		this->unschedule(schedule_selector(Hero::UpdateHpBar));
	}
	HpBarProgress->setPercentage(percentage);
}
void Hero::SetManaBar()
{
	auto ManaBar = Sprite::create("manabar.dds");
	ManaBarProgress = ProgressTimer::create(ManaBar);
	ManaBarProgress->setScale(0.1, 0.2);
	auto size = ManaBarProgress->getContentSize();
	float x = this->x_position+50;
	float y = this->y_position+120-size.height/5;
	ManaBarProgress->setPosition(Vec2(x, y));
	ManaBarProgress->setType(ProgressTimer::Type::BAR);
	ManaBarProgress->setMidpoint(Vec2(0, 0));
	ManaBarProgress->setBarChangeRate(Vec2(1, 0));
	ManaBarProgress->setPercentage(100*this->getManaPoints()/this->getInitManaPointsLimit());
	this->addChild(ManaBarProgress, 4, "ManaBarProgress");
	this->schedule(schedule_selector(Hero::UpdateManaBar));
}
void Hero::UpdateManaBar(float delta)
{
	float percentage = 100 * this->getManaPoints() / this->getInitManaPointsLimit();
	if (percentage <= 0)
	{
		percentage = 0;
		this->unschedule(schedule_selector(Hero::UpdateManaBar));
	}
	ManaBarProgress->setPercentage(percentage);
}
void Hero::move(Vec2 endPos,Hero* Hero)
{
	Vec2 route = Hero->getPosition() - endPos;
	float Distance = route.length();
	double Speed = 200;
	auto Moving = MoveTo::create(Distance / Speed, endPos);
	Hero->stopAllActions();
	Hero->runAction(Moving);
}