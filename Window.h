//
//  Window.h
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/8/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#ifndef _SGE_WINDOW_H_
#define _SGE_WINDOW_H_

#include <GLFW/glfw3.h>
#include <string>
#include "Color.h"
#include "Rectangle.h"


namespace sge {
	/*! Handles window and viewport settings. */
	class Window {
	public:
		/*! Constructs a window with the given parameters.
		 @param title The window's title.
		 @param x X coordinate where the window should be opened.
		 @param y Y coordinate where the window should be opened.
		 @param width Width of the window.
		 @param height Height of the window.
		 @param resizeable Whether the window should be resizeable by the user.
		 @note The window is not displayed until 
		 */
		Window(std::string title="Untitled Game", int x=50, int y=50,
		       unsigned width=640, unsigned height=480, bool resizeable=false);
		
		~Window();
		
		/*! Sets the background color of the window.
		 @param background New background color of the window.
		 */
		void setBackground(const Color& background);
		
		/*! Clears the contents of the window to the background color. */
		void clear();
		
		/*! Makes drawn objects be displayed to the screen. */
		void render();
		
		/*! Get the window's title.
		 @return The window's title.
		 */
		const std::string& getTitle();
		
		/*! Set the window's title.
		 @param title The new title for the window.
		 */
		void setTitle(std::string title);
		
		/*! Specify whether the window's aspect ratio should be
		 preserved when resizing.
		 @param preserve Whether the aspect ratio should be preserved.
		 */
		void setPreservesAspectRatio(bool preserve);
		
		/*! Check if the window's aspect ratio should be preserved.
		 @return Whether the aspect ratio is being preserved.
		 */
		bool preservesAspectRatio();
		
		/*! Get the bounds of the window (useful to display a background image).
		 @return A rectangle of the form (0.0f, 0.0f, width, height).
		 */
		Rectangle getBounds() const;
		
		/*! Get the window's width.
		 @return The window's width.
		 */
		unsigned getWidth();
		
		/*! Get the window's height.
		 @return The window's height.
		 */
		unsigned getHeight();
		
		/*! Updates the window's dimensions.
		 @param width New width for the window.
		 @param height New height for the window.
		 */
		void setSize(unsigned width, unsigned height);
		
		/*! Gets the window's x coordinate.
		 @return The window's x coordinate.
		 */
		int getX();
		
		/*! Gets the window's y coordinate.
		 @return The window's y coordinate.
		 */
		int getY();
		
		/*! Set's the window's position.
		 @param x The x coordinate for the top left corner of the window.
		 @param y The y coordinate for the top left corner of the window.
		 */
		void setPosition(int x, int y);
		
		/*! Specify whether the mouse cursor should be hidden.
		 @param hide Whether the cursor should be hidden.
		 */
		void hideCursor(bool hide);
		
		/*! Check if the window is fullscreen or windowed.
		 @return Whether the window is fullscreen.
		 */
		bool isFullscreen();
		
		/*! Toggles the fullscreen state of the window. */
		void toggleFullscreen();
		
		/*! Makes the window be fullscreen. */
		void enableFullscreen();
		
		/*! Disables fullscreen mode, making the app windowed. */
		void disableFullscreen();
		
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
		bool cursorHidden;
		
		void construct();
		void updateSize(unsigned, unsigned);
		void updateGL();
		void didMove(int, int);
		void didResize(int, int);
		
		friend class Game;
		friend void _cb_windowpos(GLFWwindow*, int, int);
		friend void _cb_windowsize(GLFWwindow*, int, int);
	};
}

#endif /* _SGE_WINDOW_H_ */
