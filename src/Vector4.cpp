//
//  Vector4.cpp
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/7/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#include "Vector4.h"
#include <math.h>
#include <ostream>
#include <sstream>

using namespace sge;


#pragma mark Constructors and Destructors -

Vector4::Vector4(float scalar)
: Vector4(scalar, scalar, scalar, scalar) {}

Vector4::Vector4(float x, float y, float z, float w)
: x(x), y(y), z(z), w(w) {}

Vector4::Vector4(const Vector4& other)
: x(other.x), y(other.y), z(other.z), w(other.w) {}

Vector4::~Vector4() {}

#pragma mark - Assignment -

Vector4& Vector4::operator=(const Vector4& other) {
	x = other.x;
	y = other.y;
	z = other.z;
	w = other.w;
	return *this;
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
	float factor = 1.0f / scale;
	x *= factor;
	y *= factor;
	z *= factor;
	w *= factor;
	return *this;
}

Vector4 Vector4::operator-() const {
	return Vector4(-x, -y, -z, -w);
}

#pragma mark - Methods -

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
		float factor = 1.0f / mag;
        ret.x = x * factor;
        ret.y = y * factor;
		ret.z = z * factor;
		ret.w = w * factor;
    }
	
    return ret;
}

Vector4& Vector4::inormalize() {
    float mag = magnitude();
	
    if(mag != 0.0f) {
		float factor = 1.0f / mag;
        x *= factor;
        y *= factor;
		z *= factor;
		w *= factor;
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

Vector4 Vector4::transform(const Matrix& mat) const {
	return Vector4(x * mat.m11 + y * mat.m21 + z * mat.m31 + w * mat.m41,
	               x * mat.m12 + y * mat.m22 + z * mat.m32 + w * mat.m42,
	               x * mat.m13 + y * mat.m23 + z * mat.m33 + w * mat.m43,
	               x * mat.m14 + y * mat.m24 + z * mat.m34 + w * mat.m44);
}

Vector4& Vector4::itransform(const Matrix& mat) {
	float nx = x * mat.m11 + y * mat.m21 + z * mat.m31 + w * mat.m41;
	float ny = x * mat.m12 + y * mat.m22 + z * mat.m32 + w * mat.m42;
	float nz = x * mat.m13 + y * mat.m23 + z * mat.m33 + w * mat.m43;
	w = x * mat.m14 + y * mat.m24 + z * mat.m34 + w * mat.m44;
	x = nx;
	y = ny;
	z = nz;
	return *this;
}


#pragma mark - Comparison Operators -

bool sge::operator<(const Vector4& l, const Vector4& r) {
	return l.sqrmagnitude() < r.sqrmagnitude();
}

bool sge::operator>(const Vector4& l, const Vector4& r) {
	return l.sqrmagnitude() > r.sqrmagnitude();
}

bool sge::operator<=(const Vector4& l, const Vector4& r) {
	return l.sqrmagnitude() <= r.sqrmagnitude();
}

bool sge::operator>=(const Vector4& l, const Vector4& r) {
	return l.sqrmagnitude() >= r.sqrmagnitude();
}

bool sge::operator==(const Vector4& l, const Vector4& r) {
	return l.x == r.x && l.y == r.y && l.z == r.z && l.w == r.w;
}

bool sge::operator!=(const Vector4& l, const Vector4& r) {
	return l.x != r.x || l.y != r.y || l.z != r.z || l.w != r.w;
}

// Left side
bool sge::operator<(const Vector4& l, float mag) {
	return l.magnitude() < mag;
}

bool sge::operator>(const Vector4& l, float mag) {
	return l.magnitude() > mag;
}

bool sge::operator<=(const Vector4& l, float mag) {
	return l.magnitude() <= mag;
}

bool sge::operator>=(const Vector4& l, float mag) {
	return l.magnitude() >= mag;
}

// Right side
bool sge::operator<(float mag, const Vector4& r) {
	return mag < r.magnitude();
}

bool sge::operator>(float mag, const Vector4& r) {
	return mag > r.magnitude();
}

bool sge::operator<=(float mag, const Vector4& r) {
	return mag <= r.magnitude();
}

bool sge::operator>=(float mag, const Vector4& r) {
	return mag >= r.magnitude();
}

#pragma mark - Arithmetic -

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
	float factor = 1.0f / scale;
	ret.x = vec.x * factor;
	ret.y = vec.y * factor;
	ret.z = vec.z * factor;
	ret.w = vec.w * factor;
	return ret;
}

#pragma mark - Stream Insertion -

std::ostream& sge::operator<<(std::ostream& stream, const Vector4& vec) {
	std::stringstream ss;
	ss << "(" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ")";
	stream << ss.str();
	return stream;
}

