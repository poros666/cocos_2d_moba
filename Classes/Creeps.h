//////////////////
/*
Ðì±þ²ý
5.27
ver3
*/

#pragma once
#include<cocos2d.h>
using namespace cocos2d;

/*¶¨ÒåÐ¡±øÃû³ÆÒ²ÊÇÐ¡±øÍ¼Æ¬ÎÄ¼þµÄÃû³Æ
  ÔÝÊ±»¹²»ÖªµÀ¶à·½ÏòºÍ¶¯Ì¬ÔõÃ´¸ã
  ÏÈÓÃÒ»ÕÅÍ¼Æ¬Ìæ´ú
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

¶¨ÒåÐ¡±øÓëÒ°¹ÖÀàÐÍ
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

	CC_SYNTHESIZE(CreepTypes, creepType, CreepType);//Ð¡±øÀàÐÍ

	CC_SYNTHESIZE(int, initHealthPointsLimit, InitHealthPointsLimit);//³õÊ¼ÑªÁ¿ÉÏÏÞ
	CC_SYNTHESIZE(int, healthPoints, HealthPoints);//µ±Ç°ÑªÁ¿
	//CC_SYNTHESIZE(int, healthRecoverPoints, HealthRecoverPoints);//ÉúÃü»Ö¸´ËÙ¶È

	//CC_SYNTHESIZE(int, armorPoints, ArmorPoints);//»¤¼×
	//CC_SYNTHESIZE(int, magicArmorPoints, MagicArmorPoints);//Ä§¿¹

	CC_SYNTHESIZE(float, atk,Atk);//¹¥»÷Á¦
	CC_SYNTHESIZE(float, atkDistance, AtkDistance);//¹¥»÷¾àÀë
	CC_SYNTHESIZE(float, atkSpeeds, AtkSpeeds);//¹¥»÷ËÙ¶È

	CC_SYNTHESIZE(int, level, Level);//µÈ¼¶//ÓÐÒ»¸öÏë·¨//°ÑÐ¡±øµÈ¼¶ÉèÎª¸ºÊý£¬È»ºó¿ÉÒÔ°ÑÉ±ÈËµÃµ½µÄÇ®ºÍÄÇ¸öµ¥Î»µÄµÈ¼¶°ó¶¨£¬¼ì²âµ½µÈ¼¶Îª¸º¼¸£¬¾Í¶ÔÓ¦¸ÃÄ³ÖÖÐ¡±øÉ±ËÀËùµÃÇ®Êý

	CC_SYNTHESIZE(cocos2d::Vec2, velocity,Velocity);//ÒÆËÙ
	CC_SYNTHESIZE(int, rewardmoney, RewardMoney);
	CC_SYNTHESIZE(int, rewardexp, RewardExp);
	/*
	¹ØÓÚCC_SYNTHESIZE
	define CC_SYNTHESIZE(varType, varName, funName)\
	protected: varType varName;
	public: virtual varType get##funName(void) const { return varName; }
	public: virtual void set##funName(varType var){ varName = var; }
	ÓÃÓÚget£¿ÔÝ²»Ã÷È·£¬µ«ÊÇÊéÉÏÑùÀýÓÐ£¬ÏÈÓÃ
	*/
public:
	//Creep(CreepTypes creepType);//¹¹Ôìº¯Êý
	//void spawnCreep();//Éú³ÉÐ¡±øº¯Êý
	//virtual void update(float dt);//ÓÎÏ·Ñ­»·µ÷ÓÃµÄÄ¬ÈÏº¯Êý//ÒâÒå²»Ã÷
	static Creep* creatWithCreepTypes(CreepTypes creepType,bool pending);//¾²Ì¬´´ÔìÐ¡±øº¯Êý
	static Creep* creatWithCreepTypes(CreepTypes creepType);
	bool isAttacking = false;
	Rect* attack_rect;
	bool hurt(float atk);//ÊÜÉË.
	void die();//ËÀÍö.
	void runF();
	void runB();
	void atkF();
	void atkB();
	void atkJ();
	//void hpRecover(int healthRecoverPoint);//»ØÑª
	Rect* newAttackRect();
	bool chechLeftHeroInRect();
	bool checkRightHeroInRect();
	bool checkTargetCreepInRect();
	bool checkOtherCreepInRect();
	bool checkTower1InRect();
	bool checkTower2InRect();
	void SetHpBar();
	void UpdateHpBar(float delta);
	void UpdateAttack1();
	void UpdateAttack2();
	void UpdateFAttack();
	void AttackAndMove1(float delta);
	void AttackAndMove2(float delta);
	void FieldAttackAndMove(float delta);
	void UpdateDeath(float);


	Rect* newRect();

	void moveForward();
	void moveBack();
	std::string getName();

	//void attackOtherHero();
	bool self;
	float x_position = 0;
	float y_position = 0;
private:
	ProgressTimer* HpBarProgress;
};

