#ifndef GAME_H	
#define GAME_H

#include <SDL.h>

#define TILE_SIZE 16

struct screen {
	int swt, sht; // screen width/height tiles
	int sw, sh; // screen width/height
	SDL_Texture* num_tiles[11];
};

struct player {
	int left;
	int right;
	int down;
	int jump;
	char last;
 	int speed;
    int grounded;
	int jumping;
	int jump_height;
	int jump_max;
	int running;
	int x;
	int y;
	int spawn_x;
	int spawn_y;
	int score;

	SDL_Texture* tile;
};

void start_game(struct screen* screen, SDL_Renderer* renderer);
void* server_thread(void* vargp);
SDL_Texture* load_texture(const char *path, SDL_Renderer *renderer);


#endif