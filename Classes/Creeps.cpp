//////////////////
/*
�����
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
/*
Creep::Creep(CreepTypes creepType) {
	this->creepType = creepType;
	this->velocity = Vec2::ZERO;
}
*/
Creep* Creep::creatWithCreepTypes(CreepTypes creepType) {
	Creep* creep = new (std::nothrow)Creep();

	std::string filename1 = Creep_test;

	//ͨ��switch����type����ʼ����ֵ
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
		//...
		break;
	
	default:
		break;
	}

	const std::string& filename = filename1;

	if (creep && creep->initWithFile(filename)) {//�ж�creep�����Ƿ����ɳɹ�
		
		creep->autorelease();//�����ڴ��ͷų��У����������ͷ�creep����
		/*//////////////////////////////////////->>
		//��creep���������������֧��
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
	if (this->checkHeroInRect()) {
		OtherHero->setHealthPoints(OtherHero->getHealthPoints() - this->getAtk());
	}

	if (this->healthPoints == 0)
	{
		this->die();
	}
	;
}

/*
void Creep::spawnCreep() {
	Size screenSize = Director::getInstance()->getVisibleSize();
	
	//���ó�ʼλ��
	float xPos = screenSize.width/ 2;
	float yPos = screenSize.height/2;

	this->setPosition(Vec2(xPos, yPos));
	this->setAnchorPoint(Vec2(0.5f,0.5f));
	//0.5f,0.5f--->>�жϳ���Ļthis->getposition().y+this->getcontenSize().height/2<0

	//��ʼ������Ҳ���������������

	this->setVisible(true);
}
*/

bool Creep::hurt(float atk){

	
	int hp=getHealthPoints();
	hp -= atk;

	if (hp <= 0){
		//die();//�����ж�����д������Ҳ����ͨ��hurt�������ص�boolֵ�ٵ���die();
		return true;
	}
	setHealthPoints(hp);

	return false;
}

void Creep::die() {
	//��֪���漰ʲô�Ȳ�д
	//rdc:������������
	this->stopAllActions();
	this->setVisible(false);
	this->setAtk(0);
}


bool Creep::checkTowerInRect(){
	if (this->newAttackRect()->containsPoint(Tower1->getPosition())) {
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

bool Creep::checkHeroInRect()
{
	if (this->newAttackRect()->containsPoint(OtherHero->getPosition())) {
		this->isAttacking = true;
		return true;
	}
	return false;
}



void Creep::attackOtherHero()
{

	if (this->isAttacking == true) {
		this->isAttacking = false;
		this->stopAllActions();
		//���Ŷ���

		OtherHero->setHealthPoints(OtherHero->getHealthPoints() - this->getAtk());
	}
}

