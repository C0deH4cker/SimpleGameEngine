//
//  Window.cpp
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/8/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#include "Window.h"
#include <string>
#include <iostream>
#include "sge_depends.h"
#include "Vector2.h"

using namespace sge;

Window::Window(std::string title, int x, int y,
			   unsigned width, unsigned height, bool resizeable)
: title(title), x(x), y(y), width(width), height(height), keepRatio(false),
resizeable(resizeable), glwindow(NULL), initialized(false),
cursorHidden(false) {
	
}

Window::~Window() {
	if(!initialized) return;
	
	glfwDestroyWindow(glwindow);
}

#pragma mark -
#pragma mark Private methods
#pragma mark -

void Window::construct() {
	if(initialized) return;
	
	initialized = true;
	
	glfwWindowHint(GLFW_RESIZABLE, resizeable);
	glwindow = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	glfwMakeContextCurrent(glwindow);
	hideCursor(cursorHidden);
	
	setPosition(x, y);
	updateGL();
	
	glClearColor(color.r, color.g, color.b, color.a);

	fullscreenwindow = NULL;
}

void Window::updateSize(unsigned newWidth, unsigned newHeight) {
	if(keepRatio) {
		// Make sure we maintain the aspect ratio
		if(width != newWidth || height != newHeight) {
			if(width >= height) {
				width = newWidth;
				height = newWidth / aspect;
			}
			else {
				width = newHeight * aspect;
				height = newHeight;
			}
		}
	}
	else {
		// Just update the window dimensions
		width = newWidth;
		height = newHeight;
		aspect = (float)width / (float)height;
	}
}

void Window::updateGL() {
	if(!initialized) return;
	
	// Set the viewport to cover the new window size
	// To ensure we cover the entire window, use framebuffer size
	int fbwidth, fbheight;
	glfwGetFramebufferSize(glwindow, &fbwidth, &fbheight);
	glViewport(0, 0, fbwidth, fbheight);
	
	// Set the aspect ratio of the clipping area to match the viewport
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	// Origin at top left corner of screen
	glOrtho(0.0, (GLdouble)width, (GLdouble)height, 0.0, -1.0, 1.0);
}

void Window::didMove(int newX, int newY) {
	x = newX;
	y = newY;
}

void Window::didResize(int newWidth, int newHeight) {
	setSize(newWidth, newHeight);
}


#pragma mark -
#pragma mark Public methods
#pragma mark -


void Window::setBackground(const Color& c) {
	color = c;
	
	if(!initialized) return;
	
	glClearColor(c.r, c.g, c.b, c.a);
}

void Window::clear() {
	// Don't check for initialization here because this method is
	// a performance critical one, and the window shouldn't be
	// cleared if it isn't initialized already anyways.
	glClear(GL_COLOR_BUFFER_BIT);
}

void Window::render() {
	// Don't check for initialization here either for the same
	// reasons stated above.
	glfwSwapBuffers(currentWindowContext());
}

const std::string& Window::getTitle() {
	return title;
}

void Window::setTitle(std::string title) {
	this->title = title;
	
	if(!initialized) return;
	
	glfwSetWindowTitle(currentWindowContext(), title.c_str());
}

void Window::setPreservesAspectRatio(bool preserve) {
	keepRatio = preserve;
}

bool Window::preservesAspectRatio() {
	return keepRatio;
}

Rectangle Window::getBounds() const {
	return Rectangle(0.0f, 0.0f, width, height);
}

unsigned Window::getWidth() {
	return width;
}

unsigned Window::getHeight() {
	return height;
}

void Window::setSize(unsigned newWidth, unsigned newHeight) {
	// Update the width and height according to the aspect ratio
	updateSize(newWidth, newHeight);
	
	// Actually apply the size change
	if(!initialized) return;
	
	glfwSetWindowSize(currentWindowContext(), width, height);
	
	updateGL();
}

int Window::getX() {
	return x;
}

int Window::getY() {
	return y;
}

void Window::setPosition(int x, int y) {
	this->x = x;
	this->y = y;
	
	if(!initialized) return;
	
	glfwSetWindowPos(currentWindowContext(), x, y);
}

void Window::hideCursor(bool hide) {
	cursorHidden = hide;
	
	if(!initialized) return;
	
	glfwSetInputMode(currentWindowContext(), GLFW_CURSOR,
					 hide ? GLFW_CURSOR_HIDDEN : GLFW_CURSOR_NORMAL);
}

void Window::toggleFullscreen() {
	if(!isFullscreen())
		enableFullscreen();
	else
		disableFullscreen();
}

void Window::enableFullscreen() {
	if(!isFullscreen()) {
		fullscreenwindow = glfwCreateWindow(width, height, title.c_str(), glfwGetPrimaryMonitor(), glwindow);
		glfwMakeContextCurrent(fullscreenwindow);
		hideCursor(cursorHidden);
		updateGL();
		glClearColor(color.r, color.g, color.b, color.a);
	}
}

void Window::disableFullscreen() {
	if(isFullscreen()) {
		glfwDestroyWindow(fullscreenwindow);
		fullscreenwindow = NULL;
		glfwMakeContextCurrent(glwindow);
		hideCursor(cursorHidden);
		setPosition(x, y);
		updateGL();
	}
}

bool Window::isFullscreen() {
	return fullscreenwindow != NULL;
}

GLFWwindow* Window::currentWindowContext() {
	GLFWwindow* current = glwindow;
	if(isFullscreen()) current = fullscreenwindow;
	return current;
}

