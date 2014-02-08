//
//  Matrix4.h
//  SimpleGameEngine
//
//  Created by C0deH4cker on 2/3/14.
//  Copyright (c) 2014 C0deH4cker. All rights reserved.
//

#ifndef _SGE_MATRIX4_H_
#define _SGE_MATRIX4_H_

#include "sge_depends.h"


namespace sge {
	struct Matrix4 {
		float m11, m12, m13, m14;
		float m21, m22, m23, m24;
		float m31, m32, m33, m34;
		float m41, m42, m43, m44;
		
		const static Matrix4 identity;
		
		Matrix4(float m11, float m12, float m13, float m14,
			   float m21, float m22, float m23, float m24,
			   float m31, float m32, float m33, float m34,
			   float m41, float m42, float m43, float m44);
		Matrix4(const float cells[]);
		Matrix4(float scalar);
		Matrix4(const Matrix4& other);
		Matrix4();
		
		static Matrix4 createRotationX(float radians);
		static Matrix4 createRotationY(float radians);
		static Matrix4 createRotationZ(float radians);
		static Matrix4 createScale(float xscale, float yscale, float zscale);
		static Matrix4 createScale(float scale);
		
		Matrix4& operator=(const Matrix4& other);
		Matrix4& operator+=(const Matrix4& other);
		Matrix4& operator+=(float scalar);
		Matrix4& operator-=(const Matrix4& other);
		Matrix4& operator-=(float scalar);
		Matrix4& operator*=(const Matrix4& other);
		Matrix4& operator*=(float scalar);
		Matrix4& operator/=(const Matrix4& other);
		Matrix4& operator/=(float scalar);
		
		float& operator[](int index);
		float operator[](int index) const;
		
		float& operator()(int row, int col);
		float operator()(int row, int col) const;
		
		Matrix4 operator-() const;
		
		bool invert();
		Matrix4 inverse() const;
		Matrix4 transpose() const;
		float determinant() const;
	};
	
	bool operator==(const Matrix4& a, const Matrix4& b);
	bool operator!=(const Matrix4& a, const Matrix4& b);
	
	Matrix4 operator+(const Matrix4& a, const Matrix4& b);
	Matrix4 operator+(const Matrix4& a, float b);
	Matrix4 operator+(float a, const Matrix4& b);
	Matrix4 operator-(const Matrix4& a, const Matrix4& b);
	Matrix4 operator-(const Matrix4& a, float b);
	Matrix4 operator-(float a, const Matrix4& b);
	Matrix4 operator*(const Matrix4& a, const Matrix4& b);
	Matrix4 operator*(const Matrix4& a, float b);
	Matrix4 operator*(float a, const Matrix4& b);
	Matrix4 operator/(const Matrix4& a, const Matrix4& b);
	Matrix4 operator/(const Matrix4& a, float b);
	Matrix4 operator/(float a, const Matrix4& b);
}


#endif /* _SGE_MATRIX4_H_ */
