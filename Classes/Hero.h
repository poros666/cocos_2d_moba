//////////////////
/*
徐炳昌
5.27
ver1
*/

#pragma once
#include<cocos2d.h>
using namespace cocos2d;

/*定义英雄名称也是英雄图片文件的名称
*/
#define Hero_test "hero_test.png"
#define Hero_1 "hero_1.png"
#define Hero_2 "hero_2.png"
#define Hero_3 "hero_3.png"
#define Hero_4 "hero_4.png"

#define SKILL_LVL_LIMIT 4
#define ITEMS_LIMIT 6
#define LEVEL_LIMIT 25
#define LEVEL_UP_LIMIT_BASE 100

/*
定义英雄类型
*/
typedef enum {
	HeroTypeTest=0,
	HeroTpye1,
}HeroTypes;

class Hero :public cocos2d::Sprite {

	CC_SYNTHESIZE(HeroTypes, heroType, HeroType);//类型

	CC_SYNTHESIZE(int, initHealthPointsLimit, InitHealthPointsLimit);//初始血量上限
	CC_SYNTHESIZE(int, healthPoints, HealthPoints);//当前血量
	CC_SYNTHESIZE(int, healthRecoverPoints, HealthRecoverPoints);//生命恢复速度

	CC_SYNTHESIZE(int, armorPoints, ArmorPoints);//护甲
	CC_SYNTHESIZE(int, magicArmorPoints, MagicArmorPoints);//魔抗

	CC_SYNTHESIZE(float, atk, Atk);//攻击力
	CC_SYNTHESIZE(float, atkDistance, AtkDistance);//攻击距离
	CC_SYNTHESIZE(float, atkSpeeds, AtkSpeeds);//攻击速度

	CC_SYNTHESIZE(int, level, Level);//等级
	CC_SYNTHESIZE(int, exp, Exp);//当前经验值
	CC_SYNTHESIZE(int, skillPoints, SkillPoints);//技能点
	CC_SYNTHESIZE(int, skillLevel_1, SkillLevel_1);//一技能等级
	CC_SYNTHESIZE(int, skillLevel_2, SkillLevel_2);//二技能等级
	CC_SYNTHESIZE(int, skillLevel_3, SkillLevel_3);//三技能等级
	CC_SYNTHESIZE(int, skillLevel_4, SkillLevel_4);//四技能等级


	CC_SYNTHESIZE(int, gold, Gold);//金钱 
	CC_SYNTHESIZE(int, itemsNum, ItemsNum);//物品数量


	CC_SYNTHESIZE(cocos2d::Vec2, velocity, Velocity);//移速
	/*
	关于CC_SYNTHESIZE
	define CC_SYNTHESIZE(varType, varName, funName)\
	protected: varType varName;
	public: virtual varType get##funName(void) const { return varName; }
	public: virtual void set##funName(varType var){ varName = var; }
	用于get？暂不明确，但是书上样例有，先用
	*/
public:
	
	//virtual void update(float dt);//游戏循环调用的默认函数
	static Hero* creatWithHeroTypes(HeroTypes heroType);//静态创造英雄函数

	bool hurt(float atk);//受伤.
	void die();//死亡.
	void hpRecover(int healthRecoverPoint);//回血
	void mpRecover(int manaRecoverPoint);//回蓝
	void addExp(int exp);//获得经验
	void addGold(int gold);//获得金钱
	
	//疑问这些只改变数值的函数或许可以不写
	//记分板在哪里做合理？我这里可以加获得总金钱，杀人数 死亡数，游戏结束后读取数据就可以了

};

