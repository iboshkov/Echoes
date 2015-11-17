############################################################
# Echoes Python bindings for Core
############################################################
SET(PROJECT_NAME "ECorePy")
PROJECT(${PROJECT_NAME})
file(GLOB HEADER_FILES "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

find_package(Echoes REQUIRED)
find_package(Eigen3 REQUIRED)


find_package(Boost COMPONENTS python REQUIRED)
find_package(PythonLibs REQUIRED)
message("Include dirs of Python: " ${PYTHON_INCLUDE_DIRS} )
message("Libs of Python: " ${PYTHON_LIBRARIES} )

include_directories(
	"${CMAKE_CURRENT_SOURCE_DIR}/include/"
	${Boost_INCLUDE_DIRS}
	${ECHOES_INCLUDE_DIRS}
	${PYTHON_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} 
	${ECHOES_LIBRARIES} 
	${Boost_LIBRARIES}
	${PYTHON_LIBRARIES}
)

set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".pyd")

install(TARGETS ${PROJECT_NAME}
	CONFIGURATIONS Debug
	RUNTIME DESTINATION bin/Debug
	LIBRARY DESTINATION lib/Debug
	ARCHIVE DESTINATION lib/Debug
)

# To working directory
install(TARGETS ${PROJECT_NAME}
	CONFIGURATIONS Debug
	RUNTIME DESTINATION ${DEMO_WORKING_DIR}/Debug
)

# To working directory
install(TARGETS ${PROJECT_NAME}
	CONFIGURATIONS
	RUNTIME DESTINATION ${DEMO_WORKING_DIR}/Release
)

install(TARGETS ${PROJECT_NAME}
	CONFIGURATIONS Release
	RUNTIME DESTINATION bin/Release
	LIBRARY DESTINATION lib/Release
	ARCHIVE DESTINATION lib/Release
)