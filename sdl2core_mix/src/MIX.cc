#include "sdl2core/MIX.h"

MIX::MIX( int flag ) {
    if( ( Mix_Init( flag ) & flag ) != flag ) {
        throw MIXException();
    }
}

MIX::~MIX() {
    Mix_Quit();
}
