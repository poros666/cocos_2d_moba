//////////////////
/*
�����
5.27
ver1
*/

#pragma once
#include<cocos2d.h>
using namespace cocos2d;

/*����Ӣ������Ҳ��Ӣ��ͼƬ�ļ�������
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
����Ӣ������
*/
typedef enum {
	HeroTypeTest=0,
	HeroTpye1,
}HeroTypes;

class Hero :public cocos2d::Sprite {

	CC_SYNTHESIZE(HeroTypes, heroType, HeroType);//����

	CC_SYNTHESIZE(int, initHealthPointsLimit, InitHealthPointsLimit);//��ʼѪ������
	CC_SYNTHESIZE(int, healthPoints, HealthPoints);//��ǰѪ��
	CC_SYNTHESIZE(int, healthRecoverPoints, HealthRecoverPoints);//�����ָ��ٶ�

	CC_SYNTHESIZE(int, armorPoints, ArmorPoints);//����
	CC_SYNTHESIZE(int, magicArmorPoints, MagicArmorPoints);//ħ��

	CC_SYNTHESIZE(float, atk, Atk);//������
	CC_SYNTHESIZE(float, atkDistance, AtkDistance);//��������
	CC_SYNTHESIZE(float, atkSpeeds, AtkSpeeds);//�����ٶ�

	CC_SYNTHESIZE(int, level, Level);//�ȼ�
	CC_SYNTHESIZE(int, exp, Exp);//��ǰ����ֵ
	CC_SYNTHESIZE(int, skillPoints, SkillPoints);//���ܵ�
	CC_SYNTHESIZE(int, skillLevel_1, SkillLevel_1);//һ���ܵȼ�
	CC_SYNTHESIZE(int, skillLevel_2, SkillLevel_2);//�����ܵȼ�
	CC_SYNTHESIZE(int, skillLevel_3, SkillLevel_3);//�����ܵȼ�
	CC_SYNTHESIZE(int, skillLevel_4, SkillLevel_4);//�ļ��ܵȼ�


	CC_SYNTHESIZE(int, gold, Gold);//��Ǯ 
	CC_SYNTHESIZE(int, itemsNum, ItemsNum);//��Ʒ����


	CC_SYNTHESIZE(cocos2d::Vec2, velocity, Velocity);//����
	/*
	����CC_SYNTHESIZE
	define CC_SYNTHESIZE(varType, varName, funName)\
	protected: varType varName;
	public: virtual varType get##funName(void) const { return varName; }
	public: virtual void set##funName(varType var){ varName = var; }
	����get���ݲ���ȷ���������������У�����
	*/
public:
	
	//virtual void update(float dt);//��Ϸѭ�����õ�Ĭ�Ϻ���
	static Hero* creatWithHeroTypes(HeroTypes heroType);//��̬����Ӣ�ۺ���

	bool hurt(float atk);//����.
	void die();//����.
	void hpRecover(int healthRecoverPoint);//��Ѫ
	void mpRecover(int manaRecoverPoint);//����
	void addExp(int exp);//��þ���
	void addGold(int gold);//��ý�Ǯ
	
	//������Щֻ�ı���ֵ�ĺ���������Բ�д
	//�Ƿְ���������������������Լӻ���ܽ�Ǯ��ɱ���� ����������Ϸ�������ȡ���ݾͿ�����

};

