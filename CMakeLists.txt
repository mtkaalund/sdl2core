cmake_minimum_required(VERSION 3.5)

project(sdl2core)
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${sdl2core_SOURCE_DIR}/cmake")

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")

#find_package(SDL2 REQUIRED)
#find_package(SDL2_image REQUIRED)

#include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_subdirectory(sdl2core_img)
add_subdirectory(sdl2core_sdl2)
add_subdirectory(sdl2core_ttf)
add_subdirectory(sdl2core_net)
add_subdirectory(sdl2core_mix)
add_subdirectory(Debug)
#add_library(sdl2core_sdl2exception STATIC src/SDL2Exception.cc)
#add_library(sdl2core_sdl2exception SHARED src/SDL2Exception.cc)
#add_library(sdl2core_sdl2 STATIC src/libSDL2.cc)
#add_library(sdl2core_sdl2 SHARED src/libSDL2.cc)

#target_link_libraries(sdl2core_sdl2exception ${SDL2_LIBRARY})
#target_link_libraries(sdl2core_sdl2 ${SDL2_LIBRARY})

#install(TARGETS sdl2core_sdl2exception sdl2core_sdl2 DESTINATION lib)
#install(FILES src/SDL2Exception.h src/libSDL2.h DESTINATION include)
