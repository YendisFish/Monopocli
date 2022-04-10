CC = gcc
CFLAGS = -g

.PHONY: all run clean

all: monopocli

monopocli: monopocli.c
	$(CC) $(CFLAGS) $^ -o $@
 
run: monopocli
	./monopocli

clean:
	rm -fv monopocli