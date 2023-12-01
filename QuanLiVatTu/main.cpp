#pragma once 

#include <iostream>
#include "graphics.h"
#include "UI.h"
#include "Button.h"
using namespace std;

int main()
{
	drawBackground();
	defaultButton();
	while (true)
	{
		// setactivepage(1 - getactivepage());
		isPointed(mousex(), mousey());
		clearmouseclick(VK_LBUTTON);
		clearmouseclick(VK_RBUTTON);
	}
	getch();
	closegraph();
	return 0;
}