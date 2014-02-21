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

Vector2::Vector2(float scalar)
: x(scalar), y(scalar) {}

Vector2::Vector2(float x, float y)
: x(x), y(y) {}

Vector2::Vector2(const Vector2& other)
: x(other.x), y(other.y) {}

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

Vector2 Vector2::operator-() const {
	return Vector2(-x, -y);
}

#pragma mark - Methods -

float Vector2::sqrmagnitude() const {
	return x*x + y*y;
}

float Vector2::magnitude() const {
    return sqrt(x*x + y*y);
}

float Vector2::angle(const Vector2& other) const {
	return acosf(dot(other) / (magnitude() * other.magnitude()));
}

float Vector2::anglenorm(const Vector2& other) const {
	return acosf(dot(other));
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

Vector2 Vector2::project(const Vector2& target) const {
	return target * (dot(target) / target.dot(target));
}

Vector2& Vector2::iproject(const Vector2& target) {
	return *this = project(target);
}

Vector2 Vector2::reflect(Vector2 normal) const {
	normal.inormalize();
	return *this - 2.0f * normal * dot(normal);
}

Vector2& Vector2::ireflect(Vector2 normal) {
	normal.inormalize();
	return *this -= 2.0f * normal * dot(normal);
}

Vector2 Vector2::rotate(float radians) const {
	return Vector2(x * cosf(radians) - y * sinf(radians),
	               y * cosf(radians) + x * sinf(radians));
}

Vector2& Vector2::irotate(float radians) {
	float tmp = x * cosf(radians) - y * sinf(radians);
	y = y * cosf(radians) + x * sinf(radians);
	x = tmp;
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

Vector2 Vector2::transform(const sge::Matrix& mat) const {
	return Vector2(x * mat.m11 + y * mat.m21 + mat.m41,
	               x * mat.m12 + y * mat.m22 + mat.m42);
}

Vector2& Vector2::itransform(const sge::Matrix& mat) {
	float tmp = x * mat.m11 + y * mat.m21 + mat.m41;
	y = x * mat.m12 + y * mat.m22 + mat.m42;
	x = tmp;
	return *this;
}


#pragma mark - Comparison Operators -

bool sge::operator<(const Vector2& l, const Vector2& r) {
	return l.sqrmagnitude() < r.sqrmagnitude();
}

bool sge::operator>(const Vector2& l, const Vector2& r) {
	return l.sqrmagnitude() > r.sqrmagnitude();
}

bool sge::operator<=(const Vector2& l, const Vector2& r) {
	return l.sqrmagnitude() <= r.sqrmagnitude();
}

bool sge::operator>=(const Vector2& l, const Vector2& r) {
	return l.sqrmagnitude() >= r.sqrmagnitude();
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
	return Vector2(vec.x + other.x, vec.y + other.y);
}

const Vector2 sge::operator+(const Vector2& vec, float amount) {
	return Vector2(vec.x + amount, vec.y + amount);
}

const Vector2 sge::operator+(float amount, const Vector2& vec) {
	return Vector2(vec.x + amount, vec.y + amount);
}

const Vector2 sge::operator-(const Vector2& vec, const Vector2& other) {
	return Vector2(vec.x - other.x, vec.y - other.y);
}

const Vector2 sge::operator-(const Vector2& vec, float amount) {
	return Vector2(vec.x - amount, vec.y - amount);
}

const Vector2 sge::operator-(float amount, const Vector2& vec) {
	return Vector2(amount - vec.x, amount - vec.y);
}

const Vector2 sge::operator*(const Vector2& a, const Vector2& b) {
	return a.dot(b);
}

const Vector2 sge::operator*(const Vector2& vec, float scale) {
	return Vector2(vec.x * scale, vec.y * scale);
}

const Vector2 sge::operator*(float scale, const Vector2& vec) {
	return Vector2(vec.x * scale, vec.y * scale);
}

const Vector2 sge::operator/(const Vector2& a, const Vector2& b) {
	return Vector2(a.x / b.x, a.y / b.y);
}

const Vector2 sge::operator/(const Vector2& vec, float scale) {
	return Vector2(vec.x / scale, vec.y / scale);
}

#pragma mark - Stream Insertion -

std::ostream& sge::operator<<(std::ostream& stream, const Vector2& vec) {
	std::stringstream ss;
	ss << "(" << vec.x << ", " << vec.y << ")";
	stream << ss.str();
	return stream;
}

