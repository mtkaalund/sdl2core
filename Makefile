CP		:= cp -v
RM		:= rm -rfv
MKDIR		:= mkdir -pv
MV		:= mv -v
ifeq ($(ARCH),)
	ARCH	:= $(shell $(CXX) -dumpmachine)
endif

INCLUDE_DIR	:= $(shell pwd)/usr/include/sdl2core
LIBRARY_DIR	:= $(shell pwd)/usr/lib/$(ARCH)
OBJECTS_DIR	:= objs
CXXFLAGS	:= $(CFLAGS) -g -Wall -std=c++11 -shared $(shell sdl2-config --cflags) -I./src/
LDFLAGS		:= $(LDFLAGS) $(shell sdl2-config --libs) -lSDL2_image -lSDL2_ttf -lSDL2_net -lSDL2_net
SDL2CORE_SRC	:= $(wildcard src/*.cc)
SDL2CORE_OBJ	:= $(addprefix $(OBJECTS_DIR)/, $(notdir $(SDL2CORE_SRC:.cc=.o)))
SDL2CORE_LIB	:= $(addprefix $(LIBRARY_DIR)/, $(notdir $(SDL2CORE_SRC:.cc=.so)))

.PHONY: all prepare-install prepare clean dist-clean

all: prepare $(SDL2CORE_LIB) 

$(SDL2CORE_LIB): $(SDL2CORE_OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS) $(CXXFLAGS) -fPIC

$(OBJECTS_DIR)/%.o: src/%.cc
	$(CXX) -o $@ $< $(CXXFLAGS) $(LDFLAGS) -fPIC

$(SDL2CORE_SRC:.cc=.d):%.d:%.cc
	$(CXX) $(CXXFLAGS) -MM $< >$@

include $(SDL2CORE_SRC:.cc=.d)

prepare-install: prepare
	$(CP) src/*.h $(INCLUDE_DIR)

prepare:
	$(MKDIR) $(OBJECTS_DIR)
	$(MKDIR) $(INCLUDE_DIR)
	$(MKDIR) $(LIBRARY_DIR)

clean:
	$(RM) src/*.d
	$(RM) $(OBJECTS_DIR)/*.o

dist-clean: clean
	$(RM) -r $(LIBRARY_DIR)
	$(RM) -r $(OBJECTS_DIR)
	$(RM) -r usr/
