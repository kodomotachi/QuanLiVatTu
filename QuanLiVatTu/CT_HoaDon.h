#pragma once
#include "VatTu.h"
struct CT_HoaDon
{
    char MaVT[10] = "";
    int SoLuong = 0;
    int DonGia = 0;
    float VAT = 0;
};

struct NodeCT_HoaDon
{
    CT_HoaDon info;
    NodeCT_HoaDon* next = NULL;
};
typedef NodeCT_HoaDon* PTRCT_HoaDon;

void create_List_CT_HoaDon(PTRCT_HoaDon& first)
{
    first = NULL;
}

PTRCT_HoaDon newNode(CT_HoaDon x)
{ // tao 1 node moi
    PTRCT_HoaDon p = new NodeCT_HoaDon;
    p->info = x;
    p->next = NULL;
    return p;
}
bool isEmpty(PTRCT_HoaDon first)
{
    return (first == NULL ? true : false);
}

void insertCT_HoaDon(PTRCT_HoaDon& first, CT_HoaDon x)
{
    PTRCT_HoaDon temp = newNode(x);
    if (first == NULL)
    {
        first = temp;
        first->next = NULL;
    }
    else
    {
        PTRCT_HoaDon p = first;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = temp;
    }
}
PTRCT_HoaDon findCT_HoaDon(PTRCT_HoaDon first, char maVT[10])
{
    PTRCT_HoaDon p = first;
    while (p != NULL)
    {
        if (strcmp(p->info.MaVT, maVT) == 0)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
int size(PTRCT_HoaDon& first)
{
    int count = 0;
    PTRCT_HoaDon p = first;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
float TongTienMotVatTu(PTRCT_HoaDon node)
{
    float sum = 0;
    PTRCT_HoaDon p = node;
    sum += p->info.SoLuong * p->info.DonGia * (1 + p->info.VAT);
    return sum;
}
float TongTienHoaDon(PTRCT_HoaDon& first)
{
    if (first == NULL)
    {
        return 0;
    }
    else
    {
        float Total = TongTienMotVatTu(first);
        PTRCT_HoaDon p = first;
        while (p->next != NULL)
        {
            Total += TongTienMotVatTu(p->next);
            p = p->next;
        }
        return Total;
    }
}
void Remove_CTHD(PTRCT_HoaDon& first, char maVT[10])
{
    PTRCT_HoaDon p = findCT_HoaDon(first, maVT);
    PTRCT_HoaDon q = first;
    while (q->next != p)
    {
        q = q->next;
    }
    q->next = p->next;
    delete p;
}

//void GiaiPhong_CT_HoaDon(PTRCT_HoaDon &first)
//{
//    PTRCT_HoaDon p;
//    while (first != NULL)
//    {
//        p = first;
//        first = first->next;
//        delete p;
//    }
//}
