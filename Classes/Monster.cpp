/*
************************************************************************
*
*	Monster.cpp
*	杜星飞	2015年6月30日
*
************************************************************************
*/

#include "cocos2d.h"
#include "Monster.h"
//#include "ccMacros.h"

USING_NS_CC;

Monster::Monster() : m_isAlive(false)
{

}
Monster::~Monster()
{
	CC_SAFE_RELEASE(m_layer);
}

//创建、初始化 怪物类
Monster* Monster::createWithLayer(CCLayer* layer)
{
	Monster* m_monster = new Monster();

	if (m_monster && m_monster->initWithLayer(layer))
		m_monster->autorelease();
	else
		CC_SAFE_DELETE(m_monster);

	return m_monster;
}

bool Monster::initWithLayer(CCLayer* layer)
{
	bool bRect = false;

	do
	{
		this->m_layer = layer;
		m_layer->retain();

		bRect = true;
	} while (0);

	return bRect;
}

//显示
void Monster::show()
{
	if (!getSprite())
		return;

	CCLOG("Monster show!");

	m_isAlive = true;
	getSprite()->setVisible(true);
}

//隐藏
void Monster::hide()
{
	if (!getSprite())
		return;

	m_isAlive = false;
	getSprite()->setVisible(false);
	getSprite()->setPosition(Vec2(INIT_X + CCRANDOM_0_1() * 20000, INIT_Y + random(1, 250)));
}

//重置参数
void Monster::reset()
{
	if (!getSprite())
		return;
	getSprite()->setPosition(Vec2(INIT_X + CCRANDOM_0_1() * 20000, INIT_Y + random(1, 250)));
}

//是否为显示状态
bool Monster::isAlive()
{
	return m_isAlive;
}

//碰撞检测
bool Monster::isCollideWithPlayer(Player* player)
{
	CCRect rectPlayer = player->getBoundingBox();
	CCRect rectMonster = this->getBoundingBox();

	return rectMonster.intersectsRect(rectPlayer);
}