//
//  Vector4.cpp
//  SimpleGameEngine
//
//  Created by Josh Huelsman on 1/23/14.
//  Copyright (c) 2014 Josh Huelsman <joshuahuelsman@gmail.com>. All rights reserved.
//

#include "Vector4.h"
#include <math.h>
#include <ostream>
#include <sstream>

using namespace sge;


Vector4::Vector4()
: Vector4(0.0f, 0.0f, 0.0f) {}

Vector4::Vector4(float x, float y, float z, float w)
: x(x), y(y), z(z), w(w) {}

Vector4::Vector4(const Vector3& vec, float w)
: x(vec.x), y(vec.y), z(vec.z), w(w) {}

Vector4::Vector4(float value)
: Vector4(value, value, value, value) {}

Vector4::~Vector4() {}


Vector4& Vector4::operator=(const Vector4& other) {
	x = other.x;
	y = other.y;
	z = other.z;
	w = other.w;
	return *this;
}


bool Vector4::operator<(const Vector4& other) const {
	return magnitude() < other.magnitude();
}

bool Vector4::operator>(const Vector4& other) const {
	return magnitude() > other.magnitude();
}

bool Vector4::operator<=(const Vector4& other) const {
	return magnitude() <= other.magnitude();
}

bool Vector4::operator>=(const Vector4& other) const {
	return magnitude() >= other.magnitude();
}

bool Vector4::operator==(const Vector4& other) const {
	return x == other.x && y == other.y && z == other.z && w == other.w;
}

bool Vector4::operator!=(const Vector4& other) const {
	return x != other.x || y != other.y || z != other.z || w != other.w;
}


bool Vector4::operator<(float mag) const {
	return magnitude() < mag;
}

bool Vector4::operator>(float mag) const {
	return magnitude() > mag;
}

bool Vector4::operator<=(float mag) const {
	return magnitude() <= mag;
}

bool Vector4::operator>=(float mag) const {
	return magnitude() >= mag;
}


Vector4& Vector4::operator+=(const Vector4& other) {
	x += other.x;
	y += other.y;
	z += other.z;
	w += other.w;
	return *this;
}

Vector4& Vector4::operator+=(float amount) {
	x += amount;
	x += amount;
	z += amount;
	w += amount;
	return *this;
}

Vector4& Vector4::operator-=(const Vector4& other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	w -= other.w;
	return *this;
}

Vector4& Vector4::operator-=(float amount) {
	x -= amount;
	y -= amount;
	z -= amount;
	w -= amount;
	return *this;
}

Vector4& Vector4::operator*=(float scale) {
	x *= scale;
	y *= scale;
	z *= scale;
	w *= scale;
	return *this;
}

Vector4& Vector4::operator/=(float scale) {
	x /= scale;
	y /= scale;
	z /= scale;
	w /= scale;
	return *this;
}


float Vector4::sqrmagnitude() const {
	return x*x + y*y + z*z + w*w;
}

float Vector4::magnitude() const {
    return sqrt(x*x + y*y + z*z + w*w);
}

const Vector4 Vector4::normalize() const {
    Vector4 ret;
    float mag = magnitude();
	
    if(mag != 0.0f) {
        ret.x = x / mag;
        ret.y = y / mag;
		ret.z = z / mag;
		ret.w = w / mag;
    }
	
    return ret;
}

Vector4& Vector4::inormalize() {
    float mag = magnitude();
	
    if(mag != 0.0f) {
        x /= mag;
        y /= mag;
		z /= mag;
		w /= mag;
    }
	
    return *this;
}

float Vector4::sqrdistance(const Vector4& other) const {
	float dx = other.x - x;
	float dy = other.y - y;
	float dz = other.z - z;
	float dw = other.w - w;
	return dx*dx + dy*dy + dz*dz + dw*dw;
}

float Vector4::distance(const Vector4& other) const {
	float dx = other.x - x;
	float dy = other.y - y;
	float dz = other.z - z;
	float dw = other.w - w;
	return sqrt(dx*dx + dy*dy + dz*dz + dw*dw);
}

float Vector4::dot(const Vector4& other) const {
	return x * other.x + y * other.y + z * other.z + w * other.w;
}


const Vector4 sge::operator+(const Vector4& vec, const Vector4& other) {
	Vector4 ret;
	ret.x = vec.x + other.x;
	ret.y = vec.y + other.y;
	ret.z = vec.z + other.z;
	ret.w = vec.w + other.w;
	return ret;
}

const Vector4 sge::operator+(const Vector4& vec, float amount) {
	Vector4 ret;
	ret.x = vec.x + amount;
	ret.y = vec.y + amount;
	ret.z = vec.z + amount;
	ret.w = vec.w + amount;
	return ret;
}

const Vector4 sge::operator+(float amount, const Vector4& vec) {
	Vector4 ret;
	ret.x = vec.x + amount;
	ret.y = vec.y + amount;
	ret.z = vec.z + amount;
	ret.w = vec.w + amount;
	return ret;
}

const Vector4 sge::operator-(const Vector4& vec) {
	Vector4 ret;
	ret.x = -vec.x;
	ret.y = -vec.y;
	ret.z = -vec.z;
	ret.w = -vec.w;
	return ret;
}

const Vector4 sge::operator-(const Vector4& vec, const Vector4& other) {
	Vector4 ret;
	ret.x = vec.x - other.x;
	ret.y = vec.y - other.y;
	ret.z = vec.z - other.z;
	ret.w = vec.w - other.w;
	return ret;
}

const Vector4 sge::operator-(const Vector4& vec, float amount) {
	Vector4 ret;
	ret.x = vec.x - amount;
	ret.y = vec.y - amount;
	ret.z = vec.z - amount;
	ret.w = vec.w - amount;
	return ret;
}

const Vector4 sge::operator-(float amount, const Vector4& vec) {
	Vector4 ret;
	ret.x = amount - vec.x;
	ret.y = amount - vec.y;
	ret.z = amount - vec.z;
	ret.w = amount - vec.w;
	return ret;
}

const Vector4 sge::operator*(const Vector4& vec, float scale) {
	Vector4 ret;
	ret.x = vec.x * scale;
	ret.y = vec.y * scale;
	ret.z = vec.z * scale;
	ret.w = vec.w * scale;
	return ret;
}

const Vector4 sge::operator*(float scale, const Vector4& vec) {
	Vector4 ret;
	ret.x = vec.x * scale;
	ret.y = vec.y * scale;
	ret.z = vec.z * scale;
	ret.w = vec.w * scale;
	return ret;
}

const Vector4 sge::operator/(const Vector4& vec, float scale) {
	Vector4 ret;
	ret.x = vec.x / scale;
	ret.y = vec.y / scale;
	ret.z = vec.z / scale;
	ret.w = vec.w / scale;
	return ret;
}


std::ostream& sge::operator<<(std::ostream& stream, const Vector4& vec) {
	std::stringstream ss;
	ss << "(" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ")";
	stream << ss.str();
	return stream;
}

