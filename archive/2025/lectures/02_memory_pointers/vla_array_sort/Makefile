CFLAGS =  -Wall -Wextra -std=c11
CC = gcc

SOURCES = vla_array_sort.c

TARGET = vla_array_sort

.PHONY: all
all: $(TARGET)

$(TARGET): $(SOURCES) 
	$(CC) $(CFLAGS) $^ -o $@

# Rydder opp
clean:
	rm -f $(TARGET)
	rm -f $(TARGET).exe
