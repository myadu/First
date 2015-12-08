/*
************************************************************************
*
*	Entity.h
*	杜星飞	2015年6月30日
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

	//获取边框大小
	CCRect getBoundingBox();

	//获取精灵
	CCSprite* getSprite();

	//绑定精灵
	virtual void bindSprite(CCSprite* sprite, int nLevel);

	//水平方向移动
	void MoveX(int x);

	//垂直方向移动
	void MoveY(int y);

	//水平/垂直方向移动
	void MoveTo(int x, int y);

//	virtual void draw();

protected:
	CCLayer* m_layer;
private:
	CCSprite* m_sprite;
};


#endif