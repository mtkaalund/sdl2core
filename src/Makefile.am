AUTOMAKE_OPTIONS = subdir-objects
ACLOCAL_AMFLAGS = $(ACLOCAL_FLAGS)

lib_LTLIBRARIES = libsdl2.la libttf.la libnet.la libmix.la libimg.la

include_HEADERS = libSDL2.h SDL2Exception.h TTF.h TTFException.h NET.h NETException.h MIX.h MIXException.h IMG.h IMGException.h DebugMacro.h

libsdl2_la_LDFLAGS = -L/usr/lib/x86_64-linux-gnu -lSDL2 
libsdl2_la_CFLAGS = -std=c++11 $(AM_CFLAGS)
libsdl2_la_SOURCES = libSDL2.cc libSDL2.h SDL2Exception.cc SDL2Exception.h

libttf_la_LDFLAGS = -L/usr/lib/x86_64-linux-gnu -lSDL2 -lSDL2_ttf
libttf_LA_CFLAGS = -std=c++11 $(AM_CFLAGS)
libttf_la_SOURCES = TTF.cc TTF.h TTFException.cc TTFException.h

libnet_la_LDFLAGS = -L/usr/lib/x86_64-linux-gnu -lSDL2 -lSDL2_net
libnet_la_CFLAGS = -std=c++11 $(AM_CFLAGS)
libnet_la_SOURCES = NET.cc NET.h NETException.cc NETException.h

libmix_la_LDFLAGS = -L/usr/lib/x86_64-linux-gnu -lSDL2 -lSDL2_mixer
libmix_la_CFLAGS = -std=c++11 $(AM_CFLAGS)
libmix_la_SOURCES = MIX.cc MIX.h MIXException.cc MIXException.h

libimg_la_LDFLAGS = -L/usr/lib/x86_64-linux-gnu -lSDL2 -lSDL2_image
libimg_la_CFLAGS = -std=c++11 $(AM_CFLAGS)
libimg_la_SOURCES = IMG.cc IMG.h IMGException.cc IMGException.h
