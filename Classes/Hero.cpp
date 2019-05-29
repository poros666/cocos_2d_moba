//////////////////
/*
�����
5.27
ver1
*/
#include"Hero.h"
using namespace cocos2d;


 Hero* Hero::creatWithHeroTypes(HeroTypes heroType) {
	Hero* hero = new (std::nothrow)Hero();
	
	std::string filename1 = Hero_test;

	//ͨ��switch����type����ʼ����ֵ
	switch (heroType)
	{
	case HeroTypeTest:
		filename1 = Hero_test;
		hero->setInitHealthPointsLimit(10);
		hero->setHealthPoints(10);
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

	if (hero && hero->initWithFile(filename)) {//�ж�tower�����Ƿ����ɳɹ�
		hero->autorelease();//�����ڴ��ͷų��У����������ͷ�creep����
		return hero;
	}
	CC_SAFE_DELETE(hero);

	return nullptr;
}

bool Hero::hurt(float atk) {

	int hp;
	hp -= (int)(atk * armorPoints);//���׼��㹫ʽ���������

	if (hp <= 0) {
		//die();//�����ж�����д������Ҳ����ͨ��hurt�������ص�boolֵ�ٵ���die();
		return true;
	}
	setHealthPoints(hp);

	return false;
}

void Hero::addExp(int exp) {
	int nowExp=getExp();
	bool lvlup = false;
	int lvl = getLevel();
	int expLimitOfThisLevel = LEVEL_UP_LIMIT_BASE * lvl;

	if (nowExp + exp > expLimitOfThisLevel) {
		lvlup=true;
		setExp(nowExp + exp - expLimitOfThisLevel);
	}

	if (lvlup) {
		lvl++;
		setLevel(lvl);
	}
}

void Hero::die() 
{
	//��֪���漰ʲô�Ȳ�д
	//rdc:������������
	this->setVisible(false);
}

