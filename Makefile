CC=gcc
CFLAGS=-std=c11 -Wall -Werror
LFLAGS=

SOURCES=$(wildcard src/*.c)
TARGETS=$(patsubst src/%.c,bin/%, $(SOURCES))

.PHONY: all clean

all: $(TARGETS)

bin/%: src/%.c
	@mkdir -p bin
	$(CC) $(CFLAGS) $< -o $@ $(LFLAGS)

clean:
	rm -f $(TARGETS)
