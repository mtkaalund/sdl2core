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
    //!< Frequency: MIX_DEFAULT_FREQUENCY is 22050 Hz as this do not use as much CPU as 44100 Hz.
    //! \param format
    //!< Format: MIX_DEFAULT_FORMAT is AUDIO_S16SYS but can be
    //!<   -   AUDIO_U8            -   Unsigned 8-bit samples
    //!<   -   AUDIO_S8            -   Signed 8-bit samples
    //!<   -   AUDIO_U16LSB        -   Unsigned 16-bit sample, little-endian
    //!<   -   AUDIO_S16LSB        -   Signed 16-bit sample, little-endian
    //!<   -   AUDIO_U16MSB        -   Unsigned 16-bit sample, big-endian
    //!<   -   AUDIO_S16MSB        -   Signed 16-bit sample, big-endian
    //!<   -   AUDIO_U16           -   Same as AUDIO_U16LSB (backward combatability)
    //!<   -   AUDIO_S16           -   Same as AUDIO_S16LSB (backward combatability)
    //!<   -   AUDIO_U16SYS        -   Unsigned 16-bit sample, system order
    //!<   -   AUDIO_S16SYS        -   Signed 16-bit sample, system order
    //! \param channels
    //!< Channels: 2 for stereo and 1 for mono
    //! \param chunksize
    //!< Chunksize default is 1024
    //! \param flags
    //!< Flags can just be or it can be or'ed together
    //!<    -   MIX_INIT_FLAC       -   FLAC audio
    //!<    -   MIX_INIT_MOD        -   MOD audio
    //!<    -   MIX_INIT_MP3        -   MP3 audio
    //!<    -   MIX_INIT_OGG        -   Vogorbis audio
    //!<
    MIX( int frequency = MIX_DEFAULT_FREQUENCY, Uint16 format = MIX_DEFAULT_FORMAT, int channels = MIX_DEFAULT_CHANNELS, int chunksize = 1024, int flags = 0 );// throw( MIXException );
    //! Destructor.  Basicly runs Mix_Quit.
    //! \sa Mix_Quit
    virtual ~MIX();
};


#endif
