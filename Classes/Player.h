/*
************************************************************************
*
*	Player.h
*	���Ƿ�	2015��6��30��
*
************************************************************************
*/
#ifndef __Player_H__
#define __Player_H__

#include "cocos2d.h"
#include "Entity.h"

USING_NS_CC;

class Player :public Entity
{
public:
	Player();
	~Player();

	//�ڲ��д���
	static Player* createWithLayer(CCLayer* layer);

	//�ڲ��г�ʼ��
	bool initWithLayer(CCLayer* layer);

	//�󶨾���
	virtual void bindSprite(CCSprite* sprite, int nLevel);

	//��Ծ
	void jump();

	//��Ծ����
	void jumpEnd();

	//�ܵ�����
	void hit();

	//�ܹ�������
	void hitEnd();

	//��ȡʳ��
	void getAnanas();

	//��ȡʳ�����
	void ananasEnd();

	//��С��
	void eatPig();

	//��С�����
	void eatPigEnd();

	//��������
	void resetData();

	//��ȡѪ��
	int getiHP();

	//��ȡ������Ŀ
	int getiAnanas();

	//��ȡС����Ŀ
	int getiPig();

protected:

private:
	bool m_isjumping;	//�Ƿ�����Ծ״̬
	bool m_isHit;//�Ƿ����ܹ���״̬
	bool m_isEating;	//�Ƿ��ڳ�С��״̬
	int m_iHP;	//Ѫ��
	int m_iAnanas;	//������Ŀ
	int m_iPig;	//С����Ŀ
	CCPoint m_initPos;	//��ʼλ��
};

#endif