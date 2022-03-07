
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "minimap.h"


int main()
{

SDL_Init(SDL_INIT_VIDEO);
SDL_Surface *screen , *perso;
screen=SDL_SetVideoMode (1000,666,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
SDL_Rect camera,posperso,backgpos;
SDL_Event event;
minimap m;

SDL_Surface *back;
perso=IMG_Load("hero.png");
back=IMG_Load("backg.png");

int continuer=1;

init_map(&m);
camera.x=0;
camera.y=0;
camera.w=1300;
camera.h=700;
posperso.x=0;
posperso.y=400;
backgpos.x=0;
backgpos.y=0;

SDL_EnableKeyRepeat(100,10);

while(continuer)
{
SDL_PollEvent(&event);

switch (event.type)
            {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    continuer = 0;
                    break;
                }break;
                
             }
SDL_BlitSurface(back,NULL,screen,&backgpos);

SDL_BlitSurface(perso,NULL,screen,&posperso);

afficherminimap(m,screen);

MAJMinimap(posperso ,  &m, camera, 20);

SDL_Flip(screen);


}

    return 0;
}





