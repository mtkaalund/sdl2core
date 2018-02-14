#include "NET.h"

NET::NET( ) throw( NETException ) {
    if( SDLNet_Init( ) != 0 ) {
        throw NETException();
    }
}

NET::~NET() {
    SDLNet_Quit();
}
