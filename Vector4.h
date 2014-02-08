//
//  Vector4.h
//  SimpleGameEngine
//
//  Created by C0deH4cker on 2/7/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#ifndef _SGE_VECTOR4_H_
#define _SGE_VECTOR4_H_

#include <ostream>
#include "sge_depends.h"
#include "Matrix4.h"


namespace sge {
	/*! A four-dimensional vector. */
	struct Vector4 {
		/*! The components of the vector. */
		float x, y, z, w;
		
		/*! Constructs a vector with both components set to `scalar`.
		 @param scalar The value each component is initialized to.
		 */
		Vector4(float scalar=0.0f);
		
		/*! Constructs a vector with the given components.
		 @param x The x coordinate of the vector.
		 @param y The y coordinate of the vector.
		 @param z The z coordinate of the vector.
		 @param w The w (4th) coordinate of the vector.
		 */
		Vector4(float x, float y, float z, float w);
		
		/*! Copying constructor.
		 @param other Vector to copy.
		 */
		Vector4(const Vector4& other);
		
		~Vector4();
		
		// Assignment
		Vector4& operator=(const Vector4& vec);
		
		// In-place arithmetic
		Vector4& operator+=(const Vector4& vec);
		Vector4& operator+=(float amount);
		Vector4& operator-=(const Vector4& vec);
		Vector4& operator-=(float amount);
		Vector4& operator*=(float scale);
		Vector4& operator/=(float scale);
		
		// Negation
		Vector4 operator-() const;
		
		/*! Calculates the vector's magnitude, squared.
		 @note Faster than `magnitude`. */
		float sqrmagnitude() const;
		
		/*! Calculates the vector's magnitude. */
		float magnitude() const;
		
		/*! Returns a unit vector in the same direction as the current one. */
		const Vector4 normalize() const;
		
		/*! Converts this vector to a unit vector, preserving direction. */
		Vector4& inormalize();
		
		/*!
		 Calculates the distance between the vectors, squared.
		 @note Faster than `distance`.
		 */
		float sqrdistance(const Vector4& other) const;
		
		/*! Calculates the distance between the vectors. */
		float distance(const Vector4& other) const;
		
		/*! Calculates the dot product of the vectors. */
		float dot(const Vector4& other) const;
		
		/*! Transforms the vector using a transformation matrix.
		 @param mat Transformation matrix to apply to the vector.
		 @return Newly transformed vector.
		 */
		Vector4 transform(const Matrix4& mat) const;
		
		/*! Transforms the vector in-place using a transformation matrix.
		 @param mat Transformation matrix to apply to the vector.
		 @return Reference to the modified vector.
		 */
		Vector4& itransform(const Matrix4& mat);
	} ATTRIB_PACKED;
	
	// Relational operators
	bool operator<(const Vector4& l, const Vector4& r);
	bool operator>(const Vector4& l, const Vector4& r);
	bool operator<=(const Vector4& l, const Vector4& r);
	bool operator>=(const Vector4& l, const Vector4& r);
	bool operator==(const Vector4& l, const Vector4& r);
	bool operator!=(const Vector4& l, const Vector4& r);
	
	bool operator>=(const Vector4& l, float mag);
	bool operator<(const Vector4& l, float mag);
	bool operator>(const Vector4& l, float mag);
	bool operator<=(const Vector4& l, float mag);
	
	bool operator>=(float mag, const Vector4& r);
	bool operator<(float mag, const Vector4& r);
	bool operator>(float mag, const Vector4& r);
	bool operator<=(float mag, const Vector4& r);
	
	// Arithmetic
	const Vector4 operator+(const Vector4& vec, const Vector4& other);
	const Vector4 operator+(const Vector4& vec, float amount);
	const Vector4 operator+(float amount, const Vector4& vec);
	const Vector4 operator-(const Vector4& vec, const Vector4& other);
	const Vector4 operator-(const Vector4& vec, float amount);
	const Vector4 operator-(float amount, const Vector4& vec);
	const Vector4 operator*(const Vector4& vec, float scale);
	const Vector4 operator*(float scale, const Vector4& vec);
	const Vector4 operator/(const Vector4& vec, float scale);
	
	/*! Prints `vec` in the format "(x, y, z, w)" to `stream`. */
	std::ostream& operator<<(std::ostream& stream, const Vector4& vec);
}

#endif /* _SGE_VECTOR3_H_ */
