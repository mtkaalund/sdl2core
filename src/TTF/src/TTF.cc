#include "TTF.h"

TTF::TTF() throw( TTFException ) {
    if( ( ! TTF_WasInit() ) && ( TTF_Init() == -1 ) ) {
        throw TTFException();
    }
}

TTF::~TTF() {
    TTF_Quit();
}