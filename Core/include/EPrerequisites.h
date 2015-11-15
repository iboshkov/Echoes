#ifndef ECHOES_PREREQUISITES_H
#define ECHOES_PREREQUISITES_H

#ifdef _WIN32
#	ifdef ECHOES_DLL
#		define ECHOES_EXPORT __declspec(dllexport)
#	else
		#define ECHOES_EXPORT __declspec(dllimport)
#	endif
#else
#	define ECHOES_EXPORT
#endif // _WIN32

#endif // ECHOES_PREREQUISITES_H