#ifndef _SDL2CORE_MIXER_H_
#define _SDL2CORE_MIXER_H_

//! File: Mixer.h
//! Author: MTKaalund
//! License: GPL3 see file LICENSE

extern "C" {
#include <SDL2/SDL_mixer.h>
}

#include "MixerException.h"
//! SDL_Mixer Class - an OO implementation of Mix_Init
//! https://www.libsdl.org/projects/SDL_mixer/docs/

class Mixer {
public:
    //! Constructor. Basicly runs Mix_Init. This will throw an exception with the Mix error message.
    //! \sa Mix_Init
    //! \sa Mix_GetError
    //! \param flags
    //!< Flags can just be or it can be or'ed together
    //!<    -   MIX_INIT_FLAC       -   FLAC library on system
    //!<    -   MIX_INIT_MOD        -   libmikmod on system
    //!<    -   MIX_INIT_MP3        -   SMPEG or MAD library on system
    //!<    -   MIX_INIT_OGG        -   ogg/vorbis libraries on system
    //!<
    Mixer( int flags = 0 ) throw( MixerException );
    //! Destructor.  Basicly runs Mix_Quit.
    //! \sa Mix_Quit
    virtual ~Mixer();
};

#endif