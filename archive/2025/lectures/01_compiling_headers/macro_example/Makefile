CFLAGS =  -Wall -Wextra -std=c11
CC = gcc

# Deaktiverer alle implisitte make-regler
.SUFFIXES:
# Forhindrer at make sletter preprosesserte C-filer
.PRECIOUS: %.i

TARGET = macro

.PHONY: all
all: $(TARGET)

# Proprosesserer C-fila
%.i : %.c
		$(CC) -E $(CFLAGS) $< -o $@


# Kompilerer og lager program
$(TARGET): $(TARGET).i 
	$(CC) $(CFLAGS) $< -o $@

# Rydder opp
clean:
	rm -f $(wildcard *.i)
	rm -f $(TARGET)
	rm -f $(TARGET).exe
