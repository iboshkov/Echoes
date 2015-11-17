# - Try to find Echoes
# Once done this will define
#  ECHOES_FOUND - System has Echoes
#  ECHOES_INCLUDE_DIRS - The Echoes include directories
#  ECHOES_LIBRARIES - The libraries needed to use Echoes
#  ECHOES_DEFINITIONS - Compiler switches required for using Echoes

find_path(ECHOES_INCLUDE_DIR Core/ECore.h
          HINTS ${ECHOES_ROOT}/include ${ECHOES_INCLUDE_DIR}
          PATH_SUFFIXES Echoes )
		  
find_package(OGRE REQUIRED)
find_package(Eigen3 REQUIRED)

find_library(ECHOES_CORE_LIBRARY_DBG NAME EchoesCore_d)
find_library(ECHOES_CORE_LIBRARY_REL NAME EchoesCore)

set(ECHOES_LIBRARIES 
	optimized ${ECHOES_CORE_LIBRARY_REL} debug ${ECHOES_CORE_LIBRARY_DBG} 
)

Message(${ECHOES_LIBRARIES})

set(ECHOES_INCLUDE_DIRS 
	${ECHOES_INCLUDE_DIR}
	${ECHOES_INCLUDE_DIR}/Core
	${OGRE_INCLUDE_DIRS}
	${EIGEN3_INCLUDE_DIR}
)

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set LIBXML2_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(Echoes  DEFAULT_MSG
                                  ECHOES_CORE_LIBRARY_DBG ECHOES_CORE_LIBRARY_REL ECHOES_INCLUDE_DIR)

mark_as_advanced(ECHOES_INCLUDE_DIR ECHOES_LIBRARY)
