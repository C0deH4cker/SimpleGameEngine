//
//  sge_depends.h
//  SimpleGameEngine
//
//  Created by C0deH4cker on 2/7/14.
//  Copyright (c) 2014 C0deH4cker. All rights reserved.
//

#ifndef _SGE_DEPENDS_H_
#define _SGE_DEPENDS_H_

#ifndef __has_attribute
# define __has_attribute(x) 0
#endif

#ifndef __has_include
# define __has_include(x) 1
#endif

#if __has_include(<GL/gl.h>)
#define Rectangle __Windows_Rectangle
# include <GL/gl.h>
#undef Rectangle
#elif __has_include(<OpenGL/gl.h>)
# include <OpenGL/gl.h>
#else
# error "Couldn't find gl.h!"
#endif

#if __has_attribute(__packed__)
# define ATTRIB_PACKED __attribute__((__packed__))
#else
# define ATTRIB_PACKED
#endif

#if __has_attribute(__deprecated__)
# define ATTRIB_DEPRECATED __attribute__((__deprecated__))
#else
# define ATTRIB_DEPRECATED
#endif

#if __has_attribute(__unavailable__)
# define ATTRIB_UNAVAILABLE __attribute__((__unavailable__))
#else
# define ATTRIB_UNAVAILABLE
#endif

#endif /* _SGE_DEPENDS_H_ */
