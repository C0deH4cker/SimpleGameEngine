//
//  Rectangle.h
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/13/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#pragma once


namespace sge {
	struct Rectangle {
		float x, y, width, height;
		
		Rectangle(float x, float y, float width, float height);
		
		Rectangle& operator=(const Rectangle& other);
		
		bool intersects(const Rectangle& other) const;
	};
}

