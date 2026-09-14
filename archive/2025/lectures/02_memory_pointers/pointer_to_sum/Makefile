CFLAGS =  -Wall -Wextra -std=c11
CC = gcc

SOURCES = pointer_to_sum.c

TARGET = pointer_to_sum

.PHONY: all
all: $(TARGET)

$(TARGET): $(SOURCES) 
	$(CC) $(CFLAGS) $^ -o $@

# Rydder opp
clean:
	rm -f $(TARGET)
	rm -f $(TARGET).exe
