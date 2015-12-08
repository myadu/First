/*
************************************************************************
*
*	Ananas.cpp
*	���Ƿ�	2015��6��30��
*
************************************************************************
*/

#include "cocos2d.h"
#include "Ananas.h"
//#include "ccMacros.h"

USING_NS_CC;

Ananas::Ananas() : m_isAlive(false)
{

}
Ananas::~Ananas()
{
	CC_SAFE_RELEASE(m_layer);
}

//��������ʼ�� ������
Ananas* Ananas::createWithLayer(CCLayer* layer)
{
	Ananas* m_ananas = new Ananas();

	if (m_ananas && m_ananas->initWithLayer(layer))
		m_ananas->autorelease();
	else
		CC_SAFE_DELETE(m_ananas);

	return m_ananas;
}

bool Ananas::initWithLayer(CCLayer* layer)
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
void Ananas::show()
{
	if (!getSprite())
		return;

	CCLOG("Ananas show!");

	m_isAlive = true;
	getSprite()->setVisible(true);
}

//����
void Ananas::hide()
{
	if (!getSprite())
		return;

	m_isAlive = false;
	getSprite()->setVisible(false);
	getSprite()->setPosition(ccp(INIT_X_Ananas + CCRANDOM_0_1() * 10000, INIT_Y_Ananas + random(1, 300)));
}

//���ò���
void Ananas::reset()
{
	if (!getSprite())
		return;
	getSprite()->setPosition(ccp(INIT_X_Ananas + CCRANDOM_0_1() * 10000, INIT_Y_Ananas + random(1, 300)));
}

//�Ƿ�Ϊ��ʾ״̬
bool Ananas::isAlive()
{
	return m_isAlive;
}

//��ײ���
bool Ananas::isCollideWithPlayer(Player* player)
{
	CCRect rectPlayer = player->getBoundingBox();
	CCRect rectAnanas = this->getBoundingBox();

	return rectAnanas.intersectsRect(rectPlayer);
}