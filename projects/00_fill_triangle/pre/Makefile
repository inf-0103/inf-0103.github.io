EXECUTABLE = app
CC = gcc

CFLAGS = -D_REENTRANT -DSDL_MAIN_HANDLED
#
# fix for secret homebrew libs
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	SDL3_PATH = $(shell brew --prefix sdl3 2>/dev/null)
	CFLAGS = -D_REENTRANT -DSDL_MAIN_HANDLED -std=c23 \
	    -I$(SDL3_PATH)/include \
	    -L$(SDL3_PATH)/lib
endif

LIBS  = -lm -lSDL3

SOURCE = drawline.c main.c triangle.c
HEADER = drawline.h triangle.h teapot_data.h

.PHONY: all
all: $(EXECUTABLE)
$(EXECUTABLE): $(SOURCE) $(HEADER)
	$(info === Compiling...)
	$(shell $(PRE_BUILD))
	$(CC) $(CFLAGS) -o $@ $(SOURCE) $(LIBS)
    
.PHONY: clean
clean:
	@rm -f $(EXECUTABLE)
	$(info === Cleaned)
