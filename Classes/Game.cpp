#include"Game.h"
#include"CharacterAni.h"
USING_NS_CC;
Hero* RightHero;
Hero* LeftHero;
Tower* Tower1;
Tower* Tower2;
Tower* Base1;
Tower* Base2;
Sprite* bombsp1;
std::list<Creep*> targetCreep;
std::list<Creep*> OtherCreep;
std::list<Creep*> FieldCreep;

Scene* Game::createScene(SocketServer* server, SocketClient* client,char buf[1024])
{
	auto scene = new Game;
	scene->init(server,client,buf);
	return scene;
}
static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in StartSceneScene.cpp\n");
}
bool Game::init(SocketServer* server, SocketClient* client,char buf[1024])
{
	if (!Scene::init())
	{
		return false;
	}
	CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	cache->addSpriteFramesWithFile("Character Model  res/enemies_desert_3-hd.plist", "Character Model  res/enemies_desert_3-hd.png");
	cache->addSpriteFramesWithFile("Character Model  res/enemies_underground-hd.plist", "Character Model  res/enemies_underground-hd.png");
	cache->addSpriteFramesWithFile("Character Model  res/enemies_underground_3-hd.plist", "Character Model  res/enemies_underground_3-hd.png");
	cache->addSpriteFramesWithFile("Character Model  res/towers-hd.plist", "Character Model  res/towers-hd.png");
	cache->addSpriteFramesWithFile("Character Model  res/enemies_underground_2-hd.plist", "Character Model  res/enemies_underground_2-hd.png");
	cache->addSpriteFramesWithFile("Character Model  res/enemies_desert-hd.plist", "Character Model  res/enemies_desert-hd.png");

	auto ani = new CharaAni();
	ani->init_executioner();
	ani->init_quetza();
	ani->init_blazefang();
	ani->init_myrmidon();
	ani->init_mechsTower();
	ani->init_elite();
	ani->init_munra();
	Socketclient = client;
	Socketserver = server;
	UserDefault* defualts = UserDefault::getInstance();
	if (!defualts->getBoolForKey(OFF_LINE))
	{
		if (UserDefault::getInstance()->getBoolForKey("Server"))
		{
			if (defualts->getBoolForKey("Execu")) { LeftHero = Hero::creatWithHeroTypes(HeroTypeExecu, true); }
			if (defualts->getBoolForKey("Elite")) { LeftHero = Hero::creatWithHeroTypes(HeroTypeElite, true); }
			if (defualts->getBoolForKey("Munara")) { LeftHero = Hero::creatWithHeroTypes(HeroTypeMunra, true); }
			switch (buf[1])
			{
			case '0':
				RightHero = Hero::creatWithHeroTypes(HeroTypeTest, false);
				RightHero->setFlipX(true);
				break;
			case 'x':
				RightHero = Hero::creatWithHeroTypes(HeroTypeExecu, false);
				break;
			case 'l':
				RightHero = Hero::creatWithHeroTypes(HeroTypeElite, false);
				break;
			case 'u':
				RightHero = Hero::creatWithHeroTypes(HeroTypeMunra, false);
				break;
			}
		}
		else
		{
			if (defualts->getBoolForKey("Execu")) {RightHero = Hero::creatWithHeroTypes(HeroTypeExecu, true); }
			if (defualts->getBoolForKey("Elite")) { RightHero = Hero::creatWithHeroTypes(HeroTypeElite, true); }
			if (defualts->getBoolForKey("Munara")) { RightHero = Hero::creatWithHeroTypes(HeroTypeMunra, true); }
			switch (buf[1])
			{
			case '0':
				LeftHero = Hero::creatWithHeroTypes(HeroTypeTest, false);
				break;
			case 'x':
				LeftHero = Hero::creatWithHeroTypes(HeroTypeExecu, false);
				break;
			case 'l':
				LeftHero = Hero::creatWithHeroTypes(HeroTypeElite, false);
				break;
			case 'u':
				LeftHero = Hero::creatWithHeroTypes(HeroTypeMunra, false);
				break;
			}
		}
	}
	else
	{
		if (defualts->getBoolForKey("Execu")) { LeftHero = Hero::creatWithHeroTypes(HeroTypeExecu, true); }
		if (defualts->getBoolForKey("Elite")) { LeftHero = Hero::creatWithHeroTypes(HeroTypeElite, true); }
		if (defualts->getBoolForKey("Munara")) { LeftHero = Hero::creatWithHeroTypes(HeroTypeMunra, true); }
		RightHero = Hero::creatWithHeroTypes(HeroTypeTest, false);
		RightHero->setFlipX(true);
	}
	Tower1 = Tower::creatWithTowerTypes(TowerTypeT1,true);
	Tower2 = Tower::creatWithTowerTypes(TowerTypeT1,false);
	Base1 = Tower::creatWithTowerTypes(TowerTypeBase,true);
	Base2 = Tower::creatWithTowerTypes(TowerTypeBase,false);
	bombsp1 = Sprite::create();
	MapLayerPrint();
	HeroPrint();
	StatusLayerPrint();
	TowerPrint();
	ShopLayerPrint();
	ShowPrint();
	//BackButtonPrint();
	return true;
}
void Game::onEnter()
{
	Scene::onEnter();
	this->schedule(schedule_selector(Game::CreepsPrint), 30, -1, 0);
	this->scheduleOnce(schedule_selector(Game::FieldPrint),10);
	if (UserDefault::getInstance()->getBoolForKey("Client"))
	{
		Game::initMouseListener(RightHero);
		Game::initKeyListener(RightHero);
	}
	else
	{
		Game::initMouseListener(LeftHero);
		Game::initKeyListener(LeftHero);
	}
//	this->schedule(schedule_selector(), 1, -1, 1);
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
	LeftHero->stopAllActions();
	//Mouselistener->setEnabled(false);
	auto ShopLayer = ShopLayer::createLayer(LeftHero);
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
	auto ShowLayer = EquipmentShowLayer::createLayer(LeftHero);
	this->addChild(ShowLayer, 6);
}




