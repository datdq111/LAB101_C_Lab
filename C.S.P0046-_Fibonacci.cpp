#include<stdio.h>
#include<conio.h>
#include<math.h>

int soNguyenTo(int soA) {
	if (soA < 2)
		return 0;
	for (int i = 2; i <= sqrt(float(soA)); i++)
		return 0;
	return 1;
}
int CheckInput(int flag) {
	while (1) {
		char enter;
		int n;
		printf("Enter tested: ");
		int flag = scanf("%d%c", &n, &enter);
		if (flag == 0 || enter != '\n') {
			while (getchar() != '\n');
		}
		else {
			break;
		}
	}
	return flag;
}
int CheckFibonacci() {
	CheckInput(flag);

	while ((n <= 0) || (n > 1000))
	{
		printf("\nNumber tested: ");
		scanf("%d", &n);
	}
	int fb, fb1 = 0, fb2 = 1;
	while (fb1 + fb2 <= n)
	{
		fb = fb1 + fb2;
		fb1 = fb2;
		fb2 = fb;
	}
	if (fb == n)
		printf("\nIt's a Fibonacci term.\n");
	else
		printf("\nIt's not a Fibonacci term. \n");
	fflush(stdin);
	return main();
}
int TongChuSo() {

	int s = 0;
	printf("\nEnter an integer ");
	scanf("%d", &m);
	while (m > 0)
	{
		s = s + m % 10;
		m = m / 10;

	}
	printf("\nSum of it's digits %d \n", s);

	fflush(stdin);
	return main();

}
int SoNguyenToDauTien() {
	int dem, p;
	int i = 2;

	while (dem < p)
	{
		if (soNguyenTo(i)) {
			printf("%d ", i);
			dem++;
		}
		i++;
	}
	fflush(stdin);
	return main();
}

int main() {
	printf("\n1 - The first primes ");
	printf("\n2 - Fibonacci elecment ");
	printf("\n3 - Sum of digits");
	printf("\nChoose an option ");
	int t;
	scanf("%d", &t);
	switch (t)
	{
		case 2: {
			CheckInPut(flag);
			CheckFibonacci();
		}
		case 3: {
			CheckInPut(flag);
			TongChuSo();
		}
		case 1: {
			CheckInPut(flag);
			SoNguyenToDauTien();
		}
	}
}