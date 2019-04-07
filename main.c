#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include "projet.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>


int main(){
	SDL_Init(SDL_INIT_EVERYTHING); 
	SDL_WM_SetCaption("projet", NULL);


	SDL_Surface* ecran ;
	Map map;
	entite torch, boussole, caise, sac;

	initialiser_entite(&map ,&torch, &boussole, &caise,&sac);

	ecran= SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE);
	map.img = IMG_Load("map.png");
	map.posimg.x = 0;
        map.posimg.y = 0;

	int done = 0;
	while(!done){
		SDL_BlitSurface(map.img, NULL, ecran, &map.posimg);
		bliter_surface(&ecran, map ,torch, boussole, caise, sac);
               SDL_Flip(ecran);
	}

	liberer_surface(map,torch, boussole, caise, sac);
	SDL_FreeSurface(map.img);
	
	SDL_Quit();
	return 0;
}
