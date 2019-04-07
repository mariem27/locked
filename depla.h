#ifndef DEPLA_H_INCLUDE
#define DEPLA_H_INCLUDE
typedef struct
{  SDL_Surface *srf;
   SDL_Rect position;
}Background;

typedef struct
{  SDL_Surface *srf[20];
   SDL_Rect position;
   int direction,dp;
} entites;
void initialiser_ennemi(entites* ennemi,entites* ecran,Background* bg,Background* bg1);
void charger_images(entites* ennemi,Background* bg,Background* bg1);
int check_input(SDL_Event event, int* test,int done ,entites* ecran,entites* ennemi);
int collision_back (entites ennemi,Background bg1);;;
void deplacer_aleatoire_ennemi(entites* ennemi,Background *bg1);
void display(entites* ennemi,entites* ecran ,Background* bg ,int *test );


#endif

