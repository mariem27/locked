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
int main()
{  
   entites ecran,ennemi,srf;
   Background bg,bg1;
   SDL_Event event;
   SDL_Init(SDL_INIT_EVERYTHING);
	int done=0;
	int test=0;
   	int i;
      

   initialiser_ennemi(&ennemi,&ecran,&bg,&bg1); 
   ecran.srf[0]=SDL_SetVideoMode(640, 480, 32, SDL_DOUBLEBUF);
   charger_images(&ennemi,&bg,&bg1);
   SDL_EnableKeyRepeat(120, 120);
   SDL_WM_SetCaption( "..depla depla..", NULL );
  while(!done)
{       display(&ennemi,&ecran ,&bg ,&test );
        deplacer_aleatoire_ennemi(&ennemi,&bg1);
        collision_back (ennemi,bg1);
        done= check_input(event,&test,done,&ecran,&ennemi);
        SDL_Flip(ecran.srf[0]);
}for(i=1;i<7;i++){
         SDL_FreeSurface(ennemi.srf[i]);
   
         SDL_FreeSurface(bg.srf); 
}
   SDL_Quit();
   return 0;
}
