EXECUTABLE = app
CC = gcc

#
# fix for secret homebrew libs
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	SDL3_PATH = $(shell brew --prefix sdl3 2>/dev/null)
	CFLAGS = -Wall -Wextra -std=gnu99 -D_REENTRANT -DSDL_MAIN_HANDLED \
	    -I$(SDL3_PATH)/include \
	    -L$(SDL3_PATH)/lib
else
	CFLAGS = -Wall -Wextra -std=gnu99 -D_REENTRANT -DSDL_MAIN_HANDLED
endif

LIBS = -lm -L. -lSDL3

TEST_APP = testlist
TEST_SOURCE = list_tester.c list.c

SOURCE = main.c triangle.c drawline.c object.c list.c
HEADER = drawline.h triangle.h object.h list.h teapot_data.h sphere_data.h

.PHONY: all
all: $(EXECUTABLE)
$(EXECUTABLE): $(SOURCE) $(HEADER)
	$(info === Compiling...)
	$(CC) $(CFLAGS) -o $@ $(SOURCE) $(LIBS)
    
.PHONY: test
test: $(TEST_APP)
$(TEST_APP): $(TEST_SOURCE)
	$(info === Compiling List Test...)
	$(CC) $(CFLAGS) -o $@ $(TEST_SOURCE)

.PHONY: clean
clean:
	@rm -f *.o $(EXECUTABLE) $(TEST_APP) *~ SDL2.dll libSDL2-2.0.so.0 
	$(info === Cleaned)
