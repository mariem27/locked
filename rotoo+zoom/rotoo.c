/**
* @file rotoo.c
* @brief Testing Program.
* @author C Team
* @version 1.0
* @date Mai 1, 2019
*
* Testing program for rotoo
*
*/









#include <stdlib.h>
#include <stdio.h>
#include </usr/include/SDL/SDL.h>
#include </usr/include/SDL/SDL_image.h>
#include </usr/include/SDL/SDL_rotozoom.h>
#include "rotoo.h"
/**
* @brief To initialize rotation.
* @param surface ecran ,zoomIn,angle,zoom,tempsPrecedent ,Map
* @return Nothing
*/

void afficherRotation(SDL_Surface* *ecran, int *zoomIn, double *angle, double *zoom,  int *tempsPrecedent, Map map){
SDL_Rect a;
a.x=160;
a.y=100;
    int tempsActuel = SDL_GetTicks();
    if(tempsActuel - (*tempsPrecedent) > 30){
        (*angle) += 2;
	if(*zoomIn){
	    if((*zoom) < 1.5){
	        (*zoom) += 0.05;
	    }else{
	        (*zoomIn) = 0;
	    }
	}else{
	    if((*zoom) > 0.5){
	        (*zoom) -= 0.05;
	    }else{
	        (*zoomIn) = 1;
            }
	}
        (*tempsPrecedent) = tempsActuel;
    }else{
        SDL_Delay(30 - (tempsActuel - (*tempsPrecedent)));
    }
    SDL_FillRect(*ecran, NULL, SDL_MapRGB((*ecran)->format, 255, 255, 255));
    SDL_Surface* rotation = rotozoomSurface(map.image, *angle, *zoom, 1);
    SDL_BlitSurface(rotation, NULL, *ecran, &map.posimg);
    SDL_FreeSurface(rotation); 
}
