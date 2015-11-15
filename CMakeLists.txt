cmake_minimum_required(VERSION 3.3)
project(Echoes)

set(CMAKE_MODULE_PATH
	${CMAKE_MODULE_PATH}
	"${CMAKE_SOURCE_DIR}/CMake/"
	"${CMAKE_SOURCE_DIR}/CMake/OGRE/"
	"${CMAKE_SOURCE_DIR}/CMake/OGRE/Utils"
	"${CMAKE_SOURCE_DIR}/CMake/OGRE/Packages"
)

SET(ECHOES_STATIC OFF CACHE BOOL "Build as libraries static or shared.")

if (NOT ECHOES_STATIC)
	add_definitions(-DECHOES_DLL)
endif()

add_subdirectory(./Core Core)
add_subdirectory(./Demos Demos)