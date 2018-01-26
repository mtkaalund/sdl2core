#include "IMG2Exception.h"

IMG2Exception::IMG2Exception(): exception(), msg( SDL_GetError() ) {
}

IMG2Exception::IMG2Exception( const std::string& _msg ): exception(), msg( _msg ) {
}

IMG2Exception::~IMG2Exception() throw() {
}

const char* IMG2Exception::what() const throw() {
    return msg.c_str();
}