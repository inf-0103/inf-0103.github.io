EXECUTABLE = app
CC = gcc

CFLAGS = -Wall -Wextra -std=gnu99 -ISDL2 -D_REENTRANT -DSDL_MAIN_HANDLED
LIBS = -lm -L. -lSDL2

TEST_APP = testlist
TEST_SOURCE = list_tester.c list.c

SOURCE = main.c triangle.c drawline.c object.c list.c
HEADER = drawline.h triangle.h object.h list.h teapot_data.h sphere_data.h

include Makefile.in

.PHONY: all
all: $(EXECUTABLE)
$(EXECUTABLE): $(SOURCE) $(HEADER)
	$(info === Compiling...)
	$(shell $(PRE_BUILD))
	$(CC) $(CFLAGS) -o $@ $(SOURCE) $(LIBS)
    
.PHONY: test
test: $(TEST_APP)
$(TEST_APP): $(TEST_SOURCE)
	$(info === Compiling List Test...)
	$(shell $(PRE_BUILD))
	$(CC) $(CFLAGS) -o $@ $(TEST_SOURCE)

.PHONY: clean
clean:
	@rm -f *.o $(EXECUTABLE) $(TEST_APP) *~ SDL2.dll libSDL2-2.0.so.0 
	$(info === Cleaned)
