//////////////////
/*
Ðì±þ²ý
5.27
ver1
*/

#pragma once
#include<cocos2d.h>
#include<map>
#include"Creeps.h"
#include"Tower.h"

using namespace cocos2d;
using namespace std;
/*¶¨ÒåÓ¢ÐÛÃû³ÆÒ²ÊÇÓ¢ÐÛÍ¼Æ¬ÎÄ¼þµÄÃû³Æ
*/
#define Hero_test "desertExecutioner_0001.png"
#define Hero_execu "Character Model  res/desertExecutioner_0001.png"
#define Hero_elite "Character Model  res/SaurianElite_0001.png"
#define Hero_munra "Character Model  res/desertMunra_0001.png"
#define Hero_4 "Character Model  res/hero_4.png"

#define SKILL_LVL_LIMIT 3
#define ITEMS_LIMIT 6
#define LEVEL_LIMIT 5
#define LEVEL_UP_LIMIT_BASE 100

/*
¶¨ÒåÓ¢ÐÛÀàÐÍ
*/
typedef enum {
	HeroTypeTest=0,
	HeroTpyeExecu,
	HeroTpyeElite,
	HeroTpyeMunra
}HeroTypes;

class Hero :public cocos2d::Sprite {

	CC_SYNTHESIZE(HeroTypes, heroType, HeroType);//ÀàÐÍ

	CC_SYNTHESIZE(int, initHealthPointsLimit, InitHealthPointsLimit);//³õÊ¼ÑªÁ¿ÉÏÏÞ
	CC_SYNTHESIZE(int, healthPoints, HealthPoints);//µ±Ç°ÑªÁ¿
	CC_SYNTHESIZE(int, healthRecoverPoints, HealthRecoverPoints);//ÉúÃü»Ö¸´ËÙ¶È

	CC_SYNTHESIZE(int, initManaPointsLimit, InitManaPointsLimit);//³õÊ¼À¶Á¿ÉÏÏÞ
	CC_SYNTHESIZE(int, manaPoints, ManaPoints);//µ±Ç°À¶Á¿
	CC_SYNTHESIZE(int, manaRecoverPoints, ManaRecoverPoints);//À¶Á¿»Ö¸´ËÙ¶È

	CC_SYNTHESIZE(int, armorPoints, ArmorPoints);//»¤¼×
	//CC_SYNTHESIZE(int, magicArmorPoints, MagicArmorPoints);//Ä§¿¹

	CC_SYNTHESIZE(float, atk, Atk);//¹¥»÷Á¦
	CC_SYNTHESIZE(float, atkDistance, AtkDistance);//¹¥»÷¾àÀë
	CC_SYNTHESIZE(float, atkSpeeds, AtkSpeeds);//¹¥»÷ËÙ¶È

	CC_SYNTHESIZE(int, level, Level);//µÈ¼¶
	CC_SYNTHESIZE(int, exp, Exp);
	CC_SYNTHESIZE(int, expLimit, ExpLimit);//µ±Ç°¾­ÑéÖµ
	CC_SYNTHESIZE(int, skillPoints, SkillPoints);//¼¼ÄÜµã
	CC_SYNTHESIZE(int, skillLevel_1, SkillLevel_1);//Ò»¼¼ÄÜµÈ¼¶
	CC_SYNTHESIZE(int, skillLevel_2, SkillLevel_2);//¶þ¼¼ÄÜµÈ¼¶
	CC_SYNTHESIZE(int, skillLevel_3, SkillLevel_3);//Èý¼¼ÄÜµÈ¼¶
	CC_SYNTHESIZE(int, skillLevel_4, SkillLevel_4);//ËÄ¼¼ÄÜµÈ¼¶

	CC_SYNTHESIZE(int, movespeed, MoveSpeed);
	CC_SYNTHESIZE(int, gold, Gold);//½ðÇ® 
	CC_SYNTHESIZE(int, itemsNum, ItemsNum);//ÎïÆ·ÊýÁ¿


	CC_SYNTHESIZE(Vec2, rebornpoint, ReBornPoint);

	CC_SYNTHESIZE(cocos2d::Vec2, velocity, Velocity);//ÒÆËÙ
	/*
	¹ØÓÚCC_SYNTHESIZE
	define CC_SYNTHESIZE(varType, varName, funName)\
	protected: varType varName;
	public: virtual varType get##funName(void) const { return varName; }

	public: virtual void set##funName(varType var){ varName = var; }
	ÓÃÓÚget£¿ÔÝ²»Ã÷È·£¬µ«ÊÇÊéÉÏÑùÀýÓÐ£¬ÏÈÓÃ
	*/
public:
	
	//virtual void update(float dt);
	Rect* attack_rect; 
	Vec2 ReStart;
	static Hero* creatWithHeroTypes(HeroTypes heroType);//¾²Ì¬´´ÔìÓ¢ÐÛº¯Êý
	bool hurt(float atk);//ÊÜÉË.
	void die();//ËÀÍö.
	void setNewAtkRect();
	void hpRecover(int healthRecoverPoint);//»ØÑª
	void mpRecover(int manaRecoverPoint);//»ØÀ¶
	void addExp(int exp);//»ñµÃ¾­Ñé
	void addGold(int gold);//»ñµÃ½ðÇ®
	void SetHpBar();
	void UpdateHpBar(float delta);
	void SetManaBar();
	void UpdateManaBar(float delta);
	Rect* newAttackRect();
	void moveBack();
	void AttackAndMove();//单机模式的时候我方默认选择左边，所以这里采用右侧的逻辑，即otherhero
	void move(Vec2 endPos, Hero* Hero);

	virtual void update(float dt);
	float x_position=0;
	float y_position=0;
	Hero* EnemyHero;
	Tower* EnemyTower;
	Creep* EnemyCreep;
	list<int> equipment;
	void clickAttack(Node* target,Hero* owner);
	std::string getName();

private:
	ProgressTimer* HpBarProgress;
	ProgressTimer* ManaBarProgress;
};

