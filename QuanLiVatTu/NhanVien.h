#pragma once
#include "HoaDon.h"
#include <cstring>
#include <fstream>
using namespace std;
struct NhanVien
{
    char MaNV[10];
    char Ho[40];
    char Ten[10];
    bool Phai;
    PTRHoaDon FirstHD;
};
struct ListNhanVien
{
    int size = 0;
    NhanVien *data[100];
};

bool isEmpty(ListNhanVien &list)
{
    return list.size == 0;
}

bool isFull(ListNhanVien &list)
{
    return list.size >= 200;
}

NhanVien *newNhanVien(NhanVien &nv)
{
    NhanVien *p = new NhanVien;
    *p = nv;
    return p;
}

void addNhanVien(ListNhanVien &list, NhanVien &nv)
{
    if (!isFull(list))
    {
        list.data[list.size] = newNhanVien(nv);
        list.size++;
        for (int i = 0; i < list.size; i++)
        { // Sap xep lai mang thep MaNV
            if (strcmp(list.data[list.size - 1]->MaNV, list.data[i]->MaNV) < 0)
            {
                NhanVien *temp = list.data[list.size - 1];
                list.data[list.size - 1] = list.data[i];
                list.data[i] = temp;
            }
        }
    }
    else
    {
        return;
    }
}
int findNhanVien(ListNhanVien &list, int l, int r, char maNV[8])
{

    if (r >= 1)
    {
        int mid = (l + r) / 2;
        if (strcmp(list.data[mid]->MaNV, maNV) == 0)
        {
            return mid;
        }
        else if (strcmp(list.data[mid]->MaNV, maNV) > 0)
        {
            return findNhanVien(list, l, mid - 1, maNV);
        }
        else
        {
            return findNhanVien(list, mid + 1, r, maNV);
        }
    }
    return -1;
}

void removeNhanVien(ListNhanVien &list, char maNV[8])
{
    int idx = findNhanVien(list, 0, list.size - 1, maNV);
    if (idx == -1)
    {
        cout << "Khong tim thay nhan vien!\n";
    }
    else
    {
        for (int j = idx; j < list.size - 1; j++)
        {
            list.data[j] = list.data[j + 1];
        }
        delete list.data[list.size - 1];
        list.size--;
    }
}
void GiaiPhongNV(ListNhanVien &list)
{ // Chua giai phong CT_hoa don
    for (int i = 0; i < list.size; i++)
    {
        GiaiPhong_HoaDon(list.data[i]->FirstHD);
        delete list.data[i];
    }
    list.size = 0;
}
void InRaMangTam(ListNhanVien &list, ListNhanVien &temp)
{
    for (int i = 0; i < list.size; i++)
    {
        temp.data[i] = list.data[i];
    }
}
void sortNhanVien(ListNhanVien &arr)
{ // Theo ten ho nhan vien
    for (int i = 0; i < arr.size - 1; i++)
    {
        for (int j = i + 1; j < arr.size; j++)
        {
            if (strcmp(arr.data[i]->Ten, arr.data[j]->Ten) > 0)
            {
                NhanVien *temp = arr.data[i];
                arr.data[i] = arr.data[j];
                arr.data[j] = temp;
            }
            else if (strcmp(arr.data[i]->Ten, arr.data[j]->Ten) == 0)
            {
                if (strcmp(arr.data[i]->Ho, arr.data[j]->Ho) > 0)
                {
                    NhanVien *temp = arr.data[i];
                    arr.data[i] = arr.data[j];
                    arr.data[j] = temp;
                }
            }
        }
    }
}
//================Ghi File================
void DocFileNhanVien(ListNhanVien &ds)
{
    ifstream file_nv;
    string data;
    file_nv.open("NhanVien.txt");
    if (file_nv.fail())
    {
        cout << "Failed to open file!" << endl;
        return;
    }
    while (!file_nv.eof())
    {
        int count_hd = 0, count_ct_hd = 0;
        NhanVien *nv = new NhanVien;    
        getline(file_nv, data);
        strcpy_s(nv->MaNV,10, data.c_str());
        getline(file_nv, data);
        strcpy_s(nv->Ho,40, data.c_str());
        getline(file_nv, data);
        strcpy_s(nv->Ten,10, data.c_str());
        getline(file_nv, data);
        nv->Phai = stoi(data);
        getline(file_nv, data);
        // Doc hoa don
        file_nv >> count_hd;
        getline(file_nv, data);
        PTRHoaDon first = NULL;
        if (count_hd == 0)
            return;
        else
        {
            for (int i = 0; i < count_hd; i++)
            {
                HoaDon hd;
                getline(file_nv, data);
                strcpy_s(hd.soHD,20, data.c_str());
                getline(file_nv, data);
                hd.ngayLap.day = stoi(data);
                getline(file_nv, data);
                hd.ngayLap.month = stoi(data);
                getline(file_nv, data);
                hd.ngayLap.year = stoi(data);
                getline(file_nv, data);
                strcpy_s(hd.loai,1, data.c_str()); // error
                // Doc chi tiet hoa don
                file_nv >> count_ct_hd;
                getline(file_nv, data);
                PTRCT_HoaDon first_ct = NULL;
                if (count_ct_hd == 0)
                    return;
                else
                {
                    for (int j = 0; j < count_ct_hd; j++)
                    {
                        CT_HoaDon ct_hd;
                        getline(file_nv, data);
                        strcpy_s(ct_hd.MaVT,10, data.c_str());
                        getline(file_nv, data);
                        ct_hd.SoLuong = stoi(data);
                        getline(file_nv, data);
                        ct_hd.DonGia = stoi(data);
                        getline(file_nv, data);
                        ct_hd.VAT = stof(data);
                        insertCT_HoaDon(first_ct, ct_hd);
                    }
                }
                hd.FirstCT_HD = first_ct;
                hd.TongTien = TongTienHoaDon(hd.FirstCT_HD);
                insertHoaDon(first, hd);
            }
        }
        // xu ly
        nv->FirstHD = first;
        ds.data[ds.size] = nv;
        ds.size++;
    }
    file_nv.close();
}
void GhiFileNhanVien(ListNhanVien &ds)
{
    ofstream file_nv;
    file_nv.open("NhanVien.txt");
    for (int i = 0; i < ds.size; i++)
    {
        file_nv << ds.data[i]->MaNV << endl
                << ds.data[i]->Ho << endl
                << ds.data[i]->Ten << endl
                << ds.data[i]->Phai << endl
                << size(ds.data[i]->FirstHD) << endl;
        if (ds.data[i]->FirstHD != NULL)
        {
            for (PTRHoaDon p = ds.data[i]->FirstHD; p != NULL; p = p->next)
            {
                file_nv << p->info.soHD << endl
                        << p->info.ngayLap.day << endl
                        << p->info.ngayLap.month << endl
                        << p->info.ngayLap.year << endl
                        << p->info.loai << endl
                        << size(p->info.FirstCT_HD) << endl;
                if (p->info.FirstCT_HD != NULL)
                {
                    for (PTRCT_HoaDon q = p->info.FirstCT_HD; q != NULL; q = q->next)
                    {
                        file_nv << q->info.MaVT << endl
                                << q->info.SoLuong << endl
                                << q->info.DonGia << endl
                                << q->info.VAT << endl;
                    }
                }
            }
        }
    }
    file_nv.close();
}
void deleteListNV(ListNhanVien &list)
{
    for (int i = 0; i < list.size; i++)
    {
        delete list.data[i];
    }
    list.size = 0;
}