# SDL2 Core
C++ handles for SDL2, with exceptions. When the program exits this automatic quits it library.

## TODO
- [ ] Need to create `make install`
- [ ] Need to include win in shared library
- [ ] Need to update README.md to show how to use shared library

## Getting the code
~~Go to the directory that you will be using for the source code, something like:~~
```
user@computer:~$ mkdir -pv MySuperGame/src
user@computer:~$ cd MySuperGame/src
user@computer:~/MySuperGame/src$ git submodule add https://github.com/mtkaalund/sdl2core.git
```
~~There is a example code for initializing the SDL2, SDL2_image, SDL2_ttf, SDL2_net and SDL2_mixer. As there is an example Makefile. Just put them in your source code directory and run `make all`.~~
## Example of usage

```C++
#include <iostream>
#include <exception>
// SDL2 Subsystem
#include "sdl2core/SDL2.h"
#include "sdl2core/IMG.h"
#include "sdl2core/TTF.h"
#include "sdl2core/MIX.h"
#include "sdl2core/NET.h"

int main( int argc, char * argv[] ) {
    try {
        // SDL2 Video and SDL2 timer subsystem init
        SDL2    sdl2( SDL_INIT_VIDEO | SDL_INIT_TIMER );
        IMG     img( IMG_INIT_PNG );
        MIX     mix( MIX_INIT_MP3 );
        TTF     ttf;
        NET     net;
        // Do some thing

    } catch( SDL2Exception &error ) {
        std::cerr << "SDL error: " << error.what() << std::endl;
    } catch( IMGException &error ) {
        std::cerr << "IMG error: " << error.what() << std::endl;
    } catch( MIXException &error ) {
        std::cerr << "MIX error: " << error.what() << std::endl;
    } catch( TTFException &error ) {
        std::cerr << "TTF error: " << error.what() << std::endl;
    } catch( NETException &error )  {
        std::cerr << "NET error: " << error.what() << std::endl;
    } catch( const std::exception &error ) {
        std::cerr << "Exception: " << error.what() << std::endl;
    }

    return 0;
}
```

## Linux compilation
~~By using g++~~
```
g++ main.cc sdl2core/*.cc -g -Wall -std=c++11 $(sdl2-config --cflags --libs ) -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_net -o test 
```

~~An example Makefile~~
```Makefile
TARGET          := test
CC              := g++
CXXFLAGS        := -g -Wall -std=c++11 $(shell sdl2-config --cflags)
LDFLAGS         := $(shell sdl2-config --libs) -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_net
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
NET     | -lSDL2_net

## SDL2 urls

Library | Url
--------|-----
SDL2 | https://www.libsdl.org/
SDL2_Image | https://www.libsdl.org/projects/SDL_image/
SDL2_ttf | https://www.libsdl.org/projects/SDL_ttf/
SDL2_mixer | https://www.libsdl.org/projects/SDL_mixer/
SDL2_net | https://www.libsdl.org/projects/SDL_net/

## Some other urls
Gernot Klingler has a slight outdated tutorial on how to make a shared library. The only thing that have change is in newer gcc, you'll have to `g++ -o libshared.so -fPIC -shared shared.cpp` instead of `g++ -fPIC -shared shared.cpp -o libshared.so`.
But do check it out the blog: http://gernotklingler.com/blog/creating-using-shared-libraries-different-compilers-different-operating-systems/

Angel Leon (@gubatron) has created a usefull note on compiling with shared libraries. Do check it out: https://gist.github.com/gubatron/32f82053596c24b6bec6

George Brocklehurst has made a article about how to use configure, make, make install: https://robots.thoughtbot.com/the-magic-behind-configure-make-make-install
