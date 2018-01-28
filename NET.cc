#include "NET.h"

NET::NET( ) throw( NETException ) {
    if( SDLNet_Init( ) != 0 ) {
        throw MIXException();
    }
}

NET::~NET() {
    SDLNet_Quit();
}