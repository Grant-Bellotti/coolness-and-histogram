CC = gcc
SOURCES = $(wildcard *.c)
OBJECTS = $(subst .c,.o,$(SOURCES))

.PHONY: all clean

all: histogram

histogram: $(OBJECTS)
	$(CC) -o histogram $(OBJECTS)

%.o: %.c
	$(CC) -c $<

clean:
	rm -f $(OBJECTS) histogram