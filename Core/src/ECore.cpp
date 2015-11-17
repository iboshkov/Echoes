#include "ECore.h"
#include "EException.h"
#include "OgreRoot.h"
#include "OgreRenderWindow.h"
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
	mRoot.reset();
	mRootWindow.reset();
}

void Core::run()
{

}

void Echoes::Core::render(const float& delta)
{
	if (!mInitialized)
		ECHOES_EXCEPT(Exception::ERR_DEFAULT, "Trying to render without initializing the core.", "ECore.cpp");
	mRoot->renderOneFrame(delta);
}
