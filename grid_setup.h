#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

#include "config.h"

void render_grid(int grid[HEIGHT][WIDTH], SDL_Renderer *renderer) {
	for (int y = 0; y < HEIGHT; y++) {
			for (int x = 0; x < WIDTH; x++) {
				if (grid[y][x]) {
					SDL_Rect cell = { x * CELL_SIZE * 1.5, y * CELL_SIZE * 1.5, CELL_SIZE * 1.5, CELL_SIZE * 1.5};
					SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
					SDL_RenderFillRect(renderer, &cell);
				}
			}
	}
	SDL_RenderPresent(renderer);
	SDL_Delay(100);
}

void set_initial_grid(int grid[HEIGHT][WIDTH], SDL_Renderer *renderer){
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			int choice = rand() % 100;
			if (choice < 5){
				grid[i][j] = 1;
			} else {
				grid[i][j] = 0;
			}
		}
	}

	render_grid(grid, renderer);
}

void life_cycle(int grid[HEIGHT][WIDTH], SDL_Renderer *renderer) {
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			int live_neighbors = 0;
			for (int i = x - 1; i <= x + 1; i++) {
				for (int j = y - 1; j <= y + 1; j++){
					if ( i == x && j == y) {
						continue;
					}
					if (grid[i][j] == 1) {
						live_neighbors++;
					}
				}
			}
			if (grid[x][y] == 1) {
				if (live_neighbors != 2 && live_neighbors != 3){
					grid[x][y] = 0;
				}
			}
			else {
				if (live_neighbors == 3) {
					grid[x][y] = 1;
				}
			}
		}
	}

	render_grid(grid, renderer);
}
