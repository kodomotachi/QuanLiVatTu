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

	// Set color for window's background
	setbkcolor(COLOR(255, 246, 245));

	// Clear all on window (expect color background)
	cleardevice();
}

void drawTabButton()
{
	// Set color for tab default button
	setfillstyle(SOLID_FILL, TAB_DEFAULT_BACKGROUND);

	bar(210, 20, 410, 90); // First button

	// Set color for others tab button
	setfillstyle(SOLID_FILL, BUTTON_BACKGROUND);

	bar(430, 20, 630, 90); // Second button
	bar(650, 20, 850, 90); // Third button
	bar(870, 20, 1070, 90); // Forth button
}

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