//
//  Camera.h
//  SimpleGameEngine
//
//  Created by Josh Huelsman on 1/20/14.
//  Copyright (c) 2014 Josh Huelsman <joshuahuelsman@gmail.com>. All rights reserved.
//

#ifndef CAMERA_H
#define CAMERA_H

#include "Matrix4.h"

namespace sge {
	struct Camera
	{
		Matrix4 projectionMatrix;
		Matrix4 viewMatrix;

		Camera();
		~Camera();
	
		
	};
}



#endif
