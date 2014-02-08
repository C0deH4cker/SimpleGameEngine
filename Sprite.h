//
//  Sprite.h
//  SimpleGameEngine
//
//  Created by C0deH4cker on 2/4/14.
//  Copyright (c) 2014 C0deH4cker. All rights reserved.
//

#ifndef _SGE_SPRITE_H_
#define _SGE_SPRITE_H_

#include "Texture2D.h"
#include "Rectangle.h"

namespace sge {
	/*! Used to draw a portion of a texture. */
	class Sprite {
	public:
		/*! Constructs a sprite given a source image and rectangle.
		 @param texture Source texture containing the sprite.
		 @param sourceRect Rectangular region in texture to get sprite from.
		 */
		Sprite(const Texture2D* texture, Rectangle sourceRect);
		
		/*! Draw sprite to the screen at a specified location.
		 @param destRect Rectangle on screen to draw into.
		 @param rotation Rotation angle in radians.
		 */
		void draw(const Rectangle& destRect, float rotation=0.0f) const;
		
		float getWidth() const;
		float getHeight() const;
		
	private:
		const Texture2D* tex;
		Rectangle rect;
	};
}

#endif /* _SGE_SPRITE_H_ */
