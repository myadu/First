/*
************************************************************************
*
*	Player.cpp
*	���Ƿ�	2015��6��30��
*
************************************************************************
*/
#include "SimpleAudioEngine.h"
#include "Player.h"
#include "FlowWord.h"

USING_NS_CC;

Player::Player() : m_isjumping(false), m_isHit(false), m_isEating(false), m_iHP(300), m_iAnanas(0), m_iPig(0), m_initPos(ccp(0, 0))
{
	//Ԥ��������
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("hit.wav");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("jump.wav");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("eat.mp3");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->preloadEffect("eat_1s.mp3");

}
Player::~Player()
{
	CC_SAFE_RELEASE(m_layer);

	//ж������
	CocosDenshion::SimpleAudioEngine::sharedEngine()->unloadEffect("hit.wav");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->unloadEffect("jump.wav");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->unloadEffect("eat.mp3");
	CocosDenshion::SimpleAudioEngine::sharedEngine()->unloadEffect("eat_1s.mp3");

}

//�ڲ��д���
Player* Player::createWithLayer(CCLayer* layer)
{
	Player* m_player = new Player();
	if (m_player && m_player->initWithLayer(layer))
		m_player->autorelease();
	else
		CC_SAFE_DELETE(m_player);

	return m_player;
}

//�ڲ��г�ʼ��
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

//�󶨾���
void Player::bindSprite(CCSprite* sprite, int nLevel)
{
	Entity::bindSprite(sprite, nLevel);

	//��ȡ ��� ��ǰλ��
	m_initPos = getSprite()->getPosition();
}

//��Ծ
void Player::jump()
{
	//�Ƿ���� ʵ�壬�Ƿ�����Ծ״̬
	if (!getSprite() || m_isjumping || m_isHit || m_isEating)
		return;

	//�趨������Ծ״̬
	m_isjumping = true;

	//��Ծ����
	CCActionInterval* m_jump = CCJumpBy::create(1.5f, ccp(0, 0), 400, 1);

	//��ת����
	CCActionInterval* m_rotateBy = CCRotateBy::create(0.5f, 360);
	CCActionInterval* m_rotateBack = m_rotateBy->reverse();
	CCActionInterval* m_rotate = CCSequence::create(m_rotateBy, m_rotateBack, NULL);

	//��Ծ����ת �������
	CCActionInterval* m_action = CCSpawn::create(m_jump, m_rotate, NULL);

	CCCallFunc* m_callFunc = CCCallFunc::create(this, callfunc_selector(Player::jumpEnd));

	//ִ�ж���
	getSprite()->runAction(CCSequence::create(m_action, m_callFunc, NULL));

	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("jump.wav");
}

//��Ծ����
void Player::jumpEnd()
{
//	CCLog("jumpEnd!");
	m_isjumping = false;
}

//�ܵ�����
void Player::hit()
{
	if (!getSprite() || m_isEating)
		return;

	m_isHit = true;

	//ֹͣ���ж��� ��ʼ��λ��
	getSprite()->stopAllActions();
	resetData();

	//Ѫ������
	m_iHP -= 15;
	if (m_iHP<0)
		m_iHP = 0;

	/************************************************************************/
	/* ���˶���                                                             */
	/************************************************************************/

	//��Ծ����
	CCActionInterval* m_jumpUp = CCJumpBy::create(0.5f, ccp(0, 0), 50, 1);

	//��ת����
	CCActionInterval* m_rotateBack = CCRotateBy::create(0.1f, -30, 0);
	CCActionInterval* m_rotateForward = CCRotateBy::create(0.1f, 30, 0);

	CCActionInterval* m_rotate = CCSequence::create(m_rotateBack, m_rotateForward, NULL);

	//��Ծ����ת �������
	CCActionInterval* m_actionBack = CCSpawn::create(m_jumpUp, m_rotate, NULL);


	CCCallFunc* m_callFunc = CCCallFunc::create(this, callfunc_selector(Player::hitEnd));

	//ִ�ж���
	getSprite()->runAction(CCSequence::create(m_actionBack, m_callFunc, NULL));

#if 0

#endif

	//Ʈ��Ч��
	FlowWord* m_word = FlowWord::create();
	this->addChild(m_word);
	CCActionInterval* m_action = m_word->hitFlowWord();
	m_word->showFlowWord("-15 %>_<%", getSprite()->getPosition(), m_action);

	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("hit.wav");
}

//�ܹ�������
void Player::hitEnd()
{
//	CCLog("hitEnd!");
	m_isHit = false;
	getSprite()->setPosition(m_initPos);
}

//�Ե�����
void Player::getAnanas()
{
	if (!getSprite() || m_isEating)
		return;

	//Ѫ������
	m_iAnanas += 1;
	if (m_iAnanas>100)
	{
		//��ת��ʤ������
		m_iAnanas += 1;
	}

	//Ʈ��Ч��
	FlowWord* m_ananasFlowWord = FlowWord::create();
	this->addChild(m_ananasFlowWord);


	CCActionInterval* m_action = m_ananasFlowWord->ananasFlowWord();
	m_ananasFlowWord->showFlowWord("+1", getSprite()->getPosition(), m_action);

	CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect("eat_1s.mp3");
}

//�Բ��ܽ���
void Player::ananasEnd()
{
	//CCLog("ananasEnd!");
}

//��С��
void Player::eatPig()
{
	if (!getSprite() || m_isEating)
		return;

	m_isEating = true;

	resetData();
	/************************************************************************/
	/*��С���� ������                                                    */
	/************************************************************************/

	//С����������
	m_iPig += 1;
	if (m_iPig>20)
	{
		//��ת��ʤ������
		m_iPig += 1;
	}

	//Ʈ��Ч��
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

//��С�����
void Player::eatPigEnd()
{
//	CCLog("eatPigEnd!");
	m_isEating = false;
	getSprite()->setPosition(m_initPos);
}

//��������
void Player::resetData()
{
	if (m_isjumping)
		m_isjumping = false;

	getSprite()->setPosition(getSprite()->getPosition());
	getSprite()->setScale(1.0f);
	getSprite()->setRotation(0);
}

//��ȡѪ��
int Player::getiHP()
{
	return this->m_iHP;
}

//��ȡ������Ŀ
int Player::getiAnanas()
{
	return this->m_iAnanas;
}

//��ȡС����Ŀ
int Player::getiPig()
{
	return this->m_iPig;
}
