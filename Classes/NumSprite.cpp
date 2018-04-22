//
//  NumSprite.cpp
//  CarrotFantasy
//
//  Created by ������ on 18-3-30.
//  
//
#include "NumSprite.h"

Node *NumSprite::createNum(const std::string &rSNum, const std::string &rSImage, int spacing)
{
	//ԭͼ��С��ȡ��
	auto aSize = Sprite::create(rSImage)->getContentSize(); 
	auto aINumSize = rSNum.size();

	auto pNumNode = Node::create();
	pNumNode->retain();

	for (int i = 0; i < aINumSize; ++i)
	{
		//����rSNum��size���쾫�飬���Ѿ������pNumNode��
		auto aINum = atoi(StringUtils::format("%c", rSNum.at(i)).c_str());
		auto pNum = Sprite::create(rSImage, Rect(aSize.width / 12 * (aINum + 2), 0, aSize.width / 12, aSize.height));
		auto aPos = (spacing == 0 ? Vec2(pNum->getContentSize().width * i, 0) : Vec2(spacing * i, 0));
		pNum->setPosition(aPos);
		pNumNode->addChild(pNum);
	}
	return pNumNode;
}

Sprite *NumSprite::createSprit(const std::string &rsImage)
{
	auto frame = SpriteFrame::create(rsImage, Rect(20, 0, 20, 40));
	return Sprite::createWithSpriteFrame(frame);
}
