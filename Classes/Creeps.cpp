//////////////////
/*
徐炳昌
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

	//通过switch根据type来初始化数值
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

	if (creep && creep->initWithSpriteFrameName(creepFramName)) {//判断creep对象是否生成成功
		creep->autorelease();//加入内存释放池中，不会立即释放creep对象
		///////////////////////////////////////->>
		//对creep对象添加物理引擎支持
		auto body = PhysicsBody::create();
		////////////////////////////////////////<<-
	}
	/////////////////////////////////////////////////////////////////////////以下是物理碰撞部分，暂时不写
}

//void Creep::update(float dt) {

void Creep::spawnCreep() {
	Size screenSize = Director::getInstance()->getVisibleSize();
	
	//设置初始位置
	//float xPos = ;
	//float yPos = ;

	//this->setPosition(Vec2(xPos, yPos));
	//this->setAnchorPoint(Vec2());

	//初始化数据也可以在这个函数里

	this->setVisible(true);
}

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
}

