#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>
#include "depla.h"
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
void initialiser_ennemi(entites* ennemi,entites* ecran,Background* bg,Background* bg1){
	ennemi->srf[0]=NULL;
	ecran->srf[0]=NULL;
	bg->srf=NULL;
        bg1->srf=NULL;
	ennemi->position.x=0;
	ennemi->position.y=300;
	bg->position.x=0;
	bg->position.y=0;
        bg1->position.x=0;
	bg1->position.y=0;

}
void charger_images(entites* ennemi,Background* bg,Background *bg1){
        bg->srf = IMG_Load("map.png");
        bg1->srf= IMG_Load("mask.png");
	ennemi->srf[0] = IMG_Load("ennemi.png");
        ennemi->srf[1] = IMG_Load("ennemi.png");
	ennemi->srf[2] = IMG_Load("1.png");
	ennemi->srf[3] = IMG_Load("2.png");
	ennemi->srf[4] = IMG_Load("3.png");
	ennemi->srf[5] = IMG_Load("4.png");
	ennemi->srf[6] = IMG_Load("5.png");
	ennemi->srf[7] = IMG_Load("6.png");
	ennemi->srf[8] = IMG_Load("7.png");
	
}

int check_input(SDL_Event event, int* test,int done ,entites* ecran,entites* ennemi){
int i=1;
	while( SDL_PollEvent( &event )){
		switch( event.type ){
                case SDL_QUIT:
                done=1;
		break;
			case SDL_KEYUP:
				switch( event.key.keysym.sym ){
					case SDLK_SPACE:
					ennemi->position.x+=20;
					ennemi->position.y+=30;
					break;
					 case SDLK_d:
						(*test) = 0;
						break;
	                                        case SDLK_q:
						(*test)=0;
				}
	            break;
			 case SDL_MOUSEBUTTONUP:

			        if (event.button.button == SDL_BUTTON_RIGHT){
            			ennemi->position.x = event.button.x;
           		        ennemi->position.y = event.button.y;
           		        break;

				}else if(event.button.button == SDL_BUTTON_LEFT){
				ennemi->position.x +=10;
				ennemi->position.y -=20;
				}

			case SDL_KEYDOWN:
				switch( event.key.keysym.sym ){
					case SDLK_ESCAPE:
						done=1;
						break;
					case SDLK_d:
						ennemi->position.x+=30;
						(*test)=1;
                              if(ennemi->position.x > 580){
	                    	ennemi->position.x = 580;
	                    }	
						
						break;
					case SDLK_q:
						ennemi->position.x-=30;
						(*test)=2;
                               if(ennemi->position.x < 0)
	                       	ennemi->position.x = 0;
						break;
					case SDLK_e:
						(*test)=3;
						break;
		
					case SDLK_SPACE:
						ennemi->position.x+=50;
						ennemi->position.y-=50;
						break;		
				}
					break;
		}
	}
	return done;
}


SDL_Color GetPixel (SDL_Surface *pSurface,int x,int y)
{
  SDL_Color color;
  Uint32 col= 0;
  char* pPosition = (char*) pSurface->pixels;
  pPosition += (pSurface->pitch * y);
  pPosition += (pSurface->format->BytesPerPixel * x);
  memcpy (&col,pPosition,pSurface->format->BytesPerPixel);
  SDL_GetRGB (col,pSurface->format,&color.r,&color.g,&color.b);
 return (color);
}

