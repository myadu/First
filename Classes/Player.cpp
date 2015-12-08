/*
************************************************************************
*
*	Player.cpp
*	杜星飞	2015年6月30日
*
************************************************************************
*/
#include "SimpleAudioEngine.h"
#include "Player.h"
#include "FlowWord.h"

USING_NS_CC;

Player::Player() : m_isjumping(false), m_isHit(false), m_isEating(false), m_iHP(300), m_iAnanas(0), m_iPig(0), m_initPos(ccp(0, 0))
{
	//预加载声音
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("hit.wav");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("jump.wav");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("eat.mp3");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("eat_1s.mp3");

}
Player::~Player()
{
	CC_SAFE_RELEASE(m_layer);

	//卸载声音
	CocosDenshion::SimpleAudioEngine::sharedEngine()->unloadEffect("hit.wav");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->unloadEffect("jump.wav");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->unloadEffect("eat.mp3");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->unloadEffect("eat_1s.mp3");

}

//在层中创建
Player* Player::createWithLayer(CCLayer* layer)
{
	Player* m_player = new Player();
	if (m_player && m_player->initWithLayer(layer))
		m_player->autorelease();
	else
		CC_SAFE_DELETE(m_player);

	return m_player;
}

//在层中初始化
bool Player::initWithLayer(CCLayer* layer)
{
	bool bRect = false;

	do
	{
		this->m_layer = layer;
		m_layer->retain();

		bRect = true;
	} while (0);

	return bRect;
}

//绑定精灵
void Player::bindSprite(CCSprite* sprite, int nLevel)
{
	Entity::bindSprite(sprite, nLevel);

	//获取 玩家 当前位置
	m_initPos = getSprite()->getPosition();
}

//跳跃
void Player::jump()
{
	//是否存在 实体，是否处于跳跃状态
	if (!getSprite() || m_isjumping || m_isHit || m_isEating)
		return;

	//设定处于跳跃状态
	m_isjumping = true;

	//跳跃动作
	CCActionInterval* m_jump = CCJumpBy::create(1.5f, ccp(0, 0), 400, 1);

	//旋转动作
	CCActionInterval* m_rotateBy = CCRotateBy::create(0.5f, 360);
	CCActionInterval* m_rotateBack = m_rotateBy->reverse();
	CCActionInterval* m_rotate = CCSequence::create(m_rotateBy, m_rotateBack, NULL);

	//跳跃、旋转 动作组合
	CCActionInterval* m_action = CCSpawn::create(m_jump, m_rotate, NULL);

	CCCallFunc* m_callFunc = CCCallFunc::create(this, callfunc_selector(Player::jumpEnd));

	//执行动作
	getSprite()->runAction(CCSequence::create(m_action, m_callFunc, NULL));

	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("jump.wav");
}

//跳跃结束
void Player::jumpEnd()
{
//	CCLog("jumpEnd!");
	m_isjumping = false;
}

//受到攻击
void Player::hit()
{
	if (!getSprite() || m_isEating)
		return;

	m_isHit = true;

	//停止所有动作 初始化位置
	getSprite()->stopAllActions();
	resetData();

	//血量减少
	m_iHP -= 15;
	if (m_iHP<0)
		m_iHP = 0;

	/************************************************************************/
	/* 后退动作                                                             */
	/************************************************************************/

	//跳跃动作
	CCActionInterval* m_jumpUp = CCJumpBy::create(0.5f, ccp(0, 0), 50, 1);

	//旋转动作
	CCActionInterval* m_rotateBack = CCRotateBy::create(0.1f, -30, 0);
	CCActionInterval* m_rotateForward = CCRotateBy::create(0.1f, 30, 0);

	CCActionInterval* m_rotate = CCSequence::create(m_rotateBack, m_rotateForward, NULL);

	//跳跃、旋转 动作组合
	CCActionInterval* m_actionBack = CCSpawn::create(m_jumpUp, m_rotate, NULL);


	CCCallFunc* m_callFunc = CCCallFunc::create(this, callfunc_selector(Player::hitEnd));

	//执行动作
	getSprite()->runAction(CCSequence::create(m_actionBack, m_callFunc, NULL));

#if 0

#endif

	//飘字效果
	FlowWord* m_word = FlowWord::create();
	this->addChild(m_word);
	CCActionInterval* m_action = m_word->hitFlowWord();
	m_word->showFlowWord("-15 %>_<%", getSprite()->getPosition(), m_action);

	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("hit.wav");
}

//受攻击结束
void Player::hitEnd()
{
//	CCLog("hitEnd!");
	m_isHit = false;
	getSprite()->setPosition(m_initPos);
}

//吃到菠萝
void Player::getAnanas()
{
	if (!getSprite() || m_isEating)
		return;

	//血量减少
	m_iAnanas += 1;
	if (m_iAnanas>100)
	{
		//跳转到胜利界面
		m_iAnanas += 1;
	}

	//飘字效果
	FlowWord* m_ananasFlowWord = FlowWord::create();
	this->addChild(m_ananasFlowWord);


	CCActionInterval* m_action = m_ananasFlowWord->ananasFlowWord();
	m_ananasFlowWord->showFlowWord("+1", getSprite()->getPosition(), m_action);

	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("eat_1s.mp3");
}

//吃菠萝结束
void Player::ananasEnd()
{
	//CCLog("ananasEnd!");
}

//吃小猪
void Player::eatPig()
{
	if (!getSprite() || m_isEating)
		return;

	m_isEating = true;

	resetData();
	/************************************************************************/
	/*吃小猪动作 、声音                                                    */
	/************************************************************************/

	//小猪数量增加
	m_iPig += 1;
	if (m_iPig>20)
	{
		//跳转到胜利界面
		m_iPig += 1;
	}

	//飘字效果
	FlowWord* m_word = FlowWord::create();
	this->addChild(m_word);
	CCActionInterval* m_action = m_word->pigFlowWord();
	m_word->showFlowWord("\(^o^)/", getSprite()->getPosition(), m_action);

	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("eat.mp3");

	CCActionInterval* m_scaleLarge1 = CCScaleTo::create(0.5, 2, 2);
	CCActionInterval* m_scaleSmall1 = CCScaleTo::create(0.5, 0.5, 0.5);

	CCActionInterval* m_scaleLarge2 = CCScaleTo::create(0.5, 4, 4);
	CCActionInterval* m_scaleSmall2 = CCScaleTo::create(0.5, 1.0, 1.0);

	CCActionInterval* m_rotate = CCRotateBy::create(0.5, 360);
	CCActionInterval* m_rotateBack = CCRotateBy::create(0.5, -360);

	CCCallFunc* callFunc = CCCallFunc::create(this, callfunc_selector(Player::eatPigEnd));

	getSprite()->runAction(CCSequence::create(m_scaleLarge1, m_scaleSmall1, m_scaleLarge2, m_scaleSmall2, m_rotate, m_rotateBack, callFunc, NULL));

}

//吃小猪结束
void Player::eatPigEnd()
{
//	CCLog("eatPigEnd!");
	m_isEating = false;
	getSprite()->setPosition(m_initPos);
}

//重置数据
void Player::resetData()
{
	if (m_isjumping)
		m_isjumping = false;

	getSprite()->setPosition(getSprite()->getPosition());
	getSprite()->setScale(1.0f);
	getSprite()->setRotation(0);
}

//获取血量
int Player::getiHP()
{
	return this->m_iHP;
}

//获取菠萝数目
int Player::getiAnanas()
{
	return this->m_iAnanas;
}

//获取小猪数目
int Player::getiPig()
{
	return this->m_iPig;
}
