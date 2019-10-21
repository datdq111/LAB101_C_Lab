#include <stdio.h>

int main() {
	int n,i;
	char a, b, c;
	//Check điều kiện ------------------------
	do {
		while (1) {
			fflush(stdin);//Giải phóng bộ nhớ. Vòng lặp thứ 2 nếu 'Y' thì nó sẽ hiển thị lại bảng cửu chương trước đó
			printf("Please enter a number (1-9): ");
			int flag = scanf("%d%c", &n, &c);
			//Check điều kiện --------------------
			if (flag == 0 || c != '\n') {
				while (getchar() != '\n');//Dừng vòng lặp 'Please enter a number (1-9): '..... Kí tự nhập vào khác enter ('\n') thì thoát ra while
			}
			else if (n < 1 || n > 9);
			else if (n >= 1 && n <= 9) {
				//-----------------------------------
					//Bảng cửu chương
				printf("Multiplication table for %d number.\n", n);
				for (i = 1; i <= 10; i++) {
					int m = n * i;
					printf("%d x %d = %d\n", n, i, m);
				}
				break;
			}
		}
		while (1) {
			printf("Do you want to continues? Y/N: ");
			int flag = scanf("%c%c", &a, &b);
			if (flag == 0 || b != '\n') {
				while (getchar() != '\n');
			}
			else if ((a == 'Y') || (a == 'y') || (a == 'N') || (a == 'n'))
				break;
		}
	} while (a == 'Y' || a == 'y');
	//----------------------------------------
	getchar();
}