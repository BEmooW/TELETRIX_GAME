#ifndef ENIGME_TEXTE_H_INCLUDED
#define ENIGME_TEXTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>



typedef struct 
{
        SDL_Rect pos ;
        SDL_Surface *enigme[2] ;


}enigme;

void afficherEnigme(enigme e, SDL_Surface * screen);
void InitEnigme(enigme * e, char *nomfichier);
void animer (enigme * e);
void sauvegarder (personne p, background b, char * nomfichier); 
int charger ( personne * p, background *b , char * nomfichier);

#endif // ENIGME_TEXTE_H_INCLUDED
