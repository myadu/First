/*
************************************************************************
*
*	Entity.h
*	���Ƿ�	2015��6��30��
*
************************************************************************
*/

#ifndef __Entity_H__
#define __Entity_H__

#include "cocos2d.h"

USING_NS_CC;

class Entity :public CCNode
{
public:
	Entity();
	~Entity();

	//��ȡ�߿��С
	CCRect getBoundingBox();

	//��ȡ����
	CCSprite* getSprite();

	//�󶨾���
	virtual void bindSprite(CCSprite* sprite, int nLevel);

	//ˮƽ�����ƶ�
	void MoveX(int x);

	//��ֱ�����ƶ�
	void MoveY(int y);

	//ˮƽ/��ֱ�����ƶ�
	void MoveTo(int x, int y);

//	virtual void draw();

protected:
	CCLayer* m_layer;
private:
	CCSprite* m_sprite;
};


#endif