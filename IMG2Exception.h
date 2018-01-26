#ifndef _SDL2CORE_IMG2EXCEPTION_H_
#define _SDL2CORE_IMG2EXCEPTION_H_

#include <string>
#include <exception>

extern "C" {
    #include <SDL2/SDL_image.h>
}

class IMG2Exception : public std::exception {
public:
    IMG2Exception();
    IMG2Exception( const std::string& );
    virtual ~SDL2Exception();
    virtual const char * what() const throw();
private:
    std::string msg;
};

#endif