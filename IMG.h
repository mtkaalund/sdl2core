#ifndef _SDL2CORE_IMG_H_
#define _SDL2CORE_IMG_H_

//! File: IMG.h
//! Author: MTKaalund
//! License: GPL3 see file LICENSE

extern "C" {
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
}

#include "IMGException.h"

//! IMG Class - an OO implementation of IMG_Init
//!
//! C++ example from https://wiki.libsdl.org/SDL_Init
//! After 4th januar 2017, the example could'nt be found.
class IMG {
public:
    //! Constructor. Basicly runs IMG_Init. This will throw an exception with the SDL error message.
    //! \sa IMG_Init
    //! \sa IMG_GetError
    //! \param flags
    //!< Flags can just be or it can be or'd together
    //!<    -   IMG_INIT_JPG    -   JPG support enabled
    //!<    -   IMG_INIT_PNG    -   PNG support enabled
    //!<    -   IMG_INIT_TIF    -   TIF support enabled
    //!<
    IMG( int flags = 0 ) throw( IMGException);
    //! Destructor.  Basicly runs IMG_Quit.
    //! \sa IMG_Quit
    virtual ~IMG();
};

#endif