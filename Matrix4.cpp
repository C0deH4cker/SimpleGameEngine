//
//  Matrix4.cpp
//  SimpleGameEngine
//
//  Created by Josh Huelsman on 1/20/14.
//  Copyright (c) 2014 Josh Huelsman <joshuahuelsman@gmail.com>. All rights reserved.
//

#include <stdexcept>
#include <sstream>
#include "Matrix4.h"

using namespace sge;

Matrix4::Matrix4() {

}

Matrix4::~Matrix4() {

}

float& Matrix4::operator[](uint8_t i) {
	switch(i) {
		case 0:
			return m00;
		case 1:
			return m01;
		case 2:
			return m02;
		case 3:
			return m03;
		case 4:
			return m10;
		case 5:
			return m11;
		case 6:
			return m12;
		case 7:
			return m13;
		case 8:
			return m20;
		case 9:
			return m21;
		case 10:
			return m22;
		case 11:
			return m23;
		case 12:
			return m30;
		case 13:
			return m31;
		case 14:
			return m32;
		case 15:
			return m33;
		default:
			std::stringstream ss;
			ss << "Matrix[] index out of bounds: " << (uint16_t)i;
			throw std::runtime_error(ss.str());
	}
}

Matrix4& Matrix4::identity() {
	Matrix4* mat = new Matrix4();
	for (uint8_t i = 0; i < 16; ++i)
	{
		(*mat)[i] = 0.0;
	}

	mat->m00 = 1.0f;
	mat->m11 = 1.0f;
	mat->m22 = 1.0f;
	mat->m33 = 1.0f;

	return *mat;
}

