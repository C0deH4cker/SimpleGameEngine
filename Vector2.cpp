//
//  Vector2.cpp
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/7/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#include "Vector2.h"
#include <math.h>
#include <ostream>
#include <sstream>

using namespace sge;


Vector2::Vector2()
: Vector2(0.0f, 0.0f) {}

Vector2::Vector2(float x, float y)
: x(x), y(y) {}

Vector2::Vector2(float value)
: Vector2(value, value) {}

Vector2::~Vector2() {}


Vector2& Vector2::operator=(const Vector2& other) {
	x = other.x;
	y = other.y;
	return *this;
}


bool Vector2::operator<(const Vector2& other) const {
	return magnitude() < other.magnitude();
}

bool Vector2::operator>(const Vector2& other) const {
	return magnitude() > other.magnitude();
}

bool Vector2::operator<=(const Vector2& other) const {
	return magnitude() <= other.magnitude();
}

bool Vector2::operator>=(const Vector2& other) const {
	return magnitude() >= other.magnitude();
}

bool Vector2::operator==(const Vector2& other) const {
	return x == other.x && y == other.y;
}

bool Vector2::operator!=(const Vector2& other) const {
	return x != other.x || y != other.y;
}


bool Vector2::operator<(float mag) const {
	return magnitude() < mag;
}

bool Vector2::operator>(float mag) const {
	return magnitude() > mag;
}

bool Vector2::operator<=(float mag) const {
	return magnitude() <= mag;
}

bool Vector2::operator>=(float mag) const {
	return magnitude() >= mag;
}


Vector2& Vector2::operator+=(const Vector2& other) {
	x += other.x;
	y += other.y;
	return *this;
}

Vector2& Vector2::operator+=(float amount) {
	x += amount;
	x += amount;
	return *this;
}

Vector2& Vector2::operator-=(const Vector2& other) {
	x -= other.x;
	y -= other.y;
	return *this;
}

Vector2& Vector2::operator-=(float amount) {
	x -= amount;
	y -= amount;
	return *this;
}

Vector2& Vector2::operator*=(float scale) {
	x *= scale;
	y *= scale;
	return *this;
}

Vector2& Vector2::operator/=(float scale) {
	x /= scale;
	y /= scale;
	return *this;
}


float Vector2::sqrmagnitude() const {
	return x*x + y*y;
}

float Vector2::magnitude() const {
    return sqrt(x*x + y*y);
}

const Vector2 Vector2::normalize() const {
    Vector2 ret;
    float mag = magnitude();
	
    if(mag != 0.0f) {
        ret.x = x / mag;
        ret.y = y / mag;
    }
	
    return ret;
}

Vector2& Vector2::inormalize() {
    float mag = magnitude();
	
    if(mag != 0.0f) {
        x /= mag;
        y /= mag;
    }
	
    return *this;
}

Vector2 Vector2::reflect(const Vector2 &normal) const {
	float dotted = dot(normal);
	return {x - ((2.0f * dotted) * normal.x),
		    y - ((2.0f * dotted) * normal.y)};
}

float Vector2::sqrdistance(const Vector2& other) const {
	float dx = other.x - x;
	float dy = other.y - y;
	return dx*dx + dy*dy;
}

float Vector2::distance(const Vector2& other) const {
	float dx = other.x - x;
	float dy = other.y - y;
	return sqrt(dx*dx + dy*dy);
}

float Vector2::dot(const Vector2& other) const {
	return x * other.x + y * other.y;
}


const Vector2 sge::operator+(const Vector2& vec, const Vector2& other) {
	Vector2 ret;
	ret.x = vec.x + other.x;
	ret.y = vec.y + other.y;
	return ret;
}

const Vector2 sge::operator+(const Vector2& vec, float amount) {
	Vector2 ret;
	ret.x = vec.x + amount;
	ret.y = vec.y + amount;
	return ret;
}

const Vector2 sge::operator+(float amount, const Vector2& vec) {
	Vector2 ret;
	ret.x = vec.x + amount;
	ret.y = vec.y + amount;
	return ret;
}

const Vector2 sge::operator-(const Vector2& vec) {
	Vector2 ret;
	ret.x = -vec.x;
	ret.y = -vec.y;
	return ret;
}

const Vector2 sge::operator-(const Vector2& vec, const Vector2& other) {
	Vector2 ret;
	ret.x = vec.x - other.x;
	ret.y = vec.y - other.y;
	return ret;
}

const Vector2 sge::operator-(const Vector2& vec, float amount) {
	Vector2 ret;
	ret.x = vec.x - amount;
	ret.y = vec.y - amount;
	return ret;
}

const Vector2 sge::operator-(float amount, const Vector2& vec) {
	Vector2 ret;
	ret.x = amount - vec.x;
	ret.y = amount - vec.y;
	return ret;
}

const Vector2 sge::operator*(const Vector2& vec, float scale) {
	Vector2 ret;
	ret.x = vec.x * scale;
	ret.y = vec.y * scale;
	return ret;
}

const Vector2 sge::operator*(float scale, const Vector2& vec) {
	Vector2 ret;
	ret.x = vec.x * scale;
	ret.y = vec.y * scale;
	return ret;
}

const Vector2 sge::operator/(const Vector2& vec, float scale) {
	Vector2 ret;
	ret.x = vec.x / scale;
	ret.y = vec.y / scale;
	return ret;
}


std::ostream& sge::operator<<(std::ostream& stream, const Vector2& vec) {
	std::stringstream ss;
	ss << "(" << vec.x << ", " << vec.y << ")";
	stream << ss.str();
	return stream;
}

