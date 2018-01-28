#include "MIX.h"

MIX::MIX( int flag ) throw( MIXException ) {
    if( ( Mix_Init( flag ) & flag ) != flag ) {
        throw MIXException();
    }
}

MIX::~MIX() {
    Mix_Quit();
}