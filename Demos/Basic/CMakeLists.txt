############################################################
# Echoes BasicDemo
############################################################
SET(DEMO_NAME "BasicDemo")
PROJECT(${DEMO_NAME})
file(GLOB HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

find_package(Echoes REQUIRED)

include_directories(
	"${CMAKE_CURRENT_SOURCE_DIR}/include/"
	${OGRE_INCLUDE_DIRS}
)

add_executable(${DEMO_NAME} ${HEADER_FILES} ${SOURCE_FILES})