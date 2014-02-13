//
//  Texture2D.h
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/13/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#ifndef _SGE_TEXTURE2D_H_
#define _SGE_TEXTURE2D_H_

#include <string>
#include "sge_depends.h"
#include "Rectangle.h"


namespace sge {
	/*! Handles loading and displaying of textures. */
	class Texture2D {
	public:
		/*! Currently active GL texture.
		 @note If `glBind` is used manually, this must be updated. */
		static GLuint active;
		
		/*! Dimensions of the texture. Set when loading from file. */
		int width, height;
		/*! The GL texture id associated with this texture. */
		GLuint gltexture;
		
		/*! Loads a texture from a PNG file into a GL texture.
		 @param filename Path to the PNG file to load.
		 @param width Pointer whose value will be set to the PNG's width.
		 @param height Pointer whose value will be set to the PNG's height.
		 @param filter GL minification/magnification filter for the texture.
		 @note `width` and `height` may be NULL.
		 @return GL texture id for the loaded texture, or 0 on failure.
		 */
		static GLuint loadPNG(const char* filename, int* width,
							  int* height, GLenum filter);
		
		/*! Constructs a Texture2D from the texture found in `path`.
		 @param path Path to the texture to load (currently only PNG supported).
		 @param filter GL minification/magnification filter for the texture.
		 */
		Texture2D(const std::string& path, GLenum filter=GL_LINEAR);
		~Texture2D();
		
		/*! Draws the entire texture to the screen.
		 @param frame Frame in which to draw the texture.
		 */
		void draw(const Rectangle& frame, float rotation=0.0f) const;
		
		/*! Draws a portion of the texture to the screen.
		 @param frame Frame in which to draw the partial texture.
		 @param sprite Region of the texture to draw.
		 */
		void draw(const Rectangle& frame, const Rectangle& sprite,
				  float rotation=0.0f) const;
		
		/*! Returns whether the texture is currently active. */
		bool isActive() const;
	};
}

#endif /* _SGE_TEXTURE2D_H_ */
