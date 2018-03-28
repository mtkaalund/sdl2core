#ifndef _SDL2CORE_TTF_H_
#define _SDL2CORE_TTF_H_

extern "C" {
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_ttf.h>
}

#include "TTFException.h"

class TTF {
public:
    //! Constructor. Basicly runs TTF_Init. This will throw an exception with the TTF error message.
    //! \sa TTF_Init
    //! \sa TTF_GetError
    TTF() throw( TTFException );
    //! Destructor.  Basicly runs TTF_Quit.
    //! \sa TTF_Quit
    virtual ~TTF();
};

#endif