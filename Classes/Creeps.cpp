//////////////////
/*
徐炳昌
5.27
ver4
*/
#include"Creeps.h"
#include"Hero.h"
#include"Tower.h"
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


/*
Creep::Creep(CreepTypes creepType) {
	this->creepType = creepType;
	this->velocity = Vec2::ZERO;
}
*/
Creep* Creep::creatWithCreepTypes(CreepTypes creepType,bool pending) {
	Creep* creep = new (std::nothrow)Creep();

	std::string filename1 = Creep_test;
	creep->self = pending;
	//通过switch根据type来初始化数值
	if (pending) {
		switch (creepType)
		{
		case CreepTypeTest:
			creep->setCreepType(creepType);
			filename1 = Creep_test;
			creep->initHealthPointsLimit = 20;
			creep->healthPoints = 20;
			//creep->armorPoints = 10;
			//creep->magicArmorPoints = 10;
			creep->atk = 10;
			creep->atkDistance = 1000;
			creep->atkSpeeds = 10;
			creep->SetHpBar();
			creep->setRewardMoney(30);
			creep->setRewardExp(50);
			creep->UpdateAttack1();
			creep->schedule(schedule_selector(Creep::UpdateDeath));
			//...
			break;

		case CreepTypeMelee:
			creep->setCreepType(creepType);
			filename1 = Creep_melee;
			creep->initHealthPointsLimit = 550;
			creep->healthPoints = 550;
			creep->atk = 15;
			creep->atkDistance = 60;
			creep->atkSpeeds = 1;
			creep->SetHpBar();
			creep->setRewardMoney(40);
			creep->setRewardExp(50);
			creep->UpdateAttack1();
			creep->schedule(schedule_selector(Creep::UpdateDeath));
			//...
			break;
		case CreepTypeRange:
			creep->setCreepType(creepType);
			filename1 = Creep_range;
			creep->initHealthPointsLimit = 200;
			creep->healthPoints = 200;
			creep->atk = 20;
			creep->atkDistance = 130;
			creep->atkSpeeds = 1;
			creep->SetHpBar();
			creep->setRewardMoney(60);
			creep->setRewardExp(75);
			creep->UpdateAttack1();
			creep->schedule(schedule_selector(Creep::UpdateDeath));
			//...
			break;
		case CreepTypeCannon:
			creep->setCreepType(creepType);
			filename1 = Creep_cannon;
			creep->initHealthPointsLimit = 700;
			creep->healthPoints = 700;
			creep->atk = 30;
			creep->atkDistance = 150;
			creep->atkSpeeds = 1;
			creep->SetHpBar();
			creep->setRewardMoney(100);
			creep->setRewardExp(90);
			creep->UpdateAttack1();
			creep->schedule(schedule_selector(Creep::UpdateDeath));
			//...
			break;
		case CreepTypeJ1:
			creep->setCreepType(creepType);
			filename1 = Creep_j1;
			creep->initHealthPointsLimit = 700;
			creep->healthPoints = 700;
			creep->atk = 30;
			creep->atkDistance = 100;
			creep->atkSpeeds = 1;
			creep->SetHpBar();
			creep->setRewardMoney(200);
			creep->setRewardExp(100);
			creep->UpdateFAttack();
			creep->schedule(schedule_selector(Creep::UpdateDeath));
		case CreepTypeJ2:
			creep->setCreepType(creepType);
			filename1 = Creep_j2;
			creep->initHealthPointsLimit = 700;
			creep->healthPoints = 700;
			creep->atk = 30;
			creep->atkDistance = 100;
			creep->atkSpeeds = 1;
			creep->SetHpBar();
			creep->setRewardMoney(200);
			creep->setRewardExp(100);
			creep->UpdateFAttack();
			creep->schedule(schedule_selector(Creep::UpdateDeath));
		case CreepTypeJ3:
			creep->setCreepType(creepType);
			filename1 = Creep_j3;
			creep->initHealthPointsLimit = 700;
			creep->healthPoints = 700;
			creep->atk = 30;
			creep->atkDistance = 100;
			creep->atkSpeeds = 1;
			creep->SetHpBar();
			creep->setRewardMoney(200);
			creep->setRewardExp(100);
			creep->UpdateFAttack();
			creep->schedule(schedule_selector(Creep::UpdateDeath));
		case CreepTypeJ4:
			creep->setCreepType(creepType);
			filename1 = Creep_j4;
			creep->initHealthPointsLimit = 700;
			creep->healthPoints = 700;
			creep->atk = 30;
			creep->atkDistance = 100;
			creep->atkSpeeds = 1;
			creep->SetHpBar();
			creep->setRewardMoney(200);
			creep->setRewardExp(100);
			creep->UpdateFAttack();
			creep->schedule(schedule_selector(Creep::UpdateDeath));
		default:
			break;
		}
	}
	else {
		switch (creepType)
		{
		case CreepTypeTest:
			creep->setCreepType(creepType);
			filename1 = Creep_test;
			creep->initHealthPointsLimit = 20;
			creep->healthPoints = 20;
			//creep->armorPoints = 10;
			//creep->magicArmorPoints = 10;
			creep->atk = 10;
			creep->atkDistance = 1000;
			creep->atkSpeeds = 10;
			creep->SetHpBar();
			creep->setRewardMoney(30);
			creep->setRewardExp(50);
			creep->UpdateAttack2();
			creep->schedule(schedule_selector(Creep::UpdateDeath));
			//...
			break;

		case CreepTypeMelee:
			creep->setCreepType(creepType);
			filename1 = Creep_melee;
			creep->initHealthPointsLimit = 550;
			creep->healthPoints = 550;
			creep->atk = 15;
			creep->atkDistance = 60;
			creep->atkSpeeds = 1;
			creep->SetHpBar();
			creep->setRewardMoney(40);
			creep->setRewardExp(50);
			creep->UpdateAttack2();
			creep->schedule(schedule_selector(Creep::UpdateDeath));
			//...
			break;
		case CreepTypeRange:
			creep->setCreepType(creepType);
			filename1 = Creep_range;
			creep->initHealthPointsLimit = 200;
			creep->healthPoints = 200;
			creep->atk = 20;
			creep->atkDistance = 130;
			creep->atkSpeeds = 1;
			creep->SetHpBar();
			creep->setRewardMoney(60);
			creep->setRewardExp(75);
			creep->UpdateAttack2();
			creep->schedule(schedule_selector(Creep::UpdateDeath));
			//...
			break;
		case CreepTypeCannon:
			creep->setCreepType(creepType);
			filename1 = Creep_cannon;
			creep->initHealthPointsLimit = 700;
			creep->healthPoints = 700;
			creep->atk = 30;
			creep->atkDistance = 150;
			creep->atkSpeeds = 1;
			creep->SetHpBar();
			creep->setRewardMoney(100);
			creep->setRewardExp(90);
			creep->UpdateAttack2();
			creep->schedule(schedule_selector(Creep::UpdateDeath));
			//...
			break;

		default:
			break;
		}
	}
	const std::string& filename = filename1;

	if (creep && creep->initWithFile(filename)) {//判断creep对象是否生成成功
		
		creep->autorelease();//加入内存释放池中，不会立即释放creep对象
		/*//////////////////////////////////////->>
		//对creep对象添加物理引擎支持
		auto body = PhysicsBody::create();

		if (creepType == CreepTypeTest) {
			body->addShape(PhysicsShapeBox::create());
		}
		else if (creepType == CreepTypeMelee) {
			Vec2 verts[] = {
				Vec2(),

			};
			body->addShape(PhysicsShapePolygon::create(verts, 6));
		}
		body->setCategoryBitmask(0x01);
		body->setCollisionBitmask(0x02);
		body->setContactTestBitmask(0x01);

		creep->setPhysicsBody(body);
		*/
		//creep->setVisible(false);
		//creep->spawnCreep();
		//creep->unscheduleUpdate();
		//creep->scheduleUpdate();
		///////////////////////////////////////*///<<-
		return creep;
	}
	CC_SAFE_DELETE(creep);	
	return nullptr;
}

