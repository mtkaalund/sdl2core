#ifndef _SDL2CORE_TTFEXCEPTION_H_
#define _SDL2CORE_TTFEXCEPTION_H_

#include <string>
#include <exception>

extern "C" {
    #include <SDL2/SDL.h>
    #include <SDL2/SDL_ttf.h>
}

class TTFException : public std::exception {
public:
    TTFException();
    TTFException( const std::string& );
    virtual ~TTFException() throw() {}
    virtual const char * what() const throw();
private:
    std::string msg;
};

#endif
