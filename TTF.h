#ifndef _SDL2CORE_TTF_H_
#define _SDL2CORE_TTF_H_

extern "C" {
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_ttf.h>
}

#include "TTFException.h"

class TTF {
public:
    TTF() throw( TTFException );
    virtual ~TTF();
};

#endif