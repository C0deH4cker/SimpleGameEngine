//
//  Matrix4.h
//  SimpleGameEngine
//
//  Created by Josh Huelsman on 1/20/14.
//  Copyright (c) 2014 Josh Huelsman <joshuahuelsman@gmail.com>. All rights reserved.
//

#ifndef MATRIX4_H
#define MATRIX4_H

#include <stdint.h>

namespace sge {
	struct Matrix4
	{
		static const Matrix4 Identity;

		float m00, m01, m02, m03;
		float m10, m11, m12, m13;
		float m20, m21, m22, m23;
		float m30, m31, m32, m33;

		Matrix4();
		~Matrix4();

		float& operator[](uint8_t);
		float operator[](uint8_t) const;

		///@return a new 4x4 identity matrix.
		static Matrix4& identity();

	};
}



#endif
