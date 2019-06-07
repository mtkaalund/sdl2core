#ifndef _SDL2CORE_SDL2EXCEPTION_H_
#define _SDL2CORE_SDL2EXCEPTION_H_

#include <string>
#include <exception>

extern "C" {
    #include <SDL2/SDL.h>
}

class SDL2Exception : public std::exception {
public:
    SDL2Exception();
    SDL2Exception( const std::string& );
    virtual ~SDL2Exception() throw() {}
    virtual const char * what() const throw();
private:
    std::string msg;
};

#endif
