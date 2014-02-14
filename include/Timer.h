//
//  Timer.h
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/8/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#ifndef _SGE_TIMER_H_
#define _SGE_TIMER_H_

#include <chrono>
#include "sge_depends.h"


namespace sge {
	/*!
	 Used to measure spans of time with extreme accuracy. Useful as a stopwatch
	 or to measure elapsed time within a run loop.
	 */
	class Timer {
	public:
		/*! Constructs and starts a timer. */
		Timer();
		
		/*!
		 Returns the amount of time in seconds that has elapsed since the last
		 time the timer was reset.
		 */
		double elapsed() const;
		
		/*!
		 Returns the amount of time in seconds that has elapsed since the last
		 time the timer was reset, and then resets it.
		 */
		double tick();
		
		/*! Resets the timer to 0. */
		void reset();
		
	private:
		std::chrono::steady_clock clock;
		std::chrono::steady_clock::time_point lastTime;
	};
}

#endif /* _SGE_TIMER_H_ */
