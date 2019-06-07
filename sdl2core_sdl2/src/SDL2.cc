#include "sdl2core/SDL2.h"

SDL2::SDL2( int flags ) {
    if( SDL_Init( flags ) != 0 ) {
        throw SDL2Exception();
    }
}

SDL2::~SDL2() {
    SDL_Quit();
}
