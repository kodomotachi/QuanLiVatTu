#pragma once 

#include <iostream>
#include "function_library.h"
#include "UI.h"
#include "Button.h"

using namespace std;

char s[50];

int main()
{
	int cnt = 0;
	drawBackground();
	drawTabButton();
	defaultButton();
	drawSubwindow();

	/*
	while (true)
	{

	}
	*/

	getch();
	closegraph();

	return 0;
}