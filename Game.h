//
//  Game.h
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/8/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#pragma once

#include <GLFW/glfw3.h>
#include "Window.h"
#include "Timer.h"
#include "Vector2.h"
#include "Content.h"


namespace sge {
	class Game {
	public:
		Window* window;
		Content* content;
		Vector2 mouse;
		
		static Game& instance();
		
		int run();
		void terminate(int status);
		
		/* Required */
		virtual void initialize() = 0;
		virtual void update(double deltaTime) = 0;
		virtual void draw(double deltaTime) = 0;
		
		/* Optional */
		Game();
		virtual ~Game();
		virtual void windowMoved(int x, int y) {};
		virtual void windowResized(int width, int height) {};
		virtual void windowClosed() {};
		virtual void windowFocused(bool focused) {};
		virtual void windowMinimized(bool minimized) {};
		virtual void framebufferResized(int width, int height) {};
		virtual void mouseDown(int button, int mods) {};
		virtual void mouseUp(int button, int mods) {};
		virtual void mouseMoved(const Vector2& pos) {};
		virtual void mouseEntered(bool entered) {};
		virtual void scrolled(const Vector2& offset) {};
		virtual void keyDown(int key, int scancode, int mods) {
			if(key == GLFW_KEY_ESCAPE)
				terminate(0);
		};
		virtual void keyUp(int key, int scancode, int mods) {};
		virtual void keyRepeat(int key, int scancode, int mods) {};
		virtual void charTyped(unsigned uc) {};
		
	protected:
		GLFWwindow* glwindow;
		
	private:
		Timer updateTimer;
		Timer drawTimer;
		
		static Game* game;
		
		int status;
		bool shutdown;
		bool inRunLoop;
		
		void registerCallbacks();
		void initGL();
		void display();
		void mainloop();
		
		friend void _cb_windowpos(GLFWwindow*, int, int);
		friend void _cb_windowsize(GLFWwindow*, int, int);
		friend void _cb_windowrefresh(GLFWwindow*);
	};
}

