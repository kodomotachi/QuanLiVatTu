#pragma once

#include "graphics.h"
#include "DefineConstatant.h"

// Draw background for my console app
void drawBackground()
{
	// Naming for window
	char title[50] = "Materials Management Software";

	// Initwindow syntax create new window with the following parameters: width, height, name of window, poisition you put this window on screen
	initwindow(SCREEN_WIDTH, SCREEN_HEIGHT, title, (getmaxwidth() - SCREEN_WIDTH) / 2, (getmaxheight() - SCREEN_HEIGHT) / 2);

	setbkcolor(COLOR(255, 246, 245)); // Set color for window's background

	cleardevice(); // Clear all on window (expect color background)
}

void drawTabButton()
{
	setfillstyle(SOLID_FILL, TAB_DEFAULT_BACKGROUND); // Set color for tab default button

	bar(210, 20, 410, 90); // First button

	setfillstyle(SOLID_FILL, BUTTON_BACKGROUND); // Set color for others tab button

	bar(430, 20, 630, 90); // Second button
	bar(650, 20, 850, 90); // Third button
	bar(870, 20, 1070, 90); // Forth button
}

// draw rectangle with light-blue color
void drawContentBoard()
{
	setfillstyle(SOLID_FILL, COLOR(232, 242, 247));
	bar(50, 120, 1200, 650);
}

// Draw color for subwindow
void drawSubwindow()
{
	setfillstyle(SOLID_FILL, SUBWINDOW_BACKGROUND);
	bar(25, 100, 1257, 682);
	setcolor(BUTTON_BACKGROUND);
	setlinestyle(0, 0, 3);
	rectangle(25, 100, 1257, 682);
}

// Draw exit button for window
void drawExitButton()
{
	int left = 1240, top = 5, right = 1270, bottom = 35;
	setbkcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	bar(left, top, right, bottom);
	char s[2] = "X";
	int textWidth = textwidth(s);
	int textHeight = textheight(s);
	setcolor(BLACK);
	outtextxy((left + right - textWidth) / 2, (top + bottom - textHeight) / 2, s);
}