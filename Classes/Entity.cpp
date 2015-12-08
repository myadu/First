/*
************************************************************************
*
*	Entity.cpp
*	���Ƿ�	2015��6��30��
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

//��ȡ�߿��С
CCRect Entity::getBoundingBox()
{
	if (!m_sprite)
		return CCRect(0, 0, 0, 0);
	return m_sprite->boundingBox();
}

//��ȡ����
CCSprite* Entity::getSprite()
{
	return  this->m_sprite;
}

//�󶨾���
void Entity::bindSprite(CCSprite* sprite, int nLevel)
{
	this->m_sprite = sprite;
	if (m_layer)
		m_layer->addChild(m_sprite, nLevel);
}

//ˮƽ�����ƶ�
void Entity::MoveX(int x)
{
	if (!m_sprite)
		return;
	m_sprite->setPositionX(m_sprite->getPositionX() + x);
}

//��ֱ�����ƶ�
void Entity::MoveY(int y)
{
	if (!m_sprite)
		return;
	m_sprite->setPositionY(m_sprite->getPositionY() + y);
}

//ˮƽ/��ֱ�����ƶ�
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