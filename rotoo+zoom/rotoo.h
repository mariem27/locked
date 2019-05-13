#ifndef ROTOO_H_INCLUDED
#define ROTOO_H_INCLUDED
/**
* @struct Map
* @brief struct for Map
*/

typedef struct{
	SDL_Surface *image;/*!< surface image*/
	SDL_Rect posimg;/*!< Posimg */
} Map;

void afficherRotation(SDL_Surface* *ecran, int *zoomIn, double *angle, double *zoom, int *tempsPrecedent, Map map);

#endif
