/*
************************************************************************
*
*	FlowWord.h
*	���Ƿ�	2015��6��30��
*
************************************************************************
*/
#ifndef __FlowWord_H__
#define __FlowWord_H__

#include "cocos2d.h"

USING_NS_CC;

class FlowWord :public CCNode
{
public:
	FlowWord();
	~FlowWord();

	//�����ͳ�ʼ�� Ʈ��
	static FlowWord* create();
	bool init();

	//��ʾƮ��
	void showFlowWord(const char* text, CCPoint pos, CCActionInterval* flowWord);

	//��ʾƮ�ֽ���
	void showEnd();

	CCActionInterval* hitFlowWord();

	CCActionInterval* ananasFlowWord();

	CCActionInterval* pigFlowWord();
protected:
private:

	CCLabelTTF* m_textLabel;
};
#endif