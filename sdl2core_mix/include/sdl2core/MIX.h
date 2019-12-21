#ifndef _SDL2CORE_MIX_H_
#define _SDL2CORE_MIX_H_

extern "C" {
    #include <SDL2/SDL_mixer.h>
}

#include "MIXException.h"

class MIX {
public:
    //! Constructor. Basicly runs Mix_Init. This will throw an exception with the Mix error message.
    //! \sa Mix_Init
    //! \sa Mix_GetError
    //! \param frequency
    //! \param format
    //! \param channels
    //! \param chunksize
    //! \param flags
    //!< Flags can just be or it can be or'ed together
    //!<    -   MIX_INIT_FLAC       -   FLAC audio
    //!<    -   MIX_INIT_MOD        -   MOD audio
    //!<    -   MIX_INIT_MP3        -   MP3 audio
    //!<    -   MIX_INIT_OGG        -   Vogorbis audio
    //!<
    MIX( int frequency = 0, Uint16 format = 0, int channels = 0, int chunksize = 0, int flags = 0 );// throw( MIXException );
    //! Destructor.  Basicly runs Mix_Quit.
    //! \sa Mix_Quit
    virtual ~MIX();
};


#endif
