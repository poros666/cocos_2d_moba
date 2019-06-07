#include"Game.h"
#include"CharacterAni.h"
int a = 0;
USING_NS_CC;
Scene* Game::createScene()
{
	return Game::create();
}
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in StartSceneScene.cpp\n");
}
bool Game::init()
{
	if (!Scene::init())
	{
		return false;
	}
	CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	cache->addSpriteFramesWithFile("enemies_desert_3-hd.plist", "enemies_desert_3-hd.png");

	auto ani = new CharaAni();
	ani->init_Executioner();
	Myhero = Hero::creatWithHeroTypes(HeroTypeTest);
	OtherHero = Hero::creatWithHeroTypes(HeroTypeTest);
	Tower1 = Tower::creatWithTowerTypes(TowerTypeTest);
	MapLayerPrint();
	HeroPrint();
	StatusLayerPrint();
	TowerPrint();
	ShopLayerPrint();
	ShowPrint();
	return true;
}
void Game::onEnter()
{
	Scene::onEnter();
	Game::initMouseListener(Myhero);
	Game::initKeyListener(Myhero);
	this->scheduleUpdate();
	this->schedule(schedule_selector(Game::CreepsPrint), 1, -1, 0);
}
void Game::MapLayerPrint()
{
	//if (UserDefault::getInstance()->getBoolForKey(SINGLE))
	//{
		auto Maplayer = OneMapLayer::CreateLayer();
	//}
	//else 
	//{ 
		//这里加载5v5地图如果有的话; 
	//}
	this->addChild(Maplayer, 0 ,"MapLayer");
}
void Game::ShopLayerPrint()
{
	auto ShopItem = MenuItemImage::create("ShopItem.png","ShopItem.png",CC_CALLBACK_1(Game::menuShopCallback, this));
	ShopItem->setPosition(Vec2(origin.x + visibleSize.width/2-30, origin.y +visibleSize.height/2-25));
	auto menu = Menu::create(ShopItem,NULL);
	this->addChild(menu, 5);
}

void Game::menuShopCallback(cocos2d::Ref* pSender)
{
	Myhero->stopAllActions();
	//Mouselistener->setEnabled(false);
	auto ShopLayer = ShopLayer::createLayer(Myhero);
	this->addChild(ShopLayer, 6,"Shop");
}

void Game::ShowPrint()
{
	auto ShowItem = MenuItemImage::create("EquipmentShow.png", "EquipmentShow.png", CC_CALLBACK_1(Game::menuShowCallback,this));
	if (ShowItem == nullptr ||
		ShowItem->getContentSize().width <= 0 ||
		ShowItem->getContentSize().height <= 0) {
		problemLoading("'EquipmentShow.png'and'EquipmentShow.png'");
	}
	else {
		ShowItem->setPosition(Vec2(origin.x + visibleSize.width / 2 - 150, origin.y + visibleSize.height / 2 - 25));
	}
	auto menu = Menu::create(ShowItem, NULL);
	this->addChild(menu, 5);
}

void Game::menuShowCallback(cocos2d::Ref* pSender)
{
	auto ShowLayer = EquipmentShowLayer::createLayer(Myhero);
	this->addChild(ShowLayer, 6);
}




void Game::StatusLayerPrint()
{
	skillQ = Skill::createWithNameCdPicOwner("ski_right",5,"Ski_right.png",Myhero);
	skillQ->setPosition(Vec2(visibleSize.width /2-200,visibleSize.height/2-200));
	auto Statuslayer = StatusLayer::createLayer();
	this->addChild(Statuslayer,3,"StatusLayer");
	Statuslayer->addChild(skillQ,1);
}
void Game::ScoreBoardPrint()
{
	auto layer = ScoreBoard::createLayer(Myhero);
	this->addChild(layer, 7, "ScoreBoard");

}
void Game::ScoreBoardRelesed() 
{
	this->removeChildByName("ScoreBoard");
}
void Game::HeroPrint()
{
	//生成英雄的函数
	int _atkDistance=Myhero->getAtkDistance();
	Myhero->x_position = visibleSize.width / 2 - 100;
	Myhero->y_position = visibleSize.height / 2 - 100;
	Myhero->setPosition(Vec2(Myhero->x_position,Myhero->y_position));
	Myhero->attack_rect = new Rect(Myhero->getPositionX() - _atkDistance,Myhero->getPositionY() - _atkDistance,2* _atkDistance,2* _atkDistance);
	this->getChildByName("MapLayer")->addChild(Myhero, 2,"Myhero");
	SetHpBar();
	SetManaBar();

	OtherHero->x_position = visibleSize.width / 2-200;
	OtherHero->y_position = visibleSize.height / 2-200;
	OtherHero->setPosition(Vec2(visibleSize.width / 2 - 200, visibleSize.height / 2 - 20));
	this->getChildByName("MapLayer")->addChild(OtherHero, 2, "OtherHero");
}


