#pragma once 

#include <iostream>
#include "graphics.h"
#include "DefineConstatant.h"
#include <WinUser.h>

void draw_button(int left, int top, int right, int bottom, int backgroundColor, int textColor, char* text)
{
	setfillstyle(SOLID_FILL, backgroundColor);
	bar(left, top, right, bottom);

	setbkcolor(backgroundColor);
	setcolor(textColor);
	outtextxy((left + right - textwidth(text)) / 2, (top + bottom - textheight(text)) / 2, text);
}

int returnString()
{
	for (int i = 65; i <= 90; i++) {
		if (GetAsyncKeyState((char)(i)) & 1) {
			return i;
		}
	}
}