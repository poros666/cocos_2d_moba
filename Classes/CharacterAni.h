#pragma once
#include"cocos2d.h"
using namespace cocos2d;

class CharaAni {
public:
	static CharaAni* getInstance();//µ¥ÀýÄ£Ê½


	void initAni();
	//void initCreeps();
	void init_executioner();//h1
	void init_myrmidon();//melee
	void init_blazefang();//range
	void init_quetza();//cannon
	void init_mechsTower();//tower
	void init_elite();//h2
	void init_munra();//h3
	void init_scorpion();//junglecreep1
	void init_immortal();//jungle creep2
	void init_raider();//jungle creep3
	void init_thug();//jungle creep4
	void init_fallen();//jungle creep5
	void init_skill();//skill


	Animation* createAnimation(const char* prefixName, int start, int end, float delay);
	Animation* createAnimation(const char* prefixName, int start, int end, float delay, std::string lastFrame);
private:
	//static CharaAni* instance;
};