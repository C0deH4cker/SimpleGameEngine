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
		
		/*!
		 Returns the total elapsed time since the timer was started.
		 */
		double totalTime() const;
		
		/*! Resets the timer to 0. */
		void reset();
		
		/*! Pauses the timer. */
		void pause();
		
		/*! Resumes the timer. */
		void resume();
		
		/*! Returns true if the timer is currently paused, false otherwise. */
		bool paused() const;
		
	private:
		std::chrono::steady_clock clock;
		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point lastTime;
		std::chrono::steady_clock::time_point pauseTime;
		double skipped;
		bool isPaused;
		
		double timeSince(std::chrono::steady_clock::time_point) const;
	};
}

#endif /* _SGE_TIMER_H_ */
