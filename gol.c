#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define HEIGHT 30
#define WIDTH 30

void print_grid(char grid[HEIGHT][WIDTH]) {
	for (int i = 0; i < HEIGHT; i++){
		for (int j = 0; j < WIDTH; j++) {
			printf(" %c", grid[i][j]);
		}
		printf("\n");
	}
}

void set_initial_grid(char grid[HEIGHT][WIDTH]) {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			int choice = rand() % 100;
			if (choice < 5){
				grid[i][j] = '#';
			} else {
				grid[i][j] = '-';
			}
		}
	}

}

int main() {
	srand(time(NULL));
	char grid[HEIGHT][WIDTH];

	if (grid[0][0] != '#' || grid[0][0] != '-'){
		set_initial_grid(grid);
	}

	print_grid(grid);

	return 0;

}
