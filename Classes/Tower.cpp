//////////////////
/*
�����
5.25
ver1
*/
#include<Tower.h>
using namespace cocos2d;

bool Tower::hurt(float atk) {

	int hp;
	hp -= (int)(atk * armorPoints);//���׼��㹫ʽ���������

	if (hp <= 0) {
		//die();//�����ж�����д������Ҳ����ͨ��hurt�������ص�boolֵ�ٵ���die();
		return true;
	}
	setHealthPoints(hp);

	return false;
}

void Tower::die() {
	//��֪���漰ʲô�Ȳ�д
}

void Tower::win() {
	//
}