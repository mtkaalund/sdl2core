#ifndef _SDL2CORE_MIXEXCEPTION_H_
#define _SDL2CORE_MIXEXCEPTION_H_

#include <string>
#include <exception>

extern "C" {
    #include <SDL2/SDL_mixer.h>
}

class MIXException : public std::exception {
public:
    MIXException();
    MIXException( const std::string& );
    virtual ~MIXException() throw() {}
    virtual const char * what() const throw();
private:
    std::string msg;
};


#endif
