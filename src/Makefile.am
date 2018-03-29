AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_FLAGS)

lib_LTLIBRARIES = libsdl2.la libttf.la libnet.la libmix.la libimg.la

libsdl2_LDFLAGS = -L/usr/lib/x86_64-linux-gnu -lSDL2 
libsdl2_SOURCES = SDL2.cc SDL2.h SDL2Exception.cc SDL2Exception.h

libttf_LDFLAGS = -L/usr/lib/x86_64-linux-gnu -lSDL2 -lSDL2_ttf
libttf_SOURCES = TTF.cc TTF.h TTFException.cc TTFException.h

libnet_LDFLAGS = -L/usr/lib/x86_64-linux-gnu -lSDL2 -lSDL2_net
libnet_SOURCES = NET.cc NET.h NETException.cc NETException.h

libmix_LDFLAGS = -L/usr/lib/x86_64-linux-gnu -lSDL2 -lSDL2_mix
libmix_SOURCES = MIX.cc MIX.h MIXException.cc MIXException.h

libimg_LDFLAGS = -L/usr/lib/x86_64-linux-gnu -lSDL2 -lSDL2_image
libimg_SOURCES = IMG.cc IMG.h IMGException.cc IMGException.h
