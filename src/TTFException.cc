#include "TTFException.h"

TTFException::TTFException(): exception(), msg( TTF_GetError() ) {
}

TTFException::TTFException( const std::string& _msg ): exception(), msg( _msg ) {
}

TTFException::~TTFException() throw() {
}

const char * TTFException::what() const throw() {
    return msg.c_str();
}