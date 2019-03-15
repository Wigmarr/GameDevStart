#pragma once
#include "consoleColor.h"



//constants
const int rowsCount = 15;
const int columnsCount = 35;

const unsigned char CellSymbol_Empty =		' ';
const unsigned char CellSymbol_Wall =		'#';
const unsigned char CellSymbol_Hero =		'h';
const unsigned char CellSymbol_Exit =		'e';
const unsigned char CellSymbol_Orc =		'o';
const unsigned char CellSymbol_Skeleton =	's';
const unsigned char CellSymbol_Stick =		'1';
const unsigned char CellSymbol_Club =		'2';
const unsigned char CellSymbol_Spear =		'3';
const unsigned char CellSymbol_Saber =		'4';

const unsigned char levelData0[rowsCount][columnsCount + 1] = {
	"###################################",
	"#   # ##     o           s        #",
	"# # o  #o############# ########## #",
	"# ###### ##### ##3 s    ##s##   # #",
	"#  s       #   #######  #4 s  #s# #",
	"######## ### #######    #s##### # #",
	"##  o  # # # ##      #######o # # #",
	"#  #   # # o  # ## ######s#     # #",
	"######## # ##         #   # # # #s#",
	"#  2#    #    ####### # # #     # #",
	"# ### #### ####    o  # #    #    #",
	"#  o      #     ####### ###########",
	"########### #####   #1# # s #     #",
	"#h                #   #   #s    # #",
	"#################################e#",
};

unsigned char GetRenderCellSymbol(unsigned char cellSymbol)
{
	switch (cellSymbol)
	{
	case CellSymbol_Empty:		return ' ';
	case CellSymbol_Wall:		return 177;
	case CellSymbol_Hero:		return 64;
	case CellSymbol_Orc:		return 64;
	case CellSymbol_Skeleton:	return 64;
	case CellSymbol_Stick:		return 47;
	case CellSymbol_Club:		return 33;
	case CellSymbol_Spear:		return 241;
	case CellSymbol_Saber:		return 108;
	case CellSymbol_Exit:		return 178;
	}

	return '?';
}

ConsoleColor GetRenderCellsSymbolColor(unsigned char cellSymbol)
{
	switch (cellSymbol)
	{
	case CellSymbol_Empty:		return ConsoleColor_Black;
	case CellSymbol_Wall:		return ConsoleColor_White;
	case CellSymbol_Hero:		return ConsoleColor_Yellow;
	case CellSymbol_Orc:		return ConsoleColor_Green;
	case CellSymbol_Skeleton:	return ConsoleColor_White;
	case CellSymbol_Stick:		return ConsoleColor_DarkYellow;
	case CellSymbol_Club:		return ConsoleColor_DarkRed;
	case CellSymbol_Spear:		return ConsoleColor_DarkCyan;
	case CellSymbol_Saber:		return ConsoleColor_Cyan;
	case CellSymbol_Exit:		return ConsoleColor_DarkRed;
	}
}