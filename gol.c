#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define HEIGHT 20
#define WIDTH 20

int main() {
	srand(time(NULL));
	int grid[HEIGHT][WIDTH];
	
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH; j++) {
			int choice = rand() % 100;
			if (choice < 10){
				printf("# ");
			} else {
				printf("- ");
			}
		}
		printf("\n");
	}

	return 0;

}
