#include "renderSystem.h"
#include <stdio.h>
#include <Windows.h>

HANDLE consoleHandle = 0;

ConsoleSymbolData backBuffer[screenRows][screenColumns];
ConsoleSymbolData screenBuffer[screenRows][screenColumns];

void RenderSystemInitialize()
{
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursorInfo;
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = 0;
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);

	for (int r = 0; r < screenRows; r++)
	{
		for (int c = 0; c < screenColumns; c++)
		{
			backBuffer[r][c].symbol = 0;
			backBuffer[r][c].symbolColor = ConsoleColor_Grey;
			backBuffer[r][c].backgroundColor = ConsoleColor_Black;
			screenBuffer[r][c] = backBuffer[r][c];
		}
	}
}

void RenderSystemClear()
{
	for (int r = 0; r < screenRows; r++)
	{
		for (int c = 0; c < screenColumns; c++)
		{
			backBuffer[r][c].symbol = 0;
			backBuffer[r][c].symbolColor = ConsoleColor_Black;
			backBuffer[r][c].backgroundColor = ConsoleColor_Black;
		}
	}
}

void RenderSystemDrawChar(int r, int c, char symbol, ConsoleColor symbolColor, ConsoleColor backgroundColor)
{
	backBuffer[r][c].symbol = symbol;
	backBuffer[r][c].symbolColor = symbolColor;
	backBuffer[r][c].backgroundColor = backgroundColor;
}

void RenderSystemDrawText(int r, int c, char *text, ConsoleColor symbolColor, ConsoleColor backgroundColor)
{
	int column = c;
	char symbol = *text;

	while (symbol)
	{
		RenderSystemDrawChar(r, column, symbol, symbolColor, backgroundColor);

		text++;
		column++;
		symbol = *text;
	}
}

void SetConsoleCursor(int r, int c)
{
	COORD cursorCoord;
	cursorCoord.X = c;
	cursorCoord.Y = r;
	SetConsoleCursorPosition(consoleHandle, cursorCoord);
}

void SetConsoleColor(ConsoleColor symbolColor, ConsoleColor backgroudColor)
{
	unsigned char consoleColor = symbolColor | (backgroudColor << 4);
	SetConsoleTextAttribute(consoleHandle, consoleColor);
}

void RenderSystemMoveRight()
{
	ConsoleSymbolData tempBuffer[screenRows][screenColumns];
	for (int r = 0; r < screenRows; r++)
		for (int c = 0; c < screenColumns; c++)
		{
			if (c + 1 == screenColumns)
				tempBuffer[r][0] = backBuffer[r][c];
			else
				tempBuffer[r][c + 1] = backBuffer[r][c];
		}

	for (int r = 0; r < screenRows; r++)
		for (int c = 0; c < screenColumns; c++)
			backBuffer[r][c] = tempBuffer[r][c];

}

void RenderSystemMoveLeft()
{
	ConsoleSymbolData tempBuffer[screenRows][screenColumns];
	for (int r = 0; r < screenRows; r++)
		for (int c = 0; c < screenColumns; c++)
		{
			if (c == 0)
				tempBuffer[r][screenColumns - 1] = backBuffer[r][c];
			else
				tempBuffer[r][c - 1] = backBuffer[r][c];
		}

	for (int r = 0; r < screenRows; r++)
		for (int c = 0; c < screenColumns; c++)
			backBuffer[r][c] = tempBuffer[r][c];

}

//void RenderSystemMoveUp()
//{
//	ConsoleSymbolData tempBuffer[screenRows][screenColumns];
//	for (int r = 0; r < screenRows; r++)
//		for (int c = 0; c < screenColumns; c++)
//		{
//			if (r == 0)
//				tempBuffer[screenRows - 1][c] = backBuffer[r][c];
//			else
//				tempBuffer[r+1][c] = backBuffer[r][c];
//		}
//
//	for (int r = 0; r < screenRows; r++)
//		for (int c = 0; c < screenColumns; c++)
//			backBuffer[r][c] = tempBuffer[r][c];
//
//}
//
//void RenderSystemMoveDown()
//{
//	ConsoleSymbolData tempBuffer[screenRows][screenColumns];
//	for (int r = 0; r < screenRows; r++)
//		for (int c = 0; c < screenColumns; c++)
//		{
//			if (r == screenRows - 1)
//				tempBuffer[0][c] = backBuffer[r][c];
//			else
//				tempBuffer[r - 1][c] = backBuffer[r][c];
//		}
//
//	for (int r = 0; r < screenRows; r++)
//		for (int c = 0; c < screenColumns; c++)
//			backBuffer[r][c] = tempBuffer[r][c];
//
//}

void RenderSystemFlush()
{
	bool screenBufferModified = false;

	for (int r = 0; r < screenRows; r++)
	{
		for (int c = 0; c < screenColumns; c++)
		{
			if ((backBuffer[r][c].symbol != screenBuffer[r][c].symbol)
				|| (backBuffer[r][c].symbolColor != screenBuffer[r][c].symbolColor)
				|| (backBuffer[r][c].backgroundColor != screenBuffer[r][c].backgroundColor))
			{
				screenBuffer[r][c] = backBuffer[r][c];

				SetConsoleCursor(r, c);
				SetConsoleColor(screenBuffer[r][c].symbolColor, screenBuffer[r][c].backgroundColor);
				printf("%c", screenBuffer[r][c].symbol);

				screenBufferModified = true;
			}
		}
	}
	if (screenBufferModified)
		SetConsoleCursor(0, 0);
}



