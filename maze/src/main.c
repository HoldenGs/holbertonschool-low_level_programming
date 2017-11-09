#include "../headers/main.h"



#define TILE_SIZE 256
#define WALL_HEIGHT 256

#define EPSILON 0.00001
#define FOV 60
#define PLAYERPROJECTIONDISTANCE 622
#define DIVIDEBYDISTANCE (PLAYERPROJECTIONDISTANCE * WALL_HEIGHT)

#define SCREEN_WIDTH 1260
#define SCREEN_HEIGHT 720
#define SCREEN_Y_MIDDLE 360
#define SCREEN_X_MIDDLE 630

#define ANGLE60 PLAYERPROJECTIONDISTANCE
#define ANGLE30 (ANGLE60 / 2)
#define ANGLE15 (ANGLE30 / 2)
#define ANGLE90 (ANGLE30 * 3)
#define ANGLE180 (ANGLE90 * 2)
#define ANGLE270 (ANGLE90 * 3)
#define ANGLE360 (ANGLE180 * 2)
#define ANGLE0 0


// TODO:
// 	- connect player struct to renderer
// 	- connect map struct to renderer
// 	- work out all bugs in renderer


int main(void)
{
	int quit = 0;
	int new_map[25];
	SDL_Instance instance;
	MAZE_Map map;
	MAZE_Player player;
	// SDL_RWops *file;
	// char map_path[] = "../maps/map_1.map";
	char *old_map = "1111100110011001100110011001100110011111";
	for (int c = 0; old_map[c] != 0; c++)
	{
		if (old_map[c] == 49)
			new_map[c] = 1;
		else
			new_map[c] = 0;
	}
	map.map = new_map;
	map.width = 4;
	map.height = 10;


	player.height = 128;
	// player.x = TILE_SIZE * 3 - (TILE_SIZE / 2) - 32;
	// player.y = TILE_SIZE * 6 - (TILE_SIZE / 2);
	player.x = 438.187197;
	player.y =797.032192;
	player.orientation = 265;


	if (init_instance(&instance) != 0)
		return (1);

	while (!quit)
	{
		SDL_SetRenderDrawColor(instance.renderer, 128, 255, 255, 255);
		SDL_RenderClear(instance.renderer);
		draw_rays(instance, player, map);
		SDL_RenderPresent(instance.renderer);
		if (poll_events(&player) == 1)
			quit = 1;
	}
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
	return (0);
}


int poll_events(MAZE_Player *player)
{
	int left, right;
	SDL_Event event;
	SDL_KeyboardEvent key;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				return (1);
			case SDL_KEYDOWN:
			{
				key = event.key;
				if (key.keysym.scancode == 0x29)
					return (1);
				else if (key.keysym.scancode == SDL_SCANCODE_A)
				{
					player->orientation += 5;
					if (player->orientation > 360)
						player->orientation -= 360;
				}
				else if (key.keysym.scancode == SDL_SCANCODE_D)
				{
					player->orientation -= 5;
					if (player->orientation < 0)
						player->orientation += 360;
				}
				else if (key.keysym.scancode == SDL_SCANCODE_W)
				{
					player->x += 20 * cos(d_to_r(player->orientation));
					player->y -= 20 * sin(d_to_r(player->orientation));
					printf("player.x: %f\nplayer.y: %f\n", player->x, player->y);
					printf("fov center: %f\n", player->orientation);
				}
				else if (key.keysym.scancode == SDL_SCANCODE_S)
				{
					player->x -= 10 * cos(d_to_r(player->orientation));
					player->y += 10 * sin(d_to_r(player->orientation));
				}
			}
			case SDL_KEYUP:
			{
				key = event.key;
				if (key.keysym.scancode == SDL_SCANCODE_A)
					left = 0;
				else if (key.keysym.scancode == SDL_SCANCODE_D)
					right = 0;
			}
		}
		// if (left) ;
		// if (right) ;
	}
	return (0);
}

double d_to_r(double degrees)
{
	return (M_PI * (double)degrees) / 180;
}

// SDL_RWops import_map(map_path)
// {

// }

// print out map
// for (int i = 0; i < map.height; i++)
// 	{
// 		for (int j = 0; j < map.width; j++)
// 		{
// 			printf("%i", map.map[i * map.width + j]);
// 		}
// 		printf("\n");
// 	}

