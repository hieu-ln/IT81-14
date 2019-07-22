#include <iostream>
using namespace std;

// Cau 5.1 khai bao cau truc stack
#define MAX 100
int a[MAX];
int sp;

//Cau 5.2 Khoi tao stack rong
void init(int a[], int &sp)
{
	sp = -1;
}

// Cau 5.3 kiem tra stack rong
int isEmpty(int a[], int &sp)
{
	if (sp == -1)
		return 1;
	else
		return 0;
}

// Cau 5.4 kiem tra stack day
int isFull(int a[], int &sp)
{
	if (sp == MAX - 1)
		return 1;
	else
		return 0;
}

// Cau 5.5 them 1 phan tu vao stack
int push(int a[], int &sp, int n)
{
	if (sp < MAX - 1)
	{
		a[++sp] = n;
		return 1;
	}
	return 0;
}

// Cau 5.6 Xoa 1 phan tu trong stack
int pop(int a[], int &sp, int n)
{
	if(sp != -1)
	{
		n = a[sp--];
		return 1;
	}
	return 0;
}

// Xuat stack
void xuat(int a[], int&sp)
{
	for (int i = 0; i < sp + 1; i++)
		cout << a[i] << "  ";
	cout << endl;
}

int main()
{
	int a[MAX];
	int choose, sp, kq, n;
	system("cls");
	cout << "1.Khoi tao danh sach rong\n";
	cout << "2. Kiem tra stack rong\n";
	cout << "3. Kiem tra stack day\n";
	cout << "4. Them 1 phan tu vao stack\n";
	cout << "5. Xoa 1 phan tu trong stack\n";
	cout << "6. Xuat stack ra man hinh\n";
	cout << "7. Thoat\n";
	do{
		cout << "Nhap so thu tu thao tac muon thuc hien: ";
		cin >> choose;
		switch(choose)
		{
		case 1:
			init(a, sp);
			cout << "Khoi tao danh sach thanh cong!\n";
			break;
		case 2:
			if (isEmpty(a, sp) == 1)
				cout << "Stack rong\n";
			else
				cout << "Stack khong rong\n";
			break;
		case 3:
			if (isFull(a, sp) == 1)
				cout << "Stack da day\n";
			else
				cout << "Stack hien tai chua day\n";
			break;
		case 4:
			cout << "Nhap gia tri can them: ";
			cin >> n;
			kq = push(a, sp, n);
			cout << "Stack sau khi them la: ";
			xuat(a, sp);
			break;
		case 5:
			cout << "Nhap gia tri can xoa: ";
			cin >> n;
			kq = pop(a, sp, n);
			cout << "Stack sau khi lay " << n << " ra: ";
			xuat(a,sp);
			break;
		case 6:
			if (isEmpty(a, sp) == 1)
				cout << "Stack khong co\n";
			else
				xuat(a, sp);
			break;
		case 7:
			cout << "Ban chon thoat!\n";
			break;
		default:
			break;
		}
	} while (choose != 7);
	return 0;
}