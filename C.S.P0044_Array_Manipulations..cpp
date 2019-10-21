/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

 /*
  * File:   main.cpp
  * Author: tad
  *
  * Created on March 19, 2019, 7:56 PM
  */

#include <stdio.h>
#include <cstdlib>

int check_int(int &n);
void add_value(int *a, int &n);
int FindIndex(int array[], int number, int value);
void display(int *a, int &n, int b);
int *GetValueInRange(int array[], int number, int minValue, int maxValue, int *pCount);
int *SortAscendingArray(int array[], int number);

using namespace std;

/*
 *
 */
int main(int argc, char** argv) {
	int urchoice, *a, n, c, minValue, maxValue, *pCount;
	n = 0;
	a = (int*)malloc(100 * sizeof(int));
	pCount = (int*)malloc(100 * sizeof(int));
	while (1) {
		printf("\n1- Add a value\n");
		printf("2- Search a value\n");
		printf("3- Print out the array\n");
		printf("4- Print out values in a range of inputted min and max values, inclusively\n");
		printf("5- Sort the array in ascending order\n");
		printf("Others - Quit\n\n");

		while (1) {
			printf("Your choice: \n");
			check_int(urchoice);
			if (urchoice == 1) {
				add_value(a, n);
				break;
			}
			else if (urchoice == 2) {
				printf("Input value need find: ");
				check_int(c);
				FindIndex(a, n, c);
			}
			else if (urchoice == 3) {
				display(a, n, 0);
				break;
			}
			else if (urchoice == 4) {
//				do {
//					printf("Enter max value: ");
//					check_int(maxValue);
//					printf("Enter min value: ");
//					check_int(minValue);
//					if (maxValue < minValue) {
//						printf("Please enter max value >= min value!\n");
//					}
//				} while (maxValue < minValue);
//				GetValueInRange(a, n, minValue, maxValue, pCount);
//				break;
			}
			else if (urchoice == 5) {
//				SortAscendingArray(a, n);
//				break;
			}
			else if (urchoice <= 0 || urchoice > 5) {
				return 0;
			}
		}
	}

	return 0;
}

int check_int(int &n) {
	while (1) {
		fflush(stdin);
		char enter, a;
		printf("");
		int flag = scanf("%d%c", &n, &enter);
		if (flag != 0 && n == int(n) && enter == '\n') {
			break;
		}
		else if (n == int(n) && (enter == '\n' || enter == ' ')) {
			scanf("%c", &a);
			if (a == '\n' || a == ' ') {
				break;
			}
		}
		printf("Please enter again! \n");
	}
	return n;
}

void add_value(int *a, int &n) {
	int c;
	n++;
	while (1) {
		printf("Add a value = ");
		check_int(c);
		a[n - 1] = c;
		break;
	}
}


int FindIndex(int array[], int number, int value) {
	int count = 0;
	for (int i = 0; i < number; i++) {
		if (value == array[i]) {
			printf("Value %d appears at : a[%d]\n", value, i);
			count++;
		}
	}
	if (count == 0) {
		printf("Not found!\n");
	}
	return number;
}

void display(int *a, int &n, int b) {
	if (b == 1) {
		printf("Sort the array in ascending order:\n");
	}
	else if (b == 2) {
		printf("Value in a range of inputted min and max values: \n");
	}
	else {
		printf("The element of array: ");
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

//int *GetValueInRange(int array[], int number, int minValue, int maxValue, int *pCount) {
//	for (int i = 0; i < number; i++) {
//		if (array[i] >= minValue && array[i] <= maxValue) {
//			printf("%d ", array[i]);
//		}
//	}
//	return 0;
//}
//
//int *SortAscendingArray(int array[], int number) {
//	for (int i = 0; i < number - 1; i++) {
//		for (int j = 0; j < number - i - 1; j++) {
//			if (array[j] > array[j + 1]) {
//				int temp = array[j];
//				array[j] = array[j + 1];
//				array[j + 1] = temp;
//			}
//		}
//	}
//	display(array, number, 1);
//	return 0;
//}