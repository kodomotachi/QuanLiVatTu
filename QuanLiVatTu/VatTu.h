#pragma once

#include <fstream>

class VatTu {
private:
    char maVT[10];
    char tenVT[50];
    char dvt[10];
    int soLuongTon;
public:
    void nhap();
    void xuat();
    char* getMaVT();
    char* getTenVT();
    char* getDVT();
    int getSoLuongTon();
};