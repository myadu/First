/*
************************************************************************
*
*	Pig.h
*	���Ƿ�	2015��6��30��
*
************************************************************************
*/

#ifndef __Pig_H__
#define __Pig_H__

#include "cocos2d.h"
#include "Entity.h"
#include "Player.h"

USING_NS_CC;

class Pig :public Entity
{
public:
	Pig();
	~Pig();

	//��������ʼ�� С����
	static Pig* createWithLayer(CCLayer* layer);

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