/*
************************************************************************
*
*	Ananas.h
*	杜星飞	2015年6月30日
*
************************************************************************
*/

#ifndef __Ananas_H__
#define __Ananas_H__

#include "cocos2d.h"
#include "Entity.h"
#include "Player.h"

USING_NS_CC;

const int INIT_X_Ananas = CCDirector::sharedDirector()->getVisibleSize().width;
const int INIT_Y_Ananas = CCDirector::sharedDirector()->getVisibleSize().height / 2;

class Ananas :public Entity
{
public:
	Ananas();
	~Ananas();

	//创建、初始化 菠萝类
	static Ananas* createWithLayer(CCLayer* layer);

	bool initWithLayer(CCLayer* layer);

	//显示
	void show();

	//隐藏
	void hide();

	//重置参数
	void reset();

	//是否为显示状态
	bool isAlive();

	//碰撞检测
	bool isCollideWithPlayer(Player* player);

protected:
private:
	bool m_isAlive;
};
#endif