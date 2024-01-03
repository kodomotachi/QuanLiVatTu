#pragma once 

#include <iostream>
#include <WinUser.h>
#include "graphics.h"
#include "DefineConstatant.h"
#include "supplies.h"
#include "staff.h"
#include "invoice.h"
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

// Check if button left clicked on exit button
bool is_pointed_exit_button(int xMouse, int yMouse)
{
	if (xMouse <= 1270 && xMouse >= 1240 && yMouse >= 5 && yMouse <= 35)
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

int check_state_button_tab(int xMouse, int yMouse)
{
	if (is_pointed_button_1(xMouse, yMouse) && GetAsyncKeyState(VK_LBUTTON) && 0x8000)
		return 1;
	if (is_pointed_button_2(xMouse, yMouse) && GetAsyncKeyState(VK_LBUTTON) && 0x8000)
		return 2;
	if (is_pointed_button_3(xMouse, yMouse) && GetAsyncKeyState(VK_LBUTTON) && 0x8000)
		return 3;
	if (is_pointed_button_4(xMouse, yMouse) && GetAsyncKeyState(VK_LBUTTON) && 0x8000)
		return 4;
	if (is_pointed_exit_button(xMouse, yMouse) && GetAsyncKeyState(VK_LBUTTON) && 0x8000)
		return 5;
	return 0;
}

void isPointed(int xMouse, int yMouse)
{	
	if (is_pointed_button_1(xMouse, yMouse) && GetAsyncKeyState(VK_LBUTTON) && 0x8000 && cnt != 0) // 0x8000
	{
		button_chosen(0);
		drawSubwindow();
		supplies_drawSheet();
		supplies_drawTitle();
	}
	if (is_pointed_button_2(xMouse, yMouse) && GetAsyncKeyState(VK_LBUTTON) && 0x8000 && cnt != 1)
	{
		button_chosen(1);
		drawSubwindow();
		staff_drawSheet();
		staff_drawTitle();
		staff_writeData();
		/*
		int msgboxID = MessageBox(
			GetForegroundWindow(),
			(LPCWSTR)L"Do you want switch to other tab?",
			(LPCWSTR)L"Warning",
			MB_ICONEXCLAMATION | MB_OKCANCEL
		);
		*/
		draw_staff_button();
		while (true)
		{
			check_state_staff(mousex(), mousey());
			if (check_state_button_tab(mousex(), mousey()) > 0)
				break;
		}
		
	}
	if (is_pointed_button_3(xMouse, yMouse) && GetAsyncKeyState(VK_LBUTTON) && 0x8000 && cnt != 2)
	{
		button_chosen(2);
		drawSubwindow();
		invoice_drawSheet();
		invoice_drawTitle();
	}
	if (is_pointed_button_4(xMouse, yMouse) && GetAsyncKeyState(VK_LBUTTON) && 0x8000 && cnt != 3)
	{
		button_chosen(3);
		drawSubwindow();
	}
	if (is_pointed_exit_button(xMouse, yMouse) && GetAsyncKeyState(VK_LBUTTON) && 0x8000)
		exit(0); // exit program immediately
}

// Make default when you open my software
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
	supplies_drawSheet();
	supplies_drawTitle();
	supplies_writeData();
}