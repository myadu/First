/*
************************************************************************
*
*	Ananas.h
*	���Ƿ�	2015��6��30��
*
************************************************************************
*/

#ifndef __Ananas_H__
#define __Ananas_H__

#include "cocos2d.h"
#include "Entity.h"
#include "Player.h"

USING_NS_CC;

const int INIT_X_Ananas = CCDirector::sharedDirector()->getVisibleSize().width;
const int INIT_Y_Ananas = CCDirector::sharedDirector()->getVisibleSize().height / 2;

class Ananas :public Entity
{
public:
	Ananas();
	~Ananas();

	//��������ʼ�� ������
	static Ananas* createWithLayer(CCLayer* layer);

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