//
//  Sprite.cpp
//  SimpleGameEngine
//
//  Created by C0deH4cker on 2/4/14.
//  Copyright (c) 2014 C0deH4cker. All rights reserved.
//

#include "Sprite.h"

using namespace sge;

Sprite::Sprite(const Texture2D* texture, Rectangle sourceRect)
: tex(texture), rect(sourceRect) {}

void Sprite::draw(const Rectangle& destRect, float rotation) const {
	tex->draw(destRect, rect, rotation);
}

float Sprite::getWidth() const {
	return rect.width;
}

float Sprite::getHeight() const {
	return rect.height;
}

