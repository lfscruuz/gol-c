#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "config.h"

void set_initial_grid(int grid[HEIGHT][WIDTH]){
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
}

