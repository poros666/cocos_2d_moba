//////////////////
/*
�����
5.27
ver3
*/

#pragma once
#include<cocos2d.h>
using namespace cocos2d;

/*����С������Ҳ��С��ͼƬ�ļ�������
  ��ʱ����֪���෽��Ͷ�̬��ô��
  ����һ��ͼƬ���
*/
#define Creep_test "creep_test.png"
#define Creep_melee "Character Model  res/SaurianMyrmidon_0001.png"
#define Creep_range "Character Model  res/SaurianBlazefang_0001.png"
#define Creep_cannon "Character Model  res/SaurianQuetzal_0001.png"
#define Creep_j1 "Character Model  res/scorpion_0001.png"
#define Creep_j2 "Character Model  res/desertImmortal_0001.png"
#define Creep_j3 "Character Model  res/desertRaider_0001.png"
#define Creep_j4 "Character Model  res/desertThug_0001.png"
#define Creep_j5 "Character Model  res/fallen_0001.png"


/*

����С����Ұ������
*/
typedef enum {
	CreepTypeTest=0,
	CreepTypeMelee,
	CreepTypeRange,
	CreepTypeCannon,
	CreepTypeJ1,
	CreepTypeJ2,
	CreepTypeJ3,
	CreepTypeJ4,
	CreepTypeJ5,
}CreepTypes;

class Creep :public cocos2d::Sprite {

	CC_SYNTHESIZE(CreepTypes, creepType, CreepType);//С������

	CC_SYNTHESIZE(int, initHealthPointsLimit, InitHealthPointsLimit);//��ʼѪ������
	CC_SYNTHESIZE(int, healthPoints, HealthPoints);//��ǰѪ��
	//CC_SYNTHESIZE(int, healthRecoverPoints, HealthRecoverPoints);//�����ָ��ٶ�

	//CC_SYNTHESIZE(int, armorPoints, ArmorPoints);//����
	//CC_SYNTHESIZE(int, magicArmorPoints, MagicArmorPoints);//ħ��

	CC_SYNTHESIZE(float, atk,Atk);//������
	CC_SYNTHESIZE(float, atkDistance, AtkDistance);//��������
	CC_SYNTHESIZE(float, atkSpeeds, AtkSpeeds);//�����ٶ�

	CC_SYNTHESIZE(int, level, Level);//�ȼ�//��һ���뷨//��С���ȼ���Ϊ������Ȼ����԰�ɱ�˵õ���Ǯ���Ǹ���λ�ĵȼ��󶨣���⵽�ȼ�Ϊ�������Ͷ�Ӧ��ĳ��С��ɱ������Ǯ��

	CC_SYNTHESIZE(cocos2d::Vec2, velocity,Velocity);//����
	CC_SYNTHESIZE(int, rewardmoney, RewardMoney);
	CC_SYNTHESIZE(int, rewardexp, RewardExp);
	/*
	����CC_SYNTHESIZE
	define CC_SYNTHESIZE(varType, varName, funName)\
	protected: varType varName;
	public: virtual varType get##funName(void) const { return varName; }
	public: virtual void set##funName(varType var){ varName = var; }
	����get���ݲ���ȷ���������������У�����
	*/
public:
	//Creep(CreepTypes creepType);//���캯��
	//void spawnCreep();//����С������
	virtual void update(float dt);//��Ϸѭ�����õ�Ĭ�Ϻ���//���岻��
	static Creep* creatWithCreepTypes(CreepTypes creepType);//��̬����С������
	bool isAttacking = false;
	Rect* attack_rect;
	bool hurt(float atk);//����.
	void die();//����.
	//void hpRecover(int healthRecoverPoint);//��Ѫ
	Rect* newAttackRect();
	bool checkHeroInRect();
	bool checkCreepInRect();//֮���־����С����֮��д������С��
	bool checkTowerInRect();
	void SetHpBar();
	void UpdateHpBar(float delta);

	std::string getName();

	void attackOtherHero();

	float x_position = 0;
	float y_position = 0;
private:
	ProgressTimer* HpBarProgress;
};

