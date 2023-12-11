#pragma once 

#include <iostream>
#include "graphics.h"
#include "DefineConstatant.h"
#include "supplies.h"
#include "UI.h"

char title_button[4][12] = {"SUPPLIES", "STAFF", "INVOICE", "STATISTICS"};
int position[4] = {210, 430, 650, 870};
int top = 20, bottom = 90, cnt = 0;

// Check if button left clicked on button 1
bool is_pointed_button_1(int xMouse, int yMouse)
{
	if (xMouse <= position[0] + 200 && xMouse >= position[0] && yMouse <= 90 && yMouse >= 20)
		return true;
	return false;
}

// Check if button left clicked on button 2
bool is_pointed_button_2(int xMouse, int yMouse)
{
	if (xMouse <= position[1] + 200 && xMouse >= position[1] && yMouse <= 90 && yMouse >= 20)
		return true;
	return false;
}

// Check if button left clicked on button 3
bool is_pointed_button_3(int xMouse, int yMouse)
{
	if (xMouse <= position[2] + 200 && xMouse >= position[2] && yMouse <= 90 && yMouse >= 20)
		return true;
	return false;
}

// Check if button left clicked on button 4
bool is_pointed_button_4(int xMouse, int yMouse)
{
	if (xMouse <= position[3] + 200 && xMouse >= position[3] && yMouse <= 90 && yMouse >= 20)
		return true;
	return false;
}

// Button which chosen
void button_chosen(int index)
{
	cnt = index;
	setfillstyle(SOLID_FILL, TAB_DEFAULT_BACKGROUND);
	bar(position[index], 20, position[index] + 200, 90);
	setcolor(BLACK);
	setbkcolor(TAB_DEFAULT_BACKGROUND);
	outtextxy((position[index] + position[index] + 200 - textwidth(title_button[index])) / 2, (90 + 20 - textheight(title_button[index])) / 2, title_button[index]);

	setfillstyle(SOLID_FILL, BUTTON_BACKGROUND);
	for (int i = 0; i < 4; i++)
	{
		if (i != index)
		{
			bar(position[i], 20, position[i] + 200, 90);
			setcolor(BLACK);
			setbkcolor(BUTTON_BACKGROUND);
			outtextxy((position[i] + position[i] + 200 - textwidth(title_button[i])) / 2, (90 + 20 - textheight(title_button[i])) / 2, title_button[i]);
		}
	}
	std::cout << index << "\n";
}

void isPointed(int xMouse, int yMouse)
{	
	if (is_pointed_button_1(xMouse, yMouse) && GetAsyncKeyState(VK_LBUTTON) && 0x8000 && cnt != 0)
	{
		button_chosen(0);
		drawSubwindow();
		drawSheet();
		drawTitle();
	}
	if (is_pointed_button_2(xMouse, yMouse) && GetAsyncKeyState(VK_LBUTTON) && 0x8000 && cnt != 1)
	{
		button_chosen(1);
		drawSubwindow();
	}
	if (is_pointed_button_3(xMouse, yMouse) && GetAsyncKeyState(VK_LBUTTON) && 0x8000 && cnt != 2)
	{
		button_chosen(2);
		drawSubwindow();
	}
	if (is_pointed_button_4(xMouse, yMouse) && GetAsyncKeyState(VK_LBUTTON) && 0x8000 && cnt != 3)
	{
		button_chosen(3);
		drawSubwindow();
	}
}

void defaultButton()
{
	setfillstyle(SOLID_FILL, TAB_DEFAULT_BACKGROUND);
	bar(position[0], 20, position[0] + 200, 90);

	setcolor(BLACK);
	setbkcolor(TAB_DEFAULT_BACKGROUND);
	outtextxy((position[0] + position[0] + 200 - textwidth(title_button[0])) / 2, (90 + 20 - textheight(title_button[0])) / 2, title_button[0]);

	setfillstyle(SOLID_FILL, BUTTON_BACKGROUND);
	for (int i = 1; i < 4; i++)
	{
		bar(position[i], top, position[i] + 200, bottom);
		setcolor(BLACK);
		setbkcolor(BUTTON_BACKGROUND);
		outtextxy((position[i] + position[i] + 200 - textwidth(title_button[i])) / 2, (90 + 20 - textheight(title_button[i])) / 2, title_button[i]);
	}

	drawSubwindow();
	drawSheet();
	drawTitle();
}