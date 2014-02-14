//
//  Vector3.h
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/7/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#ifndef _SGE_VECTOR3_H_
#define _SGE_VECTOR3_H_

#include <ostream>
#include "sge_depends.h"
#include "Matrix4.h"


namespace sge {
	/*! A three-dimensional vector. */
	struct Vector3 {
		/*! The components of the vector. */
		float x, y, z;
		
		/*! Constructs a vector with both components set to `scalar`.
		 @param scalar The value each component is initialized to.
		 */
		Vector3(float scalar=0.0f);
		
		/*! Constructs a vector with the given components.
		 @param x The x coordinate of the vector.
		 @param y The y coordinate of the vector.
		 @param z The z coordinate of the vector.
		 */
		Vector3(float x, float y, float z);
		
		/*! Copying constructor.
		 @param other Vector to copy.
		 */
		Vector3(const Vector3& other);
		
		~Vector3();
		
		// Assignment
		Vector3& operator=(const Vector3& vec);
		
		// In-place arithmetic
		Vector3& operator+=(const Vector3& vec);
		Vector3& operator+=(float amount);
		Vector3& operator-=(const Vector3& vec);
		Vector3& operator-=(float amount);
		Vector3& operator*=(float scale);
		Vector3& operator/=(float scale);
		
		// Negation
		Vector3 operator-() const;
		
		/*! Calculates the vector's magnitude, squared.
		 @note Faster than `magnitude`. */
		float sqrmagnitude() const;
		
		/*! Calculates the vector's magnitude. */
		float magnitude() const;
		
		/*! Returns a unit vector in the same direction as the current one. */
		const Vector3 normalize() const;
		
		/*! Converts this vector to a unit vector, preserving direction. */
		Vector3& inormalize();
		
		/*!
		 Calculates the distance between the vectors, squared.
		 @note Faster than `distance`.
		 */
		float sqrdistance(const Vector3& other) const;
		
		/*! Calculates the distance between the vectors. */
		float distance(const Vector3& other) const;
		
		/*! Calculates the dot product of the vectors. */
		float dot(const Vector3& other) const;
		
		/*! Calculates the cross product of the vectors. */
		Vector3 cross(const Vector3& other) const;
		
		/*! Transforms the vector using a transformation matrix.
		 @param mat Transformation matrix to apply to the vector.
		 @return Newly transformed vector.
		 */
		Vector3 transform(const Matrix4& mat) const;
		
		/*! Transforms the vector in-place using a transformation matrix.
		 @param mat Transformation matrix to apply to the vector.
		 @return Reference to the modified vector.
		 */
		Vector3& itransform(const Matrix4& mat);
	} ATTRIB_PACKED;
	
	// Relational operators
	bool operator<(const Vector3& l, const Vector3& r);
	bool operator>(const Vector3& l, const Vector3& r);
	bool operator<=(const Vector3& l, const Vector3& r);
	bool operator>=(const Vector3& l, const Vector3& r);
	bool operator==(const Vector3& l, const Vector3& r);
	bool operator!=(const Vector3& l, const Vector3& r);
	
	bool operator>=(const Vector3& l, float mag);
	bool operator<(const Vector3& l, float mag);
	bool operator>(const Vector3& l, float mag);
	bool operator<=(const Vector3& l, float mag);
	
	bool operator>=(float mag, const Vector3& r);
	bool operator<(float mag, const Vector3& r);
	bool operator>(float mag, const Vector3& r);
	bool operator<=(float mag, const Vector3& r);
	
	// Arithmetic
	const Vector3 operator+(const Vector3& vec, const Vector3& other);
	const Vector3 operator+(const Vector3& vec, float amount);
	const Vector3 operator+(float amount, const Vector3& vec);
	const Vector3 operator-(const Vector3& vec, const Vector3& other);
	const Vector3 operator-(const Vector3& vec, float amount);
	const Vector3 operator-(float amount, const Vector3& vec);
	const Vector3 operator*(const Vector3& vec, float scale);
	const Vector3 operator*(float scale, const Vector3& vec);
	const Vector3 operator/(const Vector3& vec, float scale);

	/*! Prints `vec` in the format "(x, y, z)" to `stream`. */
	std::ostream& operator<<(std::ostream& stream, const Vector3& vec);
}

#endif /* _SGE_VECTOR3_H_ */
