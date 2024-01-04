#pragma once 

#include <iostream>
#include "graphics.h"
#include "DefineConstatant.h"

void draw_button(int left, int top, int right, int bottom, int backgroundColor, int textColor, char* text)
{
	setfillstyle(SOLID_FILL, backgroundColor);
	bar(left, top, right, bottom);

	setbkcolor(backgroundColor);
	setcolor(textColor);
	outtextxy((left + right - textwidth(text)) / 2, (top + bottom - textheight(text)) / 2, text);
}