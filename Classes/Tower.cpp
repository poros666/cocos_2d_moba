//////////////////
/*
徐炳昌
5.27
ver2
*/
#include<Tower.h>
using namespace cocos2d;

Tower* Tower::creatWithTowerTypes(TowerTypes towerType) {
	Tower* tower = new (std::nothrow)Tower();
	
	std::string filename1 = Tower_test;

	//通过switch根据type来初始化数值
	switch (towerType)
	{
	case TowerTypeTest:
		filename1 = Tower_test;
		tower->setInitHealthPointsLimit(10);
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

	if (tower && tower->initWithFile(filename)) {//判断tower对象是否生成成功
		tower->autorelease();//加入内存释放池中，不会立即释放creep对象
		return tower;
	}
	CC_SAFE_DELETE(tower);

	return nullptr;
}

bool Tower::hurt(float atk) {

	int hp;
	hp -= (int)(atk * armorPoints);//护甲计算公式在这里调整

	if (hp <= 0) {
		//die();//死亡判定可以写到这里也可以通过hurt函数返回的bool值再调用die();
		return true;
	}
	setHealthPoints(hp);

	return false;
}

void Tower::die() {
	//不知道涉及什么先不写
}

void Tower::win() {
	//
}