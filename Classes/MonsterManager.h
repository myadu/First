/*
************************************************************************
*
*	MonsterManager.h
*	���Ƿ�	2015��6��30��
*
************************************************************************
*/

#ifndef __MonsterManager_H__
#define __MonsterManager_H__

#include "cocos2d.h"
#include "Player.h"

USING_NS_CC;

class MonsterManager :public CCNode
{
public:
	MonsterManager();
	~MonsterManager();

	//�����ͳ�ʼ��
	static MonsterManager* createWithLayer(CCLayer* layer);
	bool initWithLayer(CCLayer* layer);

	//�����
	void bindPlayer(Player* player);

	//��дupdate����
	virtual void update(float delta);

private:
	//��������
	void createMonster();

	//��������
	void createAnanas();

	//����С��
	void createPig();

protected:
private:
	CCLayer* m_layer;
	Player* m_player;
	CCArray* m_arrayMonster;
	CCArray* m_arrayAnanas;
	CCArray* m_arrayPig;
};

#endif