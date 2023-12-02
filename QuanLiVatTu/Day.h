#pragma once
#include<ctime>
#include<cmath>

const int DAY_MONTH[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

struct Date {
	int day, month, year;

};

/***************************************XU LY NGAY***************************************************/
//tra ve thoi gian hien tai
Date Now()
{
	Date date;
	time_t now = time(0);//tra ve so giay tu 1/1/1970 den hien tai
	tm* ltm = localtime(&now);//tra ve thoi gian hien tai
	date.year = 1900 + ltm->tm_year;
	date.month = 1 + ltm->tm_mon;
	date.day = ltm->tm_mday;
	return date;
}
int NamNhuan(int nam)
{
	return(nam % 4 == 0 && nam % 100 != 0 || nam % 400 == 0) ? 1 : 0;
}
//so ngay cua tung thang
int NgayOfThang[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//kiem tra nhap dung ngay
int CheckNgay(Date date)
{
	int ngay = date.day, thang = date.month, nam = date.year;
	int check = 0, maxday = 0;
	if (thang > 12) return 1;
	switch (thang)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		maxday = 31;
		break;
	case 4: case 6: case 9: case 11:
		maxday = 30;
		break;
	case 2:
		if (NamNhuan(nam) == 1) maxday = 29;
		else maxday = 28;
		break;
	}
	if (ngay > maxday)	return 1;
	return 0;
};
int TongSoNgay(int day, int month, int year)
{
	int tong = 0;
	for (int t = 1; t < month; t++)
	{
		tong += NgayOfThang[t];
		if (t == 2) tong += NamNhuan(year);
	}
	tong += day;
	return tong;
}
int SoSanh2Ngay(Date date1, Date date2)
{
	if (date1.year > date2.year) return 1;
	if (date1.year < date2.year) return 2;
	int tongdate1 = TongSoNgay(date1.day, date1.month, date1.year);
	int tongdate2 = TongSoNgay(date2.day, date2.month, date2.year);
	if (tongdate1 < tongdate2) return 2;
	else if (tongdate1 > tongdate2) return 1;
}