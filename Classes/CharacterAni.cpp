#include"CharacterAni.h"
using namespace cocos2d;




Animation* CharaAni::createAnimation(const char* prefixName, int start, int end, float delay)
{
	Vector<SpriteFrame*> animFrames;

	for (int i = start; i <= end; i++){

		auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(String::createWithFormat(prefixName, i)->getCString());
		if (frame != nullptr)
			animFrames.pushBack(frame);
	}
	return Animation::createWithSpriteFrames(animFrames, delay);
}

/*
Animation* CharaAni::createAnimation(const char* prefixName, int start, int end, float delay, std::string lastFrame){
	Vector<SpriteFrame*> animFrames;

	for (int i = start; i <= end; i++)
	{
		auto frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(String::createWithFormat(prefixName, i)->getCString());
		if (frame != nullptr)
			animFrames.pushBack(frame);
	}
	animFrames.pushBack(SpriteFrameCache::getInstance()->getSpriteFrameByName(lastFrame));
	return Animation::createWithSpriteFrames(animFrames, delay);
}
*/
void CharaAni::initAni(){
	CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	cache->addSpriteFramesWithFile("enemies_desert_3-hd.plist", "enemies_desert_3-hd.png");
	cache->addSpriteFramesWithFile("map_spritesheet_16_a_3-hd.plist", "map_spritesheet_16_a_3-hd.png");
	cache->addSpriteFramesWithFile("map_spritesheet_16_a-hd.plist", "map_spritesheet_16_a-hd.png");
	cache->addSpriteFramesWithFile("towers-hd.plist", "towers-hd.png");
}

void CharaAni::init_executioner() {//HeroExecu
	AnimationCache::getInstance()->addAnimation(createAnimation("desertExecutioner_0%003d.png", 73, 98, 0.04f), "Executioner_attack");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertExecutioner_0%003d.png", 99, 118, 0.04f), "Executioner_death");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertExecutioner_0%003d.png", 49, 72, 0.05f), "Executioner_runup");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertExecutioner_0%003d.png", 25, 48, 0.05f), "Executioner_rundown");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertExecutioner_0%003d.png", 1, 24, 0.05f), "Executioner_runleft");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertExecutioner_0%003d.png", 1, 24, 0.05f), "Executioner_runright");
}

void CharaAni::init_elite(){//HeroElite
	AnimationCache::getInstance()->addAnimation(createAnimation("SaurianElite_0%03d.png", 1, 21, 0.04f), "Elite_runleft");
	AnimationCache::getInstance()->addAnimation(createAnimation("SaurianElite_0%03d.png", 1, 21, 0.04f), "Elite_runright");
	AnimationCache::getInstance()->addAnimation(createAnimation("SaurianElite_0%03d.png", 23, 43, 0.04f), "Elite_runup");
	AnimationCache::getInstance()->addAnimation(createAnimation("SaurianElite_0%03d.png", 45, 65, 0.04f), "Elite_rundown");
	AnimationCache::getInstance()->addAnimation(createAnimation("SaurianElite_0%03d.png", 67, 123, 0.04f), "Elite_attack");
	AnimationCache::getInstance()->addAnimation(createAnimation("SaurianElite_0%03d.png", 126, 143, 0.04f), "Elite_death");
}

void CharaAni::init_munra(){//HeroMunra
	AnimationCache::getInstance()->addAnimation(createAnimation("desertMunra_0%03d.png", 122, 163, 0.04f), "Munra_skill");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertMunra_0%03d.png", 73, 120, 0.04f), "Munra_attack");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertMunra_0%03d.png", 165, 200, 0.04f), "Munra_death");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertMunra_0%03d.png", 25, 47, 0.04f), "Munra_runup");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertMunra_0%03d.png", 49, 71, 0.04f), "Munra_rundown");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertMunra_0%03d.png", 1, 23, 0.04f), "Munra_runleft");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertMunra_0%03d.png", 1, 23, 0.04f), "Munra_runright");
}

void CharaAni::init_myrmidon(){//melee
	AnimationCache::getInstance()->addAnimation(createAnimation("SaurianMyrmidon_0%03d.png", 1, 21, 0.04f), "Myrmidon_runleft");
	AnimationCache::getInstance()->addAnimation(createAnimation("SaurianMyrmidon_0%03d.png", 1, 21, 0.04f), "Myrmidon_runright");
	AnimationCache::getInstance()->addAnimation(createAnimation("SaurianMyrmidon_0%03d.png", 23, 43, 0.04f), "Myrmidon_runup");
	AnimationCache::getInstance()->addAnimation(createAnimation("SaurianMyrmidon_0%03d.png", 45, 65, 0.04f), "Myrmidon_rundown");
	AnimationCache::getInstance()->addAnimation(createAnimation("SaurianMyrmidon_0%03d.png", 67, 85, 0.04f), "Myrmidon_attack");
	AnimationCache::getInstance()->addAnimation(createAnimation("SaurianMyrmidon_0%03d.png", 87, 104, 0.04f), "Myrmidon_death");
}

