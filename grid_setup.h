#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

#include "config.h"

void render_grid(int grid[HEIGHT][WIDTH], SDL_Renderer *renderer) {
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (grid[y][x] == 1) {
				SDL_Rect cell = { x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE};
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				SDL_RenderFillRect(renderer, &cell);
			}
		}
	}
	SDL_RenderPresent(renderer);
	SDL_Delay(100);
}

void set_initial_grid(int grid[HEIGHT][WIDTH], SDL_Renderer *renderer){
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			int choice = rand() % 100;
			if (choice < 10){
				grid[y][x] = 1;
			} else {
				grid[y][x] = 0;
			}
		}
	}

	render_grid(grid, renderer);
}

void life_cycle(int grid[HEIGHT][WIDTH], SDL_Renderer *renderer) {
	int next[HEIGHT][WIDTH] = {0};
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			int live_neighbors = 0;
			for (int i = y - 1; i <= y + 1; i++) {
				for (int j = x - 1; j <= x + 1; j++){
					if ( i == y && j == x) {
						continue;
					}
					if (i >= 0 && i < HEIGHT && j >= 0 && j < WIDTH) {
						if (grid[i][j] == 1) {
							live_neighbors++;
						}
					}
				}
			}
			if (grid[y][x] == 1) {
				if (live_neighbors == 2 || live_neighbors == 3){
					next[y][x] = 1;
				} else {
					next[y][x] = 0;
				}
			}
			else {
				if (live_neighbors == 3) {
					next[y][x] = 1;
				}
			}
		}
	}

	memcpy(grid, next, sizeof(int) * WIDTH * HEIGHT);
	render_grid(grid, renderer);
}
