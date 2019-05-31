


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

	setSkillName(skillName);//设置技能名称
	setCd(Cd);//设置技能冷却时间
	auto contentSize = this->getContentSize();//获取技能图标大小

	auto cdPicSprite = Sprite::create("skillCdpic.png");
	progress = ProgressTimer::create(cdPicSprite);
	progress->setType(ProgressTimer::Type::RADIAL);
	progress->setMidpoint(Point(0.5f, 0.5f));
	progress->setPercentage(0);
	progress->setReverseDirection(true);
	progress->setPosition(Vec2(contentSize.width / 2, contentSize.height / 2));
	this->addChild(progress);

	setOk(true);//默认技能应当不能使用，现做测试设为默认可以使用
	setLvl(1);//默认技能等级应当为0，测试用为1
	
	this->addTouchEventListener([=](Ref * sender, ui::Widget::TouchEventType type) {
		if (type == ui::Widget::TouchEventType::ENDED)
			this->Click(owner);
		});
	/*键盘监听暂时不知道怎么做，button没有键盘listener似乎
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
			owner->setHealthPoints(owner->getHealthPoints() + 40);

			ActionInterval * forward = MoveTo::create(4, Vec2(owner->getPositionX() + 100, owner->getPositionY()));
			owner->runAction(forward);
			break;
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


