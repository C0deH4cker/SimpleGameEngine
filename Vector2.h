//
//  Vector2.h
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/7/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#pragma once

#include <ostream>


namespace sge {
	struct Vector2 {
		float x, y;
		
		Vector2();
		Vector2(float x, float y);
		Vector2(float value);
		~Vector2();
		
		// Assignment
		Vector2& operator=(const Vector2& vec);
		
		// Relational operators
		bool operator<(const Vector2& vec) const;
		bool operator>(const Vector2& vec) const;
		bool operator<=(const Vector2& vec) const;
		bool operator>=(const Vector2& vec) const;
		bool operator==(const Vector2& vec) const;
		bool operator!=(const Vector2& vec) const;
		
		bool operator>=(float mag) const;
		bool operator<(float mag) const;
		bool operator>(float mag) const;
		bool operator<=(float mag) const;
		
		// In-place arithmetic
		Vector2& operator+=(const Vector2& vec);
		Vector2& operator+=(float amount);
		Vector2& operator-=(const Vector2& vec);
		Vector2& operator-=(float amount);
		Vector2& operator*=(float scale);
		Vector2& operator/=(float scale);
		
		// Vector operations
		float sqrmagnitude() const;
		float magnitude() const;
		const Vector2 normalize() const;
		Vector2& inormalize();
		Vector2 reflect(const Vector2& normal) const;
		float sqrdistance(const Vector2& other) const;
		float distance(const Vector2& other) const;
		float dot(const Vector2& other) const;
	};

	// Arithmetic
	const Vector2 operator+(const Vector2& vec, const Vector2& other);
	const Vector2 operator+(const Vector2& vec, float amount);
	const Vector2 operator+(float amount, const Vector2& vec);
	const Vector2 operator-(const Vector2& vec);
	const Vector2 operator-(const Vector2& vec, const Vector2& other);
	const Vector2 operator-(const Vector2& vec, float amount);
	const Vector2 operator-(float amount, const Vector2& vec);
	const Vector2 operator*(const Vector2& vec, float scale);
	const Vector2 operator*(float scale, const Vector2& vec);
	const Vector2 operator/(const Vector2& vec, float scale);

	// Stream insertion
	std::ostream& operator<<(std::ostream& stream, const Vector2& vec);
}

