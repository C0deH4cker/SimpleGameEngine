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

Timer::Timer() {
	reset();
}

double Timer::elapsed() const {
	auto span = duration_cast<duration<double> >(clock.now() - lastTime);
	return span.count();
}

double Timer::tick() {
	double ret = elapsed();
	reset();
	return ret;
}

void Timer::reset() {
	lastTime = clock.now();
}

