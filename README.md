# SDL2 Core
C++ handles for SDL2, with exceptions.

## Getting the code
Go to the directory that you will be using for the source code, something like:
```
user@computer:~$ mkdir -pv MySuperGame/src
user@computer:~$ cd MySuperGame/src
user@computer:~/MySuperGame/src$ git submodule add https://github.com/mtkaalund/sdl2core.git
```
There is a example code for initializing the SDL2, SDL_image, SDL_ttf and SDL2_mixer. As there is an example Makefile. Just put them in your source code directory and run `make all`.
## Example of usage

```C++
#include <iostream>
#include <exception>
// SDL2 Subsystem
#include "sdl2core/SDL2.h"
#include "sdl2core/IMG.h"
#include "sdl2core/TTF.h"
#include "sdl2core/MIX.h"

int main( int argc, char * argv[] ) {
    try {
        // SDL2 Video and SDL2 timer subsystem init
        SDL2    sdl2( SDL_INIT_VIDEO | SDL_INIT_TIMER );
        IMG     img( IMG_INIT_PNG );
        MIX     mix( MIX_INIT_MP3 );
        TTF     ttf;
        // Do some thing

    } catch( SDL2Exception &error ) {
        std::cerr << "SDL error: " << error.what() << std::endl;
    } catch( IMGException &error ) {
        std::cerr << "IMG error: " << error.what() << std::endl;
    } catch( MIXException &error ) {
        std::cerr << "MIX error: " << error.what() << std::endl;
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
g++ main.cc sdl2core/*.cc -g -Wall -std=c++11 $(sdl2-config --cflags --libs ) -lSDL2_image -lSDL2_ttf -lSDL2_mixer -o test 
```

An example Makefile
```Makefile
TARGET          := test
CC              := g++
CXXFLAGS        := -g -Wall -std=c++11 $(shell sdl2-config --cflags)
LDFLAGS         := $(shell sdl2-config --libs) -lSDL2_image -lSDL2_ttf -lSDL2_mixer
SDL2CORE_SRC    := $(wildcard sdl2core/*.cc)
SRCS            := $(wildcard *.cc) $(SDL2CORE_SRC)
OBJS            := $(SRCS:.cc=.o)

.PHONY: all clean remake

all: $(TARGET)

$(TARGET): $(OBJS)
        $(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

%.o: %.cc
        $(CC) -c $(CXXFLAGS) -o $@ $<

clean:
        rm -rfv $(OBJS) $(TARGET)
```

So depending on what you are using, you don't need link all SDL2 libraries.

Library | Linker option
--------|--------------
SDL2    | `$(shell sdl2-config --libs)`
IMG     | -lSDL2_image
TTF     | -lSDL2_ttf
MIX     | -lSDL2_mixer