/*
************************************************************************
*
*	TollgateScene.h
*	¶ÅÐÇ·É	2015Äê6ÔÂ30ÈÕ
*
************************************************************************
*/

#ifndef __TollgateScene_H__
#define __TollgateScene_H__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "Player.h"

USING_NS_CC;
using namespace cocos2d::extension;

class TollgateScene :public CCLayer
{
public:
	static CCScene* scene();
	virtual bool init();

	CREATE_FUNC(TollgateScene);

	virtual void update(float delta);

	virtual void keyReleased(EventKeyboard::KeyCode keyCode, Event* event);

private:

	void initBG();

	void initHPSlider();

	void initAnanas();

	void initPig();
protected:

private:
	CCSprite* m_bgSprite1;
	CCSprite* m_bgSprite2;
	CCLabelTTF* m_scoreLab;
	ControlSlider* m_controlSlider;
	ControlSlider* m_controlSliderAnanas;
	ControlSlider* m_controlSliderPig;

	Player* m_player;

	float m_score;
	int m_speed;
};
#endif