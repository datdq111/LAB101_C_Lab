#include <stdio.h>
#include <conio.h>
int number_of_small_package(int invitations);
int number_of_large_package(int invitations);

int main() {
	float small_price,
		  large_price, 
		  smallest;
	int invitations,
		temp_small,
		temp_large;
	char enter;
	while (true) {
		fflush(stdin);
		printf("What is the cost of a small package (in dollars)?\n");
		float flag = scanf("%f%c", &small_price, &enter);
		if (flag == 0 || enter != '\n') {
			while (getchar() != '\n');
		}
		else if (small_price < 0 || small_price>500);
		else
			break;
	}
	while (true) {
		fflush(stdin);
		printf("What is the cost of a large package (in dollars)?\n");
		float flag = scanf("%f%c", &large_price, &enter);
		if (flag == 0 || enter != '\n') {
			while (getchar() != '\n');
		}
		else if (large_price < 0 || large_price>500);
		else
			break;
	}
	while (true) {
		fflush(stdin);
		printf("How many invitations are you sending out?\n");
		float flag = scanf("%d%c", &invitations, &enter);
		if (flag == 0 || enter != '\n') {
			while (getchar() != '\n');
		}
		else if (invitations < 0 || invitations > 1000);
		else
			break;
	}
	
	float small = number_of_small_package(invitations);
	float large = number_of_large_package(invitations);
	if (small*small_price < large*large_price) {
		smallest = small * small_price;
	}
	else {
		smallest = large * large_price;
	}
	for (int i = 0; i < large; i++) {
		for (int j = 0; j < small; j++) {
			if (i * 200 + j * 50 > invitations && i*large_price + j * small_price < smallest) {
				smallest = i * large_price + j * small_price;
				temp_small = j;
				temp_large = i;
			}
		}
	}
	printf("\nYou should order %d small package (s).\n", temp_small);
	printf("You should order %d large package (s).\n",temp_large);
	printf("Your cost for invitations will be $%.2f.", smallest);
	getchar();
}
int number_of_small_package(int invitations) {
	if (invitations % 50 == 0) {
		return invitations / 50;
	}
	else {
		return invitations / 50 + 1;
	}
}

int number_of_large_package(int invitations) {
	if (invitations % 200 == 0) {
		return invitations / 200;
	}
	else {
		return invitations / 200 + 1;
	}
}


//do {
//	fflush(stdin);
//	printf("What is the cost of a small package (in dollars)?\n");
//} while ((scanf("%f%c", &small_price, &enter) != 2) || enter != '\n' || (small_price < 0 || small_price > 500));