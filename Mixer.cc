#include "Mixer.h"

Mixer::Mixer( int flags ) throw( MixerException ) {
    if( ( Mix_Init( flags ) & flags ) != flags ) {
        throw MixerException();
    }
}

Mixer::~Mixer() {
    // So as described in the SDL_Mixer documentation, Mix_Init can be initialized multiple times.
    // But since this should remove all instance of Mix_Init, else you can do
    // while( Mix_Init( 0 ) ) {
    //      Mix_Quit();
    //}
    // This should run until all have been unloaded.
    Mix_Quit();
}