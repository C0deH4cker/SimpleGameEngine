//
//  Matrix.h
//  SimpleGameEngine
//
//  Created by C0deH4cker on 2/3/14.
//  Copyright (c) 2014 C0deH4cker. All rights reserved.
//

#ifndef _SGE_Matrix_H_
#define _SGE_Matrix_H_

#include "sge_depends.h"


namespace sge {
	struct Matrix {
		float m11, m12, m13, m14;
		float m21, m22, m23, m24;
		float m31, m32, m33, m34;
		float m41, m42, m43, m44;
		
		const static Matrix identity;
		
		Matrix(float m11, float m12, float m13, float m14,
			   float m21, float m22, float m23, float m24,
			   float m31, float m32, float m33, float m34,
			   float m41, float m42, float m43, float m44);
		Matrix(const float cells[]);
		Matrix(float scalar);
		Matrix(const Matrix& other);
		Matrix();
		
		static Matrix createRotationX(float radians);
		static Matrix createRotationY(float radians);
		static Matrix createRotationZ(float radians);
		static Matrix createScale(float xscale, float yscale, float zscale);
		static Matrix createScale(float scale);
		
		Matrix& operator=(const Matrix& other);
		Matrix& operator+=(const Matrix& other);
		Matrix& operator+=(float scalar);
		Matrix& operator-=(const Matrix& other);
		Matrix& operator-=(float scalar);
		Matrix& operator*=(const Matrix& other);
		Matrix& operator*=(float scalar);
		Matrix& operator/=(const Matrix& other);
		Matrix& operator/=(float scalar);
		
		float& operator[](int index);
		float operator[](int index) const;
		
		float& operator()(int row, int col);
		float operator()(int row, int col) const;
		
		Matrix operator-() const;
		
		bool invert();
		Matrix inverse() const;
		Matrix transpose() const;
		float determinant() const;
	};
	
	bool operator==(const Matrix& a, const Matrix& b);
	bool operator!=(const Matrix& a, const Matrix& b);
	
	Matrix operator+(const Matrix& a, const Matrix& b);
	Matrix operator+(const Matrix& a, float b);
	Matrix operator+(float a, const Matrix& b);
	Matrix operator-(const Matrix& a, const Matrix& b);
	Matrix operator-(const Matrix& a, float b);
	Matrix operator-(float a, const Matrix& b);
	Matrix operator*(const Matrix& a, const Matrix& b);
	Matrix operator*(const Matrix& a, float b);
	Matrix operator*(float a, const Matrix& b);
	Matrix operator/(const Matrix& a, const Matrix& b);
	Matrix operator/(const Matrix& a, float b);
	Matrix operator/(float a, const Matrix& b);
}


#endif /* _SGE_Matrix_H_ */