void Game::TowerPrint()
{
	//放置塔的函数

	Tower1->setPosition(Vec2(visibleSize.width / 2 -50, visibleSize.height / 2 - 50));
	this->getChildByName("MapLayer")->addChild(Tower1, 2);
}


void Game::CreepsPrint(float delta)
{
	//生成兵的函数

	auto creep1 = Creep::creatWithCreepTypes(CreepTypeTest);
	creep1->setPosition(Vec2(visibleSize.width / 2+a*15, visibleSize.height / 2));
	this->getChildByName("MapLayer")->addChild(creep1, 2);
	targetCreep.push_back(creep1);
	a++;
}
void Game::SetHpBar()
{
	auto Healthbar = Sprite::create("healthbar.dds");
	HpBarProgress = ProgressTimer::create(Healthbar);
	HpBarProgress->setScale(0.5, 0.5);
	auto size = HpBarProgress->getContentSize();
	float x = visibleSize.width / 2;
	float y =size.height-7;
	HpBarProgress->setPosition(Vec2(x,y));
	HpBarProgress->setType(ProgressTimer::Type::BAR);
	HpBarProgress->setMidpoint(Vec2(0, 0));
	HpBarProgress->setBarChangeRate(Vec2(1, 0));
	HpBarProgress->setPercentage(100*Myhero->getHealthPoints()/Myhero->getInitHealthPointsLimit());
	this->addChild(HpBarProgress,4,"HpBarProgress");
	this->schedule(schedule_selector(Game::UpdateHpBar));
}
void Game::UpdateHpBar(float delta)
{
	float percentage = 100*Myhero->getHealthPoints() / Myhero->getInitHealthPointsLimit();
	if (percentage <= 0)
	{
		percentage = 0;
		this->unschedule(schedule_selector(Game::UpdateHpBar));
	}
	HpBarProgress->setPercentage(percentage);
}
void Game::SetManaBar()
{
	auto ManaBar = Sprite:: create("manabar.dds");
	ManaBarProgress = ProgressTimer::create(ManaBar);
	ManaBarProgress->setScale(0.5, 0.5);
	auto size = ManaBarProgress->getContentSize();
	float x = visibleSize.width / 2;
	float y = size.height/2-6;
	ManaBarProgress->setPosition(Vec2(x, y));
	ManaBarProgress->setType(ProgressTimer::Type::BAR);
	ManaBarProgress->setMidpoint(Vec2(0, 0));
	ManaBarProgress->setBarChangeRate(Vec2(1, 0));
	ManaBarProgress->setPercentage(100*Myhero->getManaPoints()/Myhero->getInitManaPointsLimit());
	this->addChild(ManaBarProgress, 4, "ManaBarProgress");
	this->schedule(schedule_selector(Game::UpdateManaBar));
}
void Game::UpdateManaBar(float delta)
{
	float percentage = 100 * Myhero->getManaPoints() / Myhero->getInitManaPointsLimit();
	if (percentage <= 0)
	{
		percentage = 0;
		this->unschedule(schedule_selector(Game::UpdateManaBar));
	}
	ManaBarProgress->setPercentage(percentage);
}
void Game::update(float delta)
{
	//血条蓝条经验条的实时更新
	


	//英雄死亡监测
	if (Myhero->getHealthPoints() <= 0)
	{
		this->unscheduleUpdate();
		Game::HeroDie();
	}
}
void Game::HeroDie()
{
	Myhero->die();
	this->scheduleOnce(schedule_selector(Game::recreateHero), 1.0f);
}
void Game::recreateHero(float delta)
{
	Myhero->setVisible(true);
	Myhero->setHealthPoints(Myhero->getInitHealthPointsLimit());
	this->scheduleUpdate();
	this->schedule(schedule_selector(Game::UpdateHpBar));
	this->schedule(schedule_selector(Game::UpdateManaBar));
	Myhero->schedule(schedule_selector(Hero::UpdateHpBar));
	Myhero->schedule(schedule_selector(Hero::UpdateManaBar));
}
void Game::initKeyListener(Hero* hero)
{
	keylistener = EventListenerKeyboard::create();
	keylistener->onKeyPressed = [this, hero](EventKeyboard::KeyCode keycode, Event *event)
	{
		switch (keycode)
		{
		case EventKeyboard::KeyCode::KEY_TAB:
		{	
			ScoreBoardPrint();
			//Mouselistener->setEnabled(false);
			break;
		}
		case EventKeyboard::KeyCode::KEY_B:
		{
			if (this->getChildByName("Shop") == nullptr)
			{
				auto ShopLayer = ShopLayer::createLayer(hero);
				this->addChild(ShopLayer, 6,"Shop");
				//Mouselistener->setEnabled(false);
			}
			break;
		}
		case EventKeyboard::KeyCode::KEY_Q:
		{
			
			skillQ->Click(hero);
			break;
		}
		case EventKeyboard::KeyCode::KEY_W:
			break;
		case EventKeyboard::KeyCode::KEY_E:
			break;
		case EventKeyboard::KeyCode::KEY_R:
			break;
		case EventKeyboard::KeyCode::KEY_A:
		{
			hero->hurt(10);
			break;
		}
		case EventKeyboard::KeyCode::KEY_S:
			break;
		default:
			break;
		}
		return true;
	};
	keylistener->onKeyReleased = [this, hero](EventKeyboard::KeyCode keycode, Event *event)
	{
		switch (keycode)
		{
		case EventKeyboard::KeyCode::KEY_TAB:
		{	
			ScoreBoardRelesed();
			Mouselistener->setEnabled(true);
			break;
		}
		default:
			break;
		}
		return true;
	};
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keylistener, this->getChildByName("MapLayer"));
}

