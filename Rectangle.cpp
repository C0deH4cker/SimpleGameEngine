//
//  Rectangle.cpp
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/13/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#include "Rectangle.h"
#include "helpers.h"
#include <math.h>

using namespace sge;

Rectangle::Rectangle(float x, float y, float width, float height)
: x(x), y(y), width(width), height(height) {}

Rectangle::Rectangle(const Vector2& p1, const Vector2& p2)
: x(MIN(p1.x, p2.x)), y(MIN(p1.y, p2.y)),
width(ABS(p2.x - p1.x)), height(ABS(p2.y - p1.y)) {}


Rectangle& Rectangle::operator=(const sge::Rectangle& other) {
	x = other.x;
	y = other.y;
	width = other.width;
	height = other.height;
	
	return *this;
}

void Rectangle::setCenter(const sge::Vector2& center) {
	x += center.x - midX();
	y += center.y - midY();
}

bool Rectangle::intersects(const Rectangle& other) const {
	return !(other.x > x + width ||
			 other.x + other.width < x ||
			 other.y > y + height ||
			 other.y + other.height < y);
}

float Rectangle::left() const {
	return x;
}

float Rectangle::midX() const {
	return x + width / 2.0f;
}

float Rectangle::right() const {
	return x + width;
}

float Rectangle::top() const {
	return y;
}

float Rectangle::midY() const {
	return y + height / 2.0f;
}

float Rectangle::bottom() const {
	return y + height;
}


float Rectangle::diagonal() const {
	return sqrt(width*width + height*height);
}


Vector2 Rectangle::topLeft() const {
	return Vector2(x, y);
}

Vector2 Rectangle::topCenter() const {
	return Vector2(x + width / 2.0f, y);
}

Vector2 Rectangle::topRight() const {
	return Vector2(x + width, y);
}

Vector2 Rectangle::leftCenter() const {
	return Vector2(x, y + width / 2.0f);
}

Vector2 Rectangle::center() const {
	return Vector2(x + width / 2.0f, y + height / 2.0f);
}

Vector2 Rectangle::rightCenter() const {
	return Vector2(x + width, y + width / 2.0f);
}

Vector2 Rectangle::bottomLeft() const {
	return Vector2(x, y + height);
}

Vector2 Rectangle::bottomCenter() const {
	return Vector2(x + width / 2.0f, y + height);
}

Vector2 Rectangle::bottomRight() const {
	return Vector2(x + width, y + height);
}

