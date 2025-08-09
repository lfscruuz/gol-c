#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

#include "config.h"

void render_grid(int grid[HEIGHT][WIDTH], SDL_Renderer *renderer);
void set_initial_grid(int grid[HEIGHT][WIDTH], SDL_Renderer *renderer);
void life_cycle(int grid[HEIGHT][WIDTH], SDL_Renderer *renderer);
