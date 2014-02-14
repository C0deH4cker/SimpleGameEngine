//
//  Matrix4.cpp
//  SimpleGameEngine
//
//  Created by C0deH4cker on 2/3/14.
//  Copyright (c) 2014 C0deH4cker. All rights reserved.
//

#include "Matrix4.h"
#include <stdexcept>
#include <math.h>


using namespace sge;

const Matrix4 Matrix4::identity = Matrix4(1.0f, 0.0f, 0.0f, 0.0f,
                                       0.0f, 1.0f, 0.0f, 0.0f,
                                       0.0f, 0.0f, 1.0f, 0.0f,
                                       0.0f, 0.0f, 0.0f, 1.0f);

Matrix4::Matrix4(float m11, float m12, float m13, float m14,
			   float m21, float m22, float m23, float m24,
			   float m31, float m32, float m33, float m34,
			   float m41, float m42, float m43, float m44)
: m11(m11), m12(m12), m13(m13), m14(m14),
  m21(m21), m22(m22), m23(m23), m24(m24),
  m31(m31), m32(m32), m33(m33), m34(m34),
  m41(m41), m42(m42), m43(m43), m44(m44) {}

Matrix4::Matrix4(const float cells[])
: m11(cells[0]), m12(cells[1]), m13(cells[2]), m14(cells[3]),
  m21(cells[4]), m22(cells[5]), m23(cells[6]), m24(cells[7]),
  m31(cells[8]), m32(cells[9]), m33(cells[10]), m34(cells[11]),
  m41(cells[12]), m42(cells[13]), m43(cells[14]), m44(cells[15]) {}

Matrix4::Matrix4(float scalar)
: m11(scalar), m12(scalar), m13(scalar), m14(scalar),
  m21(scalar), m22(scalar), m23(scalar), m24(scalar),
  m31(scalar), m32(scalar), m33(scalar), m34(scalar),
  m41(scalar), m42(scalar), m43(scalar), m44(scalar) {}

Matrix4::Matrix4(const Matrix4& other)
: m11(other.m11), m12(other.m12), m13(other.m13), m14(other.m14),
  m21(other.m21), m22(other.m22), m23(other.m23), m24(other.m24),
  m31(other.m31), m32(other.m32), m33(other.m33), m34(other.m34),
  m41(other.m41), m42(other.m42), m43(other.m43), m44(other.m44) {}

Matrix4::Matrix4()
: Matrix4(identity) {}

Matrix4 Matrix4::createRotationX(float radians) {
	Matrix4 ret(identity);
	
	float val1 = cosf(radians);
	float val2 = sinf(radians);
	
	ret.m22 = val1;
	ret.m23 = val2;
	ret.m32 = -val2;
	ret.m33 = val1;
	
	return ret;
}

Matrix4 Matrix4::createRotationY(float radians) {
	Matrix4 ret(identity);
	
	float val1 = cosf(radians);
	float val2 = sinf(radians);
	
	ret.m11 = val1;
	ret.m13 = -val2;
	ret.m31 = val2;
	ret.m33 = val1;
	
	return ret;
}

Matrix4 Matrix4::createRotationZ(float radians) {
	Matrix4 ret(identity);
	
	float val1 = cosf(radians);
	float val2 = sinf(radians);
	
	ret.m11 = val1;
	ret.m12 = val2;
	ret.m21 = -val2;
	ret.m22 = val1;
	
	return ret;
}

Matrix4 Matrix4::createScale(float xscale, float yscale, float zscale) {
	Matrix4 ret(0.0f);
	
	ret.m11 = xscale;
	ret.m22 = yscale;
	ret.m33 = zscale;
	ret.m44 = 1.0f;
	
	return ret;
}

Matrix4 Matrix4::createScale(float scale) {
	Matrix4 ret(0.0f);
	
	ret.m11 = ret.m22 = ret.m33 = scale;
	ret.m44 = 1.0f;
	
	return ret;
}


Matrix4& Matrix4::operator=(const Matrix4& other) {
	m11 = other.m11;
	m12 = other.m12;
	m13 = other.m13;
	m14 = other.m14;
	m21 = other.m21;
	m22 = other.m22;
	m23 = other.m23;
	m24 = other.m24;
	m31 = other.m31;
	m32 = other.m32;
	m33 = other.m33;
	m34 = other.m34;
	m41 = other.m41;
	m42 = other.m42;
	m43 = other.m43;
	m44 = other.m44;
	return *this;
}

