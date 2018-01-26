#ifndef _SDL2CORE_MIXEREXCEPTION_H_
#define _SDL2CORE_MIXEREXCEPTION_H_

#include <string>
#include <exception>

extern "C" {
    #include <SDL2/SDL_mixer.h>
}

class MixerException: public std::exception {
public:
    MixerException();
    MixerException( const std::string& );
    virtual ~MixerException();
    virtual const char * what() const throw();
private:
    std::string msg;
};

#endif