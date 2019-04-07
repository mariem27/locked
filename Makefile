prog :  depla.o  main.o
	gcc depla.o main.o -o prog -g -lSDL -lSDL_ttf -lSDL_mixer -lSDL_image
main.o : main.c depla.h
	gcc -c main.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
depla.o : depla.c depla.h
	gcc -c  depla.c -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
