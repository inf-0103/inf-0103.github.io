CFLAGS =  -Wall -Wextra -std=c11
CC = gcc

SOURCES = pointer_arithmetric.c

TARGET = pointer_arithmetric

.PHONY: all
all: $(TARGET)

$(TARGET): $(SOURCES) 
	$(CC) $(CFLAGS) $^ -o $@

# Rydder opp
clean:
	rm -f $(TARGET)
	rm -f $(TARGET).exe
