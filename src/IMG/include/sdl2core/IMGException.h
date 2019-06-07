#ifndef _SDL2CORE_IMGEXCEPTION_H_
#define _SDL2CORE_IMGEXCEPTION_H_

#include <string>
#include <exception>

extern "C" {
    #include <SDL2/SDL_image.h>
}

class IMGException : public std::exception {
public:
    IMGException();
    IMGException( const std::string& );
    virtual ~IMGException() throw() {}
    virtual const char * what() const throw();
private:
    std::string msg;
};

#endif
