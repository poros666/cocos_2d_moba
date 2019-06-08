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
		tower->setHealthPoints(10);
		tower->SetHpBar();

		//...
		break;
		
	case TowerTypeT1:
		filename1 = Tower_1;
		tower->setInitHealthPointsLimit(1000);
		tower->setHealthPoints(1000);
		tower->setAtk(100);
		tower->setAtkDistance(150);
		tower->setAtkSpeeds(1);
		tower->SetHpBar();
		//...
		break;
	case TowerTypeT2:
		filename1 = Tower_1;
		tower->setInitHealthPointsLimit(1200);
		tower->setHealthPoints(1200);
		tower->setAtk(120);
		tower->setAtkDistance(150);
		tower->setAtkSpeeds(1);
		tower->SetHpBar();
		//...
		break;
	case TowerTypeT3:
		filename1 = Tower_1;
		tower->setInitHealthPointsLimit(1400);
		tower->setHealthPoints(1400);
		tower->setAtk(140);
		tower->setAtkDistance(150);
		tower->setAtkSpeeds(1);
		tower->SetHpBar();
		//...
		break;
	case TowerTypeBase:
		filename1 = Base_1;
		tower->setInitHealthPointsLimit(1500);
		tower->setHealthPoints(1500);
		tower->setAtk(0);
		tower->setAtkDistance(0);
		tower->setAtkSpeeds(0);
		tower->SetHpBar();
		//...
		break;
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

	int hp = getHealthPoints();
	hp -= atk;


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
void Tower::SetHpBar()
{
	auto Healthbar = Sprite::create("healthbar.dds");
	HpBarProgress = ProgressTimer::create(Healthbar);
	HpBarProgress->setScale(0.08, 0.3);
	auto size = HpBarProgress->getContentSize();
	float x = this->x_position + 30;
	float y = this->y_position + 60;
	HpBarProgress->setPosition(Vec2(x, y));
	HpBarProgress->setType(ProgressTimer::Type::BAR);
	HpBarProgress->setMidpoint(Vec2(0, 0));
	HpBarProgress->setBarChangeRate(Vec2(1, 0));
	HpBarProgress->setPercentage(100 * this->getHealthPoints() / this->getInitHealthPointsLimit());
	this->addChild(HpBarProgress, 4, "HpBarProgress");
	this->schedule(schedule_selector(Tower::UpdateHpBar));
}
void Tower::UpdateHpBar(float delta)
{
	float percentage = 100 * this->getHealthPoints() / this->getInitHealthPointsLimit();
	if (percentage <= 0)
	{
		percentage = 0;
		this->unschedule(schedule_selector(Tower::UpdateHpBar));
	}
	HpBarProgress->setPercentage(percentage);
}