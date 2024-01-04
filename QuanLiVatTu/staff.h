#pragma once

#include "graphics.h"
#include "DefineConstatant.h"
#include "UIController.h"
#include "Button.h"
#include <fstream>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

const int MAXN = 200004;

struct staff
{
	char MANV[15];
	char HO[40];
	char TEN[10];
	int PHAI;
};

staff arr[MAXN]; // array use struct staff

// write title's sheet
void staff_drawTitle()
{
	char title[15] = "STAFF DATA";
	setbkcolor(SUBWINDOW_BACKGROUND);
	setcolor(COLOR(3, 53, 252));
	outtextxy((SUBWINDOW_LEFT + SUBWINDOW_RIGHT - textwidth(title)) / 2, SUBWINDOW_TOP + 20, title);
}

void staff_drawSheet()
{
	int x = LEFT_BORDER;
	int y = TOP_BORDER + 50;

	// background color
	setbkcolor(TAB_ON_SELECTED_BACKGROUND);
	setcolor(TAB_ON_SELECTED_BACKGROUND);
	setfillstyle(SOLID_FILL, TAB_ON_SELECTED_BACKGROUND);
	bar(x, TOP_BORDER, RIGHT_BORDER, y);

	setbkcolor(TAB_ON_SELECTED_BACKGROUND);
	setcolor(BLACK);
	setlinestyle(0, 0, 3);

	// draw border for sheet
	rectangle(LEFT_BORDER, TOP_BORDER, RIGHT_BORDER, BOTTOM_BORDER);

	// first line
	line(x, y, RIGHT_BORDER, y);
	line(225, TOP_BORDER, 225, BOTTOM_BORDER);
	line(438, TOP_BORDER, 438, BOTTOM_BORDER);
	line(850, TOP_BORDER, 850, BOTTOM_BORDER);
	line(1063, TOP_BORDER, 1063, BOTTOM_BORDER);
}

// write titile and data into sheet
void staff_writeData()
{
	char s[10][3] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
	setcolor(BLACK);

	for (int i = 0; i < 10; i++)
	{
		int textHeight = (200 + i * 36 + 200 + (i + 1) * 36 - textheight(s[i])) / 2;
		int textWidth = (225 + 125 - textwidth(s[i])) / 2;
		outtextxy(textWidth, textHeight, s[i]);
	}

	// write title on sheet 
	char title[5][30] = { "NUMBER", "ID", "FIRST NAME", "LAST NAME", "SEX" };

	setbkcolor(TAB_ON_SELECTED_BACKGROUND);
	outtextxy((LEFT_BORDER + 225 - textwidth(title[0])) / 2, (TOP_BORDER + TOP_BORDER + 50 - textheight(title[0])) / 2, title[0]);
	outtextxy((438 + 225 - textwidth(title[1])) / 2, (TOP_BORDER + TOP_BORDER + 50 - textheight(title[1])) / 2, title[1]);
	outtextxy((850 + 438 - textwidth(title[2])) / 2, (TOP_BORDER + TOP_BORDER + 50 - textheight(title[2])) / 2, title[2]);
	outtextxy((850 + 1063 - textwidth(title[3])) / 2, (TOP_BORDER + TOP_BORDER + 50 - textheight(title[3])) / 2, title[3]);
	outtextxy((1063 + RIGHT_BORDER - textwidth(title[4])) / 2, (TOP_BORDER + TOP_BORDER + 50 - textheight(title[4])) / 2, title[4]);

	int cnt = 0, index_staff = 0;

	ifstream input("staff.txt"); // open file staff.txt

	if (input.fail()) // if file has error
	{
		std::cout << "File nhu con cac, viet lai file moi cho bo may";
		return void();
	}

	// input data from file 
	while (!input.eof())
	{
		if (cnt % 4 == 0)
		{
			//char tmp[15];
			input.getline(arr[index_staff].MANV, 15);
		}
		else if (cnt % 4 == 1)
		{
			input.getline(arr[index_staff].HO, 40);
		}
		else if (cnt % 4 == 2)
		{
			input.getline(arr[index_staff].TEN, 10);
		}
		else
		{
			char tmp[3];
			input.getline(tmp, 3);
			char* output;
			int result = strtol(tmp, &output, 10);
			//cout << "Input: " << result << "\n";
			arr[index_staff].PHAI = result;
			index_staff++;
		}
		++cnt;
	}

	setbkcolor(SUBWINDOW_BACKGROUND);
	for (int i = 0; i < 10; i++)
	{
		outtextxy((438 + 225 - textwidth(arr[i].MANV)) / 2, (200 + i * 36 + 200 + (i + 1) * 36 - textheight(arr[i].MANV)) / 2, arr[i].MANV);
		outtextxy((850 + 438 - textwidth(arr[i].HO)) / 2, (200 + i * 36 + 200 + (i + 1) * 36 - textheight(arr[i].HO)) / 2, arr[i].HO);
		outtextxy((1063 + 850 - textwidth(arr[i].TEN)) / 2, (200 + i * 36 + 200 + (i + 1) * 36 - textheight(arr[i].TEN)) / 2, arr[i].TEN);
		
		string check;
		
		if (arr[i].PHAI)
			check = "Nu";
		else
			check = "Nam";
		char *tmp = &check[0];
		outtextxy((1155 + 1063 - textwidth(tmp)) / 2, (200 + i * 36 + 200 + (i + 1) * 36 - textheight(tmp)) / 2, tmp);
	}

	input.close();
}

