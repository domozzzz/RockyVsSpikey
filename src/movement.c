#include "movement.h"
#include <stdio.h>

#define MAXBUFLEN 100

void get_movement(struct player *player, struct player *player2) {
    SDL_Event event;
	SDL_PollEvent(&event);
	const uint8_t *keystate = SDL_GetKeyboardState(NULL);

	if (event.type == SDL_QUIT) 
        player->running = 0;

	// Player 1

	if (keystate[SDL_SCANCODE_W])
		player->jump = 1;

	if (keystate[SDL_SCANCODE_S])
		player->down = 1;
	
	if (keystate[SDL_SCANCODE_A])
		player->left = 1;
	
	if (keystate[SDL_SCANCODE_D])
		player->right = 1;
	
	// Player 2
	if (keystate[SDL_SCANCODE_UP])
		player2->jump = 1;

	if (keystate[SDL_SCANCODE_DOWN])
		player->down = 1;
	
	if (keystate[SDL_SCANCODE_LEFT])
		player2->left = 1;
	
	if (keystate[SDL_SCANCODE_RIGHT])
		player2->right = 1;
	

}


void handle_movement(struct player *player, struct screen* screen) {
	// Left
	if (player->left) {
		if (player->x > 0) {
			player->x -= player->speed;
		}
	}
	
	// Right
	if (player->right) {
		if (player->x < screen->sw - TILE_SIZE)
			player->x += player->speed;
	}

	// Jump
	if (player->jump && player->grounded) {
		player->jumping = 1;
		player->grounded = 0;
	}
	
	// Jumping up
	if (player->jumping) {
		if (player->jump_height < player->jump_max) {
			player->y -= player->speed;
			player->jump_height++;
		} else if (player->jump_height == player->jump_max)
			player->jumping = 0;
	}
	
	// Falling
	if (!player->jumping && !player->grounded) {
		if (player->jump_height > 0) {
			player->y += player->speed;
			player->jump_height--;
		} else if (player->jump_height == 0)
			player->grounded = 1;
	}
}


void handle_collisions(struct player *player,struct player *player2, struct screen* screen) {
	
	SDL_Rect p1_rect = {player->x, player->y, TILE_SIZE, TILE_SIZE};
	SDL_Rect p2_rect = {player2->x, player2->y, TILE_SIZE, TILE_SIZE};	

	// Check Collision
	if (SDL_HasIntersection(&p1_rect, &p2_rect)) {
		// Player one higher
		if (player->y < player2->y) {
			player->x = player->spawn_x;
			player->y = player->spawn_y;
			player->grounded = 1;
			player->jumping = 0;
			player->jump_height = 0;
			player2->x = player2->spawn_x;
			player2->y = player2->spawn_y;
			player2->grounded = 1;
			player2->jumping = 0;
			player2->jump_height = 0;

			player->score++;

		// Player two higher
		} else if (player->y > player2->y) {
			player->x = player->spawn_x;
			player->y = player->spawn_y;
			player->grounded = 1;
			player->jumping = 0;
			player->jump_height = 0;
			player2->x = player2->spawn_x;
			player2->y = player2->spawn_y;
			player2->grounded = 1;
			player2->jumping = 0;
			player2->jump_height = 0;
			
			player2->score++;
		}
	}
}
	
void clear_movement(struct player *player) {
	player->left = 0;
	player->right = 0;
	player->jump = 0;
}