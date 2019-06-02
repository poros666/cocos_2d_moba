#pragma once
#include"cocos2d.h"
using namespace cocos2d;

class CharaAni {
public:
	static CharaAni* getInstance();//µ¥ÀýÄ£Ê½


	void initAni();
	//void initCreeps();
	void init_Executioner();


	Animation* createAnimation(const char* prefixName, int start, int end, float delay);
private:
	//static CharaAni* instance;
};