Matrix4& Matrix4::operator+=(const Matrix4& other) {
	m11 += other.m11;
	m12 += other.m12;
	m13 += other.m13;
	m14 += other.m14;
	m21 += other.m21;
	m22 += other.m22;
	m23 += other.m23;
	m24 += other.m24;
	m31 += other.m31;
	m32 += other.m32;
	m33 += other.m33;
	m34 += other.m34;
	m41 += other.m41;
	m42 += other.m42;
	m43 += other.m43;
	m44 += other.m44;
	return *this;
}

Matrix4& Matrix4::operator+=(float scalar) {
	m11 += scalar;
	m12 += scalar;
	m13 += scalar;
	m14 += scalar;
	m21 += scalar;
	m22 += scalar;
	m23 += scalar;
	m24 += scalar;
	m31 += scalar;
	m32 += scalar;
	m33 += scalar;
	m34 += scalar;
	m41 += scalar;
	m42 += scalar;
	m43 += scalar;
	m44 += scalar;
	return *this;
}

Matrix4& Matrix4::operator-=(const Matrix4& other) {
	m11 -= other.m11;
	m12 -= other.m12;
	m13 -= other.m13;
	m14 -= other.m14;
	m21 -= other.m21;
	m22 -= other.m22;
	m23 -= other.m23;
	m24 -= other.m24;
	m31 -= other.m31;
	m32 -= other.m32;
	m33 -= other.m33;
	m34 -= other.m34;
	m41 -= other.m41;
	m42 -= other.m42;
	m43 -= other.m43;
	m44 -= other.m44;
	return *this;
}

Matrix4& Matrix4::operator-=(float scalar) {
	m11 -= scalar;
	m12 -= scalar;
	m13 -= scalar;
	m14 -= scalar;
	m21 -= scalar;
	m22 -= scalar;
	m23 -= scalar;
	m24 -= scalar;
	m31 -= scalar;
	m32 -= scalar;
	m33 -= scalar;
	m34 -= scalar;
	m41 -= scalar;
	m42 -= scalar;
	m43 -= scalar;
	m44 -= scalar;
	return *this;
}

Matrix4& Matrix4::operator*=(const Matrix4& other) {
	float m_11 = (m11 * other.m11) + (m12 * other.m21) + (m13 * other.m31) + (m14 * other.m41);
	float m_12 = (m11 * other.m12) + (m12 * other.m22) + (m13 * other.m32) + (m14 * other.m42);
	float m_13 = (m11 * other.m13) + (m12 * other.m23) + (m13 * other.m33) + (m14 * other.m43);
	float m_14 = (m11 * other.m14) + (m12 * other.m24) + (m13 * other.m34) + (m14 * other.m44);
	float m_21 = (m21 * other.m11) + (m22 * other.m21) + (m23 * other.m31) + (m24 * other.m41);
	float m_22 = (m21 * other.m12) + (m22 * other.m22) + (m23 * other.m32) + (m24 * other.m42);
	float m_23 = (m21 * other.m13) + (m22 * other.m23) + (m23 * other.m33) + (m24 * other.m43);
	float m_24 = (m21 * other.m14) + (m22 * other.m24) + (m23 * other.m34) + (m24 * other.m44);
	float m_31 = (m31 * other.m11) + (m32 * other.m21) + (m33 * other.m31) + (m34 * other.m41);
	float m_32 = (m31 * other.m12) + (m32 * other.m22) + (m33 * other.m32) + (m34 * other.m42);
	float m_33 = (m31 * other.m13) + (m32 * other.m23) + (m33 * other.m33) + (m34 * other.m43);
	float m_34 = (m31 * other.m14) + (m32 * other.m24) + (m33 * other.m34) + (m34 * other.m44);
	float m_41 = (m41 * other.m11) + (m42 * other.m21) + (m43 * other.m31) + (m44 * other.m41);
	float m_42 = (m41 * other.m12) + (m42 * other.m22) + (m43 * other.m32) + (m44 * other.m42);
	float m_43 = (m41 * other.m13) + (m42 * other.m23) + (m43 * other.m33) + (m44 * other.m43);
	float m_44 = (m41 * other.m14) + (m42 * other.m24) + (m43 * other.m34) + (m44 * other.m44);
	
	m11 = m_11;
	m12 = m_12;
	m13 = m_13;
	m14 = m_14;
	m21 = m_21;
	m22 = m_22;
	m23 = m_23;
	m24 = m_24;
	m31 = m_31;
	m32 = m_32;
	m33 = m_33;
	m34 = m_34;
	m41 = m_41;
	m42 = m_42;
	m43 = m_43;
	m44 = m_44;
	
	return *this;
}

