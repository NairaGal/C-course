#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
	if (n < 2) return false;
	for(int i = 2; i * i <= n; i++) {
		if(n % i == 0) return false;

	}
	return true;
}

void findPrimeSums(int n) {
	bool found = false;
	for (int i = 2; i <= n / 2; i++) {
		int j = n - i;
		if (isPrime(i) && isPrime(j)) {
			printf("%d + %d = %d\n", i, j, n);
			found = true;
		}
	}
	if (!found) {
		printf("No combinations of two primes sum to %d.\n", n);
	}
}

int main() {
	int number;
	printf("Enter a number: ");
	if (scanf("%d", &number) != 1 || number < 2) {
		printf("Invalid input. Enter a number >= 2.\n");
		return 1;
	}

	findPrimeSums(number);

	return 0;
}
