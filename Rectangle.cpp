//
//  Rectangle.cpp
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/13/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#include "Rectangle.h"
#include "helpers.h"

using namespace sge;

Rectangle::Rectangle(float x, float y, float width, float height)
: x(x), y(y), width(width), height(height) {}


Rectangle& Rectangle::operator=(const sge::Rectangle &other) {
	x = other.x;
	y = other.y;
	width = other.width;
	height = other.height;
	
	return *this;
}

bool Rectangle::intersects(const Rectangle& other) const {
	return !(other.x > x + width ||
			 other.x + other.width < x ||
			 other.y > y + height ||
			 other.y + other.height < y);
}