Matrix4& Matrix4::operator*=(float scalar) {
	m11 *= scalar;
	m12 *= scalar;
	m13 *= scalar;
	m14 *= scalar;
	m21 *= scalar;
	m22 *= scalar;
	m23 *= scalar;
	m24 *= scalar;
	m31 *= scalar;
	m32 *= scalar;
	m33 *= scalar;
	m34 *= scalar;
	m41 *= scalar;
	m42 *= scalar;
	m43 *= scalar;
	m44 *= scalar;
	return *this;
}

Matrix4& Matrix4::operator/=(const Matrix4& other) {
	return *this *= other.inverse();
}

Matrix4& Matrix4::operator/=(float scalar) {
	float factor = 1.0f / scalar;
	
	m11 *= factor;
	m12 *= factor;
	m13 *= factor;
	m14 *= factor;
	m21 *= factor;
	m22 *= factor;
	m23 *= factor;
	m24 *= factor;
	m31 *= factor;
	m32 *= factor;
	m33 *= factor;
	m34 *= factor;
	m41 *= factor;
	m42 *= factor;
	m43 *= factor;
	m44 *= factor;
	return *this;
}

float& Matrix4::operator[](int index) {
	switch(index) {
		case 0: return m11;
		case 1: return m12;
		case 2: return m13;
		case 3: return m14;
		case 4: return m21;
		case 5: return m22;
		case 6: return m23;
		case 7: return m24;
		case 8: return m31;
		case 9: return m32;
		case 10: return m33;
		case 11: return m34;
		case 12: return m41;
		case 13: return m42;
		case 14: return m43;
		case 15: return m44;
		
		default:
			throw std::out_of_range("Matrix4 index out of range.");
	}
}

float Matrix4::operator[](int index) const {
	switch(index) {
		case 0: return m11;
		case 1: return m12;
		case 2: return m13;
		case 3: return m14;
		case 4: return m21;
		case 5: return m22;
		case 6: return m23;
		case 7: return m24;
		case 8: return m31;
		case 9: return m32;
		case 10: return m33;
		case 11: return m34;
		case 12: return m41;
		case 13: return m42;
		case 14: return m43;
		case 15: return m44;
			
		default:
			throw std::out_of_range("Matrix4 index out of range.");
	}
}

float& Matrix4::operator()(int row, int col) {
	switch(row) {
		case 0: switch(col) {
			case 0: return m11;
			case 1: return m12;
			case 2: return m13;
			case 3: return m14;
			default:
				throw std::out_of_range("Matrix4 column out of range.");
		}
		case 1: switch(col) {
			case 0: return m21;
			case 1: return m22;
			case 2: return m23;
			case 3: return m24;
			default:
				throw std::out_of_range("Matrix4 column out of range.");
		}
		case 2: switch(col) {
			case 0: return m31;
			case 1: return m32;
			case 2: return m33;
			case 3: return m34;
			default:
				throw std::out_of_range("Matrix4 column out of range.");
		}
		case 3: switch(col) {
			case 0: return m41;
			case 1: return m42;
			case 2: return m43;
			case 3: return m44;
			default:
				throw std::out_of_range("Matrix4 column out of range.");
		}
		
		default:
			throw std::out_of_range("Matrix4 row out of range.");
	}
}

