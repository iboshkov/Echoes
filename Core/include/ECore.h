#ifndef ECHOES_CORE_H
#define ECHOES_CORE_H

#include "EPrerequisites.h"
#include "EWindow.h"

namespace Ogre {
	class Root;
}

namespace Echoes {
#ifdef ECHOES_CORE_USE_SFML
	typedef std::vector <Window*> WindowVector;
#endif

	class ECHOES_EXPORT Core
	{
	public:
		Core();
		~Core();
		
		bool initialize();
		void run();
		void render(const float& delta);
		void destroy();

	protected:
		bool				mInitialized;

		WindowVector						mWindows;
		std::unique_ptr<Ogre::Root>			mRoot;
		std::unique_ptr<Ogre::RenderWindow>	mRootWindow;
	};
}


#endif // ECHOES_CORE_H