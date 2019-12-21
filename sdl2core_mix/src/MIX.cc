#include "sdl2core/MIX.h"

MIX::MIX( int frequency, Uint16 format, int channels, int chunksize, int flag ) {
    // There is a bug in SDL2 Mixer, where no support for audio files unless
    // Mix_OpenAudio is called. So here we are.
    if( Mix_OpenAudio( frequency, format, channels, chunksize ) < 0 ) {
        throw MIXException();
    }

    int result  = 0;
    if( flag != ( result = Mix_Init( flag ) ) ) {
        throw MIXException();
    }
}

MIX::~MIX() {
    Mix_CloseAudio();
    Mix_Quit();
}
