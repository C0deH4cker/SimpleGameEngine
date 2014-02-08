//
//  Rectangle.h
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/13/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#ifndef _SGE_RECTANGLE_H_
#define _SGE_RECTANGLE_H_

#include "sge_depends.h"
#include "Vector2.h"


namespace sge {
	/*! Defines a two-dimensional rectangular region. */
	struct Rectangle {
		/*! The components of the rectangle */
		float x, y, width, height;
		
		/*! Constructs a rectangle with the given parameters.
		 @param x The x coordinate.
		 @param y The y coordinate.
		 @param width The rectangle's width.
		 @param height The rectangle's height.
		 */
		Rectangle(float x=0, float y=0, float width=0, float height=0);
		
		/*! Constructs a rectangle given points of opposite corners.
		 @param p1 A corner of the rectangle.
		 @param p2 A corner of the rectangle.
		 */
		Rectangle(const Vector2& p1, const Vector2& p2);
		
		Rectangle& operator=(const Rectangle& other);
		
		/*! Moves the rectangle's center while preserving its dimensions.
		 @param center The new center for the rectangle.
		 */
		void setCenter(const Vector2& center);
		
		/*! Returns true if the rectangles overlap, or false otherwise. */
		bool intersects(const Rectangle& other) const;
		
		/*! The x coordinate of the left side. */
		float left() const;
		/*! The x coordinate of the center. */
		float midX() const;
		/*! The x coordinate of the right side. */
		float right() const;
		/*! The y coordinate of the top. */
		float top() const;
		/*! The y coordinate of the center. */
		float midY() const;
		/*! The y coordinate of the bottom. */
		float bottom() const;
		
		/*! Calculates the length of the rectangle's diagonal. */
		float diagonal() const;
		
		Vector2 topLeft() const;
		Vector2 topCenter() const;
		Vector2 topRight() const;
		Vector2 leftCenter() const;
		Vector2 center() const;
		Vector2 rightCenter() const;
		Vector2 bottomLeft() const;
		Vector2 bottomCenter() const;
		Vector2 bottomRight() const;
	} ATTRIB_PACKED;
}

#endif /* _SGE_RECTANGLE_H_ */
