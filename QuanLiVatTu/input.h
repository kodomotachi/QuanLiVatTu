#pragma once 

#include <iostream>
#include "DefineConstatant.h"
using namespace std;

int returnString()
{
	for (int i = 65; i <= 90; i++) {
		if (GetAsyncKeyState((char)(i)) & 1) {
			return i;
		}
	}
}