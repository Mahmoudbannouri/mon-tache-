test:main.o minimap.o
	gcc main.o -o minimap.o -lSDL -lSDL_image -g
main.o:main.c
	gcc -c main.c -g
minimap.o:minimap.c
	gcc -c minimap.c -g
