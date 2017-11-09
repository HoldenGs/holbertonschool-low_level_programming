#include <SDL2/SDL.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

#include "player.h"
#include "map.h"

#ifndef _MAIN_H_
#define _MAIN_H_


typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

int init_instance(SDL_Instance *);
void draw_rays(SDL_Instance, MAZE_Player, MAZE_Map);
int poll_events();
double d_to_r(double);

#endif
