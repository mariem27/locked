#ifndef ANIMATION_H_
#define ANIMATION_H_

typedef struct{
	SDL_Surface* surface[20];
	SDL_Rect position;
} ennemi;

typedef struct { 
  SDL_Surface* srf;
  SDL_Rect pos;
} Imm; 

void init(ennemi* e, Imm* ecran, Imm* bg);

void load(ennemi* e, Imm* bg);

int check_input(SDL_Event event, int* test, int done, Imm* ecran, ennemi *e);

void display(ennemi* e, Imm* ecran, Imm* bg , int *test);

#endif
