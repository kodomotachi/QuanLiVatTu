#pragma once

#include "graphics.h"
#include "DefineConstatant.h"
#include <fstream>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

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

	int cnt = 0;

	ifstream input("staff.txt"); // open file staff.txt

	if (input.fail())
	{
		std::cout << "File nhu con cac, viet lai file moi cho bo may";
	}

	input.ignore();

	while (!input.eof())
	{
		char tmp[255];
		input.getline(tmp, 255);
		if (cnt % 4 < 3)
		{
			string s = tmp;
			cout << s << "\n";
		}
		else
		{
			char* output;
			int result = strtol(tmp, &output, 10);
			cout << "Input: " << result << "\n";
		}
		++cnt;
	}

	input.close();
}