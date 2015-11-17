#ifndef ECHOES_WINDOW_H
#define ECHOES_WINDOW_H

#include "EPrerequisites.h"
#define ECHOES_CORE_USE_SFML

namespace Ogre {
	class RenderWindow;
}

namespace sf {
	class Window;
}

namespace Echoes {

	class ECHOES_EXPORT Window
	{
	public:
		Window() {}
		~Window() {}

		void addViewport(int layer, int top, int left, int width, int height) {}
		void removeViewport(int layer) {}

	protected:
		Ogre::Root*			mRoot;
		Ogre::RenderWindow*	mRootWindow;
#ifdef ECHOES_CORE_USE_SFML
		
#endif
	};
}


#endif // ECHOES_WINDOW_H