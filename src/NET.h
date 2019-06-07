#ifndef _SDL2CORE_NET_H_
#define _SDL2CORE_NET_H_

extern "C" {
    #include <SDL2/SDL_net.h>
}

#include "NETException.h"

class NET {
public:
    //! Constructor. Basicly runs SDLNet_Init. This will throw an exception with the SDL net error message.
    //! \sa SDLNet_Init
    //! \sa SDLNet_GetError
    NET();// throw( NETException );
    //! Destructor.  Basicly runs SDLNet_Quit.
    //! \sa SDLNet_Quit
    virtual ~NET();
};

#endif
