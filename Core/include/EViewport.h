#ifndef ECHOES_VIEWPORT_H
#define ECHOES_VIEWPORT_H

#include "EPrerequisites.h"

namespace Ogre {
	class RenderWindow;
	class Viewport;
}

namespace Echoes {
	class ECHOES_EXPORT Viewport
	{
	public:
		Viewport() {}
		~Viewport() {}


	protected:
		Ogre::Viewport*		mViewport;
		Ogre::RenderWindow*	mParentWindow;
	};
}


#endif // ECHOES_VIEWPORT_H