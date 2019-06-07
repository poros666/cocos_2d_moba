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
		creep->initHealthPointsLimit = 10;
		creep->healthPoints = 10;
		creep->armorPoints = 10;
		creep->magicArmorPoints = 10;
		creep->atk = 10;
		creep->atkDistance = 100;
		creep->atkSpeeds = 10;
		creep->SetHpBar();
		creep->setRewardMoney(30);
		creep->setRewardExp(50);
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

	int hp;
	hp -= (int)(atk * armorPoints);//���׼��㹫ʽ���������

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
	this->release();
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


/*
bool Creep::checkHeroInRect()
{
	auto distance = this->getAtkDistance();
	if (this->isAttacking && this->attack_rect->containsPoint(OtherHero->getPosition())) {
		this->isAttacking = true;
		return true;
	}
	return false;
}
void Creep::attackOtherHero()
{
	this->stopAllActions();
	if (this->isAttacking == true) {
		this->isAttacking = false;
		//���Ŷ���

		OtherHero->setHealthPoints(OtherHero->getHealthPoints() - this->getAtk());

	}
}*/
//
