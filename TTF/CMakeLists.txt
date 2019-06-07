# Subproject name
project(TTF)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)

if(SDL2_FOUND)
	include_directories(${SDL2_INCLUDE_DIRS})
	set(CMAKE_SHARED_LINKER_FLAGS ${SDL2_LIBRARIES})
	#set_target_properties(${PROJECT_NAME} PROPERTIES INTERFACE_LINK_LIBRARIES ${SDL2_LIBRARIES})
	#	target_link_libraries(${PROJECT_NAME} INTERFACE ${SDL2_LIBRARIES})
endif(SDL2_FOUND)

if(SDL2_ttf_FOUND)
	include_directories(${SDL2_TTF_INCLUDE_DIRS})
	set(CMAKE_SHARED_LINKER_FLAGS ${SDL2_TTF_LIBRARIES})
	#	set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS ${SDL2_IMAGE_LIBRARIES})
	#	target_link_libraries(${PROJECT_NAME} INTERFACE${SDL2_IMAGE_LIBRARIES})
endif(SDL2_ttf_FOUND)
# add a library with the above sources
add_library( ${PROJECT_NAME} STATIC src/TTF.cc src/TTFException.cc )
add_library( sdl2core::ttf ALIAS ${PROJECT_NAME} )

target_include_directories( ${PROJECT_NAME} 
	PUBLIC
       		${PROJECT_SOURCE_DIR}/include
	)
