//////////////////
/*
徐炳昌
5.27
ver4
*/
#include<Creeps.h>
using namespace cocos2d;
/*
Creep::Creep(CreepTypes creepType) {
	this->creepType = creepType;
	this->velocity = Vec2::ZERO;
}
*/
Creep* Creep::creatWithCreepTypes(CreepTypes creepType) {
	Creep* creep = new (std::nothrow)Creep();

	std::string filename1 = Creep_test;

	//通过switch根据type来初始化数值
	switch (creepType)
	{
	case CreepTypeTest:
		filename1 = Creep_test;
		creep->initHealthPointsLimit = 10;
		creep->healthPoints = 10;
		creep->armorPoints = 10;
		creep->magicArmorPoints = 10;
		creep->atk = 10;
		creep->atkDistance = 10;
		creep->atkSpeeds = 10;
		creep->initHealthPointsLimit = 222;
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

	int hp;
	hp -= (int)(atk * armorPoints);//护甲计算公式在这里调整

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
	this->release();
}

