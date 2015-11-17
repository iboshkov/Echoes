// Echoes
#include "EWindow.h"
#include "ECore.h"
// OGRE
#include "OgreRoot.h"
#include "OgreRenderWindow.h"
#include "OgreRenderSystem.h"
// SFML
#include "SFML/Window.hpp"
using namespace Echoes;

Echoes::Window::Window(Core* core, String name, bool fullscreen)
	: mCore(core)
	, mName(name)
	, mRenderWindow(nullptr)
	, mDestroyOnClose(false)
{
	create(fullscreen);
}

Echoes::Window::Window(Core* core, String name, const int& width, const int& height, bool fullscreen)
	: mCore(core)
	, mName(name)
	, mRenderWindow(nullptr)
	, mDestroyOnClose(false)
{
	create(width, height, fullscreen);
}

bool Echoes::Window::update()
{
	sf::Event event;
	while (mSFMLWindow->pollEvent(event)) {
		// eventz;
		if (event.type == sf::Event::Closed)
		{
			mSFMLWindow->close();
			
			return false;
		}
	}

	return true;
}

Echoes::Window::~Window()
{
	// Additional clean up required.
	if (mRenderWindow != nullptr) {
		destroyOGRERenderWindow();
	}
}

void Echoes::Window::addViewport(int layer, int top, int left, int width, int height)
{

}

void Echoes::Window::removeViewport(int layer)
{

}

const Echoes::String Echoes::Window::getName() const
{
	return mName;
}

void Echoes::Window::close()
{
	mSFMLWindow->close();
}

void Echoes::Window::create(bool fullscreen)
{
	create(800, 600, fullscreen);
}

bool Echoes::Window::getDestroyOnClose()
{
	return mDestroyOnClose;
}

bool Echoes::Window::isOpen()
{
	return mSFMLWindow->isOpen();
}

void Echoes::Window::create(int width, int height, bool fullscreen)
{
	if (!mSFMLWindow) {
		mSFMLWindow = std::unique_ptr<sf::Window>(new sf::Window(sf::VideoMode(width, height), mName));
		createOGRERenderWindow();
	}
	else {
		destroyOGRERenderWindow();
		mSFMLWindow->create(sf::VideoMode(width, height), mName, sf::Style::Default);
		createOGRERenderWindow();
	}
}

void Echoes::Window::createOGRERenderWindow()
{

#ifdef ECHOES_CORE_USE_SFML
	Ogre::NameValuePairList params;
	sf::WindowHandle handle = mSFMLWindow->getSystemHandle();
	unsigned long winHandle = reinterpret_cast<unsigned long>(handle);
	//unsigned long winGlContext = reinterpret_cast<unsigned long>(wglGetCurrentContext());
#ifdef _WIN32
	params["externalWindowHandle"] = Ogre::StringConverter::toString(winHandle);
#else
	misc["currentGLContext"] = Ogre::String("true")
#endif
	mRenderWindow = mCore->getOGRERoot()->createRenderWindow(mName, mSFMLWindow->getSize().x, mSFMLWindow->getSize().y, false, &params);
#else
	ECHOES_EXCEPT(Exception::ERR_DEFAULT, "Can't create window without a window library.", "EWindow.cpp");
#endif
}

void Echoes::Window::destroyOGRERenderWindow()
{
	String name = mRenderWindow->getName();
	mCore->getOGRERoot()->getRenderSystem()->destroyRenderWindow(name);
	mRenderWindow = nullptr;
}
