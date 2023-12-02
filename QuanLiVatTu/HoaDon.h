#pragma once
#include "Day.h"
#include "CT_HoaDon.h"
#include <string.h>
struct HoaDon{
    char soHD[20];
    Date ngayLap;
    char loai;
    PTRCT_HoaDon FirstCT_HD= NULL;
    int TongTien = TongTienHoaDon(FirstCT_HD);
};

struct NodeHoaDon{
    HoaDon info;
    NodeHoaDon* next;
};
typedef NodeHoaDon* PTRHoaDon;

void create_List_HoaDon(PTRHoaDon& first){
    first = NULL;
}

PTRHoaDon createNode(HoaDon& x){
    PTRHoaDon p = new NodeHoaDon;
    p->info = x;
    p->next = NULL;
    return p;
}

bool isEmpty(PTRHoaDon first){
    return (first == NULL? true : false);
}

void insertHoaDon(PTRHoaDon& first, HoaDon& x){
    PTRHoaDon temp = createNode(x);
    if(first == NULL){
        first = temp;
        first->next = NULL;
    }
    else{
        PTRHoaDon p = first;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
}

int size(PTRHoaDon& first){
    int cnt = 0;
    if(first == NULL){
        return cnt;
    }
    for(PTRHoaDon k = first; k != NULL; k = k->next){
        cnt++;
    }
    return cnt;
}

PTRHoaDon findHoaDon(PTRHoaDon& first, char soHD[20]){
    for(PTRHoaDon p = first; p != NULL; p = p->next){
        if(strcmp(p->info.soHD, soHD) == 0){
            return p;
        }
    }
    return NULL;
}
void GiaiPhong_HoaDon(PTRHoaDon& first){
    PTRHoaDon p = first;
    while(p != NULL){
        PTRHoaDon temp = p;
        p = p->next;
        GiaiPhong_CT_HoaDon(temp->info.FirstCT_HD);
        delete temp;
    }
    first = NULL;
}
void NhapNgay();
//=======Ghi file HoaDon=======


