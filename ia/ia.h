#ifndef ia_H_INCLUDE
#define ia_H_INCLUDE
/**
* @struct Background
* @brief struct for background
*/

typedef struct{
	SDL_Surface *srf;/*!< surface*/
   	SDL_Rect position;/*!< position. */
} Background;
/**
* @struct entites
* @brief struct for entites
*/

typedef struct{	
 	SDL_Surface *srf[20];/*!< Surface. */
   	SDL_Rect position;/*!< position. */
   	int direction, dp, etat, vie;
} entites;

void initialiser_ennemi(entites *ennemi, entites *perso, Background *bg);

void charger_images(entites *ennemi, entites *perso, Background *bg);

void display(entites ennemi, SDL_Surface* *ecran, entites perso, Background bg);

int check_input(entites *perso, Uint8* keys);

void deplacer_aleatoire_ennemi(entites *ennemi, entites *perso, Background *bg, int interval1, int interval2);

#endif
