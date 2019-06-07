#include "sdl2core/NET.h"

NET::NET( ) {
    if( SDLNet_Init( ) != 0 ) {
        throw NETException();
    }
}

NET::~NET() {
    SDLNet_Quit();
}
