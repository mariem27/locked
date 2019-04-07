#include <stdio.h>
#include <stdlib.h> 
#include <SDL/SDL.h> 
#include <SDL/SDL_image.h> 
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>
#include "animation.h"

int main(){  
   ennemi e;
   Imm ecran, bg;
   SDL_Event event;
   SDL_Init(SDL_INIT_EVERYTHING);
   int done = 0, test = 0, i;
   init(&e, &ecran, &bg); 
   ecran.srf = SDL_SetVideoMode(640, 480, 32, SDL_DOUBLEBUF); 
   load(&e, &bg);
   SDL_EnableKeyRepeat(120, 120);
   SDL_WM_SetCaption( "..animation animation..", NULL );
   while(!done){
      display(&e, &ecran, &bg, &test);
      done = check_input(event, &test, done, &ecran, &e);
      SDL_Flip(ecran.srf);
   }
   for(i = 0; i < 7; i++){
      SDL_FreeSurface(e.surface[i]);
   } 
   SDL_FreeSurface(bg.srf); 
   SDL_Quit();
   return 0;
}
