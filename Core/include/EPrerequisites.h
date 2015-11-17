#ifndef ECHOES_PREREQUISITES_H
#define ECHOES_PREREQUISITES_H

#ifdef _WIN32
#	ifdef ECHOES_DLL
#		define ECHOES_EXPORT __declspec(dllexport)
#	else
		#define ECHOES_EXPORT __declspec(dllimport)
#	endif
#	define ECHOES_NORETURN __declspec(noreturn)
#else
#	define ECHOES_EXPORT
#	define ECHOES_NORETURN
#endif // _WIN32

#include "Eigen/Dense"
#include "OgreString.h"
#include <vector>
#include <memory>

namespace Echoes {
	class Exception;

	typedef Ogre::String String;
}

#endif // ECHOES_PREREQUISITES_H