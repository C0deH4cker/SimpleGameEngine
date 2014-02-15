//
//  sge_internal.h
//  SimpleGameEngine
//
//  Created by C0deH4cker on 2/14/14.
//  Copyright (c) 2014 C0deH4cker. All rights reserved.
//

#ifndef _SGE_INTERNAL_H_
#define _SGE_INTERNAL_H_

#include "sge_depends.h"

#if __has_include(<glfw3.h>)
# include <glfw3.h>
#elif __has_include(<GLFW/glfw3.h>)
# include <GLFW/glfw3.h>
#else
# error Couldn't find glfw3.h!
#endif

#endif /* _SGE_INTERNAL_H_ */
