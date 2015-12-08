/*
************************************************************************
*
*	TollgateScene.cpp
*	杜星飞	2015年6月30日
*
************************************************************************
*/
#include "TollgateScene.h"
#include "HelloWorldScene.h"
#include "Player.h"
#include "ControlLayer.h"
#include "MonsterManager.h"
#include "Monster.h"
#include "Pig.h"
#include "SimpleAudioEngine.h"
#include "FlowWord.h"

USING_NS_CC;

CCScene* TollgateScene::scene()
{
	CCScene* m_scene = NULL;

	do
	{
		m_scene = CCScene::create();
		CC_BREAK_IF(!m_scene);

		TollgateScene* m_tollaget = TollgateScene::create();
		CC_BREAK_IF(!m_tollaget);

		m_scene->addChild(m_tollaget, 1);

	} while (0);

	return m_scene;
}
bool TollgateScene::init()
{
	bool bRect = false;

	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	do
	{
		//初始化背景
		initBG();

		//设置分数条、初始化分数、速度
		m_scoreLab = CCLabelTTF::create("Score: 0", "Arial", 35);
		m_scoreLab->setColor(ccc3(255, 0, 0));
		m_scoreLab->setPosition(ccp(visibleSize.width - m_scoreLab->getContentSize().width, visibleSize.height - m_scoreLab->getContentSize().height));

		this->addChild(m_scoreLab, 2);

		m_speed = 1;
		m_score = 0;

		//初始化血量条
		initHPSlider();

		//初始化菠萝
		initAnanas();

		//初始化小猪
		initPig();

		//初始化游戏标题
		CCSprite* m_title = CCSprite::create("title.png");
		m_title->setPosition(ccp(visibleSize.width / 2, visibleSize.height-m_title->getContentSize().height));
//		m_title->setAnchorPoint(ccp(0, 0));

		this->addChild(m_title, 2);

		//加载玩家
		CCSprite* m_sprite = CCSprite::create("yanzi1.png");
		m_sprite->setPosition(ccp(visibleSize.width / 4, visibleSize.height / 8));

		m_player = Player::createWithLayer(this);
		m_player->bindSprite(m_sprite, 2);

		this->addChild(m_player);

		//加载小怪
		MonsterManager* monsterMgr = MonsterManager::createWithLayer(this);
		monsterMgr->bindPlayer(m_player);

		this->addChild(monsterMgr, 2);

		//加载控制器
		ControlLayer* controlLayer = ControlLayer::createWithPlayer(m_player);
		CC_BREAK_IF(!controlLayer);

		this->addChild(controlLayer, 3);


		//开启帧
		this->scheduleUpdate();

		CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("WeddingInDream.mp3", true);

		bRect = true;
	} while (0);

	return bRect;
}

//初始化血量条
void TollgateScene::initHPSlider()
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	m_controlSlider = ControlSlider::create(
		CCSprite::create("background.png"),
		CCSprite::create("progress.png"),
		CCSprite::create("sliderThumb.png"));
	m_controlSlider->setPosition(ccp(visibleSize.width / 12, visibleSize.height-m_controlSlider->getContentSize().height));
	m_controlSlider->setTouchEnabled(false);
	m_controlSlider->setMaximumValue(300);
	m_controlSlider->setMinimumValue(0);
	m_controlSlider->setValue(300);
	this->addChild(m_controlSlider, 3);
}

//初始化菠萝
void TollgateScene::initAnanas()
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	m_controlSliderAnanas = ControlSlider::create(
		CCSprite::create("background1.png"),
		CCSprite::create("progress1.png"),
		CCSprite::create("sliderThumb.png"));
	m_controlSliderAnanas->setPosition(ccp(visibleSize.width / 12, visibleSize.height - m_controlSlider->getContentSize().height*2- m_controlSliderAnanas->getContentSize().height));
	m_controlSliderAnanas->setTouchEnabled(false);
	m_controlSliderAnanas->setMaximumValue(100);
	m_controlSliderAnanas->setMinimumValue(0);
	m_controlSliderAnanas->setValue(0);
	this->addChild(m_controlSliderAnanas, 3);
}

//初始化小猪
void TollgateScene::initPig()
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	m_controlSliderPig = ControlSlider::create(
		CCSprite::create("background2.png"),
		CCSprite::create("progress2.png"),
		CCSprite::create("sliderThumb.png"));
	m_controlSliderPig->setPosition(ccp(visibleSize.width / 12, visibleSize.height - m_controlSlider->getContentSize().height * 2 - m_controlSliderAnanas->getContentSize().height * 2 - m_controlSliderPig->getContentSize().height));
	m_controlSliderPig->setTouchEnabled(false);
	m_controlSliderPig->setMaximumValue(20);
	m_controlSliderPig->setMinimumValue(0);
	m_controlSliderPig->setValue(0);
	this->addChild(m_controlSliderPig, 3);
}

//初始化背景
void TollgateScene::initBG()
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	m_bgSprite1 = CCSprite::create("love.jpg");
	m_bgSprite1->setPosition(ccp(visibleSize.width / 2, visibleSize.height / 2));
	this->addChild(m_bgSprite1, 0);

	m_bgSprite2 = CCSprite::create("love.jpg");
	m_bgSprite2->setPosition(ccp(visibleSize.width + visibleSize.width / 2, visibleSize.height / 2));
	m_bgSprite2->setFlipX(true);
	this->addChild(m_bgSprite2, 0);
}


void TollgateScene::update(float delta)
{

	m_score += 0.2f;
	m_scoreLab->setString(CCString::createWithFormat("Score:%.0f", m_score)->getCString());

	m_controlSlider->setValue(m_player->getiHP());
	if (m_player->getiHP() <= 0)
	{
//		HelloWorld::m_finalScore = m_score;
		Director::getInstance()->replaceScene(HelloWorld::createScene());
	}
	 
	m_controlSliderAnanas->setValue(m_player->getiAnanas());
	m_controlSliderPig->setValue(m_player->getiPig());

	int posX1 = m_bgSprite1->getPositionX();
	int posX2 = m_bgSprite2->getPositionX();

	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	posX1 -= m_speed;
	posX2 -= m_speed;

	if (posX1 < -visibleSize.width / 2) {
		posX2 = visibleSize.width / 2;
		posX1 = visibleSize.width + visibleSize.width / 2;
	}
	if (posX2 < -visibleSize.width / 2) {
		posX1 = visibleSize.width / 2;
		posX2 = visibleSize.width + visibleSize.width / 2;
	}

	m_bgSprite1->setPositionX(posX1);
	m_bgSprite2->setPositionX(posX2);
}

void TollgateScene::keyReleased(EventKeyboard::KeyCode keyCode, Event* event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
	{
		Director::getInstance()->end();
	}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}