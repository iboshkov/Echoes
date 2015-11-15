# - Try to find Echoes
# Once done this will define
#  ECHOES_FOUND - System has Echoes
#  ECHOES_INCLUDE_DIRS - The Echoes include directories
#  ECHOES_LIBRARIES - The libraries needed to use Echoes
#  ECHOES_DEFINITIONS - Compiler switches required for using Echoes

find_path(ECHOES_INCLUDE_DIR Core/ECore.h
          HINTS ${ECHOES_ROOT}/include ${ECHOES_INCLUDE_DIR}
          PATH_SUFFIXES libxml2 )

find_library(ECHOES_LIBRARY NAME EchoesCore
             HINTS ${ECHOES_ROOT} ${ECHOES_LIBRARY_DIR} )

set(ECHOES_LIBRARIES ${ECHOES_LIBRARY} )
set(ECHOES_INCLUDE_DIRS ${ECHOES_INCLUDE_DIR} )

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set LIBXML2_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(Echoes  DEFAULT_MSG
                                  ECHOES_LIBRARY ECHOES_INCLUDE_DIR)

mark_as_advanced(ECHOES_INCLUDE_DIR ECHOES_LIBRARY)
