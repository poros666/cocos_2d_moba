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

void CharaAni::initAni(){
	CCSpriteFrameCache* cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	cache->addSpriteFramesWithFile("enemies_desert_3-hd.plist", "enemies_desert_3-hd.png");
	cache->addSpriteFramesWithFile("map_spritesheet_16_a_3-hd.plist", "map_spritesheet_16_a_3-hd.png");
	cache->addSpriteFramesWithFile("map_spritesheet_16_a-hd.plist", "map_spritesheet_16_a-hd.png");
	cache->addSpriteFramesWithFile("towers-hd.plist", "towers-hd.png");
}

void CharaAni::init_Executioner() {
	AnimationCache::getInstance()->addAnimation(createAnimation("desertExecutioner_0%003d.png", 73, 98, 0.04f), "Executioner_attack");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertExecutioner_0%003d.png", 99, 118, 0.04f), "Executioner_death");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertExecutioner_0%003d.png", 49, 72, 0.05f), "Executioner_runup");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertExecutioner_0%003d.png", 25, 48, 0.05f), "Executioner_rundown");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertExecutioner_0%003d.png", 1, 24, 0.05f), "Executioner_runleft");
	AnimationCache::getInstance()->addAnimation(createAnimation("desertExecutioner_0%003d.png", 1, 24, 0.05f), "Executioner_runright");
}