void Game::StatusLayerPrint()
{
	if (UserDefault::getInstance()->getBoolForKey("Client"))
	{
		skillQ = Skill::createWithNameCdPicOwner("ski_right", 5, "Ski_right.png", RightHero);
		skillQ->setPosition(Vec2(visibleSize.width / 2 - 200, visibleSize.height / 2 - 200));
		auto Statuslayer = StatusLayer::createLayer();
		this->addChild(Statuslayer, 3, "StatusLayer");
		Statuslayer->addChild(skillQ, 1);

		skillW = Skill::createWithNameCdPicOwner("ski_right", 5, "Ski_right.png", RightHero);
		skillW->setPosition(Vec2(visibleSize.width / 2 - 100, visibleSize.height / 2 - 200));

		Statuslayer->addChild(skillW, 1);


		skillE = Skill::createWithNameCdPicOwner("ski_right", 5, "Ski_right.png", RightHero);
		skillE->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 200));

		Statuslayer->addChild(skillE, 1);


		skillR = Skill::createWithNameCdPicOwner("ski_right", 5, "Ski_right.png", RightHero);
		skillR->setPosition(Vec2(visibleSize.width / 2 + 100, visibleSize.height / 2 - 200));

		Statuslayer->addChild(skillR, 1);
	}
	else 
	{
		skillQ = Skill::createWithNameCdPicOwner("ski_right", 5, "Ski_right.png", LeftHero);
		skillQ->setPosition(Vec2(visibleSize.width / 2 - 200, visibleSize.height / 2 - 200));
		auto Statuslayer = StatusLayer::createLayer();
		this->addChild(Statuslayer, 3, "StatusLayer");
		Statuslayer->addChild(skillQ, 1);

		skillW = Skill::createWithNameCdPicOwner("ski_right", 5, "Ski_right.png", LeftHero);
		skillW->setPosition(Vec2(visibleSize.width / 2 - 100, visibleSize.height / 2 - 200));

		Statuslayer->addChild(skillW, 1);


		skillE = Skill::createWithNameCdPicOwner("ski_right", 5, "Ski_right.png", LeftHero);
		skillE->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - 200));

		Statuslayer->addChild(skillE, 1);


		skillR = Skill::createWithNameCdPicOwner("ski_right", 5, "Ski_right.png", LeftHero);
		skillR->setPosition(Vec2(visibleSize.width / 2 + 100, visibleSize.height / 2 - 200));

		Statuslayer->addChild(skillR, 1);
	}
	
}
void Game::ScoreBoardPrint()
{
	auto layer = ScoreBoard::createLayer();
	this->addChild(layer, 7, "ScoreBoard");

}
void Game::ScoreBoardRelesed() 
{
	this->removeChildByName("ScoreBoard");
}
void Game::HeroPrint()
{
	//生成英雄的函数
	int _atkDistance=LeftHero->getAtkDistance();
	LeftHero->setReBornPoint(Vec2(300, 500));
	LeftHero->setPosition(LeftHero->getReBornPoint());
	LeftHero->attack_rect = new Rect(LeftHero->getPositionX() - _atkDistance, LeftHero->getPositionY() - _atkDistance, 2 * _atkDistance, 2 * _atkDistance);
	this->getChildByName("MapLayer")->addChild(LeftHero, 2, "LeftHero");
	SetHpBar();
	SetManaBar();
	SetExpBar();
	RightHero->setReBornPoint(Vec2(4500, 500));
	RightHero->setPosition(RightHero->getReBornPoint());
	this->getChildByName("MapLayer")->addChild(RightHero, 2, "RightHero");
}


