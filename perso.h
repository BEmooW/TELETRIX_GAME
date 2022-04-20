#ifndef perso_H_INCLUDED
#define perso_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL/SDL.h>
#include <stdbool.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_mixer.h>

typedef struct perso
{
SDL_Surface *image[2][5];
SDL_Rect pos_background; //pos perso dans bg
SDL_Rect pos_barre;//position de la barre de vie
SDL_Rect pos_score;//position du score 
int i , j ; //i=0 droite , i=1 gauche 
double vitesse , acceleration;
int score;
//int health;
int up;
SDL_Surface *vie;
double vect_x, vect_grav,vect_y;
}perso;

void initPerso (perso *p);
void affichierPerso (perso p , SDL_Surface *screen);
void deplacerPerso (perso *p , int dt);
void animerPerso (perso* p);
void saut (perso* p);

#endif 
