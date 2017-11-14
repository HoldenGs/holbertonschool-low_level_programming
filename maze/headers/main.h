#include <SDL2/SDL.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <limits.h>


#ifndef VECTOR_H
#define VECTOR_H

typedef struct Vector_s
{
	double x;
	double y;
} Vector;

#endif


#include "player.h"
#include "map.h"


#ifndef INSTANCE_H
#define INSTANCE_H

typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;


int init_instance(SDL_Instance *);
void draw_rays(SDL_Instance, MAZE_Player, MAZE_Map);
MAZE_Map import_map(char *, MAZE_Player *);
int poll_events(MAZE_Player *, MAZE_Map, double);
double d_to_r(double);

#endif


