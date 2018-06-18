AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_FLAGS)

lib_LTLIBRARIES = libsdl2.la libttf.la libnet.la libmix.la libimg.la

libsdl2_la_LDFLAGS = -L/usr/lib/x86_64-linux-gnu -lSDL2 
libsdl2_la_SOURCES = SDL2.cc SDL2.h SDL2Exception.cc SDL2Exception.h

libttf_la_LDFLAGS = -L/usr/lib/x86_64-linux-gnu -lSDL2 -lSDL2_ttf
libttf_la_SOURCES = TTF.cc TTF.h TTFException.cc TTFException.h

libnet_la_LDFLAGS = -L/usr/lib/x86_64-linux-gnu -lSDL2 -lSDL2_net
libnet_la_SOURCES = NET.cc NET.h NETException.cc NETException.h

libmix_la_LDFLAGS = -L/usr/lib/x86_64-linux-gnu -lSDL2 -lSDL2_mix
libmix_la_SOURCES = MIX.cc MIX.h MIXException.cc MIXException.h

libimg_la_LDFLAGS = -L/usr/lib/x86_64-linux-gnu -lSDL2 -lSDL2_image
libimg_la_SOURCES = IMG.cc IMG.h IMGException.cc IMGException.h
