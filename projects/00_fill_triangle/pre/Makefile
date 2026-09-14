EXECUTABLE = app
CC = gcc

CFLAGS = -D_REENTRANT -DSDL_MAIN_HANDLED
LIBS  = -lm -lSDL2

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