// hover function -> make to change color
void check_state_staff(int xmouse, int ymouse)
{
	for (int i = 0; i < 10; i++)
	{
		if (xmouse >= LEFT_BORDER && xmouse <= RIGHT_BORDER && ymouse >= 200 + i * 36 && ymouse <= 200 + ((i + 1) * 36))
		{
			setcolor(TAB_DEFAULT_BACKGROUND);
			setbkcolor(SUBWINDOW_BACKGROUND);
			outtextxy((438 + 225 - textwidth(arr[i].MANV)) / 2, (200 + i * 36 + 200 + (i + 1) * 36 - textheight(arr[i].MANV)) / 2, arr[i].MANV);
			outtextxy((850 + 438 - textwidth(arr[i].HO)) / 2, (200 + i * 36 + 200 + (i + 1) * 36 - textheight(arr[i].HO)) / 2, arr[i].HO);
			outtextxy((1063 + 850 - textwidth(arr[i].TEN)) / 2, (200 + i * 36 + 200 + (i + 1) * 36 - textheight(arr[i].TEN)) / 2, arr[i].TEN);

			string check;

			if (arr[i].PHAI)
				check = "Nu";
			else
				check = "Nam";
			char* tmp = &check[0];
			outtextxy((1155 + 1063 - textwidth(tmp)) / 2, (200 + i * 36 + 200 + (i + 1) * 36 - textheight(tmp)) / 2, tmp);
		}
		else
		{
			setcolor(BLACK);
			setbkcolor(SUBWINDOW_BACKGROUND);
			outtextxy((438 + 225 - textwidth(arr[i].MANV)) / 2, (200 + i * 36 + 200 + (i + 1) * 36 - textheight(arr[i].MANV)) / 2, arr[i].MANV);
			outtextxy((850 + 438 - textwidth(arr[i].HO)) / 2, (200 + i * 36 + 200 + (i + 1) * 36 - textheight(arr[i].HO)) / 2, arr[i].HO);
			outtextxy((1063 + 850 - textwidth(arr[i].TEN)) / 2, (200 + i * 36 + 200 + (i + 1) * 36 - textheight(arr[i].TEN)) / 2, arr[i].TEN);

			string check;

			if (arr[i].PHAI)
				check = "Nu";
			else
				check = "Nam";
			char* tmp = &check[0];
			outtextxy((1155 + 1063 - textwidth(tmp)) / 2, (200 + i * 36 + 200 + (i + 1) * 36 - textheight(tmp)) / 2, tmp);
		}
	}
	if (xmouse >= 540 && xmouse <= 590 && ymouse >= 610 && ymouse <= 640)
	{
		char _left[2] = "<";

		draw_button(540, 610, 590, 640, WHITE, BUTTON_TEXT_COLOR, _left);
	}
	else
	{
		char _left[2] = "<";

		draw_button(540, 610, 590, 640, BUTTON_PAGE, BLACK, _left);
	}
	if (xmouse >= 660 && xmouse <= 710 && ymouse >= 610 && ymouse <= 640)
	{
		char _right[2] = ">";

		draw_button(660, 610, 710, 640, WHITE, BUTTON_TEXT_COLOR, _right);
	}
	else
	{
		char _right[2] = ">";

		draw_button(660, 610, 710, 640, BUTTON_PAGE, BLACK, _right);
	}
}

// draw roll-page button
void draw_staff_button()
{
	char _left[2] = "<";
	char _right[2] = ">";

	int left = SCREEN_WIDTH / 2 - 100;
	int top = BOTTOM_BORDER + 50;
	int right = left + 50;
	int bottom = top + 30;

	draw_button(left, top, right, bottom, BUTTON_PAGE, BLACK, _left); // draw left button

	draw_button(right + 70, top, right + 120, bottom, BUTTON_PAGE, BLACK, _right); // draw right button
}

void staff_search_box()
{
	char tmp[7] = "SEARCH";

	setbkcolor(SUBWINDOW_BACKGROUND);
	setcolor(EDITEXT_TEXT_COLOR);

	outtextxy((LEFT_BORDER + 225 - textwidth(tmp)) / 2, (100 + 148 - textheight(tmp)) / 2, tmp);
}