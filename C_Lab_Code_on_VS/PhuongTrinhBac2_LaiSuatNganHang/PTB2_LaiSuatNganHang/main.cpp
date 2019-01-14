#include <stdio.h>
#include <math.h>

int pt_bank(int n);

int main(int argc, char** argv) {
	int urChoice,x;
	char enter;
	printf("1- Quadratic equation");
	printf("\n2- Bank deposit problem");
	printf("\n3- Quit\n");
	while(1) {
		printf("\nEnter Your Choice: ");
		int flag = scanf("%d%c", &urChoice, &enter);
		if (flag == 0 || enter != '\n') {
			while (getchar() != '\n');
		}
		else if (urChoice < 1 || urChoice > 3) {
			return 0;
		}
		else if (urChoice == 3) {
			return 0;
		}
		else if (urChoice >= 1 && urChoice <= 2) {
			pt_bank(urChoice);
		}
		else
			break;
	}
	getchar();
    return 0;
}



int pt_bank(int n) {
	switch (n) {
		case 1: {
			float x,a,b,c;
			printf("Input a: ");
			scanf("%f", &a);
			printf("Input b: ");
			scanf("%f", &b);
			printf("Input c: ");
			scanf("%f", &c);
			float delta = (b*b) - 4 * a*c;
			if (a == 0) {
				if (b == 0) {
					if (c == 0) {
						printf("Phuong trinh vo so nghiem\n");
					}
					else {
						printf("Phuong trinh vo nghiem\n");
					}
				}
				else {
					x = -c / b;
					printf("Phuong trinh co nghiem: %.2f\n", x);
				}
			}
			else {
				if (delta < 0) {
					printf("Phuong trinh vo nghiem\n");
				}
				else if (delta == 0) {
					x = -b / (2 * a);
					printf("Phuong trinh co nghiem kep: %.2f\n", x);
				}
				else if (delta > 0) {
					float canDelta = sqrtf(delta);
					float x1 = (-b + canDelta) / (2 * a);
					float x2 = (-b - canDelta) / (2 * a);
					printf("Phuong trinh co 2 nghiem: %.2f %.2f\n", x1, x2);
				}
			}
			break;
		}
		case 2: {
			float tienLai, tienNhan, tienGui, laiSuat, soThangGui ;
			printf("Deposit: ");//số tiền gửi
			scanf("%f", &tienGui);
			printf("Interest rate: ");
			scanf("%f", &laiSuat);
			printf("No of deposit months: ");
			scanf("%f", &soThangGui);
			laiSuat = laiSuat / 100;
			tienLai = tienGui * (laiSuat/12) * soThangGui; // Công thức: Tiền lãi = Tiền gửi * lãi suất (% năm) / 12 * số tháng gửi
			tienNhan = tienGui + tienLai;
			printf("Total amount: %.2f\n", tienNhan);
			break;
		}
		default:
			break;
	}
	return 0;
}