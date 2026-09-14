CFLAGS =  -Wall -Wextra -std=c11
CC = gcc

SOURCES = pass_by_example.c

TARGET = pass_by_example

.PHONY: all
all: $(TARGET)

$(TARGET): $(SOURCES) 
	$(CC) $(CFLAGS) $^ -o $@

# Rydder opp
clean:
	rm -f $(TARGET)
	rm -f $(TARGET).exe
