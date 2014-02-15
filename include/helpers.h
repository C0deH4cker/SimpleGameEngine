//
//  helpers.h
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/7/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#ifndef _SGE_HELPERS_H_
#define _SGE_HELPERS_H_

#include <vector>
#include "sge_depends.h"


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

#define SIGN(x) ({ \
	(x) < 0 ? -1 : 1; \
})

#endif /* _SGE_HELPERS_H_ */
