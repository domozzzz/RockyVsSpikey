#include "game.h"
#include "movement.h"
#include "render.h"

void start_game(struct screen* screen, SDL_Renderer* renderer) {

	struct player *player = malloc(sizeof(struct player));
	struct player *player2 = malloc(sizeof(struct player));

	player->running = 1;
	player->left = 0;
	player->right = 0;
	player->down = 0;
	player->jump = 0;
	player->last = 'r';
 	player->speed = 1;
    player->grounded = 1;
	player->jumping = 0;
	player->jump_max = 7 * TILE_SIZE;
	player->jump_height = 0;
	player->spawn_x = 5 * TILE_SIZE;
	player->spawn_y = 8 * TILE_SIZE;
	player->x = player->spawn_x;
	player->y = player->spawn_y;
	player->score = 0;

	player2->running = 1;
	player2->left = 0;
	player2->right = 0;
	player2->jump = 0;
	player2->down = 0;
	player2->last = 'r';
 	player2->speed = 1;
    player2->grounded = 1;
	player2->jumping = 0;
	player2->jump_max = 7 * TILE_SIZE;
	player2->jump_height = 0;
	player2->spawn_x = 12 * TILE_SIZE;
	player2->spawn_y = 8 * TILE_SIZE;
	player2->x = player2->spawn_x;
	player2->y = player2->spawn_y;
	player2->score = 0;
	
	player->tile = load_texture("tiles/rock.bmp", renderer);
	player2->tile = load_texture("tiles/spikey.bmp", renderer);

	screen->num_tiles[0] = load_texture("tiles/0.bmp", renderer);
	screen->num_tiles[1] = load_texture("tiles/1.bmp", renderer);
	screen->num_tiles[2] = load_texture("tiles/2.bmp", renderer);
	screen->num_tiles[3] = load_texture("tiles/3.bmp", renderer);
	screen->num_tiles[4] = load_texture("tiles/4.bmp", renderer);
	screen->num_tiles[5] = load_texture("tiles/5.bmp", renderer);
	screen->num_tiles[6] = load_texture("tiles/6.bmp", renderer);
	screen->num_tiles[7] = load_texture("tiles/7.bmp", renderer);
	screen->num_tiles[8] = load_texture("tiles/8.bmp", renderer);
	screen->num_tiles[9] = load_texture("tiles/9.bmp", renderer);
	screen->num_tiles[10] = load_texture("tiles/crown.bmp", renderer);

	while (player->running) {
		get_movement(player, player2);
		handle_movement(player, screen);
		handle_movement(player2, screen);
		handle_collisions(player, player2, screen);
		render(renderer, screen, player, player2);
		clear_movement(player);
		clear_movement(player2);
	}
	
	SDL_DestroyTexture(player->tile);
	SDL_DestroyTexture(player2->tile);
}

SDL_Texture* load_texture(const char *path, SDL_Renderer *renderer) {
	
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP(path));
	return texture;
}