/*void Creep::update(float dt) {
	if (this->healthPoints == 0)
	{
		this->die();
	}
	;
}
*/
/*
void Creep::spawnCreep() {
	Size screenSize = Director::getInstance()->getVisibleSize();
	
	//设置初始位置
	float xPos = screenSize.width/ 2;
	float yPos = screenSize.height/2;

	this->setPosition(Vec2(xPos, yPos));
	this->setAnchorPoint(Vec2(0.5f,0.5f));
	//0.5f,0.5f--->>判断出屏幕this->getposition().y+this->getcontenSize().height/2<0

	//初始化数据也可以在这个函数里

	this->setVisible(true);
}
*/

bool Creep::hurt(float atk){

	
	int hp=getHealthPoints();
	hp -= atk;

	if (hp <= 0){
		//die();//死亡判定可以写到这里也可以通过hurt函数返回的bool值再调用die();
		hp = 0;
	}
	setHealthPoints(hp);

	return false;
}

void Creep::die() {
	//不知道涉及什么先不写
	//rdc:播放死亡动画
	//死亡动画
	const auto typ = this->getCreepType();
	std::string actname = "Myrmidon_death";
	switch (typ)
	{
	case CreepTypeMelee:
		actname = "Myrmidon_death";
		break;
	case CreepTypeRange:
		actname = "Blazefang_death";
		break;
	case CreepTypeCannon:
		actname = "Quetzal_death";
		break;
	case CreepTypeJ1:
		actname = "Scorpion_death";
		break;
	case CreepTypeJ2:
		actname = "Immortal_death";
		break;
	case CreepTypeJ3:
		actname = "Raider_death";
		break;
	case CreepTypeJ4:
		actname = "Thug_death";
		break;
	case CreepTypeJ5:
		actname = "Fallen_death";
		break;
	}


	this->stopAllActions();
	
	auto dieact= Sequence::create(Animate::create(AnimationCache::getInstance()->getAnimation(actname)), DelayTime::create(1), CallFunc::create([&]() {
		this->setVisible(false);
	}),NULL);
	this->runAction(dieact);
	this->setAtk(0);
	if (self)
	{
		RightHero->addGold(this->getRewardMoney());
		RightHero->addExp(this->getRewardExp());
	}
	else
	{
		LeftHero->addGold(this->getRewardMoney());
		LeftHero->addExp(this->getRewardExp());
	}

//	this->release();
}

