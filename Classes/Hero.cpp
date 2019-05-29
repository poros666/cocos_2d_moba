//////////////////
/*
徐炳昌
5.27
ver1
*/
#include"Hero.h"
using namespace cocos2d;


 Hero* Hero::creatWithHeroTypes(HeroTypes heroType) {
	Hero* hero = new (std::nothrow)Hero();
	
	std::string filename1 = Hero_test;

	//通过switch根据type来初始化数值
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

	if (hero && hero->initWithFile(filename)) {//判断tower对象是否生成成功
		hero->autorelease();//加入内存释放池中，不会立即释放creep对象
		return hero;
	}
	CC_SAFE_DELETE(hero);

	return nullptr;
}

bool Hero::hurt(float atk) {

	int hp;
	hp -= (int)(atk * armorPoints);//护甲计算公式在这里调整

	if (hp <= 0) {
		//die();//死亡判定可以写到这里也可以通过hurt函数返回的bool值再调用die();
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
	//不知道涉及什么先不写
	//rdc:播放死亡动画
	this->setVisible(false);
}

