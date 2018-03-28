#ifndef _SDL2CORE_SDL2_H_
#define _SDL2CORE_SDL2_H_

//! File: SDL2.h
//! Author: MTKaalund
//! License: GPL3 see file LICENSE

extern "C" {
#include <SDL2/SDL.h>
}

#include "SDL2Exception.h"

//! SDL2 Class - an OO implementation of SDL_Init
//!
//! C++ example from https://wiki.libsdl.org/SDL_Init
//! After 4th januar 2017, the example could'nt be found.

class SDL2 {
public:
    //! Constructor. Basicly runs SDL_Init. This will throw an exception with the SDL error message.
    //! \sa SDL_Init
    //! \sa SDL_GetError
    //! \param flags
    //!< Flags can just be or it can be or'ed together
    //!<    -   SDL_INIT_TIMER          -   Timer subsystem
    //!<    -   SDL_INIT_AUDIO          -   audio subsystem
    //!<    -   SDL_INIT_VIDEO          -   video subsystem
    //!<    -   SDL_INIT_JOYSTICK       -   joystick subsystem
    //!<    -   SDL_INIT_HAPTIC         -   force feedback subsystem
    //!<    -   SDL_INIT_GAMECONTROLLER -   controller subsystem
    //!<    -   SDL_INIT_EVENTS         -   events subsystem
    //!<    -   SDL_INIT_EVERYTHING     -   all above subsystems
    //!<    -   SDL_INIT_NOPARACHUTE    -   this flag is ignored
    //!<
    SDL2( int flags = 0 ) throw( SDL2Exception );
    //! Destructor.  Basicly runs SDL_Quit.
    //! \sa SDL_Quit
    virtual ~SDL2();
};

#endif
