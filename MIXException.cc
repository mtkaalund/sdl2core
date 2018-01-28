#include "MIXException.h"

MIXException::MIXException(): exception(), msg( Mix_GetError() ) {
}

MIXException::MIXException( const std::string& _msg ): exception(), msg( _msg ) {
}

MIXException::~MIXException() throw() {
}

const char * MIXException::what() const throw() {
    return msg.c_str();
}