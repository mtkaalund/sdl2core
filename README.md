# SDL2 Core
C++ handles for SDL2, with exceptions.

## Example of usage

```C++
#include <iostream>
#include <exception>
// SDL2 Subsystem
#include "sdl2core/SDL2.h"
#include "sdl2core/IMG.h"
#include "sdl2core/TTF.h"

int main( int argc, char * argv[] ) {
    try {
        // SDL2 Video and SDL2 timer subsystem init
        SDL2    sdl2( SDL_INIT_VIDEO | SDL_INIT_TIMER );
        IMG     img( IMG_INIT_PNG );
        TTF     ttf;
        // Do some thing

    } catch( SDL2Exception &error ) {
        std::cerr << "SDL error: " << error.what() << std::endl;
    } catch( IMGException &error ) {
        std::cerr << "IMG error: " << error.what() << std::endl;
    } catch( TTFException &error ) {
        std::cerr << "TTF error: " << error.what() << std::endl;
    } catch( const std::exception &error ) {
        std::cerr << "Exception: " << error.what() << std::endl;
    }

    return 0;
}
```

## Linux compilation
By using g++
```
g++ main.cc sdl2core/*.cc -g -Wall -std=c++11 $(sdl2-config --cflags --libs ) -lSDL2_image -lSDL2_ttf -o test 
```

An example Makefile
```Makefile
TARGET          := test
CC              := g++
CXXFLAGS        := -g -Wall -std=c++11 $(shell sdl2-config --cflags)
LDFLAGS         := $(shell sdl2-config --libs) -lSDL2_image -lSDL2_ttf
SDL2CORE_SRC    := $(wildcard sdl2core/*.cc)
SRCS            := $(wildcard *.cc) $(SDL2CORE_SRC)
OBJS            := $(SRCS:.cc=.o)

.PHONY: all clean remake

clean:
    @rm -rfv $(OBJS) $(TARGET)

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.cc
    $(CC) -c $(CXXFLAGS) -o $@ $<
```