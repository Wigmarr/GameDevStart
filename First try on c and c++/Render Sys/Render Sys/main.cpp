//Include
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <ctype.h>
#include "renderSystem.h"
#include <string.h>
#include "input.h"
#define _USE_MATH_DEFINES
#include <math.h>
//logic variables
int direction = 1;
bool isGameActive = true;


//Functions
void SetupSystem()
{
	srand(time(0));

	RenderSystemInitialize();
}

void Initialize()
{

}

void Render()
{

	RenderSystemFlush();
}

void Update()
{
}

void Shutdown()
{

}

int main()
{
	SetupSystem();
	Initialize();

	do
	{
		Render();
		Update();
	} while (isGameActive);
	_getch();
	Shutdown();
	return 0;
}
