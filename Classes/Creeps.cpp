//////////////////
/*
�����
5.26
ver3
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
	//auto sp = Sprite::create("ShopItem.png");
	//TextureCache::getInstance()->addImage("ShopItem.png");
	//auto texture=TextureCache::getInstance()->getTextureForKey("ShopItem.png");
	//auto frame = SpriteFrame::createWithTexture(texture, Rect(0, 0, 150, 200));
	//ͨ��switch����type����ʼ����ֵ
	switch (creepType)
	{
	case CreepTypeTest:

		creep->initHealthPointsLimit = 10;
		creep->healthPoints = 10;
		creep->armorPoints = 10;
		creep->magicArmorPoints = 10;
		creep->atk = 10;
		creep->atkDistance = 10;
		creep->atkSpeeds = 10;
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
	

	if (creep && creep->initWithSpriteFrameName(Creep_test)) {//�ж�creep�����Ƿ����ɳɹ�
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

		creep->setVisible(false);
		creep->spawnCreep();
		creep->unscheduleUpdate();
		creep->scheduleUpdate();
		///////////////////////////////////////*///<<-
		creep->setVisible(true);
		creep->spawnCreep();
		return creep;
	}
	CC_SAFE_DELETE(creep);

	return nullptr;
}

void Creep::update(float dt) {
}
void Creep::spawnCreep() {
	Size screenSize = Director::getInstance()->getVisibleSize();
	
	//���ó�ʼλ��
	float xPos = CCRANDOM_0_1()*(screenSize.width-this->getContentSize().width);
	float yPos = screenSize.height+this->getContentSize().height/2;

	this->setPosition(Vec2(xPos, yPos));
	this->setAnchorPoint(Vec2(0.5f,0.5f));
	//0.5f,0.5f--->>�жϳ���Ļthis->getposition().y+this->getcontenSize().height/2<0

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

