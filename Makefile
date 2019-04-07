prog:main.o animation.o
	gcc main.o animation.o -o prog -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
main.o:main.c animation.h
	gcc -c main.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
animation.o:animation.c animation.h
	gcc -c animation.c -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
