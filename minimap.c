#include "minimap.h"

void init_map(minimap *m)
{
  m->map = IMG_Load("minimap.jpg");
  m->minijoueur = IMG_Load("joueurmini.png");
  m->positionmap.x = 800-159;
  m->positionmap.y = 537-107;
  m->positionminijoueur.x = 800-159;
  m->positionminijoueur.y = 537-107;
}

void MAJMinimap(SDL_Rect posJoueur, minimap *m, SDL_Rect camera, int redimensionnement)
{
  SDL_Rect posJoueurABS;
  posJoueurABS.x = 0;
  posJoueurABS.y = 0;
  posJoueurABS.x = posJoueur.x + camera.x;
  posJoueurABS.y = posJoueur.y + camera.y;
  m->positionminijoueur.x = (posJoueurABS.x * redimensionnement / 100) + 800-159 ;
  m->positionminijoueur.y = (posJoueurABS.y * redimensionnement / 100) + 537-107;
}

void afficherminimap(minimap m, SDL_Surface *screen)
{
  SDL_BlitSurface(m.map, NULL, screen, &m.positionmap);
  SDL_BlitSurface(m.minijoueur, NULL, screen, &m.positionminijoueur);
}

