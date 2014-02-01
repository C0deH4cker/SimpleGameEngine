//
//  Vector2.h
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/7/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#ifndef _SGE_VECTOR2_H_
#define _SGE_VECTOR2_H_

#include <ostream>


namespace sge {
	/*! A two-dimensional vector. */
	struct Vector2 {
		/*! The components of the vector. */
		float x, y;
		
		/*! Constructs a zero vector. */
		Vector2();
		
		/*! Constructs a vector with the given components.
		 @param x The x coordinate of the vector.
		 @param y The y coordinate of the vector.
		 */
		Vector2(float x, float y);
		
		/*! Constructs a vector with both components set to `value`.
		 @param value The value each component is initialized to.
		 */
		Vector2(float value);
		
		~Vector2();
		
		// Assignment
		Vector2& operator=(const Vector2& vec);
		
		// In-place arithmetic
		Vector2& operator+=(const Vector2& vec);
		Vector2& operator+=(float amount);
		Vector2& operator-=(const Vector2& vec);
		Vector2& operator-=(float amount);
		Vector2& operator*=(float scale);
		Vector2& operator/=(float scale);
		
		/*! Calculates the vector's magnitude, squared. Faster than `magnitude`. */
		float sqrmagnitude() const;
		
		/*! Calculates the vector's magnitude. */
		float magnitude() const;
		
		/*! Returns a unit vector in the same direction as the current one. */
		const Vector2 normalize() const;
		
		/*! Converts this vector to a unit vector, preserving direction. */
		Vector2& inormalize();
		
		/*! Reflects the vector over `normal`.
		 @param normal The vector over which to reflect.
		 */
		Vector2 reflect(const Vector2& normal) const;
		
		/*!
		 Calculates the distance between the vectors, squared.
		 Faster than `distance`.
		 */
		float sqrdistance(const Vector2& other) const;
		
		/*! Calculates the distance between the vectors. */
		float distance(const Vector2& other) const;
		
		/*! Calculates the dot product of the vectors. */
		float dot(const Vector2& other) const;
	};
	
	// Relational operators
	bool operator<(const Vector2& l, const Vector2& r);
	bool operator>(const Vector2& l, const Vector2& r);
	bool operator<=(const Vector2& l, const Vector2& r);
	bool operator>=(const Vector2& l, const Vector2& r);
	bool operator==(const Vector2& l, const Vector2& r);
	bool operator!=(const Vector2& l, const Vector2& r);
	
	bool operator>=(const Vector2& l, float mag);
	bool operator<(const Vector2& l, float mag);
	bool operator>(const Vector2& l, float mag);
	bool operator<=(const Vector2& l, float mag);
	
	bool operator>=(float mag, const Vector2& r);
	bool operator<(float mag, const Vector2& r);
	bool operator>(float mag, const Vector2& r);
	bool operator<=(float mag, const Vector2& r);

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

	/*! Prints `vec` in the format "(x, y)" to `stream`. */
	std::ostream& operator<<(std::ostream& stream, const Vector2& vec);
}

#endif /* _SGE_VECTOR2_H_ */
