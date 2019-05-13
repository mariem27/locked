
/**
* @file main.c
* @brief Testing Program.
* @author C Team
* @version 1.0
* @date Mai 01, 2019
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

int main(){
    SDL_Surface *ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
    SDL_Event event;
    Map map;
    double angle = 0;
    int continuer = 1;
    int tempsPrecedent = 0;
    int zoomIn = 1;
    int tourner = 350;
    double zoom = 1.0;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_WM_SetCaption("Faire des rotations avec SDL_gfx", NULL);
    map.image = IMG_Load("map.png");
    map.posimg.x = 0;
    map.posimg.y = 0;
    while(continuer){
        SDL_PollEvent(&event);
        switch(event.type){
            case SDL_QUIT:
                continuer = 0;
                break;
        }
	if(tourner > 0){
            afficherRotation(&ecran, &zoomIn, &angle, &zoom, &tempsPrecedent, map);
            tourner--;
        }
        SDL_Flip(ecran);
    }
    SDL_FreeSurface(ecran);
    SDL_FreeSurface(map.image);
    SDL_Quit();
    return EXIT_SUCCESS;
}
