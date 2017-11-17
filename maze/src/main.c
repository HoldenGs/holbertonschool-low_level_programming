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



int main(int argc, char **argv)
{
	int quit;
	double frame_time, new_time, old_time;
	SDL_Instance instance;
	MAZE_Keys keys;
	MAZE_Player player;
	MAZE_Map map;
	quit = new_time = old_time = 0;

	if (argc > 1)
		map = import_map(argv[1], &player);

	// for (int i = 0; i < map.height; i++)
	// {
	// 	for (int j = 0; map.map[i][j] != '\n'; j++)
	// 	{
	// 		printf("%c", map.map[i][j]);
	// 	}
	// 	printf("\n");	
	// }

	// Initialize keys and player attributes
	keys.left = keys.right = keys.forward = keys.backward = 0;
	player.dir.x = -1;
	player.dir.y = 0;
	player.plane.x = 0;
	player.plane.y = 0.66;



	if (init_instance(&instance) != 0)
		return (1);

	while (!quit)
	{
		SDL_SetRenderDrawColor(instance.renderer, 128, 255, 255, 255);
		SDL_RenderClear(instance.renderer);
		old_time = new_time;
		draw_rays(instance, player, map);
		new_time = clock();
		frame_time = (new_time - old_time) / CLOCKS_PER_SEC;
		//printf("FPS: %f\n", 1 / frame_time);
		SDL_RenderPresent(instance.renderer);
		if (poll_events(&keys) == 1)
			quit = 1;
		move_player(&player, keys, map, frame_time);
	}
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
	return (0);
}


void move_player(MAZE_Player *player, MAZE_Keys keys, MAZE_Map map, double frame_time)
{
	double old_dir_x, old_plane_x, speed, rot_speed;
	speed = frame_time * 50;
	rot_speed = frame_time * 30;

	if (keys.left)
	{
		old_dir_x = player->dir.x;
		old_plane_x = player->plane.x;
		player->dir.x = player->dir.x * cos(rot_speed) - player->dir.y * sin(rot_speed);
		player->dir.y = old_dir_x * sin(rot_speed) + player->dir.y * cos(rot_speed);
		player->plane.x = player->plane.x * cos(rot_speed) - player->plane.y * sin(rot_speed);
		player->plane.y = old_plane_x * sin(rot_speed) + player->plane.y * cos(rot_speed);
	}
	if (keys.right)
	{
		old_dir_x = player->dir.x;
		old_plane_x = player->plane.x;
		player->dir.x = player->dir.x * cos(-rot_speed) - player->dir.y * sin(-rot_speed);
		player->dir.y = old_dir_x * sin(-rot_speed) + player->dir.y * cos(-rot_speed);
		player->plane.x = player->plane.x * cos(-rot_speed) - player->plane.y * sin(-rot_speed);
		player->plane.y = old_plane_x * sin(-rot_speed) + player->plane.y * cos(-rot_speed);
	}
	if (keys.forward)
	{
		if (map.map[(int)player->pos.y][(int)(player->pos.x + player->dir.x * speed)] == '0')
			player->pos.x += player->dir.x * speed;
		if (map.map[(int)(player->pos.y + player->dir.y * speed)][(int)player->pos.x] == '0')
			player->pos.y += player->dir.y * speed;
	}
	if (keys.backward)
	{
		if (map.map[(int)player->pos.y][(int)(player->pos.x - player->dir.x * speed)] == '0')
			player->pos.x -= player->dir.x * speed;
		if (map.map[(int)(player->pos.y - player->dir.y * speed)][(int)player->pos.x] == '0')
			player->pos.y -= player->dir.y * speed;
	}
}


