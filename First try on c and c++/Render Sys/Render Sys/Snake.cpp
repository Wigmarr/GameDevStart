#include "Snake.h"

void MoveSnakeRight(Snake* snake, int count)
{
	snake->prevX = snake->X;
	snake->prevY = snake->Y;
	snake->X+1;
	RenderSystemDrawChar(snake->Y, snake->X, snake->head, ConsoleColor_Green, ConsoleColor_Black);
	if (count > 1)
		for (int i = 0; i < count; i++)
		{/*
			snake = snake->next;
			tempX = snake->X;
			tempY = snake->Y;
			snake->X = snakprevX;
			snake->Y = prevY;
			prevX = tempX;
			prevY = tempY;
			RenderSystemDrawChar(snake->X, snake->Y, snake->body, ConsoleColor_Green, ConsoleColor_Black);*/
		}
	
}

void MoveSnakeLeft(Snake* snake, int count)
{
	int prevX = snake->X;
	int prevY = snake->Y;
	int tempX;
	int tempY;
	RenderSystemDrawChar(snake->Y, snake->X - 1, snake->head, ConsoleColor_Green, ConsoleColor_Black);
	snake->X++;
	if (count > 1)
		for (int i = 0; i < count; i++)
		{
			snake = snake->next;
			tempX = snake->X;
			tempY = snake->Y;
			snake->X = prevX;
			snake->Y = prevY;
			prevX = tempX;
			prevY = tempY;
			RenderSystemDrawChar(snake->X, snake->Y, snake->body, ConsoleColor_Green, ConsoleColor_Black);
		}

}

void MoveSnakeUp(Snake* snake, int count)
{
	int prevX = snake->X;
	int prevY = snake->Y;
	int tempX;
	int tempY;
	RenderSystemDrawChar(snake->Y - 1, snake->X, snake->head, ConsoleColor_Green, ConsoleColor_Black);
	snake->X++;
	if (count > 1)
		for (int i = 0; i < count; i++)
		{
			snake = snake->next;
			tempX = snake->X;
			tempY = snake->Y;
			snake->X = prevX;
			snake->Y = prevY;
			prevX = tempX;
			prevY = tempY;
			RenderSystemDrawChar(snake->X, snake->Y, snake->body, ConsoleColor_Green, ConsoleColor_Black);
		}

}

void MoveSnakeDown(Snake* snake, int count)
{	
	int prevX = snake->X;
	int prevY = snake->Y;
	int tempX;
	int tempY;
	RenderSystemDrawChar(snake->Y + 1, snake->X, snake->head, ConsoleColor_Green, ConsoleColor_Black);
	snake->X++;
	if (count > 1)
		for (int i = 0; i < count; i++)
		{
			snake = snake->next;
			tempX = snake->X;
			tempY = snake->Y;
			snake->X = prevX;
			snake->Y = prevY;
			prevX = tempX;
			prevY = tempY;
			RenderSystemDrawChar(snake->X, snake->Y, snake->body, ConsoleColor_Green, ConsoleColor_Black);
		}

}

Snake* CreateSnakeBody()
{
	Snake* newBody;
	return newBody;
}

void AddSnakeBody(Snake** head, Snake* body)
{
	Snake* temphead = *head;
	while (temphead->next != NULL)
		temphead = temphead->next;
	temphead->next = body;
	temphead->next->prev = temphead;
}