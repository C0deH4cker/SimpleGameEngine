//
//  Camera.h
//  SimpleGameEngine
//
//  Created by Josh Huelsman on 1/20/14.
//  Copyright (c) 2014 Josh Huelsman <joshuahuelsman@gmail.com>. All rights reserved.
//

#ifndef _SGE_CAMERA_H_
#define _SGE_CAMERA_H_

#include "sge_depends.h"
#include "Matrix4.h"


namespace sge {
	struct Camera {
		Matrix4 projectionMatrix;
		Matrix4 viewMatrix;

		Camera();
		~Camera();
	};
}

#endif /* _SGE_CAMERA_H_ */
