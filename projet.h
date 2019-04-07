#ifndef _PROJET_H
#define _PROJET_H
#include <SDL/SDL.h>

typedef struct{
	SDL_Surface *img;
	SDL_Rect posimg;
} Map ;

typedef struct 
{
	SDL_Surface *img;
	SDL_Rect posimg;
} entite;

void initialiser_entite(Map *map ,entite *torch, entite *boussole, entite *caise, entite *sac);

void bliter_surface(SDL_Surface* *ecran, Map map ,entite torch, entite boussole,entite caise, entite sac);

void afficher_entite(SDL_Surface* ecran, Map map, entite torch, entite boussole, entite caise , entite sac);

void liberer_surface(Map map ,entite torch, entite boussole, entite caise, entite sac);



#endif
