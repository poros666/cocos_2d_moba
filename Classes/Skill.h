#pragma once
#include"cocos2d.h"
#include"ui/CocosGUI.h"
#include"Hero.h"

using namespace cocos2d;

class Skill :public cocos2d::ui::Button {
public:
	//std::function<void(void)> onClick;
	void Click(Hero* owner);

	//通过技能名称、cd时间、技能图片生成技能button 
	static Skill* createWithNameCdPicOwner(const std::string& skillName, float cd, const std::string& skillPic,Hero* owner);
	virtual bool init(const std::string& skillName, float Cd, const std::string& skillPic,Hero* owner);
	
	bool isOk(){
		return _isOk; 
	}
	void setOk(bool _isOk);

private:
	CC_SYNTHESIZE(std::string, skillName, SkillName);
	CC_SYNTHESIZE(float,cdTimer,CdTimer);//技能冷却时间计时器
	CC_SYNTHESIZE(float,cd,Cd);//技能冷却时间
	CC_SYNTHESIZE(int, lvl,Lvl);//技能等级
	
	bool _isOk;

	cocos2d::ProgressTimer* progress;//用于产生技能冷却图样的progress
	cocos2d::EventListenerTouchOneByOne* listener;//单点触摸监听器

	void cdProcess();//技能冷却具体实现函数

};