void Creep::runF() {

	const auto typ = this->getCreepType();
	std::string actname = "Myrmidon_death";
	switch (typ)
	{
	case CreepTypeMelee:
		actname = "Myrmidon_runright";
		break;
	case CreepTypeRange:
		actname = "Blazefang_runright";
		break;
	case CreepTypeCannon:
		actname = "Quetzal_runleft";
		break;
	}


	this->stopAllActions();
	this->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(actname)));

	auto Moving = MoveTo::create(1, Vec2(this->getPositionX() + 50, this->getPositionY()));

	this->runAction(Moving);
	//this->moveForward();
}

void Creep::runB() {

	const auto typ = this->getCreepType();
	std::string actname = "Myrmidon_death";
	switch (typ)
	{
	case CreepTypeMelee:
		actname = "Myrmidon_runleft";
		break;
	case CreepTypeRange:
		actname = "Blazefang_runleft";
		break;
	case CreepTypeCannon:
		actname = "Quetzal_runleft";
		break;
	}

	this->setFlipX(true);
	this->stopAllActions();
	this->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(actname)));

	auto Moving = MoveTo::create(1, Vec2(this->getPositionX() - 50, this->getPositionY()));

	this->runAction(Moving);
	//this->moveForward();
}


void Creep::atkF() {

	const auto typ = this->getCreepType();
	std::string actname = "Myrmidon_death";
	switch (typ)
	{
	case CreepTypeMelee:
		actname = "Myrmidon_attack";
		break;
	case CreepTypeRange:
		actname = "Blazefang_attack";
		break;
	case CreepTypeCannon:
		actname = "Quetzal_attack";
		break;
	case CreepTypeJ1:
		actname = "Scorpion_attack";
		break;
	case CreepTypeJ2:
		actname = "Immortal_attack";
		break;
	case CreepTypeJ3:
		actname = "Raider_attack";
		break;
	case CreepTypeJ4:
		actname = "Thug_attack";
		break;
	case CreepTypeJ5:
		actname = "Fallen_attack";
		break;
	}


	this->stopAllActions();
	this->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(actname)));
