#include <SDL2/SDL.h>

#ifndef _DEMO_H_
#define _DEMO_H_


typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

int init_instance(SDL_Instance *);
void draw_stuff(SDL_Instance);
int poll_events();

#endif