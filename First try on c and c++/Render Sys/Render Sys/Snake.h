#pragma once
#include "renderSystem.h"
#include "input.h"
#include "consoleColor.h"

struct Snake {
	int X;
	int Y;
	int prevX;
	int prevY;
	int count;
	char head = '@';
	char body = 176;
	Snake* next;
	Snake* prev;
};

Snake* CreateSnakeBody();
void AddSnakeBody(Snake** head, Snake* body);

void MoveSnakeLeft(Snake* snake, int count);
void MoveSnakeRight(Snake* snake, int count);
void MoveSnakeUp(Snake* snake, int count);
void MoveSnakeDown(Snake* snake, int count);