float Matrix4::operator()(int row, int col) const {
	switch(row) {
		case 0: switch(col) {
			case 0: return m11;
			case 1: return m12;
			case 2: return m13;
			case 3: return m14;
			default:
				throw std::out_of_range("Matrix4 column out of range.");
		}
		case 1: switch(col) {
			case 0: return m21;
			case 1: return m22;
			case 2: return m23;
			case 3: return m24;
			default:
				throw std::out_of_range("Matrix4 column out of range.");
		}
		case 2: switch(col) {
			case 0: return m31;
			case 1: return m32;
			case 2: return m33;
			case 3: return m34;
			default:
				throw std::out_of_range("Matrix4 column out of range.");
		}
		case 3: switch(col) {
			case 0: return m41;
			case 1: return m42;
			case 2: return m43;
			case 3: return m44;
			default:
				throw std::out_of_range("Matrix4 column out of range.");
		}
			
		default:
			throw std::out_of_range("Matrix4 row out of range.");
	}
}

Matrix4 Matrix4::operator-() const {
	return Matrix4(-m11, -m12, -m13, -m14,
	              -m21, -m22, -m23, -m24,
	              -m31, -m32, -m33, -m34,
	              -m41, -m42, -m43, -m44);
}

/* Based on http://stackoverflow.com/a/1148405/1344461 */
bool Matrix4::invert() {
	float inv11 = m22 * m33 * m44 -
	m22 * m34 * m43 -
	m32 * m23 * m44 +
	m32 * m24 * m43 +
	m42 * m23 * m34 -
	m42 * m24 * m33;
	
	float inv21 = -m21 * m33 * m44 +
	m21 * m34 * m43 +
	m31 * m23 * m44 -
	m31 * m24 * m43 -
	m41 * m23 * m34 +
	m41 * m24 * m33;
	
	float inv31 = m21 * m32 * m44 -
	m21 * m34 * m42 -
	m31 * m22 * m44 +
	m31 * m24 * m42 +
	m41 * m22 * m34 -
	m41 * m24 * m32;
	
	float inv41 = -m21 * m32 * m43 +
	m21 * m33 * m42 +
	m31 * m22 * m43 -
	m31 * m23 * m42 -
	m41 * m22 * m33 +
	m41 * m23 * m32;
	
	float inv12 = -m12 * m33 * m44 +
	m12 * m34 * m43 +
	m32 * m13 * m44 -
	m32 * m14 * m43 -
	m42 * m13 * m34 +
	m42 * m14 * m33;
	
	float inv22 = m11 * m33 * m44 -
	m11 * m34 * m43 -
	m31 * m13 * m44 +
	m31 * m14 * m43 +
	m41 * m13 * m34 -
	m41 * m14 * m33;
	
	float inv32 = -m11 * m32 * m44 +
	m11 * m34 * m42 +
	m31 * m12 * m44 -
	m31 * m14 * m42 -
	m41 * m12 * m34 +
	m41 * m14 * m32;
	
	float inv42 = m11 * m32 * m43 -
	m11 * m33 * m42 -
	m31 * m12 * m43 +
	m31 * m13 * m42 +
	m41 * m12 * m33 -
	m41 * m13 * m32;
	
	float inv13 = m12 * m23 * m44 -
	m12 * m24 * m43 -
	m22 * m13 * m44 +
	m22 * m14 * m43 +
	m42 * m13 * m24 -
	m42 * m14 * m23;
	
	float inv23 = -m11 * m23 * m44 +
	m11 * m24 * m43 +
	m21 * m13 * m44 -
	m21 * m14 * m43 -
	m41 * m13 * m24 +
	m41 * m14 * m23;
	
	float inv33 = m11 * m22 * m44 -
	m11 * m24 * m42 -
	m21 * m12 * m44 +
	m21 * m14 * m42 +
	m41 * m12 * m24 -
	m41 * m14 * m22;
	
	float inv43 = -m11 * m22 * m43 +
	m11 * m23 * m42 +
	m21 * m12 * m43 -
	m21 * m13 * m42 -
	m41 * m12 * m23 +
	m41 * m13 * m22;
	
	float inv14 = -m12 * m23 * m34 +
	m12 * m24 * m33 +
	m22 * m13 * m34 -
	m22 * m14 * m33 -
	m32 * m13 * m24 +
	m32 * m14 * m23;
	
	float inv24 = m11 * m23 * m34 -
	m11 * m24 * m33 -
	m21 * m13 * m34 +
	m21 * m14 * m33 +
	m31 * m13 * m24 -
	m31 * m14 * m23;
	
	float inv34 = -m11 * m22 * m34 +
	m11 * m24 * m32 +
	m21 * m12 * m34 -
	m21 * m14 * m32 -
	m31 * m12 * m24 +
	m31 * m14 * m22;
	
	float inv44 = m11 * m22 * m33 -
	m11 * m23 * m32 -
	m21 * m12 * m33 +
	m21 * m13 * m32 +
	m31 * m12 * m23 -
	m31 * m13 * m22;
	
	float det = m11 * inv11 + m12 * inv21 + m13 * inv31 + m14 * inv41;
	
	if(det == 0.0f)
		return false;
	
	det = 1.0f / det;
	
	m11 = det * inv11;
	m12 = det * inv12;
	m13 = det * inv13;
	m14 = det * inv14;
	m21 = det * inv21;
	m22 = det * inv22;
	m23 = det * inv23;
	m24 = det * inv24;
	m31 = det * inv31;
	m32 = det * inv32;
	m33 = det * inv33;
	m34 = det * inv34;
	m41 = det * inv41;
	m42 = det * inv42;
	m43 = det * inv43;
	m44 = det * inv44;
	
	return true;
}

