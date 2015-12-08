/*
************************************************************************
*
*	Player.h
*	杜星飞	2015年6月30日
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

	//在层中创建
	static Player* createWithLayer(CCLayer* layer);

	//在层中初始化
	bool initWithLayer(CCLayer* layer);

	//绑定精灵
	virtual void bindSprite(CCSprite* sprite, int nLevel);

	//跳跃
	void jump();

	//跳跃结束
	void jumpEnd();

	//受到攻击
	void hit();

	//受攻击结束
	void hitEnd();

	//获取食物
	void getAnanas();

	//获取食物结束
	void ananasEnd();

	//吃小猪
	void eatPig();

	//吃小猪结束
	void eatPigEnd();

	//重置数据
	void resetData();

	//获取血量
	int getiHP();

	//获取菠萝数目
	int getiAnanas();

	//获取小猪数目
	int getiPig();

protected:

private:
	bool m_isjumping;	//是否在跳跃状态
	bool m_isHit;//是否在受攻击状态
	bool m_isEating;	//是否在吃小猪状态
	int m_iHP;	//血量
	int m_iAnanas;	//菠萝数目
	int m_iPig;	//小猪数目
	CCPoint m_initPos;	//初始位置
};

#endif