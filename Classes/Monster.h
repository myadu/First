/*
************************************************************************
*
*	Monster.h
*	���Ƿ�	2015��6��30��
*
************************************************************************
*/

#ifndef __Monster_H__
#define __Monster_H__

#include "cocos2d.h"
#include "Entity.h"
#include "Player.h"

USING_NS_CC;

const int INIT_X = CCDirector::sharedDirector()->getVisibleSize().width;
const int INIT_Y = CCDirector::sharedDirector()->getVisibleSize().height / 3;

class Monster :public Entity
{
public:
	Monster();
	~Monster();

	//��������ʼ�� ������
	static Monster* createWithLayer(CCLayer* layer);

	bool initWithLayer(CCLayer* layer);

	//��ʾ
	void show();

	//����
	void hide();

	//���ò���
	void reset();

	//�Ƿ�Ϊ��ʾ״̬
	bool isAlive();

	//��ײ���
	bool isCollideWithPlayer(Player* player);

protected:
private:
	bool m_isAlive;
};
#endif