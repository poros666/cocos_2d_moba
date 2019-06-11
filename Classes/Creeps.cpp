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
extern Hero* Myhero;
extern Hero* OtherHero;
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

	//通过switch根据type来初始化数值
	if (pending) {
		switch (creepType)
		{
		case CreepTypeTest:
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
			//...
			break;

		case CreepTypeMelee:
			filename1 = Creep_melee;
			creep->initHealthPointsLimit = 550;
			creep->healthPoints = 550;
			creep->atk = 15;
			creep->atkDistance = 40;
			creep->atkSpeeds = 1;
			creep->SetHpBar();
			creep->UpdateAttack1();
			//...
			break;
		case CreepTypeRange:
			filename1 = Creep_range;
			creep->initHealthPointsLimit = 200;
			creep->healthPoints = 200;
			creep->atk = 20;
			creep->atkDistance = 130;
			creep->atkSpeeds = 1;
			creep->SetHpBar();
			creep->UpdateAttack1();
			//...
			break;
		case CreepTypeCannon:
			filename1 = Creep_cannon;
			creep->initHealthPointsLimit = 700;
			creep->healthPoints = 700;
			creep->atk = 30;
			creep->atkDistance = 145;
			creep->atkSpeeds = 1;
			creep->SetHpBar();
			creep->UpdateAttack1();
			//...
			break;
		case CreepTypeJ1:
			filename1 = Creep_j1;
			creep->initHealthPointsLimit = 700;
			creep->healthPoints = 700;
			creep->atk = 30;
			creep->atkDistance = 145;
			creep->atkSpeeds = 1;
			creep->SetHpBar();
			creep->UpdateFAttack();
		case CreepTypeJ2:
			filename1 = Creep_j2;
			creep->initHealthPointsLimit = 700;
			creep->healthPoints = 700;
			creep->atk = 30;
			creep->atkDistance = 145;
			creep->atkSpeeds = 1;
			creep->SetHpBar();
			creep->UpdateFAttack();
		case CreepTypeJ3:
			filename1 = Creep_j3;
			creep->initHealthPointsLimit = 700;
			creep->healthPoints = 700;
			creep->atk = 30;
			creep->atkDistance = 145;
			creep->atkSpeeds = 1;
			creep->SetHpBar();
			creep->UpdateFAttack();
		case CreepTypeJ4:
			filename1 = Creep_j4;
			creep->initHealthPointsLimit = 700;
			creep->healthPoints = 700;
			creep->atk = 30;
			creep->atkDistance = 145;
			creep->atkSpeeds = 1;
			creep->SetHpBar();
			creep->UpdateFAttack();
		default:
			break;
		}
	}
	else {
		switch (creepType)
		{
		case CreepTypeTest:
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
			//...
			break;

		case CreepTypeMelee:
			filename1 = Creep_melee;
			creep->initHealthPointsLimit = 550;
			creep->healthPoints = 550;
			creep->atk = 15;
			creep->atkDistance = 40;
			creep->atkSpeeds = 1;
			creep->SetHpBar();
			creep->UpdateAttack2();
			//...
			break;
		case CreepTypeRange:
			filename1 = Creep_range;
			creep->initHealthPointsLimit = 200;
			creep->healthPoints = 200;
			creep->atk = 20;
			creep->atkDistance = 130;
			creep->atkSpeeds = 1;
			creep->SetHpBar();
			creep->UpdateAttack2();
			//...
			break;
		case CreepTypeCannon:
			filename1 = Creep_cannon;
			creep->initHealthPointsLimit = 700;
			creep->healthPoints = 700;
			creep->atk = 30;
			creep->atkDistance = 145;
			creep->atkSpeeds = 1;
			creep->SetHpBar();
			creep->UpdateAttack2();
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

void Creep::update(float dt) {
	if (this->healthPoints == 0)
	{
		this->die();
	}
	;
}

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
		return true;
	}
	setHealthPoints(hp);

	return false;
}

void Creep::die() {
	//不知道涉及什么先不写
	//rdc:播放死亡动画
	this->stopAllActions();
	this->setVisible(false);
	this->setAtk(0);
//	this->release();
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
	float x = this->x_position + 30;
	float y = this->y_position + 60;
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
	this->schedule(schedule_selector(Creep::AttackAndMove1), 1, -1, 0);
}

void Creep::UpdateAttack2()
{
	this->schedule(schedule_selector(Creep::AttackAndMove2), 1, -1, 0);
}

void Creep::UpdateFAttack()
{
	this->schedule(schedule_selector(Creep::FieldAttackAndMove), 1, -1, 0);
}



