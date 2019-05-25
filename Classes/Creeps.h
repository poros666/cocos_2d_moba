//////////////////
/*
徐炳昌
5.24
ver1
*/

#pragma once
#include<cocos2d.h>

/*定义小兵名称也是小兵精灵帧的名称
  暂时还不知道多方向和动态怎么搞
  先用一张图片替代
*/
#define Creep_test "creep_test.png"
//#define Creep_melee "creep_melee.png"
//#define Creep_range "creep_range.png"
//#define Creep_cannon "creep_cannon.png"

/*
定义小兵类型
*/
typedef enum {
	CreepTypeTest=0,
	CreepTypeMelee,
	CreepTypeRange,
	CreepTypeCannon
}CreepTypes;

class Creep :public cocos2d::Sprite {
	CC_SYNTHESIZE(CreepTypes, creepType, CreepType);//小兵类型
	CC_SYNTHESIZE(int, initHealthPoints, InitHealthPoints);//初始血量
	CC_SYNTHESIZE(int, healthRecoverPoints, HealthRecoverPoints);//生命恢复速度
	CC_SYNTHESIZE(int, initManaPoints, InitManaPoints);//初始蓝量
	CC_SYNTHESIZE(int, armorPoints, ArmorPoints);//护甲
	CC_SYNTHESIZE(int, magicArmorPoints, MagicArmorPoints);//魔抗
	CC_SYNTHESIZE(int, attackPoints, AttackPoints);//攻击力
	CC_SYNTHESIZE(int, attackDistance, AttackDistance);//攻击距离
	CC_SYNTHESIZE(int, attackSpeeds, AttackSpeeds);//攻击速度
	CC_SYNTHESIZE(int, level, Level);//等级//有一个想法//把小兵等级设为负数，然后可以把杀人得到的钱和那个单位的等级绑定，检测到等级为负几，就对应该某种小兵杀死所得钱数
	CC_SYNTHESIZE(cocos2d::Vec2, velocity,Velocity);//移速
	/*
	关于CC_SYNTHESIZE
	define CC_SYNTHESIZE(varType, varName, funName)\
	protected: varType varName;
	public: virtual varType get##funName(void) const { return varName; }
	public: virtual void set##funName(varType var){ varName = var; }
	用于get？暂不明确，但是书上样例有，先用
	*/
public:
	Creep(CreepTypes creepType);//构造函数
	void spawnCreep();//生成小兵函数
	virtual void update(float dt);//游戏循环调用的默认函数//意义不明
	static Creep* creatWithCreepTypes(CreepTypes creepType);//静态创造小兵函数
};

