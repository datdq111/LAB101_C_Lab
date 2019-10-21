#include <stdio.h>

int main() {

	char c, x;

	do {
		int n;
		printf("Enter n: ");
		scanf("%d", &n);

		while ((n < 1 || n > 9) || (x = getchar()) != '\n') {
			fflush(stdin);
			printf("You're not enter a number, please re-enter n: ");
			scanf("%d", &n);

		}

		for (int i = 1; i <= 10; i++)
			printf("%d x %d = %d\n", n, i, n*i);

		fflush(stdin);
		printf("(y/n) ");
		scanf("%c", &c);

		while ((c != 'y' && c != 'Y' && c != 'n' && c != 'N') || (x = getchar()) != '\n') {
			fflush(stdin);
			printf("please re-enter (y/n): ");
			scanf("%c", &c);
		}
	} while (c == 'y' || c == 'Y');

	getchar();
}