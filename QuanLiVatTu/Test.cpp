#include "VatTu.h"
#include "NhanVien.h"
#include "HoaDon.h"
#include "CT_HoaDon.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
	AVLTree root;
	ListNhanVien list;
	createTree(root);
	DocFileVatTu(root);
	DocFileNhanVien(list);
	int kt = true;
	while (kt)
	{
		int chon;
		cout << ">>>>>>>>>QUAN LY VAT TU<<<<<<<<<" << endl;
		cout << "		 1. VAT TU" << endl;
		cout << "		 2. NHAN VIEN" << endl;
		cout << "		 3. HOA DON" << endl;
		cout << "		 4. THOAT" << endl;
		cout << "Nhap lua chon: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
		{
			bool kt1 = true;
			while (kt1)
			{
				int chon1;
				cout << "1. Them vat tu" << endl;
				cout << "2. Xoa vat tu" << endl;
				cout << "3. Sua vat tu" << endl;
				cout << "4. In danh sach vat tu" << endl;
				cout << "5. Quay lai" << endl;
				cout << "Nhap lua chon: ";
				cin >> chon1;

				switch (chon1)
				{
				case 1:
				{
					VatTu vt;
					cout << "Nhap ma vat tu: ";
					cin >> vt.maVT;
					cout << "Nhap ten vat tu: ";
					cin >> vt.tenVT;
					cout << "Nhap don vi tinh: ";
					cin >> vt.DVT;
					cout << "Nhap so luong ton: ";
					cin >> vt.soLuongTon;
					root = addVatTu(root, vt);
					break;
				}
				case 2:
				{
					char maVT[10];
					cout << "Nhap ma Vat Tu can xoa: ";
					cin >> maVT;
					AVLTree tmp = findVatTu(root, maVT);
					if (tmp != NULL)
					{
						RemoveVatTu(root, tmp->data);
						cout << "Xoa thanh cong!" << endl;
					}
					else
					{
						cout << "Khong tim thay vat tu nay!" << endl;
					}
					break;
				}
				case 3:
				{
					char maVT[10];
					cout << "Nhap ma Vat Tu can sua: ";
					cin >> maVT;
					AVLTree temp = findVatTu(root, maVT);
					cout << "Nhap ma vat tu: ";
					cin >> temp->data.maVT;
					cout << "Nhap ten vat tu: ";
					cin >> temp->data.tenVT;
					cout << "Nhap don vi tinh: ";
					cin >> temp->data.DVT;
					break;
				}
				case 4:
				{
					int n = CountVatTu(root);
					int idx = 0;
					VatTu arr[100];
					GetTempArray(root, arr, idx);
					SX_TenVT(arr, n);
					for (int i = 0; i < n; i++)
					{
						cout << arr[i].maVT << " " << arr[i].tenVT << " " << arr[i].DVT << " " << arr[i].soLuongTon << endl;
					}
					break;
				}
				case 5:
				{
					kt1 = false;
					break;
				}
				}
			}
			break;
		}
		case 2:
		{
			bool kt2 = true;
			while (kt2)
			{
				cout << "1. Them nhan vien" << endl;
				cout << "2. Xoa nhan vien" << endl;
				cout << "3. Sua nhan vien" << endl;
				cout << "4. In danh sach nhan vien" << endl;
				cout << "5. Quay lai" << endl;
				int chon2;
				cin >> chon2;
				switch (chon2)
				{
				case 1:
				{
					NhanVien nv;
					cout << "Nhap ma nhan vien: ";
					cin >> nv.MaNV;
					cout << "Nhap ho nhan vien: ";
					cin >> nv.Ho;
					cout << "Nhap ten nhan vien: ";
					cin >> nv.Ten;
					cout << "Nhap phai nhan vien: ";
					cin >> nv.Phai;
					addNhanVien(list, nv);
					break;
				}
				case 2:
				{
					break;
				}
				case 4:
				{
					int n = list.size;
					for (int i = 0; i < n; i++)
					{
						cout << list.data[i]->MaNV << " " << list.data[i]->Ho << " " << list.data[i]->Ten << " " << list.data[i]->Phai << endl;
					}
					break;
				}
				case 5:
				{
					kt2 = false;
					break;
				}
				}
			}
		}
		default:
		{
			kt = false;
			GiaiPhongVatTu(root);
			GiaiPhongNV(list);
			break;
		}
		}
	}
	return 0;
}
// Chinh lai Ham sua vat tu, Build ham doc file nhan vien, hoa don, ct hoa don va xuat ra man hinh