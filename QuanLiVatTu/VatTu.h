#pragma once
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;
struct VatTu
{
    char maVT[10] = "";
    char tenVT[50] = "";
    char DVT[10] = "";
    int soLuongTon = 0;
    bool TrongHD = false;
};

struct NodeVT
{
    VatTu data;
    NodeVT* left = NULL;
    NodeVT* right = NULL;
    int height = 0;
};

typedef struct NodeVT* AVLTree;

void createTree(AVLTree& root)
{
    root = NULL;
}
AVLTree createNode(VatTu& vattu)
{
    AVLTree p = new NodeVT;
    p->data = vattu;
    p->left = NULL;
    p->right = NULL;
    p->height = 1;
    return p;
}
int findHeight(AVLTree& root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
}
AVLTree rightRotate(AVLTree& root)
{ // Xoay phai
    AVLTree x = root->left;
    AVLTree y = x->right;
    x->right = root;
    root->left = y;

    root->height = max(findHeight(root->left), findHeight(root->right)) + 1;
    x->height = max(findHeight(x->left), findHeight(x->right)) + 1;
    return x;
}
AVLTree leftRotate(AVLTree& root)
{ // Xoay trai
    AVLTree x = root->right;
    AVLTree y = x->left;
    x->left = root;
    root->right = y;

    root->height = max(findHeight(root->left), findHeight(root->right)) + 1;
    x->height = max(findHeight(x->left), findHeight(x->right)) + 1;
    return x;
}
int getBalance(AVLTree& root)
{
    if (root == NULL)
    {
        return 0;
    }
    return findHeight(root->left) - findHeight(root->right);
}
//===============Them Vat Tu================
AVLTree addVatTu(AVLTree& root, VatTu& vattu)
{ // Sap xep vat tu theo maVT
    if (root == NULL)
    {
        root = createNode(vattu);
    }
    else
    {
        if (strcmp(vattu.maVT, root->data.maVT) < 0)
        {

            root->left = addVatTu(root->left, vattu);
        }
        else
        {
            root->right = addVatTu(root->right, vattu);
        }
    }
    root->height = 1 + max(findHeight(root->left), findHeight(root->right));

    int balance = getBalance(root);
    // LL case
    if (balance > 1 && strcmp(vattu.maVT, root->left->data.maVT) < 0)
    {
        return rightRotate(root);
    }
    // RR case
    if (balance < -1 && strcmp(vattu.maVT, root->right->data.maVT) > 0)
    {
        return leftRotate(root);
    }
    // LR case
    if (balance > 1 && strcmp(vattu.maVT, root->left->data.maVT) > 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // RL case
    if (balance < -1 && strcmp(vattu.maVT, root->right->data.maVT) < 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
int CountVatTu(AVLTree& root)
{ // Dem so luong vat tu
    if (root == NULL)
    {
        return 0;
    }
    return CountVatTu(root->left) + CountVatTu(root->right) + 1;
}
//===============Tim Vat Tu================
AVLTree findVatTu(AVLTree root, char TimMaVT[10])
{ // Tim vat tu theo ma vat tu
    if (root == NULL)
    {
        return NULL;
    }
    else {
        if (strcmp(root->data.maVT, TimMaVT) == 0)
        {
            return root;
        }
        else if (strcmp(root->data.maVT, TimMaVT) < 0)
        {
            findVatTu(root->right, TimMaVT);
        }
        else
        {
            findVatTu(root->left, TimMaVT);
        }
    }
}
void GetTempArray(AVLTree root, VatTu vt[], int& idx)
{ // Lay tat ca vat tu trong cay (khoi tao idx=0)
    if (root != NULL)
    {
        if (root->data.soLuongTon != 0)
        {
            vt[idx] = root->data;
            idx++;
        }
        GetTempArray(root->left, vt, idx);
        GetTempArray(root->right, vt, idx);
    }
}
void SX_TenVT(VatTu vt[], int n)
{ // sap xep vat tu theo ten
    VatTu x;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(vt[i].tenVT, vt[j].tenVT) > 0)
            {
                x = vt[i];
                vt[i] = vt[j];
                vt[j] = x;
            }
        }
    }
}

//================Xoa Vat Tu================
void findReplaceNode(AVLTree& root, AVLTree& x)
{
    if (x->right != NULL)
    {
        findReplaceNode(root, x->right);
    }
    else
    {
        root->data = x->data;
        root = x;
        x = x->left;
    }
}
void RemoveVatTu(AVLTree& root, VatTu& vt)
{
    if (root == NULL)
    {
        return;
    }
    if (strcmp(vt.maVT, root->data.maVT) < 0)
    {
        RemoveVatTu(root->left, vt);
    }
    else if (strcmp(vt.maVT, root->data.maVT) > 0)
    {
        RemoveVatTu(root->right, vt);
    }
    else
    { // Tim thay vat tu can xoa
        AVLTree temp = root;
        if (root->left == NULL)
        {
            root = root->right;
        }
        else if (root->right == NULL)
        {
            root = root->left;
        }
        else
        {
            findReplaceNode(temp, temp->left);
        }
        delete temp;
    }
}
void GiaiPhongVatTu(AVLTree& root)
{ // Xoa toan bo dsVT
    if (root != NULL)
    {
        GiaiPhongVatTu(root->left);
        GiaiPhongVatTu(root->right);
        delete root;
    }
}
//================Ghi File================
void GhiFileVatTu_LNR(AVLTree& root, ofstream& f)
{
    if (root != NULL)
    {
        f << root->data.maVT << endl
            << root->data.tenVT << endl
            << root->data.DVT << endl
            << root->data.soLuongTon << endl;
        GhiFileVatTu_LNR(root->left, f);
        GhiFileVatTu_LNR(root->right, f);
    }
}
void GhiFileVatTu(AVLTree& root)
{
    ofstream f;
    f.open("VatTu.txt", ios::out);
    GhiFileVatTu_LNR(root, f);
    f.close();
}
void DocFileVatTu(AVLTree& root)
{
    ifstream f;
    f.open("VatTu.txt");
    if (f.fail())
    {
        cout << "Failed to open file!" << endl;
        return;
    }
    while (!f.eof())
    {
        VatTu vt;
        string data;
        getline(f, data);
        strcpy_s(vt.maVT, data.c_str());
        getline(f, data);
        strcpy_s(vt.tenVT, data.c_str());
        getline(f, data);
        strcpy_s(vt.DVT, data.c_str());
        getline(f, data);
        vt.soLuongTon = atoi(data.c_str());
        root = addVatTu(root, vt);
    }
    f.close();
}