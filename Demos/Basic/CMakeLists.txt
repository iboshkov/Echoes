############################################################
# Echoes BasicDemo
############################################################
SET(DEMO_NAME "BasicDemo")
SET(DEMO_WORKING_DIR "-" CACHE STRING "")
PROJECT(${DEMO_NAME})
file(GLOB HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

find_package(Echoes REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories(
	"${CMAKE_CURRENT_SOURCE_DIR}/include/"

	${ECHOES_INCLUDE_DIRS}
)

add_executable(${DEMO_NAME} ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(${DEMO_NAME} ${ECHOES_LIBRARIES})