void Game::TowerPrint()
{
	//放置塔的函数

	Tower1->setPosition(Vec2(1600, 500));
	this->getChildByName("MapLayer")->addChild(Tower1, 2,"Tower1");

	Tower2->setFlipX(true);
	Tower2->setPosition(Vec2(3200, 500));
	this->getChildByName("MapLayer")->addChild(Tower2, 2, "Tower2");

	Base1->setPosition(Vec2(1000, 500));
	this->getChildByName("MapLayer")->addChild(Base1, 2, "Base1");

	Base2->setFlipX(true);
	Base2->setPosition(Vec2(3800, 500));
	this->getChildByName("MapLayer")->addChild(Base2, 2, "Base2");


	bombsp1->setPosition(Vec2(1,1));
	this->getChildByName("MapLayer")->addChild(bombsp1, 2, "bombsp1");

}


void Game::CreepsPrint(float delta)
{
	//生成兵的函数	
	auto melee1 = Creep::creatWithCreepTypes(CreepTypeMelee,true);
	melee1->setPosition(640,500);
	this->getChildByName("MapLayer")->addChild(melee1, 2);
	targetCreep.push_back(melee1); 
	auto range1 = Creep::creatWithCreepTypes(CreepTypeRange, true);
	range1->setPosition(600, 530);
	this->getChildByName("MapLayer")->addChild(range1, 2);
	targetCreep.push_back(range1);
	auto cannon1 = Creep::creatWithCreepTypes(CreepTypeCannon, true);
	cannon1->setPosition(600, 470);
	this->getChildByName("MapLayer")->addChild(cannon1, 2);
	targetCreep.push_back(cannon1);

	auto melee2 = Creep::creatWithCreepTypes(CreepTypeMelee,false);
	melee2->setPosition(4160, 500);
	this->getChildByName("MapLayer")->addChild(melee2, 2);
	OtherCreep.push_back(melee2);
	auto range2 = Creep::creatWithCreepTypes(CreepTypeRange, false);
	range2->setPosition(4200, 530);
	this->getChildByName("MapLayer")->addChild(range2, 2);
	OtherCreep.push_back(range2);
	auto cannon2 = Creep::creatWithCreepTypes(CreepTypeCannon, false);
	cannon2->setPosition(4200, 470);
	this->getChildByName("MapLayer")->addChild(cannon2, 2);
	OtherCreep.push_back(cannon2);




}
void Game::FieldPrint(float delta)
{
	auto creep1 = Creep::creatWithCreepTypes(CreepTypeJ1, true);
	creep1->setPosition(1800, 150);
	this->getChildByName("MapLayer")->addChild(creep1, 2);
	FieldCreep.push_back(creep1);
	auto creep2 = Creep::creatWithCreepTypes(CreepTypeJ2, true);
	creep2->setPosition(3000, 150);
	this->getChildByName("MapLayer")->addChild(creep2, 2);
	FieldCreep.push_back(creep2);
	auto creep3 = Creep::creatWithCreepTypes(CreepTypeJ3, true);
	creep3->setPosition(1800, 800);
	this->getChildByName("MapLayer")->addChild(creep3, 2);
	FieldCreep.push_back(creep3);
	auto creep4 = Creep::creatWithCreepTypes(CreepTypeJ4, true);
	creep4->setPosition(3000, 800);
	this->getChildByName("MapLayer")->addChild(creep4, 2);
	FieldCreep.push_back(creep4);
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
	if (UserDefault::getInstance()->getBoolForKey("Client"))
	{
		HpBarProgress->setPercentage(100 * RightHero->getHealthPoints() / RightHero->getInitHealthPointsLimit());
	}
	else 
	{
		HpBarProgress->setPercentage(100 * LeftHero->getHealthPoints() / LeftHero->getInitHealthPointsLimit());
	}
	this->addChild(HpBarProgress, 4, "HpBarProgress");
	this->schedule(schedule_selector(Game::UpdateHpBar));
}
void Game::UpdateHpBar(float delta)
{
	float percentage;
	if (UserDefault::getInstance()->getBoolForKey("Client"))
	{
		percentage = 100 * RightHero->getHealthPoints() / RightHero->getInitHealthPointsLimit();
	}
	else
	{
		percentage = 100 * LeftHero->getHealthPoints() / LeftHero->getInitHealthPointsLimit();
	}
	if (percentage <= 0)
	{
		percentage = 0;
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
	if (UserDefault::getInstance()->getBoolForKey("Client"))
	{
		ManaBarProgress->setPercentage(100 * RightHero->getManaPoints() / RightHero->getInitManaPointsLimit());
	}
	else
	{
		ManaBarProgress->setPercentage(100 * LeftHero->getManaPoints() / LeftHero->getInitManaPointsLimit());
	}
	this->addChild(ManaBarProgress, 4, "ManaBarProgress");
	this->schedule(schedule_selector(Game::UpdateManaBar));
}
void Game::UpdateManaBar(float delta)
{
	float percentage;
	if (UserDefault::getInstance()->getBoolForKey("Client"))
	{
		percentage = 100 * RightHero->getManaPoints() / RightHero->getInitManaPointsLimit();
	}
	else
	{
		percentage = 100 * LeftHero->getManaPoints() / LeftHero->getInitManaPointsLimit();
	}
	if (percentage <= 0)
	{
		percentage = 0;
	}
	ManaBarProgress->setPercentage(percentage);
}
void Game::SetExpBar()
{
	auto ExpBar = Sprite::create("healthbar.dds");
	ExpBarProgress = ProgressTimer::create(ExpBar);
	ExpBarProgress->setColor(Color3B::RED);
	ExpBarProgress->setScale(0.27, 0.7);
	auto size = ExpBarProgress->getContentSize();
	float x = visibleSize.width / 2;
	float y = size.height +100 ;
	ExpBarProgress->setPosition(Vec2(x, y));
	ExpBarProgress->setType(ProgressTimer::Type::BAR);
	ExpBarProgress->setMidpoint(Vec2(0, 0));
	ExpBarProgress->setBarChangeRate(Vec2(1, 0));
	if (UserDefault::getInstance()->getBoolForKey("Client"))
	{
		ExpBarProgress->setPercentage(100 * RightHero->getExp() / 100 * RightHero->getLevel());
	}
	else
	{
		ExpBarProgress->setPercentage(100 * LeftHero->getExp() / 100 * LeftHero->getLevel());
	}
	this->addChild(ExpBarProgress, 4, "ExpBarProgress");
	this->schedule(schedule_selector(Game::UpdateExpBar));
}
void Game::UpdateExpBar(float delta)
{
	float percentage = 100 * LeftHero->getExp() /100* LeftHero->getLevel();
	while (percentage >= 100)
	{
		percentage -= 100;
	}
	ExpBarProgress->setPercentage(percentage);
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
			this->ScoreBoardPrint();
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
			if (hero->getHealthPoints() > 0)
			{
				skillQ->PressQ(hero);
			}break;
		}
		case EventKeyboard::KeyCode::KEY_W:
		{
			if (hero->getHealthPoints() > 0)
			{
				skillW->PressW(hero);
			}break;
		}
		case EventKeyboard::KeyCode::KEY_E:
		{
			if (hero->getHealthPoints() > 0)
			{
				skillE->PressE(hero);
			}break;
		}
		case EventKeyboard::KeyCode::KEY_R:
		{
			if (hero->getHealthPoints() > 0)
			{
				skillR->PressR(hero);
			}break;
		}
		case EventKeyboard::KeyCode::KEY_A:
		{
			if (hero == LeftHero) {
				if (
					hero->setNewAtkRect()->containsPoint(RightHero->getPosition()) &&
					RightHero->getHealthPoints() > 0) {
					//这里留给攻击动画
					hero->atkF();
					RightHero->hurt(hero->getAtk());
					if (RightHero->getHealthPoints() <= 0) {
						hero->setGold(hero->getGold() + RightHero->getRewardMoney());
						hero->setExp(hero->getExp() + RightHero->getRewardExp());
					}
			
				}

				//	auto a = clickRect->containsPoint(Tower1->getPosition());
				//	auto b = hero->attack_rect->containsPoint(Tower1->getPosition());
				//	auto eee = hero->getPosition();
				//	auto d = Tower1->getPosition();
				//	auto c = Tower1->getHealthPoints();
				if (
					hero->setNewAtkRect()->containsPoint(Tower2->getPosition()) &&
					Tower2->getHealthPoints() > 0) {
					//攻击动画
					hero->atkF();
					Tower2->hurt(hero->getAtk());
					if (Tower2->getHealthPoints() <= 0) {
						hero->setGold(hero->getGold() + Tower2->getRewardMoney());
						hero->setExp(hero->getExp() + Tower2->getRewardExp());
						}
					return true;
				}
				if (
					hero->setNewAtkRect()->containsPoint(Base2->getPosition()) &&
					Base2->getHealthPoints() > 0) {
					//攻击动画
					hero->atkF();
					Base2->hurt(hero->getAtk());
					if (Base2->getHealthPoints() <= 0) {
						//死亡动画
						hero->setGold(hero->getGold() + Base2->getRewardMoney());
						hero->setExp(hero->getExp() + Base2->getRewardExp());
					}
					return true;
				}
				if (OtherCreep.size()) {
					for (auto iter = OtherCreep.begin(); iter != OtherCreep.end(); iter++) {
						auto _creep = *iter;
						if (
							hero->setNewAtkRect()->containsPoint(_creep->getPosition()) &&
							_creep->getHealthPoints() > 0) {
							//攻击动画
							hero->atkF();
							_creep->hurt(hero->getAtk());
							if (_creep->getHealthPoints() <= 0) {
							
								hero->setGold(hero->getGold() + _creep->getRewardMoney());
								hero->setExp(hero->getExp() + _creep->getRewardExp());
								OtherCreep.erase(iter);
							}
							return true;
						}
					}
				}
				if (FieldCreep.size()) {
					for (auto iter = FieldCreep.begin(); iter != FieldCreep.end(); iter++) {
						auto _creep = *iter;
						if (
							hero->setNewAtkRect()->containsPoint(_creep->getPosition()) &&
							_creep->getHealthPoints() > 0) {
							//攻击动画
							hero->atkF();
							_creep->hurt(hero->getAtk());
							if (_creep->getHealthPoints() <= 0) {
								
								hero->setGold(hero->getGold() + _creep->getRewardMoney());
								hero->setExp(hero->getExp() + _creep->getRewardExp());
								FieldCreep.erase(iter);
							}
							return true;
						}
					}
				}
				//移动动画
				//hero->move(endPos, hero);

				return true;
			}
			else {
				if (
					hero->setNewAtkRect()->containsPoint(LeftHero->getPosition()) &&
					LeftHero->getHealthPoints() > 0) {
					//这里留给攻击动画
					hero->atkF();
					LeftHero->hurt(hero->getAtk());
					return true;
				}

				//	auto a = clickRect->containsPoint(Tower1->getPosition());
				//	auto b = hero->attack_rect->containsPoint(Tower1->getPosition());
				//	auto eee = hero->getPosition();
				//	auto d = Tower1->getPosition();
				//	auto c = Tower1->getHealthPoints();
				if (
					hero->setNewAtkRect()->containsPoint(Tower1->getPosition()) &&
					Tower1->getHealthPoints() > 0) {
					//攻击动画
					hero->atkF();
					Tower1->hurt(hero->getAtk());
					if (Tower1->getHealthPoints() <= 0) {
						//死亡动画
						hero->setGold(hero->getGold() + Tower1->getRewardMoney());
						hero->setExp(hero->getExp() + Tower1->getRewardExp());
					
					}
					return true;
				}

				if (
					hero->setNewAtkRect()->containsPoint(Base1->getPosition()) &&
					Base1->getHealthPoints() > 0) {
					//攻击动画
					hero->atkF();
					Base1->hurt(hero->getAtk());
					if (Base1->getHealthPoints() <= 0) {
						//死亡动画
						hero->setGold(hero->getGold() + Base1->getRewardMoney());
						hero->setExp(hero->getExp() + Base1->getRewardExp());
					
					}
					return true;
				}
				if (targetCreep.size()) {
					for (auto iter = targetCreep.begin(); iter != targetCreep.end(); iter++) {
						auto _creep = *iter;
						if (
							hero->setNewAtkRect()->containsPoint(_creep->getPosition()) &&
							_creep->getHealthPoints() > 0) {
							//攻击动画
							hero->atkF();
							_creep->hurt(hero->getAtk());
							if (_creep->getHealthPoints() <= 0) {
								hero->setGold(hero->getGold() + _creep->getRewardMoney());
								hero->setExp(hero->getExp() + _creep->getRewardExp());
								targetCreep.erase(iter);
							}
							return true;
						}
					}
				}
				if (FieldCreep.size()) {
					for (auto iter = FieldCreep.begin(); iter != FieldCreep.end(); iter++) {
						auto _creep = *iter;
						if (
							hero->setNewAtkRect()->containsPoint(_creep->getPosition()) &&
							_creep->getHealthPoints() > 0) {
							//攻击动画
							hero->atkF();
							_creep->hurt(hero->getAtk());
							if (_creep->getHealthPoints() <= 0) {
							
								hero->setGold(hero->getGold() + _creep->getRewardMoney());
								hero->setExp(hero->getExp() + _creep->getRewardExp());
								hero->setAtk(hero->getAtk() + 50);
								FieldCreep.erase(iter);
							}
							return true;
						}
					}
				}
				//移动
				//hero->move(endPos, hero);

				return true;
			}
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
			this->ScoreBoardRelesed();
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
		auto MapSizeWidth = _tileMap->getMapSize().width * 32;
		auto MapSizeHeight = _tileMap->getMapSize().height * 32;
		Vec2 startPos = hero->getPosition();
		Vec2 endPos;
		if (hero->getPositionX() <= visiblesize.width / 2) {
			endPos.x = touch->getLocation().x;
		}
		else if (hero->getPositionX() <= MapSizeWidth - visiblesize.width / 2) {
			endPos.x = hero->getPositionX() - visiblesize.width / 2 + touch->getLocation().x;
		}
		else {
			endPos.x = MapSizeWidth - visiblesize.width + touch->getLocation().x;
		}

		if (hero->getPositionY() <= visiblesize.height / 2) {
			endPos.y = touch->getLocation().y;
		}
		else if (hero->getPositionY() <= MapSizeHeight - visiblesize.height / 2) {
			endPos.y = hero->getPositionY() - visiblesize.height / 2 + touch->getLocation().y;
		}
		else {
			endPos.y = MapSizeHeight - visiblesize.height + touch->getLocation().y;
		}

		if (endPos.y >= 736 && endPos.x >= 960 && endPos.x <= 3840) {
			return false;
		}

		
		
		int Angle = CC_RADIANS_TO_DEGREES((endPos - startPos).getAngle());
		if (Angle > -45 && Angle < 45) {
			//hero->stopAllActions();
			hero->setFlipX(false);
		}
		else if ((Angle > -180 && Angle < -135) || (Angle > 135 && Angle < 180))
		{
			//hero->stopAllActions();
			hero->setFlipX(true);
		}

		if (hero->getHealthPoints() > 0) {

			auto distance = hero->getAtkDistance();
			hero->attack_rect = new Rect(hero->getPositionX() - distance, hero->getPositionY() - distance, distance, distance);
			Rect* clickRect = new Rect(endPos.x - 25, endPos.y - 25, 50, 50);

			if (hero == LeftHero) {//这个if的判断主要是留给以后联机战斗的时候能够读入hero是myhero（左边的英雄）还是otherhero（右边的英雄）
				//达到操作不同英雄的目的


				if (RightHero->newRect()->containsPoint(Vec2(endPos.x, endPos.y)) &&
					hero->attack_rect->containsPoint(RightHero->getPosition()) &&
					RightHero->getHealthPoints() > 0) {
					//这里留给攻击动画
					hero->atkF();
					RightHero->hurt(hero->getAtk());
					return true;
				}

				//	auto a = clickRect->containsPoint(Tower1->getPosition());
				//	auto b = hero->attack_rect->containsPoint(Tower1->getPosition());
				//	auto eee = hero->getPosition();
				//	auto d = Tower1->getPosition();
				//	auto c = Tower1->getHealthPoints();
				if (Tower2->newRect()->containsPoint(Vec2(endPos.x, endPos.y)) &&
					hero->attack_rect->containsPoint(Tower2->getPosition()) &&
					Tower2->getHealthPoints() > 0) {
					//攻击动画
					hero->atkF();
					Tower2->hurt(hero->getAtk());
					if (Tower2->getHealthPoints() <= 0) {
						hero->setGold(hero->getGold() + Tower2->getRewardMoney());
						hero->setExp(hero->getExp() + Tower2->getRewardExp());
					}
					return true;
				}
				if (Base2->newRect()->containsPoint(Vec2(endPos.x, endPos.y)) &&
					hero->attack_rect->containsPoint(Base2->getPosition()) &&
					Base2->getHealthPoints() > 0) {
					//攻击动画
					hero->atkF();
					Base2->hurt(hero->getAtk());
					if (Base2->getHealthPoints() <= 0) {
						//死亡动画
						hero->setGold(hero->getGold() + Base2->getRewardMoney());
						hero->setExp(hero->getExp() + Base2->getRewardExp());
					}
					return true;
				}
				if (OtherCreep.size()) {
					for (auto iter = OtherCreep.begin(); iter != OtherCreep.end(); iter++) {
						auto _creep = *iter;
						if (_creep->newRect()->containsPoint(Vec2(endPos.x, endPos.y)) &&
							hero->attack_rect->containsPoint(_creep->getPosition()) &&
							_creep->getHealthPoints() > 0) {
							//攻击动画
							hero->atkF();
							_creep->hurt(hero->getAtk());
							if (_creep->getHealthPoints() <= 0) {
								//死亡动画
								hero->setGold(hero->getGold() + _creep->getRewardMoney());
								hero->setExp(hero->getExp() + _creep->getRewardExp());
								OtherCreep.erase(iter);
							}
							return true;
						}
					}
				}
				if (FieldCreep.size()) {
					for (auto iter = FieldCreep.begin(); iter != FieldCreep.end(); iter++) {
						auto _creep = *iter;
						if (_creep->newRect()->containsPoint(Vec2(endPos.x, endPos.y)) &&
							hero->attack_rect->containsPoint(_creep->getPosition()) &&
							_creep->getHealthPoints() > 0) {
							//攻击动画
							hero->atkF();
							_creep->hurt(hero->getAtk());
							if (_creep->getHealthPoints() <= 0) {
								//死亡动画
								hero->setGold(hero->getGold() + _creep->getRewardMoney());
								hero->setExp(hero->getExp() + _creep->getRewardExp());
								hero->setAtk(hero->getAtk() + 50);
								FieldCreep.erase(iter);
							}
							return true;
						}
					}
				}
				//移动动画
				if (Angle > -45 && Angle < 45) {
					//hero->stopAllActions();
					hero->setFlipX(false);
					hero->move(endPos, hero, "right");//R					
				}
				else if (Angle > -135 && Angle < -45)
				{
					//hero->stopAllActions();					
					hero->move(endPos, hero, "down");//D				
				}
				else if ((Angle > -180 && Angle < -135) || (Angle > 135 && Angle < 180))
				{
					//hero->stopAllActions();
					hero->setFlipX(true);
					hero->move(endPos, hero, "left");//L					
				}
				else
				{
					//hero->stopAllActions();					
					hero->move(endPos, hero, "up");//U		
				}
			}

		
			else {
				if (LeftHero->newRect()->containsPoint(Vec2(endPos.x, endPos.y)) &&
					hero->attack_rect->containsPoint(LeftHero->getPosition()) &&
					LeftHero->getHealthPoints() > 0) {
					//这里留给攻击动画
					hero->atkF();
					LeftHero->hurt(hero->getAtk());
					return true;
				}

				//	auto a = clickRect->containsPoint(Tower1->getPosition());
				//	auto b = hero->attack_rect->containsPoint(Tower1->getPosition());
				//	auto eee = hero->getPosition();
				//	auto d = Tower1->getPosition();
				//	auto c = Tower1->getHealthPoints();
				if (Tower1->newRect()->containsPoint(Vec2(endPos.x, endPos.y)) &&
					hero->attack_rect->containsPoint(Tower1->getPosition()) &&
					Tower1->getHealthPoints() > 0) {
					//攻击动画
					hero->atkF();
					Tower1->hurt(hero->getAtk());
					if (Tower1->getHealthPoints() <= 0) {
						//死亡动画
						hero->setGold(hero->getGold() + Tower1->getRewardMoney());
						hero->setExp(hero->getExp() + Tower1->getRewardExp());
					}
					return true;
				}

				if (Base1->newRect()->containsPoint(Vec2(endPos.x, endPos.y)) &&
					hero->attack_rect->containsPoint(Base1->getPosition()) &&
					Base1->getHealthPoints() > 0) {
					//攻击动画
					hero->atkF();
					Base1->hurt(hero->getAtk());
					if (Base1->getHealthPoints() <= 0) {
						//死亡动画
						hero->setGold(hero->getGold() + Base1->getRewardMoney());
						hero->setExp(hero->getExp() + Base1->getRewardExp());
					}
					return true;
				}
				if (targetCreep.size()) {
					for (auto iter = targetCreep.begin(); iter != targetCreep.end(); iter++) {
						auto _creep = *iter;
						if (_creep->newRect()->containsPoint(Vec2(endPos.x, endPos.y)) &&
							hero->attack_rect->containsPoint(_creep->getPosition()) &&
							_creep->getHealthPoints() > 0) {
							//攻击动画
							hero->atkF();
							_creep->hurt(hero->getAtk());
							if (_creep->getHealthPoints() <= 0) {
								//死亡动画
								hero->setGold(hero->getGold() + _creep->getRewardMoney());
								hero->setExp(hero->getExp() + _creep->getRewardExp());
								hero->setAtk(hero->getAtk() + 50);
								targetCreep.erase(iter);
							}
							return true;
						}
					}
				}
				if (FieldCreep.size()) {
					for (auto iter = FieldCreep.begin(); iter != FieldCreep.end(); iter++) {
						auto _creep = *iter;
						if (_creep->newRect()->containsPoint(Vec2(endPos.x, endPos.y)) &&
							hero->attack_rect->containsPoint(_creep->getPosition()) &&
							_creep->getHealthPoints() > 0) {
							//攻击动画
							hero->atkF();
							_creep->hurt(hero->getAtk());
							if (_creep->getHealthPoints() <= 0) {
								//死亡动画
								hero->setGold(hero->getGold() + _creep->getRewardMoney());
								hero->setExp(hero->getExp() + _creep->getRewardExp());
								FieldCreep.erase(iter);
							}
							return true;
						}
					}
				}

			}
			//移动
			if (Angle > -45 && Angle < 45) {
				//hero->stopAllActions();
				hero->setFlipX(false);
				hero->move(endPos, hero, "right");//R					
			}
			else if (Angle > -135 && Angle < -45)
			{
				//hero->stopAllActions();					
				hero->move(endPos, hero, "down");//D				
			}
			else if ((Angle > -180 && Angle < -135) || (Angle > 135 && Angle < 180))
			{
				//hero->stopAllActions();
				hero->setFlipX(true);
				hero->move(endPos, hero, "left");//L					
			}
			else
			{
				//hero->stopAllActions();					
				hero->move(endPos, hero, "up");//U		
			}
			return true;

		}
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







