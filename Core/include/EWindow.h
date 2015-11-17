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
	class Core;
	class ECHOES_EXPORT Window
	{
		// Give Core access to the constructor and destructor.
		friend class Core;
	public:
		~Window();

		void addViewport(int layer, int top, int left, int width, int height);
		void removeViewport(int layer);
		const String getName() const;

		void close();
		void create(int width, int height, bool fullscreen = false);
		void create(bool fullscreen = false);
		bool getDestroyOnClose();
		bool isOpen();

	private:
		void createOGRERenderWindow();
		void destroyOGRERenderWindow();

	protected:
		Window(Core* core, String name, bool fullscreen = false);
		Window(Core* core, String name, const int& width, const int& height, bool fullscreen = false);
		
		bool update();

	protected:
		Core*							mCore;
		String							mName;
		bool							mDestroyOnClose;
		Ogre::RenderWindow*				mRenderWindow;
#ifdef ECHOES_CORE_USE_SFML
		std::unique_ptr<sf::Window>		mSFMLWindow;
#endif
	};
}


#endif // ECHOES_WINDOW_H