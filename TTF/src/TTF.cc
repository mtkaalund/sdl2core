#include "sdl2core/TTF.h"

TTF::TTF() {
    if( ( ! TTF_WasInit() ) && ( TTF_Init() == -1 ) ) {
        throw TTFException();
    }
}

TTF::~TTF() {
    TTF_Quit();
}
