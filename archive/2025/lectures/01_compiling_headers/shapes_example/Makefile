CFLAGS =  -Wall -Wextra -std=c11
CC = gcc

# Deaktiverer alle implisitte make-regler
.SUFFIXES:
# Forhindrer at make sletter preprosesserte C-filer
.PRECIOUS: %.i

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))

TARGET = shapes

.PHONY: all
all: $(TARGET)

# Gjennomførere preprosessering av alle C-filene
%.i : %.c %.h
		$(CC) -E $(CFLAGS) $< -o $@

# Kompilerer alt som har endelsen .i til ei objectfil med endelse .o
%.o : %.i
		$(CC) -c $(CFLAGS) $< -o $@

# Lenker sammen objectfilene til ferdig program
$(TARGET): $(OBJECTS) 
	$(CC) $(CFLAGS) $^ -o $@

# Rydder opp
clean:
	rm -f $(wildcard *.i)
	rm -f $(wildcard *.o)
	rm -f $(TARGET)
	rm -f $(TARGET).exe
