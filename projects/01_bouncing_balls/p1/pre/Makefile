EXECUTABLE = app
CC = gcc

UNAME_S := $(shell uname -s)
UNAME_M := $(shell uname -m)

# Platform detection and configuration
CFLAGS = -Wall -Wextra -std=gnu99 -D_REENTRANT -DSDL_MAIN_HANDLED
TEST_OBJ = 

ifeq ($(UNAME_S),Darwin)
	# fix for secret homebrew libs
	SDL3_PATH = $(shell brew --prefix sdl3 2>/dev/null)
	CFLAGS += -I$(SDL3_PATH)/include -L$(SDL3_PATH)/lib
	ifeq ($(UNAME_M),arm64)
		TEST_OBJ = lib/tests_mac_arm64.o
	else
		TEST_OBJ = lib/tests_mac.o
	endif
else ifeq ($(UNAME_S),Linux)
	TEST_OBJ = lib/tests_linux.o
endif

LIBS = -lm -L. -lSDL3

TEST_APP = testlist
TEST_SOURCE = list_tester.c list.c $(TEST_OBJ)

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
	$(CC) $(CFLAGS) -o $@ $(TEST_SOURCE) $(LIBS)

.PHONY: clean
clean:
	@rm -f *.o $(EXECUTABLE) $(TEST_APP) 
	$(info === Cleaned)
