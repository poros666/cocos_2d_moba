//////////////////
/*
Ðì±þ²ý
5.27
ver1
*/

#pragma once
#include<cocos2d.h>
using namespace cocos2d;

/*¶¨ÒåÓ¢ÐÛÃû³ÆÒ²ÊÇÓ¢ÐÛÍ¼Æ¬ÎÄ¼þµÄÃû³Æ
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
¶¨ÒåÓ¢ÐÛÀàÐÍ
*/
typedef enum {
	HeroTypeTest=0,
	HeroTpye1,
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
	CC_SYNTHESIZE(int, magicArmorPoints, MagicArmorPoints);//Ä§¿¹

	CC_SYNTHESIZE(float, atk, Atk);//¹¥»÷Á¦
	CC_SYNTHESIZE(float, atkDistance, AtkDistance);//¹¥»÷¾àÀë
	CC_SYNTHESIZE(float, atkSpeeds, AtkSpeeds);//¹¥»÷ËÙ¶È

	CC_SYNTHESIZE(int, level, Level);//µÈ¼¶
	CC_SYNTHESIZE(int, exp, Exp);//µ±Ç°¾­ÑéÖµ
	CC_SYNTHESIZE(int, skillPoints, SkillPoints);//¼¼ÄÜµã
	CC_SYNTHESIZE(int, skillLevel_1, SkillLevel_1);//Ò»¼¼ÄÜµÈ¼¶
	CC_SYNTHESIZE(int, skillLevel_2, SkillLevel_2);//¶þ¼¼ÄÜµÈ¼¶
	CC_SYNTHESIZE(int, skillLevel_3, SkillLevel_3);//Èý¼¼ÄÜµÈ¼¶
	CC_SYNTHESIZE(int, skillLevel_4, SkillLevel_4);//ËÄ¼¼ÄÜµÈ¼¶


	CC_SYNTHESIZE(int, gold, Gold);//½ðÇ® 
	CC_SYNTHESIZE(int, itemsNum, ItemsNum);//ÎïÆ·ÊýÁ¿


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
	
	//virtual void update(float dt);//ÓÎÏ·Ñ­»·µ÷ÓÃµÄÄ¬ÈÏº¯Êý
	static Hero* creatWithHeroTypes(HeroTypes heroType);//¾²Ì¬´´ÔìÓ¢ÐÛº¯Êý

	bool hurt(float atk);//ÊÜÉË.
	void die();//ËÀÍö.
	void hpRecover(int healthRecoverPoint);//»ØÑª
	void mpRecover(int manaRecoverPoint);//»ØÀ¶
	void addExp(int exp);//»ñµÃ¾­Ñé
	void addGold(int gold);//»ñµÃ½ðÇ®
	void SetHpBar();
	void UpdateHpBar(float delta);
	void SetManaBar();
	void UpdateManaBar(float delta);
	//ÒÉÎÊÕâÐ©Ö»¸Ä±äÊýÖµµÄº¯Êý»òÐí¿ÉÒÔ²»Ð´
	//¼Ç·Ö°åÔÚÄÄÀï×öºÏÀí£¿ÎÒÕâÀï¿ÉÒÔ¼Ó»ñµÃ×Ü½ðÇ®£¬É±ÈËÊý ËÀÍöÊý£¬ÓÎÏ·½áÊøºó¶ÁÈ¡Êý¾Ý¾Í¿ÉÒÔÁË
	float x_position=0;
	float y_position=0;
private:
	ProgressTimer* HpBarProgress;
	ProgressTimer* ManaBarProgress;
};

