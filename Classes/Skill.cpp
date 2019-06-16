


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
			this->PressQ(owner);
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

void Skill::PressQ(Hero* owner) {

	if (_isOk) {
		setOk(false);
		
		if (owner->getHealthPoints() > 0) {
				if (owner->getManaPoints() >= 10) {
					owner->setPosition(Vec2(owner->getPositionX() + 100, owner->getPositionY()));
					owner->setManaPoints(owner->getManaPoints() - 10);
				}
				break;
			}

			case 2:
	//			if (owner->getManaPoints() >= 10) {
	//				owner->setPosition(Vec2(owner->getPositionX() - 100, owner->getPositionY()));
	//				owner->setManaPoints(owner->getManaPoints() - 10);
	//			}
				break;
			case 3:
	//			if (owner->getManaPoints() >= 10) {
	//				owner->setAtk(owner->getAtk() * 2);
	//				owner->setManaPoints(owner->getManaPoints() - 10);
	//				owner->scheduleOnce(schedule_selector(Hero::unSkill3), 5);
	//			}
				break;
			case 4:
	//			if (owner->getManaPoints() >= 10) {
	//				if (owner->getHealthPoints() + 100 > owner->getInitHealthPointsLimit()) {
	//					owner->setHealthPoints(owner->getInitHealthPointsLimit());
	//				}
	//				else {
	//					owner->setHealthPoints(owner->getHealthPoints() + 100);
	//				}
	//				owner->setManaPoints(owner->getManaPoints() - 10);
	//			}
				break;
			}

		
		cdTimer = 0;
		schedule(CC_CALLBACK_0(Skill::cdProcess, this), 0.1f, "cdProcess");
		}
	}
}

void Skill::PressW(Hero* owner)
{
	if (_isOk) {
		setOk(false);
		
		auto typ = owner->getHeroType();

		if (owner->getHealthPoints() > 0) {
			switch (owner->getLevel())
			{
			case 1:
			{
				switch (typ)
				{
				case HeroTypeExecu: {
				//auto Singleton = AnimationCache::getInstance();
				//Animation* right = Singleton->getAnimation("Elite_attack");
				//Animate* animate_right = Animate::create(right);
				//owner->runAction(CCRepeatForever::create(animate_right));
				if (owner->getManaPoints() >= 10) {
						owner->setInitHealthPointsLimit(owner->getInitHealthPointsLimit() + 50);
					}
					break;
				}
				case HeroTypeElite: {
					if (owner->getManaPoints() >= 10) {
						owner->setGold(owner->getGold() + 50);
					owner->setManaPoints(owner->getManaPoints() - 10);
					}
					break;
				}
				case HeroTypeMunra: {
					if (owner->getManaPoints() >= 10) {
						owner->setInitManaPointsLimit(owner->getInitManaPointsLimit() + 50);
						owner->setManaPoints(owner->getManaPoints()+50);
						owner->setManaPoints(owner->getManaPoints() - 10);
					}
				break;
			}
				}
				break;
			}
			case 2:
			{
				switch (typ)
				{
				case HeroTypeExecu: {
					if (owner->getManaPoints() >= 20) {
						owner->setInitHealthPointsLimit(owner->getInitHealthPointsLimit() + 100);
						owner->setManaPoints(owner->getManaPoints() - 20);
					}
					break;
				}
				case HeroTypeElite: {
					if (owner->getManaPoints() >= 20) {
						owner->setGold(owner->getGold() + 100);
						owner->setManaPoints(owner->getManaPoints() - 20);
					}
					break;
				}
				case HeroTypeMunra: {
					if (owner->getManaPoints() >= 20) {
						owner->setInitManaPointsLimit(owner->getInitManaPointsLimit() + 100);
						owner->setManaPoints(owner->getManaPoints() + 50);
						owner->setManaPoints(owner->getManaPoints() - 20);
					}
					break;
				}
				}
				break;
				break;
			}
			case 3:
			{
				switch (typ)
				{
				case HeroTypeExecu: {
					if (owner->getManaPoints() >= 30) {
						owner->setInitHealthPointsLimit(owner->getInitHealthPointsLimit() + 150);
						owner->setManaPoints(owner->getManaPoints() - 30);
					}
					break;
				}
				case HeroTypeElite: {
					if (owner->getManaPoints() >= 30) {
						owner->setGold(owner->getGold() + 150);
						owner->setManaPoints(owner->getManaPoints() - 30);
					}
					break;
				}
				case HeroTypeMunra: {
					if (owner->getManaPoints() >= 30) {
						owner->setInitManaPointsLimit(owner->getInitManaPointsLimit() + 150);
						owner->setManaPoints(owner->getManaPoints() + 150);
						owner->setManaPoints(owner->getManaPoints() - 30);
					}
					break;
				}
				}
				break;
				break;
			}
			case 4:
			{
				switch (typ)
				{
				case HeroTypeExecu: {
					if (owner->getManaPoints() >= 40) {
						owner->setInitHealthPointsLimit(owner->getInitHealthPointsLimit() + 200);
						owner->setManaPoints(owner->getManaPoints() - 40);
					}
					break;
				}
				case HeroTypeElite: {
					if (owner->getManaPoints() >= 40) {
						owner->setGold(owner->getGold() + 200);
						owner->setManaPoints(owner->getManaPoints() - 40);
					}
					break;
				}
				case HeroTypeMunra: {
					if (owner->getManaPoints() >= 40) {
						owner->setInitManaPointsLimit(owner->getInitManaPointsLimit() + 200);
						owner->setManaPoints(owner->getManaPoints() + 50);
						owner->setManaPoints(owner->getManaPoints() - 40);
					}
					break;
				}
				}
				break;
				break;
			}
			}


			cdTimer = 0;
			schedule(CC_CALLBACK_0(Skill::cdProcess, this), 0.1f, "cdProcess");
		}
	}
}

