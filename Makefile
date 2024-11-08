CC=gcc
FLAGS=-Wall -Wextra -pedantic -Werrors
INCLUDE=-Iinclude
OPTS=-O0
LIBS=-lX11
SRC = $(wildcard src/*.c)
OBJECTS = $(patsubst src/%.c, bin/%.o, $(SRC))
BINARY=trail.out

default: $(BINARY)

$(BINARY): $(OBJECTS)
	@echo $^
	$(CC) -o $@ $^ $(LIBS)

bin/%.o: src/%.c
	$(CC) -c $< -o $@ $(INCLUDE)

clean:
	rm bin/*
