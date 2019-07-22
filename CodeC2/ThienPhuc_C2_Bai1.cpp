//Project: C2_Bai1.cpp
#include <iostream>
using namespace std;

// Cau 1.1
#define MAX 100
int a[MAX];
int n;

// Cau 1.2
void input(int a[], int &n)
{
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	cout << "Nhap danh sach: ";
	for(int i = 0; i < n; i++)
		cin >> a[i];
}

// Cau 1.3
void output(int a[], int &n)
{
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
}

// Cau 1.4
int Find(int a[], int &n, int x)
{
	for(int i = 0; i < n; i++)
		if(a[i] == x)
			return i + 1;
	return 0;
}
// Cau 1.5
void Add_Last(int a[], int &n, int x)
{
	a[n] = x;
	n++;
}

// Cau 1.6
int Delete_Last(int a[], int &n)
{
	if (n > 0)
	{
	    n--;
		return 1;
	}
	return 0;
}

// Cau 1.7
int Delete(int a[], int &n, int x)
{
	if (x >= 0 && x < n)
	{
	for (int i = x - 1; i < n; i++)
		a[i] = a[i + 1];
	n--;

	return 1;
	}
	return 0;
}

// Cau 1.8
int FindADelete(int a[], int &n, int x)
{
	if(Find(a, n, x) != 0)
	{
		Delete(a, n, Find(a, n, x));
		return 1;
	}
	return 0;
}

int main()
{
	cout << "------Bai tap 1 - Chuong 2---------\n";
	cout << "1.Nhap danh sach\n";
	cout << "2. Xuat danh sach\n";
	cout << "3.Tim 1 phan tu trong danh sach\n";
	cout << "4. Them 1 phan tu vao cuoi danh sach\n";
	cout << "5. Xoa phan tu cuoi danh sach\n";
	cout << "6.Xoa phan tu tai vi tri bat ky\n";
	cout << "7.Tim va xoa mot phan tu trong danh sach\n";
	cout << "8.Thoat\n";
	int choose;
	do{
		cout << "Ban chon: ";
		cin >> choose;
		if(choose < 1 && choose > 8)
			cout << "Nhap sai. Hay nhap lai\n";
	switch(choose)
	{
	case 1:
		input(a, n);
		cout << "Ban vua nhap danh sach thanh cong\n";
		break;
	case 2:
		output(a, n);
		cout << "Ban xuat danh sach thanh cong\n";
		break;
	case 3:
		int b;
		cout << "Nhap phan tu muon tim: ";
		cin >> b;
		if(Find(a, n, b) != 0)
			cout << b << " co trong danh sach o vi tri " << Find(a, n, b) << endl;
		else
			cout << b << " khong co trong danh sach\n";
		break;
	case 4:
		int y;
		cout << "Nhap phan tu muon them: ";
		cin >> y;
		Add_Last(a, n, y);
		cout << "Danh sach sau khi them cuoi: ";
		output(a, n);
		cout << endl;
		break;
	case 5:
		if(Delete_Last(a, n) == 1)
		{
			cout << "Danh sach sau khi xoa: "; 
			output(a, n);
			cout << endl;
		}
		else
			cout << "Khong thuc hien duoc\n";
		break;
	case 6:
		int k;
		cout << "Nhap vi tri phan tu muon xoa: ";
		cin >> k;
		if (Delete(a, n, k) == 1)
		{
			cout << "Danh sach sau khi xoa: ";
			output(a, n);
			cout << endl;
		}
		break;
	case 7:
		int h; 
		cout << "Nhap phan tu muon xoa: ";
		cin >> h;
		if (FindADelete(a, n, h) == 1)
		{
			cout << "Danh sach sau khi xoa: ";
			output(a, n);
			cout << endl;
		}
	}
	} while(choose != 8);
	return 0;
}