CFLAGS =  -Wall -Wextra -std=c11
CC = gcc

SOURCES = pointer_example.c

TARGET = pointer_example

.PHONY: all
all: $(TARGET)

$(TARGET): $(SOURCES) 
	$(CC) $(CFLAGS) $^ -o $@

# Rydder opp
clean:
	rm -f $(TARGET)
	rm -f $(TARGET).exe
