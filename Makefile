CC=gcc
CFLAGS=-std=c11 -Wall -Werror
LFLAGS=

SOURCES=$(wildcard src/*.c)
TARGETS=$(patsubst src/%.c,bin/%, $(SOURCES))

.PHONY: all clean

all: $(TARGETS)

bin/%: src/%.c
	$(CC) $(CFLAGS) $< -o $@ $(LFLAGS)

clean:
	rm -f $(TARGETS)
