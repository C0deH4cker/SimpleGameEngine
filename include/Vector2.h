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
#include "sge_depends.h"
#include "Matrix.h"


namespace sge {
	/*! A two-dimensional vector. */
	struct Vector2 {
		/*! The components of the vector. */
		float x, y;
		
		/*! Constructs a vector with both components set to `scalar`.
		 @param scalar The value each component is initialized to.
		 */
		Vector2(float scalar=0.0f);
		
		/*! Constructs a vector with the given components.
		 @param x The x coordinate of the vector.
		 @param y The y coordinate of the vector.
		 */
		Vector2(float x, float y);
		
		/*! Copying constructor.
		 @param other Vector to copy.
		 */
		Vector2(const Vector2& other);
		
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
		
		// Negation
		Vector2 operator-() const;
		
		/*! Calculates the vector's magnitude, squared
		 @note Faster than `magnitude`.
		 */
		float sqrmagnitude() const;
		
		/*! Calculates the vector's magnitude. */
		float magnitude() const;
		
		/*! Calculates the angle between two vectors. */
		float angle(const Vector2& other) const;
		
		/*! Calculates the angle between two normalized vectors.
		 @note Faster than `angle`.
		 */
		float anglenorm(const Vector2& other) const;
		
		/*! Returns a unit vector in the same direction as the current one. */
		const Vector2 normalize() const;
		
		/*! Converts this vector to a unit vector, preserving direction. */
		Vector2& inormalize();
		
		/*! Project the vector along another.
		 @param target Vector to project onto.
		 @return Projected vector.
		 */
		Vector2 project(const Vector2& target) const;
		
		/*! Project the vector along another, in-place.
		 @param target Vector to project onto.
		 @return Reference to modified vector.
		 */
		Vector2& iproject(const Vector2& target);
		
		/*! Reflects the vector over `normal`.
		 @param normal The vector over which to reflect.
		 */
		Vector2 reflect(Vector2 normal) const;
		
		/*! Reflects the vector over `normal` in-place.
		 @param normal The vector over which to reflect.
		 */
		Vector2& ireflect(Vector2 normal);
		
		/*! Rotate the vector around the origin
		 @param radians Angle in radians to rotate.
		 @return New rotated vector.
		 */
		Vector2 rotate(float radians) const;
		
		/*! Rotate the vector around the origin, in-place.
		 @param radians Angle in radians to rotate.
		 @return Reference to modified vector.
		 */
		Vector2& irotate(float radians);
		
		/*!
		 Calculates the distance between the vectors, squared.
		 @note Faster than `distance`.
		 */
		float sqrdistance(const Vector2& other) const;
		
		/*! Calculates the distance between the vectors. */
		float distance(const Vector2& other) const;
		
		/*! Calculates the dot product of the vectors. */
		float dot(const Vector2& other) const;
		
		/*! Transforms the vector using a transformation matrix.
		 @param mat Transformation matrix to apply to the vector.
		 @return Newly transformed vector.
		 */
		Vector2 transform(const Matrix& mat) const;
		
		/*! Transforms the vector in-place using a transformation matrix.
		 @param mat Transformation matrix to apply to the vector.
		 @return Reference to the modified vector.
		 */
		Vector2& itransform(const Matrix& mat);
	} ATTRIB_PACKED;
	
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
	const Vector2 operator-(const Vector2& vec, const Vector2& other);
	const Vector2 operator-(const Vector2& vec, float amount);
	const Vector2 operator-(float amount, const Vector2& vec);
	const Vector2 operator*(const Vector2& a, const Vector2& b);
	const Vector2 operator*(const Vector2& vec, float scale);
	const Vector2 operator*(float scale, const Vector2& vec);
	const Vector2 operator/(const Vector2& a, const Vector2& b);
	const Vector2 operator/(const Vector2& vec, float scale);

	/*! Prints `vec` in the format "(x, y)" to `stream`. */
	std::ostream& operator<<(std::ostream& stream, const Vector2& vec);
}

#endif /* _SGE_VECTOR2_H_ */
