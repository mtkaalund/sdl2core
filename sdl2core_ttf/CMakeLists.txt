cmake_minimum_required(VERSION 3.5)
# Subproject name
project(sdl2core_ttf VERSION 0.0.1 DESCRIPTION "A c++ wrapper for SDL2_ttf")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/../cmake")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

if(SDL2_FOUND)
	include_directories(${SDL2_INCLUDE_DIRS})
	set(CMAKE_SHARED_LINKER_FLAGS ${SDL2_LIBRARIES})
	#set_target_properties(${PROJECT_NAME} PROPERTIES INTERFACE_LINK_LIBRARIES ${SDL2_LIBRARIES})
	#	target_link_libraries(${PROJECT_NAME} INTERFACE ${SDL2_LIBRARIES})
endif(SDL2_FOUND)

if(SDL2_IMAGE_FOUND)
	include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
	set(CMAKE_CHARED_LINKER_FLAGS ${SDL2_IMAGE_LIBRARIES})
endif(SDL2_IMAGE_FOUND)

if(SDL2_TTF_FOUND)
	include_directories(${SDL2_TTF_INCLUDE_DIRS})
	set(CMAKE_SHARED_LINKER_FLAGS ${SDL2_TTF_LIBRARIES})
	#	set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS ${SDL2_IMAGE_LIBRARIES})
	#	target_link_libraries(${PROJECT_NAME} INTERFACE${SDL2_IMAGE_LIBRARIES})
endif(SDL2_TTF_FOUND)
# add a library with the above sources
add_library( ${PROJECT_NAME} SHARED src/TTF.cc src/TTFException.cc )
add_library( sdl2core::ttf ALIAS ${PROJECT_NAME} )
target_link_libraries(${PROJECT_NAME} SDL2_ttf)

include(GNUInstallDirs)
set_target_properties( ${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION} )
configure_file(${PROJECT_NAME}.pc.in ${PROJECT_NAME}.pc @ONLY)

target_include_directories( ${PROJECT_NAME} 
	PUBLIC
       		${PROJECT_SOURCE_DIR}/include
		${SDL2_INCLUDE_DIRS}
		${SDL2_IMAGE_INCLUDE_DIRS}
		${SDL2_TTF_INCLUDE_DIRS}
	)
target_include_directories( ${PROJECT_NAME}
	PRIVATE
		${PROJECT_SOURCE_DIR}/src
	)

install(TARGETS ${PROJECT_NAME}
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES ${CMAKE_BINARY_DIR}/${PROJECT_NAME}/${PROJECT_NAME}.pc
	DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
