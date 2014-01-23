//
//  Window.h
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/8/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#pragma once

#include <GLFW/glfw3.h>
#include <string>
#include "Color.h"


namespace sge {
	class Window {
	public:
		Window(std::string title="Untitled Game", int x=50, int y=50, unsigned width=640, unsigned height=480, bool resizeable=false);
		~Window();
		
		void setBackground(const Color& background);
		void clear();
		void render();
		
		/* Window properties */
		const std::string& getTitle();
		void setTitle(std::string title);
		
		void setPreservesAspectRatio(bool preserve);
		bool preservesAspectRatio();
		
		unsigned getWidth();
		unsigned getHeight();
		void setSize(unsigned width, unsigned height);
		
		int getX();
		int getY();
		void setPosition(int x, int y);
		
		void hideCursor(bool hide);
		
		bool isFullscreen();
		void toggleFullscreen();
		void enableFullscreen();
		void disableFullscreen();
		
		friend class Game;
		friend void _cb_windowpos(GLFWwindow*, int, int);
		friend void _cb_windowsize(GLFWwindow*, int, int);
		
	private:
		std::string title;
		GLFWwindow* glwindow;
		Color color;
		
		bool initialized;
		int x, y;
		unsigned width, height;
		float planeWidth, planeHeight;
		float aspect;
		bool resizeable, keepRatio;
		
		void construct();
		void updateSize(unsigned, unsigned);
		void updateGL();
		void didMove(int, int);
		void didResize(int, int);
	};
}