void CharaAni::init_blazefang(){//range
	AnimationCache::getInstance()->addAnimation(createAnimation("SaurianBlazefang_0%03d.png", 1, 21, 0.04f), "Blazefang_runleft");
	AnimationCache::getInstance()->addAnimation(createAnimation("SaurianBlazefang_0%03d.png", 1, 21, 0.04f), "Blazefang_runright");
	AnimationCache::getInstance()->addAnimation(createAnimation("SaurianBlazefang_0%03d.png", 23, 43, 0.04f), "Blazefang_runup");
	AnimationCache::getInstance()->addAnimation(createAnimation("SaurianBlazefang_0%03d.png", 45, 65, 0.04f), "Blazefang_rundown");
	AnimationCache::getInstance()->addAnimation(createAnimation("SaurianBlazefang_0%03d.png", 67, 95, 0.04f), "Blazefang_attack");
	AnimationCache::getInstance()->addAnimation(createAnimation("SaurianBlazefang_0%03d.png", 187, 203, 0.04f), "Blazefang_death");
}

void CharaAni::init_quetza(){//cannon
	AnimationCache::getInstance()->addAnimation(createAnimation("SaurianQuetzal_0%03d.png", 1, 13, 0.04f), "Quetzal_runleft");
	AnimationCache::getInstance()->addAnimation(createAnimation("SaurianQuetzal_0%03d.png", 1, 21, 0.04f), "Quetzal_runright");
	AnimationCache::getInstance()->addAnimation(createAnimation("SaurianQuetzal_0%03d.png", 15, 27, 0.04f), "Quetzal_runup");
	AnimationCache::getInstance()->addAnimation(createAnimation("SaurianQuetzal_0%03d.png", 28, 41, 0.04f), "Quetzal_rundown");
	AnimationCache::getInstance()->addAnimation(createAnimation("SaurianQuetzal_0%03d.png", 43, 65, 0.04f), "Quetzal_attack");
	AnimationCache::getInstance()->addAnimation(createAnimation("SaurianQuetzal_0%03d.png", 65, 83, 0.04f), "Quetzal_death");
}

void CharaAni::init_mechsTower(){//tower
	//AnimationCache::getInstance()->addAnimation(createAnimation("tower_mechs_layer2_00%02d.png", 1, 45, 0.04f), "MechsTower_layer2");
	//AnimationCache::getInstance()->addAnimation(createAnimation("tower_mechs_layer3_00%02d.png", 1, 8, 0.04f), "MechsTower_layer3");
	//AnimationCache::getInstance()->addAnimation(createAnimation("tower_mechs_layer4_00%02d.png", 1, 8, 0.04f), "MechsTower_layer4");
	//AnimationCache::getInstance()->addAnimation(createAnimation("tower_mechs_layer4_00%02d.png", 1, 27, 0.04f), "MechsTower_layer6");
	//AnimationCache::getInstance()->addAnimation(createAnimation("tower_mechs_layer7_00%02d.png", 1, 27, 0.04f), "MechsTower_layer7");
//	AnimationCache::getInstance()->addAnimation(createAnimation("tower_mechs_layer8_00%02d.png", 1, 42, 0.04f), "MechsTower_layer8");
	//AnimationCache::getInstance()->addAnimation(createAnimation("tower_mechs_layer9_00%02d.png", 1, 23, 0.04f, "tower_mechs_layer9_0001.png"), "MechsTower_layer9");

	//AnimationCache::getInstance()->addAnimation(createAnimationR("tower_mechs_layer3_00%02d.png", 8, 1, 0.04f), "MechsTower_layer3_r");
	//AnimationCache::getInstance()->addAnimation(createAnimationR("tower_mechs_layer4_00%02d.png", 8, 1, 0.04f), "MechsTower_layer4_r");

	AnimationCache::getInstance()->addAnimation(createAnimation("Mecha_00%02d.png", 1, 21, 0.03f), "Mecha_walk");
	AnimationCache::getInstance()->addAnimation(createAnimation("Mecha_00%02d.png", 24, 68, 0.03f), "Mecha_attack");
	AnimationCache::getInstance()->addAnimation(createAnimation("Mecha_0%03d.png", 75, 105, 0.03f), "Mecha_shoot");
	AnimationCache::getInstance()->addAnimation(createAnimation("Mecha_0%03d.png", 106, 143, 0.03f), "Mecha_shit");
	//AnimationCache::getInstance()->addAnimation(createAnimation("Mecha_Shitting_0%03d.png", 122, 143, 0.03f, "Mecha_Shitting_0001.png"), "Mecha_shitting");
	AnimationCache::getInstance()->addAnimation(createAnimation("mech_missile_0%03d.png", 106, 143, 0.03f), "Mecha_missile");
	AnimationCache::getInstance()->addAnimation(createAnimation("explosion_air_00%02d.png", 1, 17, 0.04f), "bomb");
	AnimationCache::getInstance()->addAnimation(createAnimation("fireball_explosion_00%02d.png", 1, 15, 0.06f), "fireBall_explosion");
	
}

