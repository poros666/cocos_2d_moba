#pragma once
#include "cocos2d.h"
class OneMapScene : public cocos2d::Scene
{
	public:
		static cocos2d::Scene* CreateScene();
		virtual bool init();
		void menuBackCallback(cocos2d::Ref* pSender);
		CREATE_FUNC(OneMapScene);
};