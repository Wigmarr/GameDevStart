#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <ctype.h>

const int rowsCount = 10;
const int columnsCount = 15;
const int levelCount = 2;
int currentLevel = 0;

const unsigned char SymbolHero = 64;
const unsigned char SymbolWall = 177;
const unsigned char SymbolBox = 254;
const unsigned char SymbolDoor = 176;
const unsigned char SymbolCrystal = 253;

const unsigned char LevelData0[levelCount][rowsCount][columnsCount + 1] = {
	{
	"###2###########",
	"#  X   #   X ##",
	"# X ### X  #  #",
	"#X X  X  ## X #",
	"# X    ##  #  #",
	"#######    # X#",
	"#   X   XX #X #",
	"#XXX # # X   ##",
	"#1 X #   X X  #",
	"###############",
	}, {
	"###############",
	"#             #",
	"#########  X# 2",
	"#  3    ## ####",
	"#XXXX  X# X   #",
	"#  ##   ## ## #",
	"#    # #    # #",
	"# 3 ## X ##X  #",
	"#  #      1 ###",
	"###############",

	}
};
/*const unsigned char LevelData2[rowsCount][columnsCount + 1] = 
{
	"###############",
	"#             #",
	"#########  X# 2",
	"#  3    ## ####",
	"#XXXX  X# X   #",
	"#  ##   #  ## #",
	"#    # #    # #",
	"# 3 ## X ##X  #",
	"#  #      1 ###",
	"###############",

};*/
HANDLE consoleHandle = 0;
bool isGameActive = true;
unsigned char levelData[rowsCount][columnsCount];
int heroRow = 0;
int heroColumn = 0;
int cristalCount = 0;

void setupSystem() 
{
	srand(time(0));

	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Render () 
{
	COORD cursorCoord;
	cursorCoord.X = 0;
	cursorCoord.Y = 0;
	SetConsoleCursorPosition(consoleHandle, cursorCoord);



	int level = currentLevel + 1;
	printf("\n\n\t\tLevel %d\n\n\t", level);
	for (int r = 0; r < rowsCount; ++r)
	{
		for (int c = 0; c < columnsCount; ++c)
		{
			unsigned char symbol = levelData[r][c];
			switch (symbol)
			{
			case SymbolWall:
				SetConsoleTextAttribute(consoleHandle, 15);
				break;
			case SymbolHero:
				SetConsoleTextAttribute(consoleHandle, 10);
				break;
			case SymbolBox:
				SetConsoleTextAttribute(consoleHandle, 14);
				break;
			case SymbolDoor:
				SetConsoleTextAttribute(consoleHandle, 12);
				break;
			case SymbolCrystal:
				SetConsoleTextAttribute(consoleHandle, 11);
				break;
			default:
				break;
			}
			printf("%c", symbol);
		}
		printf("\n\t");
	}
	SetConsoleTextAttribute(consoleHandle, 7);
	printf("\n\n\tUse WASD to move ");
	SetConsoleTextAttribute(consoleHandle, 10);
	printf("Hero");
	SetConsoleTextAttribute(consoleHandle, 7);
	printf(". Press R to restart level.");
}

void Initialise()
{
	for (int r = 0; r < rowsCount; ++r)
	{
		for (int c = 0; c < columnsCount; ++c)
		{
			unsigned char symbol = LevelData0[currentLevel][r][c];
			switch (symbol)
			{
			case '#': levelData[r][c] = SymbolWall;
				break;
			case '1': levelData[r][c] = SymbolHero;
				heroRow = r;
				heroColumn = c;
				break;
			case '2': levelData[r][c] = SymbolDoor;
				break;
			case 'X': levelData[r][c] = SymbolBox;
				break;
			case '3': levelData[r][c] = SymbolCrystal;
				break;
			default: levelData[r][c] = symbol;
				break;
			}
		}
	}
}
void MoveHeroTo(int row, int column)
{
	int heroDirectionR = row - heroRow;
	int herDirectionC = column - heroColumn;

	unsigned char destinationCell = levelData[row][column];
	bool canMoveToCell = false;

	switch (destinationCell) {

	case ' ':
		canMoveToCell = true;
		break;

	case SymbolBox:
		if (levelData[row + heroDirectionR][column + herDirectionC] == ' ')
		{
			canMoveToCell = true;
			levelData[row][column] = ' ';
			levelData[row + heroDirectionR][column + herDirectionC] = SymbolBox;
		}
		break;
	case SymbolCrystal:
		++cristalCount;
		levelData[row][column] = ' ';
		canMoveToCell = true;
		break;
	case SymbolDoor:
		switch (currentLevel)
		{
		case 0:
			++currentLevel;
			if (currentLevel < levelCount)
			{
				cristalCount = 0;
				Initialise();
			}
			else
			{
				isGameActive = false;
			}
			break;
		case 1:
			if (cristalCount == 2) {
				++currentLevel;
				if (currentLevel < levelCount)
				{
					cristalCount = 0;
					Initialise();
				}
				else
				{
					isGameActive = false;
				}
			}
			break;
		default:
			break;
		}
	default:
		break;
	}
	
	if (canMoveToCell)
	{
		levelData[heroRow][heroColumn] = ' ';

		heroRow = row;
		heroColumn = column;

		levelData[heroRow][heroColumn] = SymbolHero;
	}
}

void Update()
{
	unsigned char inputChar = _getch();
	
	inputChar = tolower(inputChar);
	switch (inputChar)
	{
	case 'w': MoveHeroTo(heroRow - 1, heroColumn);
		break;
	case 's': MoveHeroTo(heroRow + 1, heroColumn);
		break;
	case 'a': MoveHeroTo(heroRow, heroColumn - 1);
		break;
	case 'd': MoveHeroTo(heroRow, heroColumn + 1);
		break;
	case 'r': Initialise();
		break;
	default:
		break;
	}
	
}

void Shutdown()
{
	system("cls");
	printf("\n\tThanks for playing! ");
	_getch();

}

int main() 
{
	setupSystem();
	Initialise();

	do
	{
		Render();
		Update();
	} while (isGameActive);

	Shutdown();

}