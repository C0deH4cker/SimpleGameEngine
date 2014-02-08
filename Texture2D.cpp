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
#include <png.h>
#include "sge_depends.h"
#include "Rectangle.h"
#include "Matrix4.h"
#include "Vector2.h"

using namespace sge;

GLuint Texture2D::active = 0;

GLuint Texture2D::loadPNG(const char* filename, int* width,
                          int* height, GLenum filter) {
    png_byte header[8];
	
    FILE* fp = fopen(filename, "rb");
    if(fp == 0) {
        perror(filename);
        return 0;
    }
	
    // Read the header
    fread(header, 1, 8, fp);
	
    if(png_sig_cmp(header, 0, 8)) {
        fprintf(stderr, "Error: %s is not a PNG.\n", filename);
        fclose(fp);
        return 0;
    }
	
    png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING,
	                                             NULL, NULL, NULL);
    if(!png_ptr) {
        fprintf(stderr, "Error: png_create_read_struct returned 0.\n");
        fclose(fp);
        return 0;
    }
	
    // Create png info struct
    png_infop info_ptr = png_create_info_struct(png_ptr);
    if(!info_ptr) {
        fprintf(stderr, "Error: png_create_info_struct returned 0.\n");
        png_destroy_read_struct(&png_ptr, (png_infopp)NULL, (png_infopp)NULL);
        fclose(fp);
        return 0;
    }
	
    // Create png info struct
    png_infop end_info = png_create_info_struct(png_ptr);
    if(!end_info) {
        fprintf(stderr, "Error: png_create_info_struct returned 0.\n");
        png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp) NULL);
        fclose(fp);
        return 0;
    }
	
    // The code in this if statement gets called if libpng encounters an error
    if(setjmp(png_jmpbuf(png_ptr))) {
        fprintf(stderr, "Error from libpng\n");
        png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
        fclose(fp);
        return 0;
    }
	
    // Init png reading
    png_init_io(png_ptr, fp);
	
    // Let libpng know you already read the first 8 bytes
    png_set_sig_bytes(png_ptr, 8);
	
    // Read all the info up to the image data
    png_read_info(png_ptr, info_ptr);
	
    // Variables to pass to get info
    int bit_depth, color_type;
    png_uint_32 temp_width, temp_height;
	
    // Get info about png
    png_get_IHDR(png_ptr, info_ptr, &temp_width, &temp_height,
	             &bit_depth, &color_type, NULL, NULL, NULL);
	
    if(width) *width = temp_width;
    if(height) *height = temp_height;
	
    if(bit_depth != 8) {
        fprintf(stderr, "%s: Unsupported bit depth %d. Must be 8.\n",
		        filename, bit_depth);
        return 0;
    }
	
    GLint format;
    switch(color_type) {
		case PNG_COLOR_TYPE_RGB:
			format = GL_RGB;
			break;
		
		case PNG_COLOR_TYPE_RGB_ALPHA:
			format = GL_RGBA;
			break;
		
		default:
			fprintf(stderr, "%s: Unknown libpng color type %d.\n",
			        filename, color_type);
			return 0;
    }
	
    // Update the png info struct.
    png_read_update_info(png_ptr, info_ptr);
	
    // Row size in bytes.
    int rowbytes = (int)png_get_rowbytes(png_ptr, info_ptr);
	
    // glTexImage2d requires rows to be 4-byte aligned
    rowbytes += 3 - ((rowbytes-1) % 4);
	
    // Allocate the image_data as a big block, to be given to opengl
    png_byte* image_data = (png_byte*)malloc(rowbytes * temp_height *
	                                         sizeof(*image_data) + 15);
    if(image_data == NULL) {
        fprintf(stderr,
		        "Error: Could not allocate memory for PNG image data\n");
        png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
        fclose(fp);
        return 0;
    }
	
    // row_pointers points to image_data for reading the png with libpng
    png_byte** row_pointers = (png_byte**)malloc(temp_height *
	                                             sizeof(*row_pointers));
    if(row_pointers == NULL) {
        fprintf(stderr,
		        "Error: Could not allocate memory for PNG row pointers\n");
        png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
        free(image_data);
        fclose(fp);
        return 0;
    }
	
    // Set each row_pointer to point at the correct offsets of image_data
    for(unsigned int i = 0; i < temp_height; i++) {
        row_pointers[temp_height - 1 - i] = image_data + i * rowbytes;
    }
	
    // Read the png into image_data through row_pointers
    png_read_image(png_ptr, row_pointers);
	
    // Generate the OpenGL texture object
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, active = texture);
    glTexImage2D(GL_TEXTURE_2D, 0, format, temp_width, temp_height,
	             0, format, GL_UNSIGNED_BYTE, image_data);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
	
    // Clean up
    png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
    free(image_data);
    free(row_pointers);
    fclose(fp);
	
    return texture;
}


Texture2D::Texture2D(const std::string& path, GLenum filter) {
	gltexture = loadPNG(path.c_str(), &width, &height, filter);
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
	return gltexture == Texture2D::active;
}

