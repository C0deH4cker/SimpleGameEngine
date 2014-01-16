//
//  Texture2D.h
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/13/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#pragma once

#include <string>
#include <OpenGL/gl.h>
#include "Rectangle.h"


namespace sge {
	class Texture2D {
	public:
		int width, height;
		
		Texture2D(const std::string& path);
		~Texture2D();
		
		void draw(const Rectangle& frame) const;
		
	private:
		GLuint gltexture;
	};
}

