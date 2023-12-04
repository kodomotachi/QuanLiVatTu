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

	//settextstyle(0, 0, 1);
	//settextjustify(1, 1);
	//char s[70] = "Hello Sinh, have a nice day, and dont get up late, fck you!";
	//setcolor(BLACK);
	//outtextxy(230, 230, s);
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

void writeTextButton()
{
	char text[10] = "MATERIALS";
	setbkcolor(TAB_DEFAULT_BACKGROUND);
	setcolor(BLACK);

	outtextxy((210 + 410 - textwidth(text)) / 2, (20 + 90 - textheight(text)) / 2, text);
}

void drawContentBoard()
{
	setfillstyle(SOLID_FILL, COLOR(232, 242, 247));
	bar(50, 120, 1200, 650);
}