void CharaAni::init_scorpion(){//jungle creep1
	AnimationCache::getInstance()->addAnimation(createAnimation("scorpion_0%003d.png", 27, 69, 0.04f), "Scorpion_attack");
	AnimationCache::getInstance()->addAnimation(createAnimation("scorpion_0%003d.png", 70, 99, 0.04f), "Scorpion_death");
	AnimationCache::getInstance()->addAnimation(createAnimation("scorpion_0%003d.png", 10, 18, 0.04f), "Scorpion_runup");
	AnimationCache::getInstance()->addAnimation(createAnimation("scorpion_0%003d.png", 19, 27, 0.04f), "Scorpion_rundown");
	AnimationCache::getInstance()->addAnimation(createAnimation("scorpion_0%003d.png", 1, 9, 0.04f), "Scorpion_runleft");
	AnimationCache::getInstance()->addAnimation(createAnimation("scorpion_0%003d.png", 1, 9, 0.04f), "Scorpion_runright");
}

void CharaAni::init_immortal(){//jugle creep2
	AnimationCache::getInstance()->addAnimation(createAnimation("desertImmortal_0%03d.png", 67, 88, 0.04f), "Immortal_attack");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertImmortal_0%03d.png", 89, 124, 0.04f), "Immortal_death");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertImmortal_0%03d.png", 23, 44, 0.04f), "Immortal_runup");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertImmortal_0%03d.png", 45, 66, 0.04f), "Immortal_rundown");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertImmortal_0%03d.png", 1, 22, 0.04f), "Immortal_runleft");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertImmortal_0%03d.png", 1, 22, 0.04f), "Immortal_runright");
}

void CharaAni::init_raider(){//jungle creep3
	AnimationCache::getInstance()->addAnimation(createAnimation("desertRaider_0%03d.png", 89, 106, 0.04f), "Raider_death");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertRaider_0%03d.png", 23, 44, 0.04f), "Raider_runup");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertRaider_0%03d.png", 45, 66, 0.04f), "Raider_rundown");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertRaider_0%03d.png", 1, 22, 0.04f), "Raider_runleft");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertRaider_0%03d.png", 1, 22, 0.04f), "Raider_runright");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertRaider_0%03d.png", 67, 88, 0.04f), "Raider_attack");
}

void CharaAni::init_thug(){//jungle creep4
	AnimationCache::getInstance()->addAnimation(createAnimation("desertThug_0%03d.png", 89, 106, 0.04f), "Thug_death");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertThug_0%03d.png", 23, 44, 0.04f), "Thug_runup");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertThug_0%03d.png", 45, 66, 0.04f), "Thug_rundown");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertThug_0%03d.png", 1, 22, 0.04f), "Thug_runleft");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertThug_0%03d.png", 1, 22, 0.04f), "Thug_runright");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertThug_0%03d.png", 67, 88, 0.04f), "Thug_attack");
}

void CharaAni::init_fallen(){//jungle creep5
	AnimationCache::getInstance()->addAnimation(createAnimation("fallen_0%03d.png", 48, 69, 0.04f), "Fallen_attack");
	AnimationCache::getInstance()->addAnimation(createAnimation("fallen_0%03d.png", 70, 110, 0.04f), "Fallen_death");
	AnimationCache::getInstance()->addAnimation(createAnimation("fallen_0%03d.png", 17, 32, 0.04f), "Fallen_runup");
	AnimationCache::getInstance()->addAnimation(createAnimation("fallen_0%03d.png", 32, 47, 0.04f), "Fallen_rundown");
	AnimationCache::getInstance()->addAnimation(createAnimation("fallen_0%03d.png", 1, 16, 0.04f), "Fallen_runleft");
	AnimationCache::getInstance()->addAnimation(createAnimation("fallen_0%03d.png", 1, 16, 0.04f), "Fallen_runright");
	AnimationCache::getInstance()->addAnimation(createAnimation("fallen_0%03d.png", 114, 146, 0.04f), "Fallen_birth");
}
void CharaAni::init_skill() {
	AnimationCache::getInstance()->addAnimation(createAnimation("ArchMageTwister_00%02d.png", 1, 9, 0.04f), "Strom_create");
	AnimationCache::getInstance()->addAnimation(createAnimation("ArchMageTwister_00%02d.png", 9, 15, 0.04f), "Strom_twist");
	AnimationCache::getInstance()->addAnimation(createAnimation("ArchMageTwister_00%02d.png", 16, 24, 0.04f), "Strom_end");
	AnimationCache::getInstance()->addAnimation(createAnimation("effect_sellSmoke_00%02d.png", 1, 11, 0.04f), "blink_smoke");//shanxianyong yanwu
}