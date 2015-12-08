/*
************************************************************************
*
*	Pig.h
*	杜星飞	2015年6月30日
*
************************************************************************
*/

#ifndef __Pig_H__
#define __Pig_H__

#include "cocos2d.h"
#include "Entity.h"
#include "Player.h"

USING_NS_CC;

class Pig :public Entity
{
public:
	Pig();
	~Pig();

	//创建、初始化 小猪类
	static Pig* createWithLayer(CCLayer* layer);

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