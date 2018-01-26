#include "IMG.h"

IMG::IMG( int flags ) throw( IMGException ) {
    if( ! ( IMG_Init( flags ) & flags ) ) {
        throw IMGException();
    }
}

IMG::~IMG() {
    IMG_Quit();
}