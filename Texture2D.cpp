//
//  Texture2D.cpp
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/13/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#include "Texture2D.h"
#include <string>
#include <OpenGL/gl.h>
#include <png.h>
#include "Rectangle.h"
#include "Vector2.h"

using namespace sge;


GLuint png_texture_load(const char* file_name, int* width, int* height) {
    png_byte header[8];
	
    FILE* fp = fopen(file_name, "rb");
    if(fp == 0) {
        perror(file_name);
        return 0;
    }
	
    // read the header
    fread(header, 1, 8, fp);
	
    if(png_sig_cmp(header, 0, 8)) {
        fprintf(stderr, "error: %s is not a PNG.\n", file_name);
        fclose(fp);
        return 0;
    }
	
    png_structp png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if(!png_ptr) {
        fprintf(stderr, "error: png_create_read_struct returned 0.\n");
        fclose(fp);
        return 0;
    }
	
    // create png info struct
    png_infop info_ptr = png_create_info_struct(png_ptr);
    if(!info_ptr) {
        fprintf(stderr, "error: png_create_info_struct returned 0.\n");
        png_destroy_read_struct(&png_ptr, (png_infopp)NULL, (png_infopp)NULL);
        fclose(fp);
        return 0;
    }
	
    // create png info struct
    png_infop end_info = png_create_info_struct(png_ptr);
    if(!end_info) {
        fprintf(stderr, "error: png_create_info_struct returned 0.\n");
        png_destroy_read_struct(&png_ptr, &info_ptr, (png_infopp) NULL);
        fclose(fp);
        return 0;
    }
	
    // the code in this if statement gets called if libpng encounters an error
    if(setjmp(png_jmpbuf(png_ptr))) {
        fprintf(stderr, "error from libpng\n");
        png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
        fclose(fp);
        return 0;
    }
	
    // init png reading
    png_init_io(png_ptr, fp);
	
    // let libpng know you already read the first 8 bytes
    png_set_sig_bytes(png_ptr, 8);
	
    // read all the info up to the image data
    png_read_info(png_ptr, info_ptr);
	
    // variables to pass to get info
    int bit_depth, color_type;
    png_uint_32 temp_width, temp_height;
	
    // get info about png
    png_get_IHDR(png_ptr, info_ptr, &temp_width, &temp_height, &bit_depth, &color_type,
				 NULL, NULL, NULL);
	
    if(width) {
		*width = temp_width;
	}
    if(height) {
		*height = temp_height;
	}
	
    if(bit_depth != 8) {
        fprintf(stderr, "%s: Unsupported bit depth %d. Must be 8.\n", file_name, bit_depth);
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
			fprintf(stderr, "%s: Unknown libpng color type %d.\n", file_name, color_type);
			return 0;
    }
	
    // Update the png info struct.
    png_read_update_info(png_ptr, info_ptr);
	
    // Row size in bytes.
    int rowbytes = (int)png_get_rowbytes(png_ptr, info_ptr);
	
    // glTexImage2d requires rows to be 4-byte aligned
    rowbytes += 3 - ((rowbytes-1) % 4);
	
    // Allocate the image_data as a big block, to be given to opengl
    png_byte* image_data = (png_byte*)malloc(rowbytes * temp_height * sizeof(png_byte) + 15);
    if(image_data == NULL) {
        fprintf(stderr, "error: could not allocate memory for PNG image data\n");
        png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
        fclose(fp);
        return 0;
    }
	
    // row_pointers is for pointing to image_data for reading the png with libpng
    png_byte** row_pointers = (png_byte**)malloc(temp_height * sizeof(png_byte* ));
    if(row_pointers == NULL) {
        fprintf(stderr, "error: could not allocate memory for PNG row pointers\n");
        png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
        free(image_data);
        fclose(fp);
        return 0;
    }
	
    // set the individual row_pointers to point at the correct offsets of image_data
    for(unsigned int i = 0; i < temp_height; i++) {
        row_pointers[temp_height - 1 - i] = image_data + i * rowbytes;
    }
	
    // read the png into image_data through row_pointers
    png_read_image(png_ptr, row_pointers);
	
    // Generate the OpenGL texture object
    GLuint texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, format, temp_width, temp_height, 0, format, GL_UNSIGNED_BYTE, image_data);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
    // clean up
    png_destroy_read_struct(&png_ptr, &info_ptr, &end_info);
    free(image_data);
    free(row_pointers);
    fclose(fp);
    return texture;
}


Texture2D::Texture2D(const std::string& path) {
	gltexture = png_texture_load(path.c_str(), &width, &height);
}

Texture2D::~Texture2D() {
	glDeleteTextures(1, &gltexture);
}

static const GLfloat normals[4][3] = {
	{0.0f, 0.0f, 1.0f},
	{0.0f, 0.0f, 1.0f},
	{0.0f, 0.0f, 1.0f},
	{0.0f, 0.0f, 1.0f}
};
static const GLfloat texCoords[8] = {
	0.0f, 1.0f,
	1.0f, 1.0f,
	1.0f, 0.0f,
	0.0f, 0.0f
};

void Texture2D::draw(const Rectangle& frame) const {
	Vector2 vertices[4] = {{frame.x, frame.y}, {frame.x + frame.width, frame.y}, {frame.x + frame.width, frame.y + frame.height}, {frame.x, frame.y + frame.height}};
	
	// Enable features
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	
	// Setup blending mode and bind texture
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, gltexture);
	
	// Set vertices
	glVertexPointer(2, GL_FLOAT, 0, vertices);
	glTexCoordPointer(2, GL_FLOAT, 0, texCoords);
	
	// Draw image
	glDrawArrays(GL_QUADS, 0, 4);
	
	// Disable features
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

