/*
************************************************************************
*
*	ControlLayer.cpp
*	���Ƿ�	2015��6��30��
*
************************************************************************
*/
#include "ControlLayer.h"
//#include "GUI\CCControlExtension\CCControlButton.h"

USING_NS_CC;
USING_NS_CC_EXT;

ControlLayer* ControlLayer::createWithPlayer(Player* player)
{
	ControlLayer* m_controller = new ControlLayer();

	if (m_controller && m_controller->initWithPlayer(player))
		m_controller->autorelease();
	else
		CC_SAFE_DELETE(m_controller);

	return m_controller;
}

bool ControlLayer::initWithPlayer(Player* player)
{
	bool bRect = false;

	do
	{
		this->m_player = player;

		//�����ռ䰴ť
		Size visibleSize = Director::getInstance()->getVisibleSize();
		Vec2 origin = Director::getInstance()->getVisibleOrigin();

		//Jump
		auto closeItem = MenuItemImage::create(
			"button.png",
			"buttonHighlighted.png",
			CC_CALLBACK_1(ControlLayer::downEvent, this));

		closeItem->setPosition(Vec2(origin.x + closeItem->getContentSize().width / 2,
			origin.y + closeItem->getContentSize().height / 2));

		// create menu, it's an autorelease object
		auto menu = Menu::create(closeItem, NULL);
		menu->setPosition(Vec2::ZERO);
		this->addChild(menu, 1);

		bRect = true;
	} while (0);

	return bRect;
}

//�°� �¼�
void ControlLayer::downEvent(CCObject* pSender)
{
	m_player->jump();
}