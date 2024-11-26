#include <SDL.h>

#include "game.h"

int main(int argc, char* argv[]) {
	
	int SCALE = 4;

	struct screen screen;

	screen.swt = 20;
	screen.sht = 10;

	screen.sw = screen.swt * TILE_SIZE;
	screen.sh = screen.sht * TILE_SIZE;
	
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *window;
	SDL_Renderer *renderer;

	SDL_CreateWindowAndRenderer(320*SCALE, 160*SCALE, 0, &window, &renderer);
	SDL_RenderSetScale(renderer, SCALE, SCALE);
//	SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN)

	start_game(&screen, renderer);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}