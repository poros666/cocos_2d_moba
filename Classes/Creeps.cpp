//////////////////
/*
�����
5.25
ver1
*/
#include<Creeps.h>
using namespace cocos2d;

Creep::Creep(CreepTypes creepType) {
	this->creepType = creepType;
	this->velocity = Vec2::ZERO;
}

Creep* Creep::creatWithCreepTypes(CreepTypes creepType) {
	Creep* creep = new Creep(creepType);
	const char* creepFramName = Creep_test;

	//ͨ��switch����type����ʼ����ֵ
	switch (creepType)
	{
	case CreepTypeTest:
		creepFramName = Creep_test;
		creep->initHealthPointsLimit = 10;
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

	if (creep && creep->initWithSpriteFrameName(creepFramName)) {//�ж�creep�����Ƿ����ɳɹ�
		creep->autorelease();//�����ڴ��ͷų��У����������ͷ�creep����
		///////////////////////////////////////->>
		//��creep���������������֧��
		auto body = PhysicsBody::create();
		////////////////////////////////////////<<-
	}
	/////////////////////////////////////////////////////////////////////////������������ײ���֣���ʱ��д
}

//void Creep::update(float dt) {

void Creep::spawnCreep() {
	Size screenSize = Director::getInstance()->getVisibleSize();
	
	//���ó�ʼλ��
	//float xPos = ;
	//float yPos = ;

	//this->setPosition(Vec2(xPos, yPos));
	//this->setAnchorPoint(Vec2());

	//��ʼ������Ҳ���������������

	this->setVisible(true);
}

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
}

