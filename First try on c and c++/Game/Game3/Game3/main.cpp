#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <ctype.h>

int main() {
	const int lettersCount = 20;
	char letters[lettersCount];
	int step = 0;
	int err = 0;
	bool again = true;
	
	time_t start, finish;
	system("cls");
	printf("\n\tReady\n\t");

	_getch();

	for (int i = 0; i < 5; ++i) {
		printf(".");
		Sleep(175);
	}
	printf("\n\tGo!\n");
	_getch();
	time(&start);
	while (again == true) {
		time_t currentTime;
		time(&currentTime);
		
		srand(currentTime);
		for (int i = 0; i < lettersCount; i++) {
			letters[i] = 'a' + rand() % ('z' - 'a' + 1);
		}
		while (step < lettersCount) {
			system("cls");
			printf("\n\t");

			for (int i = 0; i < lettersCount; ++i) {
				if (i < step) {
					printf("%c ", 176);
				}
				else {
					printf("%c ", toupper(letters[i]));
				}
			}

			char inputChar = _getch();
			if (inputChar >= 'A' && inputChar <= 'Z') {
				inputChar = tolower(inputChar);
			}
			if (inputChar == letters[step]) {
				++step;
			}
			else {
				++err;
			}

		}
		time(&finish);
		int time_ = (int)finish - (int)start;
		float SybPerSec = (float)(lettersCount * 60) / (float)time_;
		system("cls");
		if (err > 0) {
			printf("\nErrors: %d", err);
		}
		printf("\n%d symbols for %d seconds", lettersCount, time_);
		printf("\nSymbols per second: %.3f", SybPerSec);
		printf("\nAgain? (y\\n)");
		char check = '\0';
		while (check != 'y' and check != 'n') {
			check = _getch();
		}
		if (check == 'n') {
			again = false;
		}
		else {
			step = 0;
		}
	}
	return 0;
}