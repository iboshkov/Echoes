############################################################
# Echoes core library
############################################################
SET(CORE_PROJECT_NAME "EchoesCore")
PROJECT(${CORE_PROJECT_NAME})
file(GLOB HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

find_package(OGRE REQUIRED)

include_directories(
	"${CMAKE_CURRENT_SOURCE_DIR}/include/"
	${OGRE_INCLUDE_DIRS}
)

add_library(${CORE_PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES})

install(TARGETS ${CORE_PROJECT_NAME}
	CONFIGURATIONS Debug
	RUNTIME DESTINATION bin/Debug
	LIBRARY DESTINATION lib/Debug
	ARCHIVE DESTINATION lib/static/Debug
)

install(TARGETS ${CORE_PROJECT_NAME}
	CONFIGURATIONS Release
	RUNTIME DESTINATION bin/Release
	LIBRARY DESTINATION lib/Release
	ARCHIVE DESTINATION lib/static/Release
)

foreach(HEADER HEADER_FILES)
	string(REGEX MATCH "(.*)[/\\]" DIR ${HEADER})
	install(FILES ${HEADER} DESTINATION include/${DIR})
endforeach(HEADER HEADER_FILES)
