all: EBOOT.PBP
TARGET = engine
PSP_EBOOT_TITLE = Umdra Engine

OBJS = \
src/main.o \
src/core/engine.o \
src/graphics/renderer.o \
src/input/input.o \
src/game/mygame.o

CFLAGS = -O2 -G0 -Wall -Iinclude
CXXFLAGS = $(CFLAGS)

LIBS = -lpspgu -lpspgum -lpspdisplay -lpspctrl -lpng -lz -lstdc++ -lm

include $(PSPSDK)/lib/build.mak