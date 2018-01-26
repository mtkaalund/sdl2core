#include "MixerException.h"

MixerException::MixerException(): exception(), msg( Mix_GetError() ) {
}

MixerException::MixerException( const std::string& _msg ): exception(), msg( _msg ) {
}

MixerException::~MixerException() throw() {
}

const char* MixerException::what() const throw() {
    return msg.c_str();
}