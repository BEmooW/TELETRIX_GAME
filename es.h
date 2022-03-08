#ifndef ES_H_INCLUDED
#define ES_H_INCLUDED
#include <stdio.h>
 #include<stdlib.h>
 #include<SDL/SDL.h>
 #include<SDL/SDL_image.h>
 
typedef struct ennemi{
SDL_Surface *sprite; 
int  direction;
SDL_Rect posscreen;
SDL_Rect possprite;
}ennemi;
typedef struct ennemi ennemi;
void initEnnemi(ennemi *e);
void afficherEnnemi(ennemi *e,SDL_Surface *screen);
void animerEnnemi(ennemi *e);
void deplacer(ennemi *e);
int collisionBB(SDL_Rect posp,SDL_Rect pose);
//void liberer(ennemi *a);


#endif 
