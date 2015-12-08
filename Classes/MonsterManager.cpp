#include "MonsterManager.h"
#include "Player.h"
#include "Monster.h"
#include "Ananas.h"
#include "Pig.h"

USING_NS_CC;

const int MAX_MONSTER_NUM = 4;
const int MAX_ANANAS_NUM = 5;
const int MAX_PIG_NUM = 3;

MonsterManager::MonsterManager() : m_layer(NULL), m_player(NULL), m_arrayMonster(NULL), m_arrayAnanas(NULL), m_arrayPig(NULL)
{

}

MonsterManager::~MonsterManager()
{
	CC_SAFE_RELEASE(m_layer);
	CC_SAFE_RELEASE(m_player);
	CC_SAFE_RELEASE(m_arrayMonster);
	CC_SAFE_RELEASE(m_arrayAnanas);
	CC_SAFE_RELEASE(m_arrayPig);
}

MonsterManager* MonsterManager::createWithLayer(CCLayer* layer)
{
	MonsterManager* monsterMgr = new MonsterManager();

	if (monsterMgr && monsterMgr->initWithLayer(layer))
		monsterMgr->autorelease();
	else
		CC_SAFE_DELETE(monsterMgr);

	return monsterMgr;
}

bool MonsterManager::initWithLayer(CCLayer* layer)
{
	bool bRet = false;

	do
	{
		this->m_layer = layer;
		this->m_layer->retain();

		createMonster();

		createAnanas();

		createPig();

		this->scheduleUpdate();
		bRet = true;
	} while (0);

	return bRet;
}

// 创建怪物
void MonsterManager::createMonster()
{
	m_arrayMonster = CCArray::create();
	m_arrayMonster->retain();

	Monster* monster = NULL;
	CCSprite* sprite = NULL;

	for (int i = 0; i < MAX_MONSTER_NUM; i++)
	{
		sprite = CCSprite::create("yanzi2.png");
		sprite->setPosition(Vec2(INIT_X + CCRANDOM_0_1() * 20000, INIT_Y + random(1, 250)));

		CCActionInterval* rotateBy = CCRotateBy::create(0.5f, 360);
		CCActionInterval* actions = CCRepeatForever::create(rotateBy);
		sprite->runAction(actions);

		monster = Monster::createWithLayer(m_layer);
		monster->bindSprite(sprite, 2);
		monster->show();

		this->addChild(monster);
		m_arrayMonster->addObject(monster);
	}
}

// 创建菠萝
void MonsterManager::createAnanas()
{
	m_arrayAnanas = CCArray::create();
	m_arrayAnanas->retain();

	Ananas* m_ananas = NULL;
	CCSprite* sprite = NULL;

	for (int i = 0; i < MAX_ANANAS_NUM; i++)
	{
		sprite = CCSprite::create("ananas.png");
		sprite->setPosition(ccp(INIT_X_Ananas + CCRANDOM_0_1() * 10000, INIT_Y_Ananas + random(1, 150)));

		CCActionInterval* rotateBy = CCRotateBy::create(0.5f, 360);
		CCActionInterval* rotateBack = CCRotateBy::create(0.5f, -360);

		CCActionInterval* scaleLarge = CCScaleTo::create(0.5f, 2.5, 2.5);
		CCActionInterval* scaleSmall = CCScaleTo::create(0.5f, 0.5, 0.5);

		CCActionInterval* actions1 = CCSpawn::create(rotateBy, scaleLarge, NULL);
		CCActionInterval* actions2 = CCSpawn::create(rotateBack, scaleSmall, NULL);


		CCActionInterval* actions = CCRepeatForever::create(CCSequence::create(actions1, actions2, NULL));

		sprite->runAction(actions);

		m_ananas = Ananas::createWithLayer(m_layer);
		m_ananas->bindSprite(sprite, 2);
		m_ananas->show();

		this->addChild(m_ananas);
		m_arrayAnanas->addObject(m_ananas);
	}

	for (int i = 0; i < MAX_ANANAS_NUM; i++)
	{
		sprite = CCSprite::create("banana.png");
		sprite->setPosition(ccp(INIT_X_Ananas + CCRANDOM_0_1() * 10000, INIT_Y_Ananas + random(1, 250)));

		CCActionInterval* scaleLarge = CCScaleTo::create(0.5, 2.5, 0);
		CCActionInterval* scaleSmall = CCScaleTo::create(0.5, 0, 2.5);

		CCActionInterval* actions = CCSequence::create(scaleLarge, scaleSmall, NULL);

		sprite->runAction(CCRepeatForever::create(actions));

		m_ananas = Ananas::createWithLayer(m_layer);
		m_ananas->bindSprite(sprite, 2);
		m_ananas->show();

		this->addChild(m_ananas);
		m_arrayAnanas->addObject(m_ananas);
	}

	for (int i = 0; i < MAX_ANANAS_NUM; i++)
	{
		sprite = CCSprite::create("strawberry.png");
		sprite->setPosition(ccp(INIT_X_Ananas + CCRANDOM_0_1() * 10000, INIT_Y_Ananas + random(1, 350)));

		auto actionBy = MoveBy::create(2, Vec3(180, 180, -100));
		auto actionByBack = actionBy->reverse();

		sprite->runAction(CCRepeatForever::create(Sequence::create(actionBy, actionByBack, nullptr)));

		m_ananas = Ananas::createWithLayer(m_layer);
		m_ananas->bindSprite(sprite, 2);
		m_ananas->show();

		this->addChild(m_ananas);
		m_arrayAnanas->addObject(m_ananas);
	}

	for (int i = 0; i < MAX_ANANAS_NUM; i++)
	{
		sprite = CCSprite::create("lemon.png");
		sprite->setPosition(ccp(INIT_X_Ananas + CCRANDOM_0_1() * 10000, INIT_Y_Ananas + random(1, 250)));

		auto actionTo = SkewTo::create(2, 0, 2);
		auto rotateTo = RotateTo::create(2, 61.0f);
		auto actionScaleTo = ScaleTo::create(2, -0.44f, 0.47f);

		auto actionScaleToBack = ScaleTo::create(2, 1.0f, 1.0f);
		auto rotateToBack = RotateTo::create(2, 0);
		auto actionToBack = SkewTo::create(2, 0, 0);

		sprite->runAction(CCRepeatForever::create(Sequence::create(actionTo, actionToBack, nullptr)));
		sprite->runAction(CCRepeatForever::create(Sequence::create(rotateTo, rotateToBack, nullptr)));
		sprite->runAction(CCRepeatForever::create(Sequence::create(actionScaleTo, actionScaleToBack, nullptr)));

		m_ananas = Ananas::createWithLayer(m_layer);
		m_ananas->bindSprite(sprite, 2);
		m_ananas->show();

		this->addChild(m_ananas);
		m_arrayAnanas->addObject(m_ananas);
	}
}

