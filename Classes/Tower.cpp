//////////////////
/*
�����
5.27
ver2
*/
#include<Tower.h>
using namespace cocos2d;

Tower* Tower::creatWithTowerTypes(TowerTypes towerType) {
	Tower* tower = new (std::nothrow)Tower();
	
	std::string filename1 = Tower_test;

	//ͨ��switch����type����ʼ����ֵ
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

	if (tower && tower->initWithFile(filename)) {//�ж�tower�����Ƿ����ɳɹ�
		tower->autorelease();//�����ڴ��ͷų��У����������ͷ�creep����
		return tower;
	}
	CC_SAFE_DELETE(tower);

	return nullptr;
}

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