#pragma once

#include "consoleColor.h"

const int screenRows = 25;
const int screenColumns = 80;
const int centerRow = 13;
const int centerColumn = 40;


struct ConsoleSymbolData
{
	char symbol;
	ConsoleColor symbolColor;
	ConsoleColor backgroundColor;
};
void RenderSystemMoveRight();
void RenderSystemMoveLeft();
void RenderSystemMoveDown();
void RenderSystemMoveUp();

void RenderSystemInitialize();
void RenderSystemClear();
void RenderSystemDrawChar(int r, int c, char symbol, ConsoleColor symbolColor, ConsoleColor backgroundColor);
void RenderSystemDrawText(int r, int c, char *text, ConsoleColor symbolColor, ConsoleColor backgroundColor);
void RenderSystemFlush();