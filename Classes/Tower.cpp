//////////////////
/*
徐炳昌
5.25
ver1
*/
#include<Tower.h>
using namespace cocos2d;

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