;
}

void Creep::atkB() {

	const auto typ = this->getCreepType();
	std::string actname = "Myrmidon_death";
	switch (typ)
	{
	case CreepTypeMelee:
		actname = "Myrmidon_attack";
		break;
	case CreepTypeRange:
		actname = "Blazefang_attack";
		break;
	case CreepTypeCannon:
		actname = "Quetzal_attack";
		break;
	case CreepTypeJ1:
		actname = "Scorpion_attack";
		break;
	case CreepTypeJ2:
		actname = "Immortal_attack";
		break;
	case CreepTypeJ3:
		actname = "Raider_attack";
		break;
	case CreepTypeJ4:
		actname = "Thug_attack";
		break;
	case CreepTypeJ5:
		actname = "Fallen_attack";
		break;
	}

	this->setFlipX(true);
	this->stopAllActions();
	this->runAction(Animate::create(AnimationCache::getInstance()->getAnimation(actname)));

}





bool Creep::checkTower1InRect(){
	if (this->newAttackRect()->containsPoint(Tower1->getPosition())) {
		this->isAttacking = true;
		return true;
	}
	return false;
}

bool Creep::checkTower2InRect()
{
	if (this->newAttackRect()->containsPoint(Tower2->getPosition())) {
		this->isAttacking = true;
		return true;
	}
	return false;
}

void Creep::SetHpBar()
{
	auto Healthbar = Sprite::create("healthbar.dds");
	HpBarProgress = ProgressTimer::create(Healthbar);
	HpBarProgress->setScale(0.08, 0.3);
	auto size = HpBarProgress->getContentSize();
	float x = this->x_position + 40;
	float y = this->y_position + 80;
	HpBarProgress->setPosition(Vec2(x, y));
	HpBarProgress->setType(ProgressTimer::Type::BAR);
	HpBarProgress->setMidpoint(Vec2(0, 0));
	HpBarProgress->setBarChangeRate(Vec2(1, 0));
	HpBarProgress->setPercentage(100*this->getHealthPoints()/this->getInitHealthPointsLimit());
	this->addChild(HpBarProgress, 4, "HpBarProgress");
	this->schedule(schedule_selector(Creep::UpdateHpBar));
}
void Creep::UpdateHpBar(float delta)
{
	float percentage = 100 * this->getHealthPoints() / this->getInitHealthPointsLimit();
	if (percentage <= 0)
	{
		percentage = 0;
		this->unschedule(schedule_selector(Creep::UpdateHpBar));
	}
	HpBarProgress->setPercentage(percentage);
}

void Creep::UpdateAttack1()
{
	this->schedule(schedule_selector(Creep::AttackAndMove1),1,-1,0);
}

void Creep::UpdateAttack2()
{
	this->schedule(schedule_selector(Creep::AttackAndMove2), 1,-1,0);
}

void Creep::UpdateFAttack()
{
	this->schedule(schedule_selector(Creep::FieldAttackAndMove), 1,-1,0);
}



void Creep::AttackAndMove1(float delta)
{

	if (targetCreep.size() > 0) {	
		
			if (OtherCreep.size() > 0 ) {//攻击othercreep
				for (auto iter = OtherCreep.begin(); iter != OtherCreep.end();) {
					auto ocreep = *iter;
					iter++;
					if (this->newAttackRect()->containsPoint(ocreep->getPosition()) && ocreep->getHealthPoints() > 0) {
						//攻击动画
						this->atkF();
						ocreep->hurt(atk);
						return;
					}
				}
			}
			if (this->newAttackRect()->containsPoint(Tower2->getPosition()) && Tower2->getHealthPoints()>0) {//防御塔2号
				//攻击动画
				this->atkF();
				Tower2->hurt(atk);
				return;
			}
			else if (this->newAttackRect()->containsPoint(Base2->getPosition()) && Base2->getHealthPoints()>0) {//base 2
				//攻击动画
				this->atkF();
				Base2->hurt(atk);
				return;
				
			}
			else if (this->newAttackRect()->containsPoint(RightHero->getPosition()) && RightHero->getHealthPoints()>0) {
				//攻击动画
				this->atkF();
				RightHero->hurt(atk);
				return;
			}
			else {
				
				this->runF();
			}			
		}
	
}

