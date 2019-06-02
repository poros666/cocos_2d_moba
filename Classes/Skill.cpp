


#include"Skill.h"


using namespace cocos2d;


Skill* Skill::createWithNameCdPicOwner(const std::string& skillName, float cd, const std::string& skillPic,Hero* owner) {
	auto skill = new (std::nothrow)Skill();
	if (skill && skill->init(skillName, cd, skillPic,owner)) {
		skill->autorelease();
			return skill;
	}
	CC_SAFE_DELETE(skill);
		return nullptr;
}


bool Skill::init(const std::string& skillName, float Cd, const std::string& skillPic,Hero* owner) {

	if (!Button::init(skillPic)) {
		return false;
	}

	//this->ignoreContentAdaptWithSize(true);

	setSkillName(skillName);//ÉèÖÃ¼¼ÄÜÃû³Æ
	setCd(Cd);//ÉèÖÃ¼¼ÄÜÀäÈ´Ê±¼ä
	auto contentSize = this->getContentSize();//»ñÈ¡¼¼ÄÜÍ¼±ê´óÐ¡

	auto cdPicSprite = Sprite::create("skillCdpic.png");
	progress = ProgressTimer::create(cdPicSprite);
	progress->setType(ProgressTimer::Type::RADIAL);
	progress->setMidpoint(Point(0.5f, 0.5f));
	progress->setPercentage(0);
	progress->setReverseDirection(true);
	progress->setPosition(Vec2(contentSize.width / 2, contentSize.height / 2));
	this->addChild(progress);

	setOk(true);//Ä¬ÈÏ¼¼ÄÜÓ¦µ±²»ÄÜÊ¹ÓÃ£¬ÏÖ×ö²âÊÔÉèÎªÄ¬ÈÏ¿ÉÒÔÊ¹ÓÃ
	setLvl(1);//Ä¬ÈÏ¼¼ÄÜµÈ¼¶Ó¦µ±Îª0£¬²âÊÔÓÃÎª1
	
	this->addTouchEventListener([=](Ref * sender, ui::Widget::TouchEventType type) {
		if (type == ui::Widget::TouchEventType::ENDED)
			this->Click(owner);
		});
	/*¼üÅÌ¼àÌýÔÝÊ±²»ÖªµÀÔõÃ´×ö£¬buttonÃ»ÓÐ¼üÅÌlistenerËÆºõ
	auto listenerKeyPad = EventListenerKeyboard::create();
	listenerKeyPad->onKeyReleased = [=](EventKeyboard::KeyCode keycode, Event * event) {

		if (keycode == EventKeyboard::KeyCode::KEY_CAPITAL_Q) {

			this->Click(owner);

		}
	};
	*/

	return true;

}

void Skill::setOk(bool isOk) {
	_isOk = isOk;
	if (!isOk) {
		progress->setPercentage(100.0f);
	}
	progress->setPercentage(0.0f);
}

void Skill::Click(Hero* owner) {
	if (_isOk) {
		setOk(false);
		//onClick();

		/*//////////////////////////////
		ActionInterval* forwardBy = MoveBy::create(2, Vec2(100, 100));
		ActionInterval* backBy = forwardBy->reverse();
		Action* action = Repeat::create(dynamic_cast<FiniteTimeAction*>(Sequence::create(forwardBy, backBy, NULL)), 4);
		owner->runAction(action);*/

		//Hero* tempHero = static_cast<Hero*> (owner);
		//float ss = tempHero->getPositionX();
		switch (lvl)
		{
			
		case 1: 
		{



			auto Singleton = AnimationCache::getInstance();
			Animation* right = Singleton->getAnimation("Executioner_attack");
			Animate* animate_right = Animate::create(right);
			owner->runAction(CCRepeatForever::create(animate_right));



			owner->setHealthPoints(owner->getHealthPoints() + 40);
			ActionInterval * forward = MoveTo::create(4, Vec2(owner->getPositionX() + 40, owner->getPositionY()));
			owner->runAction(forward);
			
			break;
		}

		case 2:
		
			break;
		case 3:
			break;
		case 4:
			break;
		}
		

		cdTimer = 0;
		schedule(CC_CALLBACK_0(Skill::cdProcess, this), 0.1f, "cdProcess");

	}
}


void Skill::cdProcess() {
	cdTimer = cdTimer + 0.1;

	progress->setPercentage(100.0 - 100.0 * cdTimer / cd);

	if (cdTimer >= cd) {
		unschedule("cdProcess");
		setOk(true);
	}
}


