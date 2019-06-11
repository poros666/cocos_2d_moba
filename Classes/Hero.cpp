//////////////////
/*
徐炳昌
5.27
ver1
*/
#include"Hero.h"
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

 Hero* Hero::creatWithHeroTypes(HeroTypes heroType) {
	Hero* hero = new (std::nothrow)Hero();
	
	std::string filename1 = Hero_test;

	//通过switch根据type来初始化数值
	switch (heroType)
	{
	case HeroTypeTest:
		hero->setHeroType(heroType);
		filename1 = Hero_test;
		hero->setGold(1000);
		hero->setInitHealthPointsLimit(10000);
		hero->setHealthPoints(10000);
		hero->setHealthRecoverPoints(1);
		hero->setInitManaPointsLimit(10);
		hero->setManaPoints(10);
		hero->setMoveSpeed(200);
		hero->SetHpBar();
		hero->SetManaBar();
		hero->setAtkDistance(100);
		hero->setAtk(10);
		hero->setReBornPoint(Vec2(300, 500));
		//attack_rect = new Rect();
		//...
		break;
	case HeroTypeExecu:
		hero->setHeroType(heroType);
		filename1 = Hero_execu;
		hero->setGold(0);
		hero->setInitHealthPointsLimit(500);
		hero->setHealthPoints(500);
		hero->setInitManaPointsLimit(100);
		hero->setManaPoints(100);
		hero->setMoveSpeed(200);
		hero->setArmorPoints(0);
		hero->setAtk(60);
		hero->setAtkDistance(40);
		hero->setAtkSpeeds(1);
		hero->setLevel(1);
		hero->setExp(0);
		hero->setSkillPoints(0);
		hero->SetHpBar();
		hero->SetManaBar();
		//...
		break;
	case HeroTypeElite:
		hero->setHeroType(heroType);
		filename1 = Hero_elite;
		hero->setGold(0);
		hero->setInitHealthPointsLimit(450);
		hero->setHealthPoints(450);
		hero->setInitManaPointsLimit(120);
		hero->setManaPoints(120);
		hero->setMoveSpeed(200);
		hero->setArmorPoints(0);
		hero->setAtk(50);
		hero->setAtkDistance(40);
		hero->setAtkSpeeds(1);
		hero->setLevel(1);
		hero->setExp(0);
		hero->setSkillPoints(0);
		hero->SetHpBar();
		hero->SetManaBar();
		//...
		break;
	case HeroTypeMunra:
		hero->setHeroType(heroType);
		filename1 = Hero_munra;
		hero->setGold(0);
		hero->setInitHealthPointsLimit(400);
		hero->setHealthPoints(400);
		hero->setInitManaPointsLimit(160);
		hero->setManaPoints(160);
		hero->setMoveSpeed(200);
		hero->setArmorPoints(0);
		hero->setAtk(30);
		hero->setAtkDistance(140);
		hero->setAtkSpeeds(1);
		hero->setLevel(1);
		hero->setExp(0);
		hero->setSkillPoints(0);
		hero->SetHpBar();
		hero->SetManaBar();
		
		//...
		break;
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

 void Hero::clickAttack(Node* target,Hero* owner) {
	 if (target == this->EnemyHero) {
		 Hero* tempHero = static_cast<Hero*>(target);
		 if (owner->attack_rect->containsPoint(tempHero->getPosition()) && tempHero->getHealthPoints()>0) {
			 //这里留给攻击动画
			 tempHero->setHealthPoints(tempHero->getHealthPoints() -owner->getAtk() );
		 }
	 }
	 else if (target == this->EnemyTower) {
		 Tower* tempTower = static_cast<Tower*>(target);
		 if (owner->attack_rect->containsPoint(tempTower->getPosition()) && tempTower->getHealthPoints() > 0) {
			 //ready for ani
			 tempTower->setHealthPoints(tempTower->getHealthPoints() - owner->getAtk());
		 }
	 }
	 else if (target==this->EnemyCreep) {
		 Creep* tempCreep = static_cast<Creep*>(target);
		 if (owner->attack_rect->containsPoint(tempCreep->getPosition()) && tempCreep->getHealthPoints() > 0) {
			 //ready for ani
			 tempCreep->setHealthPoints(getHealthPoints() - owner->getAtk());
		 }
	 }
 }

 


bool Hero::hurt(float atk) {

	int hp=this->getHealthPoints();
	//hp -= (int)(atk * armorPoints);//护甲计算公式在这里调整
	hp -= atk;
	if (hp <= 0) {
		setHealthPoints(0);
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
		switch (heroType)
		{
		case HeroTypeExecu:
			setHealthPoints(getHealthPoints() + 70);
			setAtk(getAtk() + 24);
			break;
		case HeroTypeElite:
			setHealthPoints(getHealthPoints() + 60);
			setAtk(getAtk() + 10);
			break;
		case HeroTypeMunra:
			setHealthPoints(getHealthPoints() + 50);
			setAtk(getAtk() + 10);
			break;
		}
		lvl++;
		setLevel(lvl);
		setSkillPoints(getSkillPoints() + 1);
	}
}

void Hero::die() 
{
	//不知道涉及什么先不写
	//rdc:播放死亡动画,挪回初始位置？


	const auto typ = this->getHeroType();
	std::string actname = "Executioner_death";
	switch (typ)
	{
	case HeroTypeTest:
		actname = "Executioner_death";
		break;
	case HeroTypeExecu:
		actname = "Executioner_death";
		break;
	case HeroTypeElite:
		actname = "Elite_death";
		break;
	case HeroTypeMunra:
		actname = "Munra_death";
		break;
	}


	this->stopAllActions();
	this->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(actname)));
	this->runAction(Sequence::create(DelayTime::create(1), CallFunc::create([&]() {
		this->setPosition(getReBornPoint());
		}), NULL));


}

