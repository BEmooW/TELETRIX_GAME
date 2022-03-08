#ifndef enemy_H_INCLUDED
#define enemy_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>



/*
//typedef struct 
{
        SDL_Rect pos ;
        SDL_Surface *enigme[2] ;


}enigme;
*/


typedef struct 
        {
        SDL_Rect  pos , reponse_pos;
        
        SDL_Surface *enigme[2] ;
        SDL_Surface *reponse[2] , *reponse1[2] , *t , *h;
        
        }enigme;


void initEnigme(enigme *e,char *nonfichier);
void afficherEnigme(enigme e,SDL_Surface *screen);
void animer(enigme *e);

#endif // DS_H_INCLUDED



#endif // DS_H_INCLUDED
