#pragma once

#include "mylib.h"
#include <ctime>

const int DAY_MONTH[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/*
struct NgayLapHD {
    int ngay;
    int thang;
    int nam;
};
*/

struct Date
{
    char day[3];
    char months[3];
    char year[5];
};

char* getDateString(Date& Date)
{
    char s[50];

}