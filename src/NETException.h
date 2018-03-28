#ifndef _SDL2CORE_IMGEXCEPTION_H_
#define _SDL2CORE_IMGEXCEPTION_H_

#include <string>
#include <exception>

extern "C" {
    #include <SDL2/SDL_net.h>
}

class NETException : public std::exception {
public:
    NETException();
    NETException( const std::string& );
    virtual ~NETException();
    virtual const char * what() const throw();
private:
    std::string msg;
};

#endif