void draw_rays(SDL_Instance instance, MAZE_Player player, MAZE_Map map)
{
	int flag, grid_index_x, grid_index_y;
	double horizontal_tile_x, horizontal_tile_y, vertical_tile_x, vertical_tile_y;
	double arc, tan_arc, sin_arc, cos_arc;
	double next_x, next_y, horizontal_d, vertical_d;
	double distorted_distance, distance, wall_height, wall_y1, wall_y2;
	arc = player.orientation + (FOV / 2);
	flag = 0;
	if (arc >= 360) // correct arc angle
		arc -= 360;


	for (int column = 0; column < SCREEN_WIDTH; column++)
	{
		tan_arc = tan(d_to_r(arc));
		sin_arc = sin(d_to_r(arc));
		cos_arc = cos(d_to_r(arc));

		// Find horizontal walls
		if (arc > 0 && arc < 180) // ray is up
		{
			horizontal_tile_y = floor(player.y / TILE_SIZE) * TILE_SIZE - 1;
			horizontal_tile_x = player.x + (player.y - horizontal_tile_y) / tan_arc;
			next_y = -TILE_SIZE;
		}
		else // ray is down
		{
			horizontal_tile_y = floor(player.y / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
			horizontal_tile_x = player.x + (player.y - horizontal_tile_y) / tan_arc;
			next_y = TILE_SIZE;
		}
		next_x = TILE_SIZE / tan_arc;
		if (fabs(arc - 0) < EPSILON || fabs(arc - 180) < EPSILON) // ray is facing exactly 0 or 180 degrees
			horizontal_d = INT_MAX;
		else
		{
			while (1) // search for walls
			{
				grid_index_y = horizontal_tile_y / TILE_SIZE;
				grid_index_x = horizontal_tile_x / TILE_SIZE;
				if (grid_index_x >= map.width || grid_index_y >= map.height ||
					grid_index_x < 0 || grid_index_y < 0)
				{
					horizontal_d = INT_MAX;
					break;
				}
				else if (map.map[grid_index_y * map.width + grid_index_x] == 1)
				{
					//horizontal_d = fabs((player.x - horizontal_tile_x) / cos_arc);
					horizontal_d = sqrt(pow((player.x - horizontal_tile_x), 2) + pow((player.y - horizontal_tile_y), 2));
					// if (horizontal_d < 0)
					// 	horizontal_d = INT_MAX;
					break;
				}
				else
				{
					horizontal_tile_y += next_y;
					horizontal_tile_x += next_x;
				}
			}
		}


		// Find vertical walls
		if (arc > 90 && arc < 270) // ray is left
		{
			vertical_tile_x = floor(player.x / TILE_SIZE) * TILE_SIZE - 1;
			vertical_tile_y = player.y + (player.x - vertical_tile_x) * tan_arc;
			next_x = -TILE_SIZE;
		}
		else // ray is right
		{
			vertical_tile_x = floor(player.x / TILE_SIZE) * TILE_SIZE + TILE_SIZE;
			vertical_tile_y = player.y + (player.x - vertical_tile_x) * tan_arc;
			next_x = TILE_SIZE;
		}
		next_y = TILE_SIZE * tan_arc;
		if (fabs(arc - 90) < EPSILON || fabs(arc - 270) < EPSILON) // ray is facing exactly 90 or 270 degrees
			vertical_d = INT_MAX;
		else
		{
			while (1)
			{
				grid_index_x = vertical_tile_x / TILE_SIZE;
				grid_index_y = vertical_tile_y / TILE_SIZE;
				if (grid_index_x >= map.width || grid_index_y >= map.height ||
					grid_index_x < 0 || grid_index_y < 0)
				{
					vertical_d = INT_MAX;
					break;
				}
				else if (map.map[grid_index_y * map.width + grid_index_x] == 1)
				{
					//vertical_d = (player.x - vertical_tile_x) / cos_arc;
					vertical_d = sqrt(pow((player.x - vertical_tile_x), 2) + pow((player.y - vertical_tile_y), 2));
					// if (vertical_d < 0)
					// 	vertical_d = INT_MAX;
					break;
				}
				else
				{
					vertical_tile_y += next_y;
					vertical_tile_x += next_x;
				}
			}
		}
		if (vertical_d < horizontal_d)
		{
			SDL_SetRenderDrawColor(instance.renderer, 100, 100, 100, 0xFF);
			distorted_distance = vertical_d;
		}
		else
		{
			SDL_SetRenderDrawColor(instance.renderer, 200, 200, 200, 0xFF);
			distorted_distance = horizontal_d;
		}
		distance = distorted_distance * cos(d_to_r(player.orientation - arc));


		wall_height = DIVIDEBYDISTANCE / (distance + EPSILON);
		wall_y1 = SCREEN_Y_MIDDLE + (wall_height / 2);
		wall_y2 = SCREEN_Y_MIDDLE - (wall_height / 2);
		SDL_RenderDrawLine(instance.renderer, column, wall_y1, column, wall_y2);
		if (arc > 264 && arc < 266 && distorted_distance == vertical_d && flag == 0)
		{
			// printf("distance: %f, arc: %f\n", distance, arc);
			// printf("vertical_d: %f, horizontal_d: %f\n", vertical_d, horizontal_d);
			// printf("vertical_d = (%f - %f) / %f\n\n", player.x, vertical_tile_x, cos(d_to_r(arc)));
			// printf("horizontal_d = (%f - %f) / %f\n\n", player.y, horizontal_tile_y, sin(d_to_r(arc)));
			// printf("vertical_tile_y: %f\n\n", vertical_tile_y);
			printf("(player.x(%f) / 256) * 256 - 1 = %f\n", player.x, vertical_tile_x);
			printf("player.y(%f) + (player.x(%f) - %f) * %f = %f\n", player.y, player.x, vertical_tile_x, tan_arc, vertical_tile_y);
			flag = 1;
		}

		arc -= ((double)FOV / (double)SCREEN_WIDTH);
		if (arc < 0) // correct arc angle
			arc += 360;
	}
}


int init_instance(SDL_Instance *instance)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		return (1);
	}

	instance->window = SDL_CreateWindow("SDL2 \\o/", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if (instance->window == NULL)
	{
		fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
		SDL_Quit();
		return(1);
	}

	instance->renderer = SDL_CreateRenderer(instance->window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (instance->renderer == NULL)
	{
		SDL_DestroyWindow(instance->window);
		fprintf(stderr, "SDL_CreateRenderer Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (1);
	}
	return (0);
}