int collision_back (entites ennemi,Background bg1)
{ 
  SDL_Rect point[8];
  SDL_Color couleur[8];

point[0].x=ennemi.position.x+ennemi.position.w+10;
point[0].y=ennemi.position.y+ennemi.position.h/2;

point[4].x=ennemi.position.x+ennemi.position.w+10;
point[4].y=ennemi.position.y+ennemi.position.h/4;

point[5].x=ennemi.position.x+ennemi.position.w+10;
point[5].y=ennemi.position.y+(ennemi.position.h*3)/4;

point[1].x=ennemi.position.x+ennemi.position.w/2;
point[1].y=ennemi.position.y+ennemi.position.h;

point[2].x=ennemi.position.x-10;
point[2].y=ennemi.position.y+ennemi.position.h/2;

point[6].x=ennemi.position.x-10;   
point[6].y=ennemi.position.y+ennemi.position.h/4;

point[7].x=ennemi.position.x-10;
point[7].y=ennemi.position.y+(ennemi.position.h*3)/4;
point[3].x=ennemi.position.x+ennemi.position.w/2;
point[3].y=ennemi.position.y;  

couleur[0]=GetPixel (bg1.srf, point[0].x, point[0].y);
couleur[1]=GetPixel (bg1.srf, point[1].x, point[1].y);
couleur[2]=GetPixel (bg1.srf, point[2].x, point[2].y);
couleur[3]=GetPixel (bg1.srf, point[3].x, point[3].y);
couleur[4]=GetPixel (bg1.srf, point[4].x, point[4].y);
couleur[5]=GetPixel (bg1.srf, point[5].x, point[5].y);
couleur[6]=GetPixel (bg1.srf, point[6].x, point[6].y);
couleur[7]=GetPixel (bg1.srf, point[7].x, point[7].y);


if (couleur[1].r==255 && couleur[1].g==0 && couleur[1].b==252)
return 1;

else if (couleur[3].r==255 && couleur[3].g==0 && couleur[3].b==252)
return 1;

else if (couleur[1].r==255 && couleur[1].g==0 && couleur[1].b==252)
return 1;

else if ((couleur[2].r==255 && couleur[2].g==0 && couleur[2].b==252)||(couleur[6].r==255 && couleur[6].g==0 && couleur[6].b==252)||(couleur[7].r==255 && couleur[7].g==0 && couleur[7].b==252))
return 1;

else if ((couleur[0].r==255 && couleur[0].g==0 && couleur[0].b==252)||(couleur[4].r==255 && couleur[4].g==0 && couleur[4].b==252)||(couleur[5].r==255 && couleur[5].g==0 && couleur[5].b==252))
return 1;

else return 0;


}
void deplacer_aleatoire_ennemi(entites* ennemi,Background* bg1){

    srand((unsigned) time(NULL));
    if(ennemi->dp == 0)//distance parcou
{
	    ennemi->direction = rand() % 2;
	    ennemi->dp = (rand() % 100) + 1;
	}
	if(ennemi->direction){
		if(!collision_back(*ennemi,*bg1) && ennemi->dp > 0){
			ennemi->position.x++;
			ennemi->dp--;
		}else{
			ennemi->dp = 1;
		}
	}else{
		if(!collision_back(*ennemi,*bg1) && ennemi->dp > 0){
			ennemi->position.x--;
			ennemi->dp--;
		}else{
			ennemi->dp = 1;
		}
	}
}
void display(entites* ennemi,entites* ecran ,Background* bg ,int *test )
{
int i=0;

   SDL_BlitSurface(bg->srf,NULL,ecran->srf[0],&bg->position);
   SDL_BlitSurface(ennemi->srf[0],NULL,ecran->srf[0],&ennemi->position);
  
  if(*test == 1){
         
         for(i=1;i<4;i++){  
        
            SDL_BlitSurface(bg->srf,NULL,ecran->srf[0],&bg->position);
            SDL_BlitSurface(ennemi->srf[i],NULL,ecran->srf[0],&ennemi->position);
      
         SDL_Flip(ecran->srf[0]);
         SDL_Delay(1000);
        
      }
	}

if(*test == 2){
  for(i=5;i<8;i++){
             SDL_BlitSurface(bg->srf,NULL,ecran->srf[0],&bg->position);
             SDL_BlitSurface(ennemi->srf[i],NULL,ecran->srf[0],&ennemi->position);
     	SDL_Flip(ecran->srf[0]);
        SDL_Delay(1000);


}
} 
}

 





