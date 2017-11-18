

OBJECTS=main.o
CFLAGS=-g -c -Wall -Werror -Wextra -pedantic

all: maze_binary

maze_binary: $(OBJECTS)
	gcc -o maze_binary $(OBJECTS) `sdl2-config --cflags --libs`

main.o: headers/main.h
	gcc $(CFLAGS) src/main.c

.PHONY : clean
clean:
	rm $(OBJECTS) maze_binary
