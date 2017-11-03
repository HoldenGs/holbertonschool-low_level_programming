all: maze_binary

maze_binary: demo_code.o demo_header.o
	gcc demo_code.o demo_header.o `sdl2-config --cflags --libs` -o maze_binary

demo_code.o:
	gcc -c src/demo_code.c

demo_header.o:
	gcc -c headers/demo_header.c

clean:
	rm *.o maze_binary