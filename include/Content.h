//
//  Content.h
//  SimpleGameEngine
//
//  Created by C0deH4cker on 12/13/13.
//  Copyright (c) 2013 C0deH4cker. All rights reserved.
//

#ifndef _SGE_CONTENT_H_
#define _SGE_CONTENT_H_

#include <string>
#include "sge_depends.h"


namespace sge {
	/*! Allows easy loading of assets from a central resources directory. */
	class Content {
	public:
		/*! Constructs a content manager.
		 @param baseDir The relative base directory containing all resources.
		 */
		Content(std::string baseDir=".");
		
		/*! Loads an asset of type T from the resources directory.
		 @param T The type of resource contained in the file.
		 @param filename The name of the file to load.
		 @param args Additional arguments passed to the resource's constructor.
		 @return A pointer to a newly created instance of the loaded resource.
		 */
		template <typename T, typename... Args>
		T* load(std::string filename, Args... args) const {
			return new T(dir + filename, args...);
		}
		
	private:
		std::string dir;
	};
}

#endif /* _SGE_CONTENT_H_ */