void Game::initMouseListener(Hero* hero)
{

	Mouselistener = EventListenerTouchOneByOne::create();

	Mouselistener->onTouchBegan = [this, hero](Touch* touch, Event* e) {
		auto visiblesize = Director::getInstance()->getVisibleSize();
		auto _tileMap = TMXTiledMap::create("temmap/filemap.tmx");
		auto MapSizeWidth = _tileMap->getMapSize().width *32;
		auto MapSizeHeight = _tileMap->getMapSize().height *32;
		Vec2 startPos = hero->getPosition() ;
		Vec2 endPos;
		if (hero->getPositionX() <= visiblesize.width/2) {
			endPos.x = touch->getLocation().x;
		}
		else if (hero->getPositionX() <= MapSizeWidth - visiblesize.width / 2) {
			endPos.x = hero->getPositionX() - visiblesize.width/2+touch->getLocation().x;
		}
		else {
			endPos.x = MapSizeWidth - visiblesize.width + touch->getLocation().x;
		}

		if (hero->getPositionY() <= visiblesize.height / 2) {
			endPos.y = touch->getLocation().y;
		}
		else if (hero->getPositionY() <= MapSizeHeight - visiblesize.height / 2) {
			endPos.y = hero->getPositionY() - visiblesize.height/2 + touch->getLocation().y;
		}
		else {
			endPos.y = MapSizeHeight- visiblesize.height + touch->getLocation().y;
		}




		/*
				int Angle = CC_RADIANS_TO_DEGREES((endPos - startPos).getAngle());

				if (Angle > -45 && Angle < 45) {

					Hero->move(Hero::Direction::RIGHT, endPos, Hero);//UP

				}

				else if (Angle > -135 && Angle < -45)

				{

					Hero->move(Hero::Direction::DOWN, endPos, Hero);//LE



				}



				else if ((Angle > -180 && Angle < -135) || (Angle > 135 && Angle < 180))

				{



					Hero->move(Hero::Direction::LEFT, endPos, Hero);//DO

				}

				else

				{

					Hero->move(Hero::Direction::UP, endPos, Hero);//R

				}

		*/
		auto iter = targetCreep.begin();
		Rect* clickRect = new Rect(endPos.x - 25, endPos.y - 25, 50, 50);

		
		if (clickRect->containsPoint(OtherHero->getPosition()) &&
			hero->attack_rect->containsPoint(OtherHero->getPosition())&&
			OtherHero->getHealthPoints()>0) {
			//这里留给攻击动画
			OtherHero->setHealthPoints(OtherHero->getHealthPoints() - hero->getAtk());
			return true;
		}
		if (clickRect->containsPoint(Tower1->getPosition()) &&
			hero->attack_rect->containsPoint(Tower1->getPosition()) &&
			Tower1->getHealthPoints() > 0) {
			Tower1->setHealthPoints(Tower1->getHealthPoints() - hero->getAtk());
			return true;
		}
		if (*iter != nullptr) {
			for (; iter != targetCreep.end(); iter++) {
				auto _creep = *iter;
				if (clickRect->containsPoint(_creep->getPosition()) &&
					hero->attack_rect->containsPoint(_creep->getPosition()) &&
					_creep->getHealthPoints() > 0) {
					_creep->setHealthPoints(_creep->getHealthPoints() - hero->getAtk());
					return true;
				}
			}
		}


		hero->move(endPos, hero);

		return true;

	};

	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(Mouselistener,1);

	Mouselistener->onTouchEnded = [this](Touch* touch, Event* e)

	{

		return true;

	};

}



bool Game::clickToAttack(Hero* owner)
{
	return false;
}







