/*
************************************************************************
*
*	ControlLayer.h
*	���Ƿ�	2015��6��30��
*
************************************************************************
*/

#ifndef __ControlLayer_H__
#define __ControlLayer_H__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "Player.h"

USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocos2d::extension;

class ControlLayer :public CCLayer
{
public:
	static ControlLayer* createWithPlayer(Player* player);
	bool initWithPlayer(Player* player);
protected:
private:
	//�°� �¼�
	void downEvent(CCObject* pSender);

	Player* m_player;
};


#endif