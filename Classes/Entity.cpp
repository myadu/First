/*
************************************************************************
*
*	Entity.cpp
*	杜星飞	2015年6月30日
*
************************************************************************
*/
#include "Entity.h"

USING_NS_CC;

Entity::Entity() : m_layer(NULL), m_sprite(NULL)
{

}
Entity::~Entity()
{

}

//获取边框大小
CCRect Entity::getBoundingBox()
{
	if (!m_sprite)
		return CCRect(0, 0, 0, 0);
	return m_sprite->boundingBox();
}

//获取精灵
CCSprite* Entity::getSprite()
{
	return  this->m_sprite;
}

//绑定精灵
void Entity::bindSprite(CCSprite* sprite, int nLevel)
{
	this->m_sprite = sprite;
	if (m_layer)
		m_layer->addChild(m_sprite, nLevel);
}

//水平方向移动
void Entity::MoveX(int x)
{
	if (!m_sprite)
		return;
	m_sprite->setPositionX(m_sprite->getPositionX() + x);
}

//垂直方向移动
void Entity::MoveY(int y)
{
	if (!m_sprite)
		return;
	m_sprite->setPositionY(m_sprite->getPositionY() + y);
}

//水平/垂直方向移动
void Entity::MoveTo(int x, int y)
{
	if (!m_sprite)
		return;
	m_sprite->setPosition(ccp(x, y));
}


/*
void Entity::draw()
{
	CCNode::draw();
}*/