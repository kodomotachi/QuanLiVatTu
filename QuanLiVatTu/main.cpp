#pragma once 

#include <iostream>
#include "function_library.h"
#include "UI.h"
#include "Button.h"
#include "supplies.h"

using namespace std;

char s[50];

int main()
{
	int cnt = 0;
	drawBackground();
	drawTabButton();
	defaultButton();
	drawExitButton();

	while (true)
	{
		isPointed(mousex(), mousey());

		clearmouseclick(VK_LBUTTON);
		clearmouseclick(VK_RBUTTON);
	}

	getch();
	closegraph();

	return 0;
}