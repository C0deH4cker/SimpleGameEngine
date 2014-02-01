//
//  Rectangle.h
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/13/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#ifndef _SGE_RECTANGLE_H_
#define _SGE_RECTANGLE_H_

#include <Vector2.h>

namespace sge {
	struct Rectangle {
		float x, y, width, height;
		
		Rectangle(float x=0, float y=0, float width=0, float height=0);
		
		Rectangle& operator=(const Rectangle& other);
		
		bool intersects(const Rectangle& other) const;
		
		float left() const;
		float midX() const;
		float right() const;
		float top() const;
		float midY() const;
		float bottom() const;
		
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
	};
}

#endif /* _SGE_RECTANGLE_H_ */