void Creep::AttackAndMove2(float delta)
{
	if (OtherCreep.size() > 0 ) {	
		if (targetCreep.size() > 0) {//攻击target
			for (auto iter = targetCreep.begin(); iter != targetCreep.end();) {
				auto ocreep = *iter;
				iter++;
				if (this->newAttackRect()->containsPoint(ocreep->getPosition()) && ocreep->getHealthPoints() > 0) {
					//攻击动画
					this->atkB();
					ocreep->hurt(atk);
					return;
				}
			}
		}
			if (this->newAttackRect()->containsPoint(Tower1->getPosition()) && Tower1->getHealthPoints()>0) {
				//攻击动画
				this->atkB();
				Tower1->hurt(atk);
				return;
			}
			else if (this->newAttackRect()->containsPoint(Base1->getPosition()) && Base1->getHealthPoints() >= 0) {
				//攻击动画
				this->atkB();
				Base1->hurt(atk);
				return;
			}
			else if (this->newAttackRect()->containsPoint(LeftHero->getPosition()) && LeftHero->getHealthPoints()>0) {
				//攻击动画
				this->atkB();
		//		auto a = LeftHero->getHealthPoints() - atk;
				LeftHero->hurt(atk);
				return;
			}
			else {
				this->runB();
			}
		}
	
}

void Creep::FieldAttackAndMove(float delta)
{
	if (this->newAttackRect()->containsPoint(LeftHero->getPosition())) {
		LeftHero->hurt(atk);
		//攻击动画
	}
	else if(this->newAttackRect()->containsPoint(RightHero->getPosition())) {
		//攻击动画
		RightHero->hurt(atk);
	}
}

Rect* Creep::newRect()
{
	return new Rect(this->getPositionX()-40,this->getPositionY()-40,80,80);
}

void Creep::moveForward()
{
	//向前移动
	auto Moving = MoveTo::create(1, Vec2(this->getPositionX() + 50, this->getPositionY()));
	this->stopAllActions();
	this->runAction(Moving);
}

void Creep::moveBack()
{
	//向后移动
	auto Moving = MoveTo::create(1, Vec2(this->getPositionX() - 50, this->getPositionY()));
	this->stopAllActions();
	this->runAction(Moving);
}


std::string Creep::getName() {
	switch (creepType)
	{
	case CreepTypeMelee:
		return "Myrmidon";
		break;
	case CreepTypeRange:
		return "Blazefang";
		break;
	case CreepTypeCannon:
		return "Quetzal";
		break;
	}
}



Rect* Creep::newAttackRect()
{
	return new Rect(this->getPositionX() - this->getAtkDistance(),this->getPositionY() - this->getAtkDistance(),this->getAtkDistance() *2,this->getAtkDistance() *2);
}

bool Creep::chechLeftHeroInRect()
{
	if (this->newAttackRect()->containsPoint(LeftHero->getPosition())) {
		this->isAttacking = true;
		return true;
	}
	return false;
}

bool Creep::checkRightHeroInRect()
{
	if (this->newAttackRect()->containsPoint(RightHero->getPosition())) {
		this->isAttacking = true;
		return true;
	}
	return false;
}

bool Creep::checkTargetCreepInRect()
{
	return false;
}

bool Creep::checkOtherCreepInRect()
{
	return false;
}



/*void Creep::attackRightHero()
{

	if (this->isAttacking == true) {
		this->isAttacking = false;
		this->stopAllActions();
		//播放动画
		RightHero->hurt(atk);
	}
}
*/
void Creep::UpdateDeath(float) {
	if (this->getHealthPoints() <= 0) {

		this->die();
		this->unscheduleAllSelectors();
		//removeFromParentAndCleanup(this);

	}
}
