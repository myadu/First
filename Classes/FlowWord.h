/*
************************************************************************
*
*	FlowWord.h
*	杜星飞	2015年6月30日
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

	//创建和初始化 飘字
	static FlowWord* create();
	bool init();

	//显示飘字
	void showFlowWord(const char* text, CCPoint pos, CCActionInterval* flowWord);

	//显示飘字结束
	void showEnd();

	CCActionInterval* hitFlowWord();

	CCActionInterval* ananasFlowWord();

	CCActionInterval* pigFlowWord();
protected:
private:

	CCLabelTTF* m_textLabel;
};
#endif