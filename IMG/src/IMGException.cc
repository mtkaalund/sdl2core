#include "IMGException.h"

IMGException::IMGException(): exception(), msg( IMG_GetError() ) {
}

IMGException::IMGException( const std::string& _msg ): exception(), msg( _msg ) {
}

//IMGException::~IMGException() throw() {
//}

const char* IMGException::what() const throw() {
    return msg.c_str();
}
