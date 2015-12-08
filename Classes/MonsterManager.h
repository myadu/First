/*
************************************************************************
*
*	MonsterManager.h
*	杜星飞	2015年6月30日
*
************************************************************************
*/

#ifndef __MonsterManager_H__
#define __MonsterManager_H__

#include "cocos2d.h"
#include "Player.h"

USING_NS_CC;

class MonsterManager :public CCNode
{
public:
	MonsterManager();
	~MonsterManager();

	//创建和初始化
	static MonsterManager* createWithLayer(CCLayer* layer);
	bool initWithLayer(CCLayer* layer);

	//绑定玩家
	void bindPlayer(Player* player);

	//重写update函数
	virtual void update(float delta);

private:
	//创建怪物
	void createMonster();

	//创建菠萝
	void createAnanas();

	//创建小猪
	void createPig();

protected:
private:
	CCLayer* m_layer;
	Player* m_player;
	CCArray* m_arrayMonster;
	CCArray* m_arrayAnanas;
	CCArray* m_arrayPig;
};

#endif