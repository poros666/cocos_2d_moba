//////////////////
/*
徐炳昌
5.27
ver2
*/
#pragma once
#include<cocos2d.h>
#include"Creeps.h"
#include"WinLayer.h"
using namespace cocos2d;

/*
  定义塔名称也是塔图片文件的名称
*/
#define Tower_test "tower_test.png"
#define Tower_1 "Character Model  res/Mecha_0001.png"
#define Base_1 "Character Model  res/ArchMageTower.png"

/*
定义tower类型
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

	CC_SYNTHESIZE(TowerTypes, towerType, TowerType);//tower类型

	CC_SYNTHESIZE(int, initHealthPointsLimit, InitHealthPointsLimit);//初始血量上限
	CC_SYNTHESIZE(int, healthPoints, HealthPoints);//当前血量
	//CC_SYNTHESIZE(int, healthRecoverPoints, HealthRecoverPoints);//生命恢复速度

	//CC_SYNTHESIZE(int, armorPoints, ArmorPoints);//护甲
	//CC_SYNTHESIZE(int, magicArmorPoints, MagicArmorPoints);//魔抗

	CC_SYNTHESIZE(float, atk, Atk);//攻击力
	CC_SYNTHESIZE(float, atkDistance, AtkDistance);//攻击距离
	CC_SYNTHESIZE(float, atkSpeeds, AtkSpeeds);//攻击速度

	CC_SYNTHESIZE(int, level, Level);//等级//有一个想法//把tower等级设为负数，然后可以把杀人得到的钱和那个单位的等级绑定，检测到等级为负几，就对应该某种小兵杀死所得钱数
	CC_SYNTHESIZE(int, rewardmoney, RewardMoney);
	CC_SYNTHESIZE(int, rewardexp, RewardExp);
	//CC_SYNTHESIZE(cocos2d::Vec2, velocity, Velocity);//移速
	/*
	关于CC_SYNTHESIZE
	define CC_SYNTHESIZE(varType, varName, funName)\
	protected: varType varName;
	public: virtual varType get##funName(void) const { return varName; }
	public: virtual void set##funName(varType var){ varName = var; }
	用于get？暂不明确，但是书上样例有，先用
	*/
public:
	//Tower(TowerTypes towerType);//构造函数
	//void spawnTower();//生成tower函数
	//virtual void update(float dt);//游戏循环调用的默认函数//设置默认对象的自动运动的位置和角度x
	static Tower* creatWithTowerTypes(TowerTypes towerType,bool pending);//静态创造tower函数
	bool isAttacking;
	bool hurt(float atk);//受伤
	void die();//死亡
	void win();//判断胜利
	//void hpRecover(int healthRecoverPoint);//回血
	void SetHpBar();
	virtual void update(float dt);
	void UpdateHpBar(float delta);
	Rect* newAttackRect();
	bool checkHeroInRect();
	bool checkCreepInRect(std::list<Creep*>::iterator iter);//之后又具体的小兵类之后写成两拨小兵
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