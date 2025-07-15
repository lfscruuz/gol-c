#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h> 
#include <SDL2/SDL.h>

#include "config.h"
#include "grid_setup.h"

void print_grid(int grid[HEIGHT][WIDTH]) {
	for (int i = 0; i < HEIGHT; i++){
		for (int j = 0; j < WIDTH; j++) {
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
}



int main() {
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *window = SDL_CreateWindow("Game Of Life", 
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			WIDTH * CELL_SIZE, HEIGHT + CELL_SIZE, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

	srand(time(NULL));
	int grid[HEIGHT][WIDTH];
	bool running = true;
	SDL_Event event;

	set_initial_grid(grid, renderer);

	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		life_cycle(grid, renderer);	
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
