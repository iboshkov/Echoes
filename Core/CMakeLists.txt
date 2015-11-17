############################################################
# Echoes core library
############################################################
SET(CORE_PROJECT_NAME "EchoesCore")
PROJECT(${CORE_PROJECT_NAME})
file(GLOB HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

find_package(OGRE REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(SFML COMPONENTS window system audio REQUIRED)

include_directories(
	"${CMAKE_CURRENT_SOURCE_DIR}/include/"
	${OGRE_INCLUDE_DIRS}
	${EIGEN3_INCLUDE_DIR}
	${SFML_INCLUDE_DIR}
)

link_directories(${Boost_LIBRARY_DIRS})

add_library(${CORE_PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(
	${CORE_PROJECT_NAME}
	${OGRE_LIBRARIES}
	${SFML_LIBRARIES}
)
set_target_properties(${CORE_PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "_d")

install(TARGETS ${CORE_PROJECT_NAME}
	CONFIGURATIONS Debug
	RUNTIME DESTINATION bin/Debug
	LIBRARY DESTINATION lib/Debug
	ARCHIVE DESTINATION lib/Debug
)

install(TARGETS ${CORE_PROJECT_NAME}
	CONFIGURATIONS Debug
	RUNTIME DESTINATION ${DEMO_WORKING_DIR}/Debug
)

install(TARGETS ${CORE_PROJECT_NAME}
	CONFIGURATIONS Release
	RUNTIME DESTINATION ${DEMO_WORKING_DIR}/Release
)

install(TARGETS ${CORE_PROJECT_NAME}
	CONFIGURATIONS Release
	RUNTIME DESTINATION bin/Release
	LIBRARY DESTINATION lib/Release
	ARCHIVE DESTINATION lib/Release
)

install(FILES ${HEADER_FILES} DESTINATION include/Core)