// 创建小猪
void MonsterManager::createPig()
{
	m_arrayPig = CCArray::create();
	m_arrayPig->retain();

	Pig* m_pig = NULL;
	CCSprite* sprite = NULL;

	for (int i = 0; i < MAX_PIG_NUM; i++)
	{
		sprite = CCSprite::create("pig.png");
		sprite->setPosition(ccp(CCRANDOM_0_1() * 20000, 150 + random(1, 250)));

		ccBezierConfig m_bezier;
		m_bezier.controlPoint_1 = ccp(100, -200);
		m_bezier.controlPoint_2 = ccp(300, 100);
		m_bezier.endPosition = ccp(0, 0);

		CCBezierBy* actions = CCBezierBy::create(3.0, m_bezier);
		//CCRepeatForever::create(actions)
		sprite->runAction(CCRepeatForever::create(actions));

		m_pig = Pig::createWithLayer(m_layer);
		m_pig->bindSprite(sprite, 2);
		m_pig->show();

		this->addChild(m_pig);
		m_arrayPig->addObject(m_pig);
	}

	for (int i = 0; i < MAX_PIG_NUM; i++)
	{
		sprite = CCSprite::create("butterfly.png");
		sprite->setPosition(ccp(CCRANDOM_0_1() * 20000, 150 + random(1, 300)));

		ccBezierConfig m_bezier;
		m_bezier.controlPoint_1 = ccp(150, -250);
		m_bezier.controlPoint_2 = ccp(350, 150);
		m_bezier.endPosition = ccp(0, 0);

		CCBezierBy* actions = CCBezierBy::create(3.0, m_bezier);
		//CCRepeatForever::create(actions)
		sprite->runAction(CCRepeatForever::create(actions));

		m_pig = Pig::createWithLayer(m_layer);
		m_pig->bindSprite(sprite, 2);
		m_pig->show();

		this->addChild(m_pig);
		m_arrayPig->addObject(m_pig);
	}

	for (int i = 0; i < MAX_PIG_NUM; i++)
	{
		sprite = CCSprite::create("cat.png");
		sprite->setPosition(ccp(CCRANDOM_0_1() * 20000, 150 + random(1, 350)));

		ccBezierConfig m_bezier;
		m_bezier.controlPoint_1 = ccp(200, -100);
		m_bezier.controlPoint_2 = ccp(200, 150);
		m_bezier.endPosition = ccp(0, 0);

		CCBezierBy* actions = CCBezierBy::create(3.0, m_bezier);
		//CCRepeatForever::create(actions)
		sprite->runAction(CCRepeatForever::create(actions));

		m_pig = Pig::createWithLayer(m_layer);
		m_pig->bindSprite(sprite, 2);
		m_pig->show();

		this->addChild(m_pig);
		m_arrayPig->addObject(m_pig);
	}
}

void MonsterManager::bindPlayer(Player* player)
{
	this->m_player = player;
	this->m_player->retain();
}

void MonsterManager::update(float dt)
{
	CCObject* obj = NULL;
	Monster* monster = NULL;
	Ananas* m_ananas = NULL;
	Pig* m_pig = NULL;

	CCARRAY_FOREACH(m_arrayMonster, obj)
	{
		monster = (Monster*)obj;

		if (monster->isAlive())
		{
			monster->MoveX(-5);

			if (monster->isCollideWithPlayer(m_player))
			{
				CCLOG("x=%f", monster->getPositionX());
				m_player->hit();
				monster->reset();
			}

			if (monster->getSprite()->getPositionX() < 0)
				monster->hide();
		}
		else
			monster->show();
	}

	CCARRAY_FOREACH(m_arrayAnanas, obj)
	{
		m_ananas = (Ananas*)obj;

		if (m_ananas->isAlive())
		{
			m_ananas->MoveX(-3);

			if (m_ananas->isCollideWithPlayer(m_player))
			{
				CCLOG("x=%f", m_ananas->getPositionX());
				m_player->getAnanas();
				m_ananas->reset();
			}

			if (m_ananas->getSprite()->getPositionX() < 0)
				m_ananas->hide();
		}
		else
			m_ananas->show();
	}

	CCARRAY_FOREACH(m_arrayPig, obj)
	{
		m_pig = (Pig*)obj;

		if (m_pig->isAlive())
		{
			m_pig->MoveX(-1);

			if (m_pig->isCollideWithPlayer(m_player))
			{
				CCLOG("x=%f", m_pig->getPositionX());
				m_player->eatPig();
				m_pig->reset();
			}

			if (m_pig->getSprite()->getPositionX() < 0)
				m_pig->hide();
		}
		else
			m_pig->show();
	}
}
