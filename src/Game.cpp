//
//  Game.cpp
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/8/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#include "Game.h"
#include <stdlib.h>
#include <iostream>
#include "sge_internal.h"
#include "Color.h"

using namespace sge;

/* Private declarations */
namespace sge {
	void _cb_error(int error, const char* description);
	void _cb_windowpos(GLFWwindow* w, int x, int y);
	void _cb_windowsize(GLFWwindow* w, int width, int height);
	void _cb_windowclose(GLFWwindow* w);
	void _cb_windowrefresh(GLFWwindow* w);
	void _cb_windowfocus(GLFWwindow* w, int dir);
	void _cb_windowiconify(GLFWwindow* w, int dir);
	void _cb_framebuffersize(GLFWwindow* w, int width, int height);
	void _cb_mousebutton(GLFWwindow* w, int button, int action, int mods);
	void _cb_cursorpos(GLFWwindow* w, double x, double y);
	void _cb_cursorenter(GLFWwindow* w, int dir);
	void _cb_scroll(GLFWwindow* w, double x, double y);
	void _cb_key(GLFWwindow* w, int key, int scancode, int action, int mods);
	void _cb_char(GLFWwindow* w, unsigned c);

	/** Singleton instance **/
	Game* Game::game;
}

/**
 The constructor shall guarantee that only one instance may ever be initialized,
 as this is a singleton. Additionally, we should initialize the Window class but
 not have it create the GLFWwindow yet. That must wait until after the user has
 performed custom window initialization as many of the custom options must
 occur during window construction.
 */
Game::Game()
: status(0), shutdown(false) {
	if(game) {
		std::cerr << "Error: There may only be one instance of Game at a time."
		          << std::endl;
		exit(1);
	}
	
	glfwInit();
	window = new Window();
	Game::game = this;
}

Game::~Game() {
	delete window;
	glfwTerminate();
}


#pragma mark -
#pragma mark Static methods
#pragma mark -

Game* Game::instance() {
	return game;
}


#pragma mark -
#pragma mark Private methods
#pragma mark -

void Game::initGL() {
	glDepthMask(false);
}

void Game::display() {
	window->clear();
	
	draw(drawTimer.tick());
	
	window->render();
}

void Game::mainloop() {
	while(!shutdown && !glfwWindowShouldClose(glwindow)) {
		update(updateTimer.tick());
		display();
		
		glfwPollEvents();
	}
}


#pragma mark -
#pragma mark Public methods
#pragma mark -

int Game::run() {
	// Create the GLFW window and setup window related OpenGL parameters
	window->construct();
	glwindow = window->currentWindowContext();
	
	// Register all of the event callbacks with GLFW
	registerCallbacks();
	
	// Initialize OpenGL so we are ready to render
	initGL();
	
	// Call user's initialization method
	initialize();
	
	// Reset timers
	updateTimer.reset();
	drawTimer.reset();
	
	// Start the main game loop
	mainloop();
	
	// Commit suicide
	delete this;
	
	return status;
}

void Game::terminate(int exitStatus) {
	shutdown = true;
	status = exitStatus;
}


#pragma mark -
#pragma mark Callbacks
#pragma mark -

void sge::_cb_error(int error, const char* description) {
	std::cerr << "Error " << error << ": " << description << std::endl;
	exit(1);
}

void sge::_cb_windowpos(GLFWwindow* w, int x, int y) {
	Game& g = *Game::instance();
	g.window->didMove(x, y);
	g.windowMoved(x, y);
}

void sge::_cb_windowsize(GLFWwindow* w, int width, int height) {
	Game& g = *Game::instance();
	g.window->didResize(width, height);
	g.windowResized(width, height);
}

void sge::_cb_windowclose(GLFWwindow* w) {
	Game::instance()->windowClosed();
}

void sge::_cb_windowrefresh(GLFWwindow* w) {
	Game::instance()->display();
}

void sge::_cb_windowfocus(GLFWwindow* w, int dir) {
	Game::instance()->windowFocused(dir);
}

void sge::_cb_windowiconify(GLFWwindow* w, int dir) {
	Game::instance()->windowMinimized(dir);
}

void sge::_cb_framebuffersize(GLFWwindow* w, int width, int height) {
	Game::instance()->framebufferResized(width, height);
}

void sge::_cb_mousebutton(GLFWwindow* w, int button, int action, int mods) {
	switch(action) {
		case GLFW_PRESS:
			Game::instance()->mouseDown(button, mods);
			break;
		
		case GLFW_RELEASE:
			Game::instance()->mouseUp(button, mods);
			break;
		
		default:
			break;
	}
}

void sge::_cb_cursorpos(GLFWwindow* w, double x, double y) {
	Game& g = *Game::instance();
	g.mouse = {static_cast<float>(x), static_cast<float>(y)};
	g.mouseMoved({static_cast<float>(x), static_cast<float>(y)});
}

void sge::_cb_cursorenter(GLFWwindow* w, int dir) {
	Game::instance()->mouseEntered(dir);
}

void sge::_cb_scroll(GLFWwindow* w, double x, double y) {
	Game::instance()->scrolled({static_cast<float>(x), static_cast<float>(y)});
}

void sge::_cb_key(GLFWwindow* w, int key, int scancode, int action, int mods) {
	switch(action) {
		case GLFW_PRESS:
			Game::instance()->keyDown(key, scancode, mods);
			break;
		
		case GLFW_RELEASE:
			Game::instance()->keyUp(key, scancode, mods);
			break;
		
		case GLFW_REPEAT:
			Game::instance()->keyRepeat(key, scancode, mods);
			break;
		
		default:
			break;
	}
}

void sge::_cb_char(GLFWwindow* w, unsigned c) {
	Game::instance()->charTyped(c);
}

#pragma mark -

void Game::registerCallbacks() {
	GLFWwindow* w = glwindow;
	
	glfwSetErrorCallback(_cb_error);
	glfwSetWindowPosCallback(w, _cb_windowpos);
	glfwSetWindowSizeCallback(w, _cb_windowsize);
	glfwSetWindowCloseCallback(w, _cb_windowclose);
	glfwSetWindowRefreshCallback(w, _cb_windowrefresh);
	glfwSetWindowFocusCallback(w, _cb_windowfocus);
	glfwSetWindowIconifyCallback(w, _cb_windowiconify);
	glfwSetFramebufferSizeCallback(w, _cb_framebuffersize);
	glfwSetMouseButtonCallback(w, _cb_mousebutton);
	glfwSetCursorPosCallback(w, _cb_cursorpos);
	glfwSetCursorEnterCallback(w, _cb_cursorenter);
	glfwSetScrollCallback(w, _cb_scroll);
	glfwSetKeyCallback(w, _cb_key);
	glfwSetCharCallback(w, _cb_char);
}

void Game::toggleFullscreen() {
	window->toggleFullscreen();
	glwindow = window->currentWindowContext();
	registerCallbacks();
}

