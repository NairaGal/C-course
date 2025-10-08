#include <stdio.h>

void printPyramid(int n) {
	for (int i =1; i <= n; i++) {
		for (int j = 1; j <= n -i; j++) {
			printf(" ");
		}

		for (int k = 1; k <= 2 * i -1; k++) {
			printf("*");
		}
		printf("\n");
	}
}

int main() {
	int rows;

	printf("Enter the number of rows for the pyramid: ");
	if (scanf("%d", &rows) != 1 || rows <= 0) {
		printf("Invalid input. Please enter a positive integer.\n");
		return 1;
	}

	printPyramid(rows);

	return 0;
}


