#include "ECore.h"
#include "EException.h"
#include "OgreRoot.h"
#include "OgreRenderWindow.h"
#include "OgreWindowEventUtilities.h"
#include <iostream>
using namespace Echoes;

Core::Core()
{
	mRoot = nullptr;
	mRootWindow = nullptr;
	mInitialized = false;
}

Core::~Core()
{
	if (mInitialized)
		destroy();
}

bool Core::initialize()
{
	if (mInitialized)
		ECHOES_EXCEPT(Exception::ERR_DEFAULT, "Failed while initializing Echoes Core - Already initialized.", "ECore.cpp");

	mRoot = std::make_unique<Ogre::Root>();
	if (!mRoot->showConfigDialog())
	{
		mRoot.reset();
		return false;	
	}
	mRootWindow = std::unique_ptr <Ogre::RenderWindow>(mRoot->initialise(true, "Echoes v0"));
	mRootWindow->setHidden(true);
	mInitialized = true;
	return true;
}

void Core::destroy()
{
	if (!mInitialized)
		ECHOES_EXCEPT(Exception::ERR_DEFAULT, "Trying to destroy an uninitialized Echoes Core.", "ECore.cpp");
	if (mRoot) mRoot.reset();
	if (mRootWindow) mRootWindow.release();
	mInitialized = false;
}

void Core::run()
{

}

void Echoes::Core::render(const float& delta)
{
	if (!mInitialized)
		ECHOES_EXCEPT(Exception::ERR_DEFAULT, "Trying to render without initializing the core.", "ECore.cpp");
	Ogre::WindowEventUtilities::messagePump();
	updateWindows();
	mRoot->renderOneFrame(delta);
}

void Echoes::Core::updateWindows()
{
	for (std::unique_ptr<Window>& window : mWindows)
	{
		window->update();
		if (!window->isOpen() && window->getDestroyOnClose()) {
			mWindowsToDelete.push_back(window->getName());
		}
	}
	if (mWindowsToDelete.size() == 0) return;
	for (String& window : mWindowsToDelete)
	{
		destroyWindow(window);
	}
	mWindowsToDelete.clear();
}

Window* Echoes::Core::createWindow(const String& name, int width, int height, bool fullscreen /*= false*/)
{
	mWindows.push_back(std::unique_ptr<Window>(new Window(this, name, width, height, fullscreen)));
	return mWindows.back().get();
}

void Echoes::Core::destroyWindow(const String& name)
{
	mWindows.erase(remove_if(mWindows.begin(), mWindows.end(), [name](const std::unique_ptr<Window>& wnd) {
		return wnd->getName() == name;
	}), mWindows.end());
}

Ogre::Root* Echoes::Core::getOGRERoot()
{
	return mRoot.get();
}
