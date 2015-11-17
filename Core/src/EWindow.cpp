#ifndef ECHOES_CORE_H
#define ECHOES_CORE_H

#include "EPrerequisites.h"

namespace Ogre {
	class Root;
}

namespace Echoes {
	class ECHOES_EXPORT Core
	{
	public:
		Core();
		~Core();
		
		void initialize();
		void run();
		void render(const float& delta);
		void destroy();

	protected:
		bool				mInitialized;
		Ogre::Root*			mRoot;
		Ogre::RenderWindow*	mRootWindow;
	};
}


#endif // ECHOES_CORE_H