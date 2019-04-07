#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "projet.h"
void initialiser_entite(Map *map ,entite *torch, entite *boussole, entite *caise, entite *sac)
{
    map->img = IMG_Load("map.png");
    torch->img = IMG_Load("torch.jpg");
    boussole->img = IMG_Load("boussole.jpg");
    caise->img = IMG_Load("caise.jpg");
    sac->img = IMG_Load("sac.jpg");
    map->posimg.x = 0;
    map->posimg.y = 0;
    torch->posimg.x = 10; 
    torch->posimg.y = 20;
    boussole->posimg.x = 50;
    boussole->posimg.y = 60;
    caise->posimg.x = 90;
    caise->posimg.y = 120;
    sac->posimg.x = 150; 
    sac->posimg.y = 170;
}
void bliter_surface(SDL_Surface* *ecran, Map map ,entite torch, entite boussole,entite caise, entite sac)
{
    SDL_BlitSurface(map.img, NULL, *ecran, &map.posimg);
    SDL_BlitSurface(torch.img, NULL, *ecran, &torch.posimg);
    SDL_BlitSurface(boussole.img, NULL, *ecran,       &boussole.posimg);
    SDL_BlitSurface(caise.img, NULL, *ecran, &caise.posimg);
    SDL_BlitSurface(sac.img, NULL, *ecran, &sac.posimg);
}
void afficher_entite(SDL_Surface* ecran, Map map, entite torch, entite boussole, entite caise , entite sac)
{
    initialiser_entite(&map, &torch, &boussole, &caise, &sac);
	bliter_surface(&ecran, map, torch, boussole, caise, sac);
	liberer_surface(map, torch, boussole, caise, sac);
}
void liberer_surface(Map map ,entite torch, entite boussole, entite caise, entite sac)

{
    SDL_FreeSurface(map.img); 
    SDL_FreeSurface(torch.img);
    SDL_FreeSurface(boussole.img);
    SDL_FreeSurface(caise.img);
    SDL_FreeSurface(sac.img);
}
