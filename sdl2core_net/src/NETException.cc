#include "sdl2core/NETException.h"

NETException::NETException(): exception(), msg( SDLNet_GetError() ) {
}

NETException::NETException( const std::string& _msg ): exception(), msg( _msg ) {
}

//NETException::~NETException() throw() {
//}

const char * NETException::what() const throw() {
    return msg.c_str();
}
