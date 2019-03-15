#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	
	const int startMoney = 500;
	const int cost = 50;
	const int doublePrise = 60;
	const int triplePrise = 100;
	
	int money = startMoney;

	char panel0 = 'X';
	char panel1 = 'X';
	char panel2 = 'X';
	int tmp = 1;
	srand(time(0));
	char ;
	bool show = 0;
	while (money > cost) {
		system("cls");

		printf("\t###################\n");
		printf("\t###   Bandito   ###\n");
		printf("\t###################\n");
		printf("\t###             ###\n");
		printf("\t###   %c  %c  %c   ###\n", panel0, panel1, panel2);
		printf("\t###             ###\n");
		printf("\t###################\n\n");
		if (tmp == 1) {
			printf("\n\n");
		} else if (tmp == 2) {
			printf("\t\t +$10\n\n");
		}
		else if (tmp == 3) {
			printf("\t\t +$50\n\n");
		}
		printf("\tMoney: %d\n\n", money);
		_getch();

		money = money - cost;
	
		panel0 = 69 + (rand() % 4);
		panel1 = 69 + (rand() % 4);
		panel2 = 69 + (rand() % 4);
		if (panel0 == panel1 && panel0 == panel2) {
			money = money + triplePrise;
			tmp = 3;
		} else if (panel0 == panel1 || panel0 == panel2 || panel1 == panel2) {
			tmp = 2;
			money = money + doublePrise;
		}
		else {
			tmp = 1;
		}
		_getch;
	}


	return 0;
}