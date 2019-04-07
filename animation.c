#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "animation.h"

void init(ennemi* e, Imm* ecran, Imm* bg){
   ecran->srf = NULL;
   e->surface[0] = NULL;
   bg->srf = NULL;
   bg->pos.x = 0;
   bg->pos.y = 0;
   e->position.x = 0;
   e->position.y = 380;
}

void load(ennemi* e, Imm* bg){
	bg->srf = IMG_Load("map.png");
	e->surface[0] = IMG_Load("ennemi.png");
	e->surface[1] = IMG_Load("1.png");
	e->surface[2] = IMG_Load("1.png");
	e->surface[3] = IMG_Load("2.png");
	e->surface[4] = IMG_Load("3.png");
	e->surface[5] = IMG_Load("4.png");
	e->surface[6] = IMG_Load("5.png");
	e->surface[7] = IMG_Load("6.png");
	e->surface[8] = IMG_Load("7.png");
	
	
}

int check_input(SDL_Event event, int* test, int done, Imm* ecran, ennemi *e){ 
	int i = 0;
	while(SDL_PollEvent(&event)){
		switch(event.type){
                case SDL_QUIT:
                done=1;
		break;
	case SDL_KEYUP:
				switch(event.key.keysym.sym){
					case SDLK_SPACE:
						e->position.x += 50;
						e->position.y += 50;
                                 case SDLK_d:
						(*test) = 0;
						break;
	                case SDLK_q:
						(*test)=0;
				}
	            break;
					
			case SDL_MOUSEBUTTONUP:
			 	if(event.button.button == SDL_BUTTON_RIGHT){
	            	        e->position.x = event.button.x;
	           		e->position.y = event.button.y;
	           		break;
				}else if(event.button.button == SDL_BUTTON_LEFT){
					e->position.x += 8;
					e->position.y -= 20;
				}
			case SDL_KEYDOWN:
				switch(event.key.keysym.sym){
					case SDLK_ESCAPE:
						done = 1;
						break;
					case SDLK_d:                      
						e->position.x += 30;
	                    (*test) = 1;
	                    if(e->position.x > 580){
	                    	e->position.x = 580;
	                    }
						break;
					case SDLK_q:
						e->position.x -= 30;
						(*test) = 2;
	                      if(e->position.x < 0){
	                       	e->position.x = 0;
	                    }                  
						break;
					case SDLK_e:
						(*test) = 3;
	                        //e->position.x -= 20;
	                   	//e->position.y -= 20;
						break;
					case SDLK_SPACE:
						e->position.x += 50;
						e->position.y -= 50;
						break;
				}
				break;
		}
	}
	return done;
}

void display(ennemi* e, Imm* ecran, Imm* bg , int *test){
	int i = 0;
   	SDL_BlitSurface(bg->srf, NULL, ecran->srf, &bg->pos);
  	SDL_BlitSurface(e->surface[0], NULL, ecran->srf, &e->position);
  	if(*test == 1){
        for(i = 1; i < 4; i++){
        	SDL_BlitSurface(bg->srf, NULL, ecran->srf, &bg->pos);
            SDL_BlitSurface(e->surface[i], NULL, ecran->srf, &e->position);
			/*for(j=0;j<300;j++){
		     	SDL_BlitSurface(e->surface[i],NULL,ecran->srf,&e->position);
			}*/
     	SDL_Flip(ecran->srf);
        SDL_Delay(100);
      }
	}
	if(*test == 2){
  		for(i = 5; i < 7; i++){
            SDL_BlitSurface(bg->srf, NULL, ecran->srf, &bg->pos);
     		SDL_BlitSurface(e->surface[i], NULL, ecran->srf, &e->position);
     		SDL_Flip(ecran->srf);
        	SDL_Delay(100);
      	}
    }
}