void Skill::PressE(Hero* owner)
{
	if (_isOk) {
		setOk(false);
		
		if (owner->getHealthPoints() > 0) {
			if (owner->getManaPoints() >= 10) {
					owner->setAtk(owner->getAtk() * 2);
					owner->setManaPoints(owner->getManaPoints() - 10);
					owner->scheduleOnce(schedule_selector(Hero::unSkill3), 5);
			}
				break;
			}

			case 2:
	//			if (owner->getManaPoints() >= 10) {
	//				owner->setPosition(Vec2(owner->getPositionX() - 100, owner->getPositionY()));
	//				owner->setManaPoints(owner->getManaPoints() - 10);
	//			}
				break;
			case 3:
	//			if (owner->getManaPoints() >= 10) {
	//				owner->setAtk(owner->getAtk() * 2);
	//				owner->setManaPoints(owner->getManaPoints() - 10);
	//				owner->scheduleOnce(schedule_selector(Hero::unSkill3), 5);
	//			}
				break;
			case 4:
	//			if (owner->getManaPoints() >= 10) {
	//				if (owner->getHealthPoints() + 100 > owner->getInitHealthPointsLimit()) {
	//					owner->setHealthPoints(owner->getInitHealthPointsLimit());
	//				}
	//				else {
	//					owner->setHealthPoints(owner->getHealthPoints() + 100);
	//				}
	//				owner->setManaPoints(owner->getManaPoints() - 10);
	//			}
				break;
			}


			cdTimer = 0;
			schedule(CC_CALLBACK_0(Skill::cdProcess, this), 0.1f, "cdProcess");
		}
	}
}

void Skill::PressR(Hero* owner)
{
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
		if (owner->getHealthPoints() > 0) {
			switch (lvl)
			{

			case 1:
			{


				//owner->stopAllActions();
				//auto Singleton = AnimationCache::getInstance();
				//Animation* right = Singleton->getAnimation("Elite_attack");
				//Animate* animate_right = Animate::create(right);
				//owner->runAction(CCRepeatForever::create(animate_right));
				if (owner->getManaPoints() >= 10) {
					if (owner->getHealthPoints() + 100 > owner->getInitHealthPointsLimit()) {
						owner->setHealthPoints(owner->getInitHealthPointsLimit());
						}
						else {
							owner->setHealthPoints(owner->getHealthPoints() + 100);
						}
						owner->setManaPoints(owner->getManaPoints() - 10);
					}
				break;
			}

			case 2:
	//			if (owner->getManaPoints() >= 10) {
	//				owner->setPosition(Vec2(owner->getPositionX() - 100, owner->getPositionY()));
	//				owner->setManaPoints(owner->getManaPoints() - 10);
	//			}
				break;
			case 3:
	//			if (owner->getManaPoints() >= 10) {
	//				owner->setAtk(owner->getAtk() * 2);
	//				owner->setManaPoints(owner->getManaPoints() - 10);
	//				owner->scheduleOnce(schedule_selector(Hero::unSkill3), 5);
	//			}
				break;
			case 4:
	//			if (owner->getManaPoints() >= 10) {
	//				if (owner->getHealthPoints() + 100 > owner->getInitHealthPointsLimit()) {
	//					owner->setHealthPoints(owner->getInitHealthPointsLimit());
	//				}
	//				else {
	//					owner->setHealthPoints(owner->getHealthPoints() + 100);
	//				}
	//				owner->setManaPoints(owner->getManaPoints() - 10);
	//			}
				break;
			}


			cdTimer = 0;
			schedule(CC_CALLBACK_0(Skill::cdProcess, this), 0.1f, "cdProcess");
			}
		}
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


