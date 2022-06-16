#include "perso.h"
typedef struct{
SDL_Surface *imag;
SDL_Rect pos;
}image;
int main(){
int acc=0;
image background;
SDL_Surface  *screen = NULL;
perso p;
SDL_Init(SDL_INIT_EVERYTHING);
screen = SDL_SetVideoMode(1363, 768, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    if( screen == NULL )
    {
        printf( "Can't set video mode: %s \n", SDL_GetError( ) );
        return EXIT_FAILURE;
    }
    background.imag=IMG_Load("/home/marououma/TÃ©lÃ©chargements/image (1).jpg");
    background.pos.x=0;
    background.pos.y=0;
    initPerso(&p);
    SDL_Event event;
int loop =1;//loop el game
int move=0;
Uint32 dt , t_prev;
while(loop){
t_prev = SDL_GetTicks ();
SDL_BlitSurface(background.imag,NULL,screen,&background.pos);
//SDL_Delay(37);
affichierPerso (p ,screen);
SDL_PollEvent(&event);


            switch(event.type)
            {
                case SDL_QUIT:
                    loop = 0;
                    break;
                    case SDL_KEYDOWN://event clavier ki tenzel 3ala ay bouton mel clavier  
                {

                    switch(event.key.keysym.sym){

			case SDLK_UP:
			p.up=1;
			break;

                   case SDLK_LEFT :
                   p.i=1;
		   move=1;
		   acc=1;
                    
                    break;//end SDLK_left
                    case SDLK_RIGHT:
                      p.i=0;
		      move =1;
		      acc=1;
                      
                    
                    break;//end SDLK_RIGHT

		    
                    }//end switch event.key.keysym.sym
                    break;
                   default :
                      { acc=0;
                      }
                     break;//end default
                     }//end SDL_KEYDOWN
                    
                    }
		
		if (move ==1)
		{p.score ++;
		 animerPerso (&p);
                 deplacerPerso (&p,dt);
		}
                    if (acc==1)
                   {p.acceleration +=0.05;
 		   if (p.acceleration >= 1)
                     {p.acceleration=1;}}
		   else if (acc==0)
			{p.acceleration -=0.06;
 		   if (p.acceleration <= 0)
                     {p.acceleration=0;
			move =0;
    			p.j=0;}}
                    
                    
                    
                   dt=SDL_GetTicks()-t_prev; 
		   saut(&p);
		   SDL_Delay(200/dt);
                   SDL_Flip(screen);
		
                    }//end loop game


return 0;
}
