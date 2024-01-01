#pragma once

#include "graphics.h"
#include "DefineConstatant.h"
#include <fstream>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

const int MAXN = 2e5 + 4;

struct staff
{
	char MANV[15];
	char HO[40];
	char TEN[10];
	int PHAI;
};

staff arr[MAXN]; // array use struct staff

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

	char title[5][30] = { "NUMBER", "ID", "FIRST NAME", "LAST NAME", "SEX" };

	int cnt = 0, index_staff = 0;

	ifstream input("staff.txt"); // open file staff.txt

	if (input.fail()) // if file has error
	{
		std::cout << "File nhu con cac, viet lai file moi cho bo may";
		return void();
	}

	// 15 40 10

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