void draw_rays(SDL_Instance instance, MAZE_Player player, MAZE_Map map)
{
	double camera_x, ray_pos_x, ray_pos_y, ray_dir_x, ray_dir_y, next_x, next_y;
	double side_dist_x, side_dist_y, delta_dist_x, delta_dist_y, perp_wall_dist;
	int map_x, map_y, hit, y_side, wall_height, wall_y1, wall_y2;

	for (int x = 0; x < SCREEN_WIDTH; x++)
	{
		camera_x = 2 * x / (double)SCREEN_WIDTH - 1; // ranges from -1 to 1
		ray_pos_x = player.pos.x;
		ray_pos_y = player.pos.y;
		ray_dir_x = player.dir.x + player.plane.x * camera_x;
		ray_dir_y = player.dir.y + player.plane.y * camera_x;

		map_x = (int)ray_pos_x;
		map_y = (int)ray_pos_y;

		delta_dist_x = sqrt(1 + (ray_dir_y * ray_dir_y) / (ray_dir_x * ray_dir_x));
		delta_dist_y = sqrt(1 + (ray_dir_x * ray_dir_x) / (ray_dir_y * ray_dir_y));

		if (ray_dir_x < 0) // ray is left
		{
			next_x = -1;
			side_dist_x = (ray_pos_x - map_x) * delta_dist_x;
		}
		else // ray is right
		{
			next_x = 1;
			side_dist_x = (map_x + 1.0 - ray_pos_x) * delta_dist_x;
		}
		if (ray_dir_y < 0) // ray is up
		{
			next_y = -1;
			side_dist_y = (ray_pos_y - map_y) * delta_dist_y;
		}
		else // ray is down
		{
			next_y = 1;
			side_dist_y = (map_y + 1.0 - ray_pos_y) * delta_dist_y;
		}

		hit = 0;
		while (hit == 0) // search for wall
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += next_x;
				y_side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += next_y;
				y_side = 1;
			}
			if (map.map[map_y][map_x] == 'W')
				hit = 1;
		}

		if (y_side == 0) perp_wall_dist = (map_x - ray_pos_x + (1 - next_x) / 2) / ray_dir_x;
		else 			 perp_wall_dist = (map_y - ray_pos_y + (1 - next_y) / 2) / ray_dir_y;

		wall_height = (int)(SCREEN_HEIGHT / perp_wall_dist);

		wall_y1 = SCREEN_Y_MIDDLE + (wall_height / 2);
		wall_y2 = SCREEN_Y_MIDDLE - (wall_height / 2);

		if (y_side) SDL_SetRenderDrawColor(instance.renderer, 200, 200, 200, 0xFF);
		else		SDL_SetRenderDrawColor(instance.renderer, 100, 100, 100, 0xFF);

		SDL_RenderDrawLine(instance.renderer, x, wall_y1, x, wall_y2);
	}

}


MAZE_Map import_map(char *file_str, MAZE_Player *player)
{
	int read;
	size_t line_count, line_length, width, i;
	FILE *map_file;
	MAZE_Map *map;
	char *line = NULL;
	read = 0;

	if ((map = malloc(sizeof(MAZE_Map))) == NULL)
	{
		printf("Malloc failed to allocate space for map!\n");
		exit(1);
	}

	if ((map_file = fopen(file_str, "r")) == NULL)
	{
		printf("Map file not found!\n");
		exit(1);
	}

	read = getline(&line, &line_length, map_file);
	if (read == -1)
	{
		printf("Map file is empty!\n");
		exit(1);
	}

	for (line_count = 0; read != -1; line_count++)
		read = getline(&line, &line_length, map_file);

	map->height = line_count;
	map->map = malloc(line_count * sizeof(int *));
	if (map->map == NULL)
	{
		printf("Malloc failed to allocate space for map!\n");
		exit(1);
	}
	rewind(map_file);
	read = getline(&line, &line_length, map_file);
	for (line_count = 0; read != -1; line_count++)
	{
		// find width of map line
		for (width = 0; line[width] != '\0'; width++)
			;

		map->map[line_count] = malloc(width * sizeof(char) + 1);
		for (i = 0; i < width; i++)
		{
			if (line[i] == 'P')
			{
				player->pos.x = i;
				player->pos.y = line_count;
				map->map[line_count][i] = '0';
			}
			else if (line[i] == ' ' || line[i] == '0')
				map->map[line_count][i] = '0';
			else
				map->map[line_count][i] = line[i];
		}
		map->map[line_count][width] = '\0';
		read = getline(&line, &line_length, map_file);
	}
	fclose(map_file);
	free(line);
	return (*map);
}


int poll_events(MAZE_Keys *keys)
{
	SDL_Event event;
	SDL_KeyboardEvent key;

	while (SDL_PollEvent(&event))
	{
		key = event.key;
		if (event.key.repeat == 0)
		{
			if (event.type == SDL_QUIT)
				return (1);
			else if (event.type == SDL_KEYDOWN)
			{
				if (key.keysym.scancode == 0x29)
					return (1);
				if (key.keysym.scancode == SDL_SCANCODE_A)
					keys->left = 1;				
				if (key.keysym.scancode == SDL_SCANCODE_D)
					keys->right = 1;
				if (key.keysym.scancode == SDL_SCANCODE_W)
					keys->forward = 1;
				if (key.keysym.scancode == SDL_SCANCODE_S)
					keys->backward = 1;
			}
			else if (event.type == SDL_KEYUP)
			{
				if (key.keysym.scancode == SDL_SCANCODE_A)
					keys->left = 0;
				if (key.keysym.scancode == SDL_SCANCODE_D)
					keys->right = 0;
				if (key.keysym.scancode == SDL_SCANCODE_W)
					keys->forward = 0;
				if (key.keysym.scancode == SDL_SCANCODE_S)
					keys->backward = 0;
			}
		}
	}
	return (0);
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
