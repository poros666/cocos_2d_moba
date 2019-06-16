//////////////////
/*
�����
5.27
ver2
*/
#pragma once
#include<cocos2d.h>
#include"Creeps.h"
#include"WinLayer.h"
using namespace cocos2d;

/*
  ����������Ҳ����ͼƬ�ļ�������
*/
#define Tower_test "tower_test.png"
#define Tower_1 "Character Model  res/Mecha_0001.png"
#define Base_1 "Character Model  res/ArchMageTower.png"

/*
����tower����
*/
typedef enum {
	TowerTypeTest = 0,
	TowerTypeT1,
	TowerTypeT2,
	TowerTypeT3,
	TowerTypeT4,
	TowerTypeBase,
}TowerTypes;

class Tower :public cocos2d::Sprite {

	CC_SYNTHESIZE(TowerTypes, towerType, TowerType);//tower����

	CC_SYNTHESIZE(int, initHealthPointsLimit, InitHealthPointsLimit);//��ʼѪ������
	CC_SYNTHESIZE(int, healthPoints, HealthPoints);//��ǰѪ��
	//CC_SYNTHESIZE(int, healthRecoverPoints, HealthRecoverPoints);//�����ָ��ٶ�

	//CC_SYNTHESIZE(int, armorPoints, ArmorPoints);//����
	//CC_SYNTHESIZE(int, magicArmorPoints, MagicArmorPoints);//ħ��

	CC_SYNTHESIZE(float, atk, Atk);//������
	CC_SYNTHESIZE(float, atkDistance, AtkDistance);//��������
	CC_SYNTHESIZE(float, atkSpeeds, AtkSpeeds);//�����ٶ�

	CC_SYNTHESIZE(int, level, Level);//�ȼ�//��һ���뷨//��tower�ȼ���Ϊ������Ȼ����԰�ɱ�˵õ���Ǯ���Ǹ���λ�ĵȼ��󶨣���⵽�ȼ�Ϊ�������Ͷ�Ӧ��ĳ��С��ɱ������Ǯ��
	CC_SYNTHESIZE(int, rewardmoney, RewardMoney);
	CC_SYNTHESIZE(int, rewardexp, RewardExp);
	//CC_SYNTHESIZE(cocos2d::Vec2, velocity, Velocity);//����
	/*
	����CC_SYNTHESIZE
	define CC_SYNTHESIZE(varType, varName, funName)\
	protected: varType varName;
	public: virtual varType get##funName(void) const { return varName; }
	public: virtual void set##funName(varType var){ varName = var; }
	����get���ݲ���ȷ���������������У�����
	*/
public:
	//Tower(TowerTypes towerType);//���캯��
	//void spawnTower();//����tower����
	//virtual void update(float dt);//��Ϸѭ�����õ�Ĭ�Ϻ���//����Ĭ�϶�����Զ��˶���λ�úͽǶ�x
	static Tower* creatWithTowerTypes(TowerTypes towerType,bool pending);//��̬����tower����
	bool isAttacking;
	bool hurt(float atk);//����
	void die();//����
	void win();//�ж�ʤ��
	//void hpRecover(int healthRecoverPoint);//��Ѫ
	void SetHpBar();
	virtual void update(float dt);
	void UpdateHpBar(float delta);
	Rect* newAttackRect();
	bool checkHeroInRect();
	bool checkCreepInRect(std::list<Creep*>::iterator iter);//֮���־����С����֮��д������С��
	void UpdateAttack1();
	void UpdateAttack2();
	void Attack1(float);
	void Attack2(float);
	void WinPending(float);

	Rect* newRect();
	float x_position = 0;
	float y_position = 0;
private:
	ProgressTimer* HpBarProgress;
};