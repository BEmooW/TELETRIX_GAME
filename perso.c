#include "perso.h"


void initPerso (perso *p)
{
int i,j;
char pers [20];
for (i=0;i<2;i++)
{for (j=0;j<5;j++)
{sprintf(pers,"pers/%d-%d.png",i,j);
p->image [i][j]=IMG_Load (pers);
}}
p->i=0;
p->j=0;
p->pos_background.x=50;
p->pos_background.y=400;
p->pos_barre.x=20;
p->pos_barre.y=20;
p->pos_score.x=600;
p->pos_score.y=50;
p->acceleration =0;
p->vitesse=1;
p->up=0;
p->vect_x=5;
p->vect_grav=0.4;
p->vect_y=-8;
p->score =0;
p->vie =IMG_Load ("pers/barre_0.png");
}

void affichierPerso (perso p , SDL_Surface *screen)
{
SDL_BlitSurface (p.image[p.i][p.j],NULL,screen,&p.pos_background);
SDL_BlitSurface (p.vie,NULL,screen,&p.pos_barre);
TTF_Init();
TTF_Font *police =TTF_OpenFont ("1_Ichiro.otf",200);
SDL_Color textColor={0,0,0};
SDL_Surface *texte=NULL;
char nom[20];
sprintf(nom,"Score : %d ",p.score/5);
printf("nom = %s\n",nom);
texte=TTF_RenderText_Blended(police,nom,textColor);
SDL_BlitSurface(texte,NULL,screen,&p.pos_score);

TTF_CloseFont(police);
TTF_Quit();
SDL_FreeSurface(texte);
}

void animerPerso (perso* p)
{
p->j++;
if (p->j >= 4)
{
p->j=0;
}}

void deplacerPerso (perso *p , int dt)
{
double dx; 
dx=0.5 * p->acceleration * dt * dt + p->vitesse *dt ;
if (p->i ==0)
{p->pos_background.x += dx;
}
else if (p->i==1)
{p->pos_background.x -=dx;
}
if (p->pos_background.x>=1300)
{p->pos_background.x = 1300 ; }
if (p->pos_background.x<=0)
{p->pos_background.x = 0;}
}

void saut (perso* p)
{
 if (p->up==1)
{if(p->i==0)
{p->pos_background.x +=p->vect_x;}
if (p->i==1)
{p->pos_background.x -= p->vect_x;}
p->pos_background.y += p->vect_y;
p->vect_y += p->vect_grav;
}
if(p->pos_background.y>400)
{p->vect_y=-8;
p->up=0;
p->pos_background.y=400;
}
if (p->pos_background.x<=0)
{p->pos_background.x=0;}
if (p->pos_background.x>=1300)
{p->pos_background.x=1300;}
}
