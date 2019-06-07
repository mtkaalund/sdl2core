#include "sdl2core/SDL2Exception.h"

SDL2Exception::SDL2Exception(): exception(), msg( SDL_GetError() ) {
}

SDL2Exception::SDL2Exception( const std::string& _msg ): exception(), msg( _msg ) {
}

//SDL2Exception::~SDL2Exception() throw() {
//}

const char* SDL2Exception::what() const throw() {
    return msg.c_str();
}
