#include "render.h"


void render(SDL_Renderer* renderer, struct screen* screen, struct player *player, struct player *player2) {
    SDL_RenderClear(renderer);

    for (int x = 0; x < screen->swt; x++) {
        for (int y = 0; y < screen->sht; y++) {

            if (y <= 0 || y >= 9) {
                SDL_Rect dest = {(x * TILE_SIZE) % screen->sw, y * TILE_SIZE, TILE_SIZE, TILE_SIZE};

                    SDL_RenderCopy(renderer, player->tile, NULL, &dest);
            }
        }
    }
		
	SDL_Rect dest;
	dest.x = player->x;
	dest.y = player->y;
	dest.w = TILE_SIZE;
	dest.h = TILE_SIZE;

   	SDL_RenderCopy(renderer, player->tile, NULL, &dest);

	dest.x = player2->x;
	dest.y = player2->y;
				
	SDL_RenderCopy(renderer, player2->tile, NULL, &dest);

    dest.x = 0;
    dest.y = TILE_SIZE;
    SDL_RenderCopy(renderer, screen->num_tiles[player->score], NULL, &dest);

    dest.x = screen->sw - TILE_SIZE;
    dest.y = TILE_SIZE;

    SDL_RenderCopy(renderer, screen->num_tiles[player2->score], NULL, &dest);

    SDL_RenderPresent(renderer);    
    SDL_Delay(1000 / 60);
}