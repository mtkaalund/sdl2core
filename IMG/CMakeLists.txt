# Subproject name
project(IMG)

# add a library with the above sources
add_library( ${PROJECT_NAME} src/IMG.cc src/IMGException.cc )
add_library( sdl2core::img ALIAS ${PROJECT_NAME} )

target_include_directories( ${PROJECT_NAME} 
	PUBLIC ${PROJECT_SOURCE_DIR}/include
	)
