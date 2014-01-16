//
//  helpers.h
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/7/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#pragma once

#include <vector>
#include <OpenGL/gl.h>


#define ABS(x) ({ \
	__typeof__(x) _x = (x); \
	_x < 0 ? -_x : _x; \
})

#define MIN(a, b) ({ \
	__typeof__(a) _a = (a); \
	__typeof__(b) _b = (b); \
	_a < _b ? _a : _b; \
})

#define MAX(a, b) ({ \
	__typeof__(a) _a = (a); \
	__typeof__(b) _b = (b); \
	_a > _b ? _a : _b; \
})

#define CLAMP(x, lo, hi) ({ \
	MIN(hi, MAX(lo, x)); \
})

template <class T>
inline void glBufferData(GLenum target, const std::vector<T>& v, GLenum usage) {
    glBufferData(target, v.size() * sizeof(T), &v[0], usage);
}