Matrix4 Matrix4::inverse() const {
	Matrix4 ret(*this);
	if(ret.invert())
		return ret;
	
	throw std::logic_error("Unable to invert Matrix4.");
}

Matrix4 Matrix4::transpose() const {
	return Matrix4(m11, m21, m31, m41,
	              m12, m22, m32, m42,
	              m13, m23, m33, m43,
	              m14, m24, m34, m44);
}

float Matrix4::determinant() const {
	return m41 * m32 * m23 * m14 - m31 * m42 * m23 * m14 -
	       m41 * m22 * m33 * m14 + m21 * m42 * m33 * m14 +
	       m31 * m22 * m43 * m14 - m21 * m32 * m43 * m14 -
	       m41 * m32 * m13 * m24 + m31 * m42 * m13 * m24 +
	       m41 * m12 * m33 * m24 - m11 * m42 * m33 * m24 -
	       m31 * m12 * m43 * m24 + m11 * m32 * m43 * m24 +
	       m41 * m22 * m13 * m34 - m21 * m42 * m13 * m34 -
	       m41 * m12 * m23 * m34 + m11 * m42 * m23 * m34 +
	       m21 * m12 * m43 * m34 - m11 * m22 * m43 * m34 -
	       m31 * m22 * m13 * m44 + m21 * m32 * m13 * m44 +
	       m31 * m12 * m23 * m44 - m11 * m32 * m23 * m44 -
	       m21 * m12 * m33 * m44 + m11 * m22 * m33 * m44;
}


bool sge::operator==(const Matrix4& a, const Matrix4& b) {
	return a.m11 == b.m11 && a.m12 == b.m12 && a.m13 == b.m13 && a.m14 == b.m14
	    && a.m21 == b.m21 && a.m22 == b.m22 && a.m23 == b.m23 && a.m24 == b.m24
	    && a.m31 == b.m31 && a.m32 == b.m32 && a.m33 == b.m33 && a.m34 == b.m34
	    && a.m41 == b.m41 && a.m42 == b.m42 && a.m43 == b.m43 && a.m44 == b.m44;
}

bool sge::operator!=(const Matrix4& a, const Matrix4& b) {
	return !(a == b);
}

Matrix4 sge::operator+(const Matrix4& a, const Matrix4& b) {
	return Matrix4(a.m11 + b.m11, a.m12 + b.m12, a.m13 + b.m13, a.m14 + b.m14,
	              a.m21 + b.m21, a.m22 + b.m22, a.m23 + b.m23, a.m24 + b.m24,
	              a.m31 + b.m31, a.m32 + b.m32, a.m33 + b.m33, a.m34 + b.m34,
	              a.m41 + b.m41, a.m42 + b.m42, a.m43 + b.m43, a.m44 + b.m44);
}

