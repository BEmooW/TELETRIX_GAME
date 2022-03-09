#include <stdio.h>
 #include<stdlib.h>
 #include<SDL/SDL.h>
 #include<SDL/SDL_image.h>

void initennemi(ennemi *e){
 e->sprite=IMG_Load("/home/achref/Bureau/es/graphic/sprite.png");
 if(e->sprite==NULL){
 return ;
 }
 e->possprite.x=0;
 e->possprite.y=0;
 e->possprite.w=1280/10; // nbre de ligne 
 e->possprite.h=327/2; //nbre de colonne  
 e->posscreen.x=0;
 e->posscreen.y=0;
 //e->direction=0;
 }