void Creep::AttackAndMove1(float delta)
{
	if (targetCreep.size() > 0) {
		for (auto iter = targetCreep.begin(); iter!= targetCreep.end();) {
			auto i = *iter;
			auto atk = i->getAtk();
			iter++;
			if (OtherCreep.size() > 0 ) {//攻击othercreep
				auto ocreep = *OtherCreep.begin();
				if (i->newAttackRect()->containsPoint(ocreep->getPosition()) && ocreep->getHealthPoints()>0) {
					ocreep->setHealthPoints(ocreep->getHealthPoints() - atk);
					if (ocreep->getHealthPoints() <= 0) {
						OtherCreep.erase(OtherCreep.begin());
						ocreep->die();
					}
					continue;
				}
			}
			if (i->newAttackRect()->containsPoint(Tower2->getPosition()) && Tower2->getHealthPoints()>0) {//防御塔2号
				Tower2->setHealthPoints(Tower2->getHealthPoints() - atk);
				if (Tower2->getHealthPoints() <= 0) {
					Tower2->die();
				}
				continue;
			}
			else if (i->newAttackRect()->containsPoint(Base2->getPosition()) && Base2->getHealthPoints()>0) {//base 2
				Base2->setHealthPoints(Base2->getHealthPoints() - atk);
				if (Base2->getHealthPoints() >= 0) {
					Base2->die();
				}
				continue;
			}
			else if (i->newAttackRect()->containsPoint(OtherHero->getPosition()) && OtherHero->getHealthPoints()>0) {
				OtherHero->setHealthPoints(OtherHero->getHealthPoints() - atk);
				if(OtherHero->getHealthPoints() <= 0) {
					OtherHero->die();
				}continue;
			}
			else {
				i->moveForward();
			}			
		}
	}
}

void Creep::AttackAndMove2(float delta)
{
	if (OtherCreep.size() > 0) {
		for (auto iter = OtherCreep.begin(); iter != OtherCreep.end();) {
			auto i = *iter;
			auto atk = i->getAtk();
			iter++;
			if (targetCreep.size() > 0) {//攻击target
				auto ocreep = *targetCreep.begin();
				if (i->newAttackRect()->containsPoint(ocreep->getPosition()) && ocreep->getHealthPoints() > 0) {
					ocreep->setHealthPoints(ocreep->getHealthPoints() - atk);
					if (ocreep->getHealthPoints() <= 0) {
						ocreep->die();
					}
					continue;
				}
			}
			if (i->newAttackRect()->containsPoint(Tower1->getPosition()) && Tower1->getHealthPoints()>0) {
				Tower1->setHealthPoints(Tower1->getHealthPoints() - atk);
				if (Tower1->getHealthPoints() <= 0) {
					Tower1->die();
				}
				continue;
			}
			else if (i->newAttackRect()->containsPoint(Base1->getPosition()) && Base1->getHealthPoints() >= 0) {
				Base1->setHealthPoints(Base1->getHealthPoints() - atk);
				if (Base1->getHealthPoints() >= 0) {
					Base1->die();
				}
				continue;
			}
			else if (i->newAttackRect()->containsPoint(Myhero->getPosition()) && Myhero->getHealthPoints()>0) {
				Myhero->setHealthPoints(Myhero->getHealthPoints() - atk);
				if (Myhero->getHealthPoints() <= 0) {
					Myhero->die();
				}continue;
			}
			else {
				i->moveBack();
			}
		}
	}
}

void Creep::FieldAttackAndMove(float delta)
{
	if (this->newAttackRect()->containsPoint(Myhero->getPosition())) {
		Myhero->setHealthPoints(Myhero->getHealthPoints() - this->getAtk());
		if (Myhero->getHealthPoints() <= 0) {
			Myhero->die();
		}
		
	}
	else if(this->newAttackRect()->containsPoint(OtherHero->getPosition())) {
		OtherHero->setHealthPoints(OtherHero->getHealthPoints() - this->getAtk());
		if (OtherHero->getHealthPoints() <= 0) {
			OtherHero->die();
		}
	}
}

void Creep::moveForward()
{
	auto Moving = MoveTo::create(1, Vec2(this->getPositionX() + 50, this->getPositionY()));
	this->stopAllActions();
	this->runAction(Moving);
}

void Creep::moveBack()
{
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

bool Creep::chechMyheroInRect()
{
	if (this->newAttackRect()->containsPoint(Myhero->getPosition())) {
		this->isAttacking = true;
		return true;
	}
	return false;
}

bool Creep::checkOtherHeroInRect()
{
	if (this->newAttackRect()->containsPoint(OtherHero->getPosition())) {
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



void Creep::attackOtherHero()
{

	if (this->isAttacking == true) {
		this->isAttacking = false;
		this->stopAllActions();
		//播放动画

		OtherHero->setHealthPoints(OtherHero->getHealthPoints() - this->getAtk());
	}
}

