#pragma once
#include"cocos2d.h"
#include"ui/CocosGUI.h"
#include"Hero.h"

using namespace cocos2d;

class Skill :public cocos2d::ui::Button {
public:
	//std::function<void(void)> onClick;
	void Click(Hero* owner);

	//ͨ���������ơ�cdʱ�䡢����ͼƬ���ɼ���button 
	static Skill* createWithNameCdPicOwner(const std::string& skillName, float cd, const std::string& skillPic,Hero* owner);
	virtual bool init(const std::string& skillName, float Cd, const std::string& skillPic,Hero* owner);
	
	bool isOk(){
		return _isOk; 
	}
	void setOk(bool _isOk);

private:
	CC_SYNTHESIZE(std::string, skillName, SkillName);
	CC_SYNTHESIZE(float,cdTimer,CdTimer);//������ȴʱ���ʱ��
	CC_SYNTHESIZE(float,cd,Cd);//������ȴʱ��
	CC_SYNTHESIZE(int, lvl,Lvl);//���ܵȼ�
	
	bool _isOk;

	cocos2d::ProgressTimer* progress;//���ڲ���������ȴͼ����progress
	cocos2d::EventListenerTouchOneByOne* listener;//���㴥��������

	void cdProcess();//������ȴ����ʵ�ֺ���

};