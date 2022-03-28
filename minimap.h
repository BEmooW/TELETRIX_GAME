#ifndef minimap_H
#define minimao_H
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <string.h>

typedef struct
{
   SDL_Surface *map;
   SDL_Surface *minijoueur;
   SDL_Rect positionmap;
   SDL_Rect positionminijoueur;

} minimap;

void init_map(minimap *m);
void MAJMinimap(SDL_Rect posJoueur, minimap *m, SDL_Rect camera, int redimensionnement);
void afficherminimap(minimap m, SDL_Surface *screen);

#endif