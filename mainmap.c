#include "minimap.h"

int main()
{
    TTF_Init();
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *screen, *perso;
    screen = SDL_SetVideoMode(800, 537, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_Rect camera, posperso;
    SDL_Event event;
    minimap m;
    SDL_Surface *back;
    perso = IMG_Load("hero.png");
    back = IMG_Load("map.jpg");
    int continuer = 1;
    init_map(&m);
    camera.x = 0;
    camera.y = 0;
    camera.w = 800;
    camera.h = 537;
    posperso.x = 0;
    posperso.y = 260;
    SDL_EnableKeyRepeat(100, 10);
    while (continuer)
    {
        SDL_BlitSurface(back, NULL, screen, NULL);
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:

                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_LEFT:
                    posperso.x -= 5;
                break;
                case SDLK_RIGHT:
                    posperso.x += 5;
                    break;
                case SDLK_UP:
                    posperso.y -= 5;
                    break;
                case SDLK_DOWN:
                    posperso.y += 5;
                    break;
                }
                break;
            }
        }
        if (posperso.x >= 800-44)
            posperso.x = 800-44;
        if (posperso.y >= 537-70)
            posperso.y = 537-70;

        SDL_BlitSurface(perso, NULL, screen, &posperso);

        MAJMinimap(posperso, &m, camera, (int)800/44);
        afficherminimap(m, screen);

        SDL_Flip(screen);
       
    }

    return 0;
}
