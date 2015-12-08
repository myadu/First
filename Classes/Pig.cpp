/*
************************************************************************
*
*	Pig.cpp
*	���Ƿ�	2015��6��30��
*
************************************************************************
*/

#include "cocos2d.h"
#include "Pig.h"
//#include "ccMacros.h"

USING_NS_CC;

Pig::Pig() : m_isAlive(false)
{

}
Pig::~Pig()
{
	CC_SAFE_RELEASE(m_layer);
}

//��������ʼ�� ������
Pig* Pig::createWithLayer(CCLayer* layer)
{
	Pig* m_pig = new Pig();

	if (m_pig && m_pig->initWithLayer(layer))
		m_pig->autorelease();
	else
		CC_SAFE_DELETE(m_pig);

	return m_pig;
}

bool Pig::initWithLayer(CCLayer* layer)
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

//��ʾ
void Pig::show()
{
	if (!getSprite())
		return;

	CCLOG("Pig show!");

	m_isAlive = true;
	getSprite()->setVisible(true);
}

//����
void Pig::hide()
{
	if (!getSprite())
		return;

	m_isAlive = false;
	getSprite()->setVisible(false);
	getSprite()->setPosition(ccp(CCRANDOM_0_1() * 20000, 150 + random(1,350)));
}

//���ò���
void Pig::reset()
{
	if (!getSprite())
		return;
	getSprite()->setPosition(ccp(CCRANDOM_0_1() * 20000, 150 + random(1, 350)));
}

//�Ƿ�Ϊ��ʾ״̬
bool Pig::isAlive()
{
	return m_isAlive;
}

//��ײ���
bool Pig::isCollideWithPlayer(Player* player)
{
	CCRect rectPlayer = player->getBoundingBox();
	CCRect rectPig = this->getBoundingBox();

	return rectPig.intersectsRect(rectPlayer);
}