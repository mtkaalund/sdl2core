#ifndef _SDL2CORE_IMG_H_
#define _SDL2CORE_IMG_H_

extern "C" {
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_image.h>
}

#include "IMGException.h"

class IMG {
public:
    IMG( int flags = 0 ) throw( IMGException);
    virtual ~IMG();
};

#endif