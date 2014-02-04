//
//  Vector4.h
//  SimpleGameEngine
//
//  Created by Josh Huelsman on 1/23/14.
//  Copyright (c) 2014 Josh Huelsman <joshuahuelsman@gmail.com>. All rights reserved.
//

#ifndef VECTOR4
#define VECTOR4

#include <ostream>
#include "Vector3.h"

namespace sge {
	struct Vector4 {
		float x, y, z, w;
		
		Vector4();
		Vector4(float x, float y, float z, float w=1.0);
		Vector4(const Vector3& vec, float w=1.0);
		Vector4(float value);
		~Vector4();
		
		// Assignment
		Vector4& operator=(const Vector4& vec);
		
		// Relational operators
		bool operator<(const Vector4& vec) const;
		bool operator>(const Vector4& vec) const;
		bool operator<=(const Vector4& vec) const;
		bool operator>=(const Vector4& vec) const;
		bool operator==(const Vector4& vec) const;
		bool operator!=(const Vector4& vec) const;
		
		bool operator>=(float mag) const;
		bool operator<(float mag) const;
		bool operator>(float mag) const;
		bool operator<=(float mag) const;
		
		// In-place arithmetic
		Vector4& operator+=(const Vector4& vec);
		Vector4& operator+=(float amount);
		Vector4& operator-=(const Vector4& vec);
		Vector4& operator-=(float amount);
		Vector4& operator*=(float scale);
		Vector4& operator/=(float scale);
		
		// Vector operations
		float sqrmagnitude() const;
		float magnitude() const;
		const Vector4 normalize() const;
		Vector4& inormalize();
		
		float sqrdistance(const Vector4& other) const;
		float distance(const Vector4& other) const;
		float dot(const Vector4& other) const;
	};

	// Arithmetic
	const Vector4 operator+(const Vector4& vec, const Vector4& other);
	const Vector4 operator+(const Vector4& vec, float amount);
	const Vector4 operator+(float amount, const Vector4& vec);
	const Vector4 operator-(const Vector4& vec);
	const Vector4 operator-(const Vector4& vec, const Vector4& other);
	const Vector4 operator-(const Vector4& vec, float amount);
	const Vector4 operator-(float amount, const Vector4& vec);
	const Vector4 operator*(const Vector4& vec, float scale);
	const Vector4 operator*(float scale, const Vector4& vec);
	const Vector4 operator/(const Vector4& vec, float scale);

	// Stream insertion
	std::ostream& operator<<(std::ostream& stream, const Vector4& vec);
}

#endif
