#include <iostream>
#include <conio.h>
using namespace std;
#define MAX 100
int a[MAX];
int sp;

void init(int a[], int &sp)
{
	sp = -1;
}

bool isEmpty(int a[], int sp)
{
	if(sp == -1)
		return 1;
	return 0;
}
bool isFull(int a[], int sp)
{
	if(sp == MAX - 1)
		return 1;
	return 0;
}
int Push(int a[], int &sp, int x)
{
	if(sp < MAX - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}
int Pop(int a[], int &sp, int &x)
{
	if(sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}
void xuat(int a[], int sp)
{
	cout << "Danh Sach gom cac phan tu: \n";
	for (int i = sp; i >= 0; i--)
	{
		cout << a[i] << endl;
	}
}
int doiSo(int a[], int sp, int so)
{
	init(a, sp);
	int np = 0;
	while(so != 0)
	{
		int du = so % 2;
		if(Push(a, sp, du))
			so /= 2;
		else 
			break;
	}
	while(!isEmpty(a, sp))
	{
		int x;
		if(Pop(a, sp, x))
			np = np * 10 + x;
		else 
			break;
	}
	return np;
}
int main()
{
	int c = 0, x;
	while(c != 8)
	{
		system("cls");
		cout << "1. Khoi Tao\n2. Kiem tra rong\n3. Kiem tra day\n4. Them 1 phan tu\n5. Xoa 1 phan tu\n6. Xuat danh sach\n7. Doi tu thap phan sang nhi phan\n8. Thoat!\nChon: ";
		cin >> c;
		switch(c)
		{
		case 1:
			init(a, sp);
			cout << "Khoi tao thanh cong\n";
			break;
		case 2:
			if(isEmpty(a, sp) == true)
				cout << "Danh sach rong!\n";
			else
				cout << "Danh sach ko rong\n";
			break;
		case 3:
			if(isFull(a, sp) == true)
				cout << "Danh sach da day\n";
			else
				cout << "Danh sach chua day\n";
			break;
		case 4:
			if(isFull(a, sp) == true)
				cout << "Danh sach da day, ko the them\n";
			else
			{
				cout << "Nhap vao gia tri cua phan tu muon them: ";
				cin >> x;
				Push(a, sp, x);
			}
			break;
		case 5:
			if(isEmpty(a, sp) == true)
				cout << "Danh sach rong, ko the xoa\n";
			else
			{
				Pop(a, sp, x);
				cout << "Gia tri vua lay ra la: " << x << endl;
			}
			break;
		case 6:
			xuat(a, sp);
			break;
		case 7:
			int x;
			cout << " Nhap so muon doi: ";
			cin >> x;
			cout << "So sau khi doi sang nhi phan : " << doiSo(a, sp, x) << endl;
			break;
		case 8:
			cout << "Tam biet\n";
			break;
		default:
			cout << "Ko co trong lua chon, moi chon lai!\n";
		}
		_getch();
	}
	return 0;
}