# Subproject name
project(SDL2)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
find_package(SDL2 REQUIRED)

if(SDL2_FOUND)
	include_directories(${SDL2_INCLUDE_DIRS})
	set(CMAKE_SHARED_LINKER_FLAGS ${SDL2_LIBRARIES})
endif(SDL2_FOUND)

add_library( ${PROJECT_NAME} STATIC src/SDL2.cc src/SDL2Exception.cc )
add_library( sdl2core::SDL2 ALIAS ${PROJECT_NAME} )

target_include_directories( ${PROJECT_NAME} 
	PUBLIC
       		${PROJECT_SOURCE_DIR}/include
	)
