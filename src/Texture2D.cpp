//
//  Texture2D.cpp
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/13/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#include "Texture2D.h"
#include <string>
#include <math.h>
#include "sge_internal.h"
#include "Texture2D.h"
#include "Rectangle.h"
#include "Matrix4.h"
#include "Vector2.h"
#include "SOIL/SOIL.h"

using namespace sge;

GLuint Texture2D::active = 0;

GLuint Texture2D::load(const char* filename, int* width,
                          int* height, GLenum filter) {
    GLuint texture = SOIL_load_OGL_texture(filename, SOIL_LOAD_RGBA,
	                                       SOIL_CREATE_NEW_ID,
                                           SOIL_FLAG_INVERT_Y);

    glBindTexture(GL_TEXTURE_2D, active = texture);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, width);
    glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, height);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
	
    return texture;
}


Texture2D::Texture2D(const std::string& path, GLenum filter) {
	gltexture = load(path.c_str(), &width, &height, filter);
}

Texture2D::~Texture2D() {
	glDeleteTextures(1, &gltexture);
}


void Texture2D::draw(const Rectangle& frame, float rotation) const {
	draw(frame, Rectangle(0.0f, 0.0f, width, height), rotation);
}

void Texture2D::draw(const sge::Rectangle &frame,
					 const sge::Rectangle &sprite, float rotation) const {
	Vector2 v[4] = {frame.topLeft(), frame.topRight(),
		frame.bottomRight(), frame.bottomLeft()};
	
	Vector2 center(frame.center());
	
	for(int i = 0; i < 4; i++) {
		v[i] -= center;
		v[i].irotate(rotation);
		v[i] += center;
	}
	
	Vector2 tex[4] = {sprite.topLeft(), sprite.topRight(),
	                  sprite.bottomRight(), sprite.bottomLeft()};
	
	Vector2 scale(1.0f / width, 1.0f / height);
	
	for(int i = 0; i < 4; i++) {
		tex[i].x *= scale.x;
		tex[i].y = 1.0f - tex[i].y * scale.y;
	}
	
	// Enable features
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	
	// Setup blending mode
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	// Bind texture only if not already bound
	if(!isActive())
		glBindTexture(GL_TEXTURE_2D, active = gltexture);
	
	// Set vertices
	glVertexPointer(2, GL_FLOAT, 0, v);
	glTexCoordPointer(2, GL_FLOAT, 0, tex);
	
	// Draw image
	glDrawArrays(GL_QUADS, 0, 4);
	
	// Disable features
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}


bool Texture2D::isActive() const {
	return gltexture == active;
}

