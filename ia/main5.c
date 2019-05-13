/**
* @file main.c
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
#include <math.h>
#include "ia.h"

int main(){ 
    entites ennemi, srf, perso;
    Background bg;	
    SDL_Surface* ecran;
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Init(SDL_INIT_VIDEO);
	SDL_WM_SetCaption( "..depla depla..", NULL);
   	ecran = SDL_SetVideoMode(1000, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
   	initialiser_ennemi(&ennemi, &perso, &bg); 
   	charger_images(&ennemi, &perso, &bg);
   	int done = 0, test = 0, distPersoEnnemi;
	Uint8 *keys;
  	while(!done){
	  	display(ennemi, &ecran, perso, bg);
	  	distPersoEnnemi = abs(ennemi.position.x - perso.position.x);
	  	if(distPersoEnnemi > 500){
	  		if(ennemi.position.x < 880 || ennemi.position.x > 100){
	  			ennemi.etat = 0;
	    	}else{
	    		ennemi.etat = 3;
	    	}
	    }else{
	    	if(distPersoEnnemi <= 5){
	    		ennemi.etat = 1;
	    	}else{
	    		ennemi.etat = 2;
	    	}
	    }
	    switch(ennemi.etat){
	    	case 0:
	    		deplacer_aleatoire_ennemi(&ennemi, &perso, &bg, 880, 1000);
	    		break;
	    	case 1:
	    		perso.vie--;
	    		break;
	    	case 2:
	    		if(ennemi.position.x - perso.position.x > 0){
	    			ennemi.position.x--;
	    		}else{
	    			ennemi.position.x++;
	    		}
	    		break;
	    	case 3:
	    		if(ennemi.position.x < 900){
	    			ennemi.position.x++;
	    		}else{
	    			ennemi.position.x--;
	    		}
	    		break;
	    }
	    SDL_PumpEvents();
	    keys = SDL_GetKeyState(NULL);
	    done = check_input(&perso, keys);
	    SDL_Flip(ecran);
	}
    SDL_FreeSurface(ennemi.srf[0]);
    SDL_FreeSurface(perso.srf[0]);
    SDL_FreeSurface(bg.srf);
    SDL_FreeSurface(ecran); 
   	SDL_Quit();
   	return 0;
}
