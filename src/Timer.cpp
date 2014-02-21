//
//  Timer.cpp
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/8/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#include "Timer.h"
#include <chrono>

using namespace sge;
using namespace std::chrono;

Timer::Timer()
: skipped(0.0), isPaused(false) {
	startTime = lastTime = clock.now();
}

double Timer::elapsed() const {
	double ret = timeSince(lastTime) - skipped;
	if(isPaused) {
		ret -= timeSince(pauseTime);
	}
	
	return ret;
}

double Timer::tick() {
	double ret = elapsed();
	reset();
	return ret;
}

double Timer::totalTime() const {
	return timeSince(startTime) - skipped;
}

void Timer::reset() {
	isPaused = false;
	skipped = 0.0;
	lastTime = clock.now();
}

void Timer::pause() {
	if(!isPaused) {
		pauseTime = clock.now();
		isPaused = true;
	}
}

void Timer::resume() {
	if(isPaused) {
		skipped += timeSince(pauseTime);
		isPaused = false;
	}
}

bool Timer::paused() const {
	return isPaused;
}


double Timer::timeSince(steady_clock::time_point old) const {
	return duration_cast<duration<double> >(clock.now() - old).count();
}

