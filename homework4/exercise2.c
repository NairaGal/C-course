#include <stdio.h>

int main() {
	double num1, num2;
	char op;

	printf("Enter expressions (e.g. 3 +,-,*,%% 4). Press Ctrl+D (EOF) to exit.\n");


	while (scanf("%lf %c %lf", &num1, &op, &num2) == 3) {
		switch (op) {
			case '+':
				printf("=%.2lf\n", num1 + num2);
				break;
			case '-':
				printf("=%.2lf\n", num1 - num2);
				break;
			case '*':
				printf("%.2lf\n", num1 * num2);
				break;
			case '/':
				if (num2 == 0)
					printf("Error: Division by zero!\n");
				printf("%.2lf\n", num1 / num2);
				break;
			case '%':
				if ((int)num2 == 0)
					printf("Error: Modulo by zero!\n");
				else
					printf("= %d\n", (int)num1 % (int)num2);
				break;
			default:
				printf("Error: Unknown operator '%c'\n", op);
		}
	}

	printf("\nExiting calculator. Goodbye!\n");
	return 0;
}