void Hero::setNewAtkRect()
{
	attack_rect = new Rect(this->getPositionX()-atkDistance,this->getPositionY()-atkDistance ,2*atkDistance ,2*atkDistance );
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
Rect* Hero::newAttackRect()
{
	return new Rect(this->getPositionX() - this->getAtkDistance(), this->getPositionY() - this->getAtkDistance(), this->getAtkDistance() * 2, this->getAtkDistance() * 2);
}
void Hero::moveBack()
{
	auto Moving = MoveTo::create(1, Vec2(this->getPositionX() - 50, this->getPositionY()));
	this->stopAllActions();
	this->runAction(Moving);
}
void Hero::AttackAndMove(float)
{
	//英雄的逻辑比较复杂，暂时初始化的时候不加入ai
	//默认ai英雄是右边的
	auto atk= this->getAtk();
	if (targetCreep.size() > 0) {//攻击target

		auto ocreep = *targetCreep.begin();
		if (this->newAttackRect()->containsPoint(ocreep->getPosition()) && ocreep->getHealthPoints() > 0) {
			//攻击动画
			//这里解释一下，一般来讲敌方英雄可能是一个个把兵线上的小兵按顺序杀掉的，所以就只搜索begin
			ocreep->setHealthPoints(ocreep->getHealthPoints() - atk);
			if (ocreep->getHealthPoints() <= 0) {
				//死亡动画
				
				targetCreep.erase(targetCreep.begin());
				ocreep->die();
			}
			return;
		}
	}
	else if (this->newAttackRect()->containsPoint(Tower1->getPosition()) && Tower1->getHealthPoints() > 0) {
		//攻击动画
		Tower1->setHealthPoints(Tower1->getHealthPoints() - atk);
		if (Tower1->getHealthPoints() <= 0) {
			//死亡动画
			Tower1->die();
		}
		return;
	}
	else if (this->newAttackRect()->containsPoint(Base1->getPosition()) && Base1->getHealthPoints() >= 0) {
		//攻击动画
		Base1->setHealthPoints(Base1->getHealthPoints() - atk);
		if (Base1->getHealthPoints() >= 0) {
			//死亡动画
			Base1->die();
		}
	}
	else if (this->newAttackRect()->containsPoint(Myhero->getPosition()) && Myhero->getHealthPoints() > 0) {
		//攻击动画
		Myhero->setHealthPoints(Myhero->getHealthPoints() - atk);
		if (Myhero->getHealthPoints() <= 0) {
			//死亡动画
			Myhero->die();
		}
		return;
	}
	else {
		//移动动画
		this->moveBack();
	}
}
void Hero::move(Vec2 endPos,Hero* Hero,std::string dir)
{
	Vec2 route = Hero->getPosition() - endPos;
	float Distance = route.length();
	double Speed = this->getMoveSpeed();
	auto Moving = MoveTo::create(Distance / Speed, endPos);
	const auto typ = this->getHeroType();
	std::string actname = "Executioner_death";
	switch (typ)
	{
	case HeroTypeTest:
		actname = "Executioner_run"+dir;
		break;
	case HeroTypeExecu:
		actname = "Executioner_run" + dir;
		break;
	case HeroTypeElite:
		actname = "Elite_run" + dir;
		break;
	case HeroTypeMunra:
		actname = "Munra_run" + dir;
		break;
	}


	//this->stopAllActions();
	//this->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(actname)));





	Hero->stopAllActions();
	Hero->runAction(Moving);
	Hero->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(actname)));
}

std::string Hero::getName() {
	switch (heroType)
	{
	case HeroTypeExecu:
		return "Executioner";
		break;
	case HeroTypeElite:
		return "Elite";
		break;
	case HeroTypeMunra:
		return "Munra";
		break;
	}
}

void Hero::update(float dt)
{
	if (this->getHealthPoints() <= 0) {
		this->die();
	}
}

void Hero::atkF() {
	const auto typ = this->getHeroType();
	std::string actname = "Executioner_death";
	switch (typ)
	{
	case HeroTypeTest:
		actname = "Executioner_attack";
		break;
	case HeroTypeExecu:
		actname = "Executioner_attack";
		break;
	case HeroTypeElite:
		actname = "Elite_attack";
		break;
	case HeroTypeMunra:
		actname = "Munra_attack";
		break;
	}


	this->stopAllActions();
	this->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(actname)));
}