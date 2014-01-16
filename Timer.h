//
//  Timer.h
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/8/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#pragma once

#include <mach/mach_time.h>


namespace sge {
	class Timer {
	public:
		Timer();
		
		double elapsed() const;
		double tick();
		void reset();
		
	private:
		mach_timebase_info_data_t timebase;
		uint64_t lastTime;
		
		double convertElapsed(uint64_t) const;
	};
}

