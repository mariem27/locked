
/**
* @file ia.c
* @brief Testing Program.
* @author C Team
* @version 2.0
* @date May 01, 2019
*
* Testing program for intelligence artific
*
*/







#include <stdlib.h>
#include <stdio.h>
#include </usr/include/SDL/SDL.h>
#include </usr/include/SDL/SDL_image.h>
#include </usr/include/SDL/SDL_ttf.h>
#include </usr/include/SDL/SDL_mixer.h>
#include <time.h>
#include "ia.h"
/**
* @brief To initialize ennemi .
* @param ennemo ,perso,bg

* @return Nothing
*/

void initialiser_ennemi(entites* ennemi, entites *perso ,Background* bg){
	ennemi->srf[0] = NULL;
	bg->srf = NULL;
	perso->srf[0] = NULL;
        ennemi->position.x = 950;
	ennemi->position.y = 440;
	bg->position.x = 0;
	bg->position.y = 0;
        perso->position.x = 10;
	perso->position.y = 317;
	ennemi->etat = 0;
	perso->vie = 100;
}
/**
* @brief To charger images  .
* @param ennemi,perso,bg

* @return Nothing
*/

void charger_images(entites* ennemi, entites *perso, Background* bg){
    bg->srf = IMG_Load("map.png");
    perso->srf[0] = IMG_Load("perso.png");
    ennemi->srf[0] = IMG_Load("ennemi.png"); 
}
/**
* @brief To display .
* @param ennemi,ecran,perso,bg

* @return Nothing
*/

void display(entites ennemi, SDL_Surface* *ecran, entites perso, Background bg){
	int i = 0;
   	SDL_BlitSurface(bg.srf, NULL, *ecran, &bg.position);
   	SDL_BlitSurface(ennemi.srf[0], NULL, *ecran, &ennemi.position);
        SDL_BlitSurface(perso.srf[0], NULL, *ecran, &perso.position);
}
/**
* @brief To check_input.
* @param perso ,keys

* @return 1 ,0
*/


int check_input(entites *perso, Uint8* keys){
	int done = 0;
	if(keys[SDLK_ESCAPE]){
		done = 1;
	}
	if(keys[SDLK_d] && perso->position.x < 1000){
		perso->position.x += 4;
	}
	if(keys[SDLK_q] && perso->position.x > 0){
		perso->position.x -= 4;
	}
	return done;
}
/**
* @brief To deplacer_alea_ennemi.
* @param ennemi,perso,bg,interval1,interval2

* @return Nothing
*/

void deplacer_aleatoire_ennemi(entites* ennemi,entites *perso,Background* bg, int interval1, int interval2){
    srand((unsigned) time(NULL));
    if(ennemi->dp == 0){
	    ennemi->direction = rand() % 2;
	    ennemi->dp = (rand() % 100) + 1;
	}
	if(ennemi->direction){
		if(ennemi->dp > 0 && ennemi->position.x < interval2){
			ennemi->position.x++;
			ennemi->dp--;
		}else{
			ennemi->dp = 0;
		}
	}else{
		if(ennemi->dp > 0 && ennemi->position.x > interval1){
			ennemi->position.x--;
			ennemi->dp--;
		}else{
			ennemi->dp = 0;
		}
	}
}
