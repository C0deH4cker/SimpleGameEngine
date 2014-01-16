//
//  Content.cpp
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/13/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#include "Content.h"

using namespace sge;

Content::Content(std::string baseDir)
: dir(baseDir) {
	if(dir.back() != '/')
		dir += '/';
}

