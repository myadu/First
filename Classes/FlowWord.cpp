/*
************************************************************************
*
*	FlowWord.cpp
*	���Ƿ�	2015��6��30��
*
************************************************************************
*/
#include "FlowWord.h"

USING_NS_CC;

FlowWord::FlowWord() : m_textLabel(NULL)
{

}
FlowWord::~FlowWord()
{

}

//�����ͳ�ʼ�� Ʈ��
FlowWord* FlowWord::create()
{
	FlowWord* m_word = new FlowWord();

	if (m_word && m_word->init())
		m_word->autorelease();
	else
		CC_SAFE_DELETE(m_word);

	return m_word;
}

bool FlowWord::init()
{
	m_textLabel = CCLabelTTF::create("", "Arial", 25);
	m_textLabel->setColor(ccc3(CCRANDOM_0_1() * 255, CCRANDOM_0_1() * 255, CCRANDOM_0_1() * 255));
	m_textLabel->setAnchorPoint(ccp(1, 0));
	m_textLabel->setVisible(false);

	this->addChild(m_textLabel);

	return true;
}

//��ʾƮ��
void FlowWord::showFlowWord(const char* text, CCPoint pos, CCActionInterval* flowWord)
{

	m_textLabel->setPosition(pos);
	m_textLabel->setString(text);
	m_textLabel->setVisible(true);

	/************************************************************************/
	/*Ʈ�ֶ���                                                              */
	/************************************************************************/
#if 0

#endif	

	m_textLabel->runAction(flowWord);
}

//��ʾƮ�ֽ���
void FlowWord::showEnd()
{
	CCLOG("showWord End!");
	m_textLabel->setVisible(false);
	m_textLabel->removeFromParentAndCleanup(true);
}

//�ܹ���Ʈ��
CCActionInterval* FlowWord::hitFlowWord()
{
	//�Ŵ���С
	CCActionInterval* m_scaleLarge = CCScaleTo::create(1.0f, 2.5, 2.5);
	CCActionInterval* m_scaleSmall = CCScaleTo::create(1.0f, 0.5, 0.5);

	//��б
	CCActionInterval* m_skew = CCSkewTo::create(1.0f, 180, 0);
	CCActionInterval* m_skewBack = CCSkewTo::create(1.0f, 0, 0);

	//��϶���
	CCActionInterval* m_action = CCSpawn::create(m_scaleLarge, m_skew, NULL);
	CCActionInterval* m_actionBack = CCSpawn::create(m_scaleSmall, m_skewBack, NULL);

	CCCallFunc* callFunc = CCCallFunc::create(this, callfunc_selector(FlowWord::showEnd));

	CCActionInterval* flow = CCSequence::create(m_action, m_actionBack, callFunc, NULL);

	return flow;
}

//�Բ���Ʈ��
CCActionInterval* FlowWord::ananasFlowWord()
{
	//�Ŵ���С
	CCActionInterval* m_scaleLarge = CCScaleTo::create(0.5f, 2.5, 2.5);
	CCActionInterval* m_scaleSmall = CCScaleTo::create(0.5f, 0.5, 0.5);

	CCCallFunc* callFunc = CCCallFunc::create(this, callfunc_selector(FlowWord::showEnd));

	CCActionInterval* flow = CCSequence::create(m_scaleLarge, m_scaleSmall, callFunc, NULL);

	return flow;
}

//��С��Ʈ��
CCActionInterval* FlowWord::pigFlowWord()
{
	//��λ
	CCActionInterval* m_move1 = CCMoveBy::create(0.7f, ccp(30, 30));
	CCActionInterval* m_move2 = CCMoveBy::create(0.7f, ccp(-30, -30));
	CCActionInterval* m_move3 = CCMoveBy::create(0.7f, ccp(30, -30));
	CCActionInterval* m_move4 = CCMoveBy::create(0.7f, ccp(-30, 30));

	//�Ŵ���С
	CCActionInterval* m_scale1 = CCScaleTo::create(0.7f, CCRANDOM_0_1() * 4, CCRANDOM_0_1() * 4);
	CCActionInterval* m_scale2 = CCScaleTo::create(0.7f, CCRANDOM_0_1() * 4, CCRANDOM_0_1() * 4);
	CCActionInterval* m_scale3 = CCScaleTo::create(0.7f, CCRANDOM_0_1() * 4, CCRANDOM_0_1() * 4);
	CCActionInterval* m_scale4 = CCScaleTo::create(0.7f, CCRANDOM_0_1() * 4, CCRANDOM_0_1() * 4);

	CCActionInterval* m_action1 = CCSpawn::create(m_move1, m_scale1, NULL);
	CCActionInterval* m_action2 = CCSpawn::create(m_move2, m_scale2, NULL);
	CCActionInterval* m_action3 = CCSpawn::create(m_move3, m_scale3, NULL);
	CCActionInterval* m_action4 = CCSpawn::create(m_move4, m_scale4, NULL);


	CCCallFunc* callFunc = CCCallFunc::create(this, callfunc_selector(FlowWord::showEnd));

	CCActionInterval* flow = CCSequence::create(m_action1, m_action2, m_action3, m_action4, callFunc, NULL);

	return flow;
}