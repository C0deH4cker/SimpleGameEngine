//
//  Timer.cpp
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/8/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#include "Timer.h"
#include <mach/mach_time.h>


using namespace sge;

Timer::Timer() {
	mach_timebase_info(&timebase);
	reset();
}

double Timer::elapsed() const {
	uint64_t current = mach_absolute_time();
	
	return convertElapsed(current - lastTime);
}

double Timer::tick() {
	double ret = elapsed();
	reset();
	return ret;
}

void Timer::reset() {
	lastTime = mach_absolute_time();
}


double Timer::convertElapsed(uint64_t elapsed) const {
	return (double)elapsed * timebase.numer / (timebase.denom * NSEC_PER_SEC);
}

