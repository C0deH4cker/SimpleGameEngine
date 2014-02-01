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


#pragma mark Constructors and Destructors -

Vector2::Vector2()
: Vector2(0.0f, 0.0f) {}

Vector2::Vector2(float x, float y)
: x(x), y(y) {}

Vector2::Vector2(float value)
: Vector2(value, value) {}

Vector2::~Vector2() {}

#pragma mark - Assignment -

Vector2& Vector2::operator=(const Vector2& other) {
	x = other.x;
	y = other.y;
	return *this;
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

#pragma mark - Methods -

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

#pragma mark - Comparison Operators -

bool sge::operator<(const Vector2& l, const Vector2& r) {
	return l.magnitude() < r.magnitude();
}

bool sge::operator>(const Vector2& l, const Vector2& r) {
	return l.magnitude() > r.magnitude();
}

bool sge::operator<=(const Vector2& l, const Vector2& r) {
	return l.magnitude() <= r.magnitude();
}

bool sge::operator>=(const Vector2& l, const Vector2& r) {
	return l.magnitude() >= r.magnitude();
}

bool sge::operator==(const Vector2& l, const Vector2& r) {
	return l.x == r.x && l.y == r.y;
}

bool sge::operator!=(const Vector2& l, const Vector2& r) {
	return l.x != r.x || l.y != r.y;
}

// Left side
bool sge::operator<(const Vector2& l, float mag) {
	return l.magnitude() < mag;
}

bool sge::operator>(const Vector2& l, float mag) {
	return l.magnitude() > mag;
}

bool sge::operator<=(const Vector2& l, float mag) {
	return l.magnitude() <= mag;
}

bool sge::operator>=(const Vector2& l, float mag) {
	return l.magnitude() >= mag;
}

// Right side
bool sge::operator<(float mag, const Vector2& r) {
	return mag < r.magnitude();
}

bool sge::operator>(float mag, const Vector2& r) {
	return mag > r.magnitude();
}

bool sge::operator<=(float mag, const Vector2& r) {
	return mag <= r.magnitude();
}

bool sge::operator>=(float mag, const Vector2& r) {
	return mag >= r.magnitude();
}

#pragma mark - Arithmetic -

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

#pragma mark - Stream Insertion -

std::ostream& sge::operator<<(std::ostream& stream, const Vector2& vec) {
	std::stringstream ss;
	ss << "(" << vec.x << ", " << vec.y << ")";
	stream << ss.str();
	return stream;
}

