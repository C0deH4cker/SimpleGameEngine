//
//  Vector3.h
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/7/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#pragma once

#include <ostream>


namespace sge {
	struct Vector3 {
		float x, y, z;
		
		Vector3();
		Vector3(float x, float y, float z);
		Vector3(float value);
		~Vector3();
		
		// Assignment
		Vector3& operator=(const Vector3& vec);
		
		// Relational operators
		bool operator<(const Vector3& vec) const;
		bool operator>(const Vector3& vec) const;
		bool operator<=(const Vector3& vec) const;
		bool operator>=(const Vector3& vec) const;
		bool operator==(const Vector3& vec) const;
		bool operator!=(const Vector3& vec) const;
		
		bool operator>=(float mag) const;
		bool operator<(float mag) const;
		bool operator>(float mag) const;
		bool operator<=(float mag) const;
		
		// In-place arithmetic
		Vector3& operator+=(const Vector3& vec);
		Vector3& operator+=(float amount);
		Vector3& operator-=(const Vector3& vec);
		Vector3& operator-=(float amount);
		Vector3& operator*=(float scale);
		Vector3& operator/=(float scale);
		
		// Vector operations
		float sqrmagnitude() const;
		float magnitude() const;
		const Vector3 normalize() const;
		Vector3& inormalize();
		
		float sqrdistance(const Vector3& other) const;
		float distance(const Vector3& other) const;
		float dot(const Vector3& other) const;
	};

	// Arithmetic
	const Vector3 operator+(const Vector3& vec, const Vector3& other);
	const Vector3 operator+(const Vector3& vec, float amount);
	const Vector3 operator+(float amount, const Vector3& vec);
	const Vector3 operator-(const Vector3& vec);
	const Vector3 operator-(const Vector3& vec, const Vector3& other);
	const Vector3 operator-(const Vector3& vec, float amount);
	const Vector3 operator-(float amount, const Vector3& vec);
	const Vector3 operator*(const Vector3& vec, float scale);
	const Vector3 operator*(float scale, const Vector3& vec);
	const Vector3 operator/(const Vector3& vec, float scale);

	// Stream insertion
	std::ostream& operator<<(std::ostream& stream, const Vector3& vec);
}