Matrix4 sge::operator+(const Matrix4& a, float b) {
	return Matrix4(a.m11 + b, a.m12 + b, a.m13 + b, a.m14 + b,
	              a.m21 + b, a.m22 + b, a.m23 + b, a.m24 + b,
	              a.m31 + b, a.m32 + b, a.m33 + b, a.m34 + b,
	              a.m41 + b, a.m42 + b, a.m43 + b, a.m44 + b);
}

Matrix4 sge::operator+(float a, const Matrix4&b) {
	return Matrix4(a + b.m11, a + b.m12, a + b.m13, a + b.m14,
	              a + b.m21, a + b.m22, a + b.m23, a + b.m24,
	              a + b.m31, a + b.m32, a + b.m33, a + b.m34,
	              a + b.m41, a + b.m42, a + b.m43, a + b.m44);
}

Matrix4 sge::operator-(const Matrix4& a, const Matrix4& b) {
	return Matrix4(a.m11 - b.m11, a.m12 - b.m12, a.m13 - b.m13, a.m14 - b.m14,
	              a.m21 - b.m21, a.m22 - b.m22, a.m23 - b.m23, a.m24 - b.m24,
	              a.m31 - b.m31, a.m32 - b.m32, a.m33 - b.m33, a.m34 - b.m34,
	              a.m41 - b.m41, a.m42 - b.m42, a.m43 - b.m43, a.m44 - b.m44);
}

Matrix4 sge::operator-(const Matrix4&a, float b) {
	return Matrix4(a.m11 - b, a.m12 - b, a.m13 - b, a.m14 - b,
	              a.m21 - b, a.m22 - b, a.m23 - b, a.m24 - b,
	              a.m31 - b, a.m32 - b, a.m33 - b, a.m34 - b,
	              a.m41 - b, a.m42 - b, a.m43 - b, a.m44 - b);
}

Matrix4 sge::operator-(float a, const Matrix4&b) {
	return Matrix4(a - b.m11, a - b.m12, a - b.m13, a - b.m14,
	              a - b.m21, a - b.m22, a - b.m23, a - b.m24,
	              a - b.m31, a - b.m32, a - b.m33, a - b.m34,
	              a - b.m41, a - b.m42, a - b.m43, a - b.m44);
}

Matrix4 sge::operator*(const Matrix4& a, const Matrix4& b) {
	Matrix4 ret(a);
	ret *= b;
	return ret;
}

Matrix4 sge::operator*(const Matrix4&a, float b) {
	return Matrix4(a.m11 * b, a.m12 * b, a.m13 * b, a.m14 * b,
	              a.m21 * b, a.m22 * b, a.m23 * b, a.m24 * b,
	              a.m31 * b, a.m32 * b, a.m33 * b, a.m34 * b,
	              a.m41 * b, a.m42 * b, a.m43 * b, a.m44 * b);
}

Matrix4 sge::operator*(float a, const Matrix4&b) {
	return Matrix4(a * b.m11, a * b.m12, a * b.m13, a * b.m14,
	              a * b.m21, a * b.m22, a * b.m23, a * b.m24,
	              a * b.m31, a * b.m32, a * b.m33, a * b.m34,
	              a * b.m41, a * b.m42, a * b.m43, a * b.m44);
}

Matrix4 sge::operator/(const Matrix4& a, const Matrix4& b) {
	Matrix4 ret(a);
	ret /= b;
	return ret;
}

Matrix4 sge::operator/(const Matrix4&a, float b) {
	float n = 1.0f / b;
	
	return Matrix4(a.m11 * n, a.m12 * n, a.m13 * n, a.m14 * n,
	              a.m21 * n, a.m22 * n, a.m23 * n, a.m24 * n,
	              a.m31 * n, a.m32 * n, a.m33 * n, a.m34 * n,
	              a.m41 * n, a.m42 * n, a.m43 * n, a.m44 * n);
}

Matrix4 sge::operator/(float a, const Matrix4&b) {
	Matrix4 m(b.inverse());
	
	return Matrix4(a * m.m11, a * m.m12, a * m.m13, a * m.m14,
	              a * m.m21, a * m.m22, a * m.m23, a * m.m24,
	              a * m.m31, a * m.m32, a * m.m33, a * m.m34,
	              a * m.m41, a * m.m42, a * m.m43, a * m.m44);
}

