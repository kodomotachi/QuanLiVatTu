#pragma once
#include "Day.h"
#include "CT_HoaDon.h"
#include <cstring>
#ifndef HOADON_H
#define HOADON_H

struct HoaDon
{
    char soHD[20];
    Date ngayLap;
    char loai[1]; // ??? error on this line, im comeback
    PTRCT_HoaDon FirstCT_HD = NULL;
    float TongTien = TongTienHoaDon(FirstCT_HD);
};

#endif // HOADON_H

struct NodeHoaDon
{
    HoaDon info;
    NodeHoaDon *next;
};
typedef NodeHoaDon *PTRHoaDon;

void create_List_HoaDon(PTRHoaDon &first)
{
    first = NULL;
}

PTRHoaDon createNode(HoaDon &x)
{
    PTRHoaDon p = new NodeHoaDon;
    p->info = x;
    p->next = NULL;
    return p;
}

bool isEmpty(PTRHoaDon first)
{
    return (first == NULL ? true : false);
}

void insertHoaDon(PTRHoaDon &first, HoaDon &x)
{
    PTRHoaDon temp = createNode(x);
    if (first == NULL)
    {
        first = temp;
        first->next = NULL;
    }
    else
    {
        PTRHoaDon p = first;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}

int size(PTRHoaDon &first)
{
    int cnt = 0;
    if (first == NULL)
    {
        return cnt;
    }
    for (PTRHoaDon k = first; k != NULL; k = k->next)
    {
        cnt++;
    }
    return cnt;
}

PTRHoaDon findHoaDon(PTRHoaDon &first, char soHD[20])
{
    for (PTRHoaDon p = first; p != NULL; p = p->next)
    {
        if (strcmp(p->info.soHD, soHD) == 0)
        {
            return p;
        }
    }
    return NULL;
}
void GiaiPhong_HoaDon(PTRHoaDon &first)
{
    PTRHoaDon p = first;
    while (p != NULL)
    {
        PTRHoaDon temp = p;
        p = p->next;
        GiaiPhong_CT_HoaDon(temp->info.FirstCT_HD);
        delete temp;
    }
    first = NULL;
}
void NhapNgay();
//=======Nhap/Xuat Vat Tu theo Hoa Don=======
// bool UpdateVatTu(AVLTree& tree, PTRHoaDon& first){
//     for(PTRHoaDon p = first; p != NULL; p = p->next){
//         for(PTRCT_HoaDon q = p->info.FirstCT_HD; q != NULL; q = q->next){
//             if(){

//             }
//         }
//     }
// };
