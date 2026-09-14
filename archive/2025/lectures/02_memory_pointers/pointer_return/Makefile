CFLAGS =  -Wall -Wextra -std=c11 -O0 # -O3
CC = gcc
SOURCES = pointer_return.c

TARGET = pointer_return

.PHONY: all
all: $(TARGET)

$(TARGET): $(SOURCES) 
	$(CC) $(CFLAGS) $^ -o $@

# Rydder opp
clean:
	rm -f $(TARGET)
	rm -f $(TARGET).exe
