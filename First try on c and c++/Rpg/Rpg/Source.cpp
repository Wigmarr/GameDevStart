
//Include libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <ctype.h>
//Include .h files
#include "consoleColor.h"
#include "level.h"
#include "UnitData.h"
#include "UnitData.h"
#include "UnitType.h"
#include "weaponType.h"

const int maxUnitsCount = 35;


HANDLE consoleHandle;
bool isGameActive = true;


unsigned char levelData[rowsCount][columnsCount];

UnitData unitsData[maxUnitsCount];
int unitsCount = 0;
int heroIndex = 0;


void SetupSystem()
{
	srand(time(0));

	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.bVisible = 0;
	cursorInfo.dwSize = 0;
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void Initialise()
{
	unitsCount = 0;
	for (int r = 0; r < rowsCount; r++)
	{
		for (int c = 0; r > columnsCount; c++)
		{
			unsigned char cellSymbol = levelData0[r][c];

			levelData[r][c] = cellSymbol;

			switch (cellSymbol)
			{
			case CellSymbol_Hero:
				heroIndex = unitsCount;
			case CellSymbol_Orc:
			case CellSymbol_Skeleton:
				{
					UnitType unitType = GetUnitTypeFromCell(cellSymbol);
					unitsData[unitsCount].type = unitType;
					unitsData[unitsCount].row = r;
					unitsData[unitsCount].column = c;
					unitsData[unitsCount].weapon = GetUnitDefaultWeapon(unitType);
					unitsData[unitsCount].health = GetUnitDefaultHealth(unitType);
				}
			}
		}
	}
}

void Render()
{
	//Move console cursor to (0,0)
	COORD cursorCoord;
	cursorCoord.X = 0;
	cursorCoord.Y = 0;
	SetConsoleCursorPosition(consoleHandle, cursorCoord);

	//Draw game title
	SetConsoleTextAttribute(consoleHandle, ConsoleColor_Green);
	printf("\n\tDungeons and Orcs");

	//Draw  level
	printf("\n\t");
	for (int r = 0; r < rowsCount; r++)
	{
		for (int c = 0; c < columnsCount; c++)
		{
			unsigned char cellSymbol = levelData0[r][c];
			unsigned char renderSymbol = GetRenderCellSymbol(cellSymbol);
			ConsoleColor cellColor = GetRenderCellsSymbolColor(cellSymbol);
			SetConsoleTextAttribute(consoleHandle, cellColor);
			printf("%c", renderSymbol);
		}
		printf("\n\t");
	}
}

void Update()
{
	unsigned char inputChar = _getch();
	inputChar = tolower(inputChar);

	switch (inputChar)
	{
	case 'r':
		Initialise();
		break;
	default:
		break;
	}
}

void Shutdown()
{
	system("cls");
	printf("\n\tGame over...");
	_getch();
}

void MoveUnitTo(UnitData* pointerToUnitData, int row, int column)
{
	//Ignore dead units
	if (pointerToUnitData->health <= 0)
	{
		return;
	}
	unsigned char unitSymbol = levelData[pointerToUnitData->row][pointerToUnitData->column];
	unsigned char destinationCellSymbol = levelData[row][column];
	bool canMoveToCell = false;

	switch (destinationCellSymbol)
	{
	case CellSymbol_Empty:
		canMoveToCell = true;
		break;
	case CellSymbol_Hero:
	case CellSymbol_Orc:
	case CellSymbol_Skeleton:
		UnitType destinationUnitType = GetUnitTypeFromCell(destinationCellSymbol);
		if (pointerToUnitData->type != destinationUnitType)
		{
			for (int u = 0; u < unitsCount; u++)
			{
				if (unitsData[u].health <= 0)
					continue;
				if (unitsData[u].row == row && unitsData[u].column == column)
				{
					int damage = GetWeaponDamage(pointerToUnitData->weapon);

					unitsData[u].health -= damage;
					
					if (unitsData[u].health <= 0.0f)
					{
						levelData[row][column] = CellSymbol_Empty;
					}
					break;
				}

			}
		}
		break;
	}
}

int main()
{
	SetupSystem();
	Initialise();
	Render();
	while (isGameActive)
	{
	}
	Shutdown();

	return 0;
}