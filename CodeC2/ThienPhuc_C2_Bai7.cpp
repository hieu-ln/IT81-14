//Project: C2_Bai7.cpp
#include <iostream>
using namespace std;
#define MAX 100
int a[MAX];
int front, rear;
void init(int a[], int &front, int &rear)
{
	front = -1;
	rear = -1;
}
int push(int a[], int &front, int &rear, int x)
{
	if( rear - front == MAX - 1)
		return 0;
	else
	{
		if (front == -1)
			front = 0;
		if (rear == MAX - 1)
		{
			for (int i = front; i <= rear; i++)
				a[i - front] = a[i];
			rear = MAX -1 - front;
			front = 0;
		}
		a[++rear] = x;
		return 1;
	}
}
int pop(int a[], int &front, int &rear, int &x)
{
	if (front == -1)
		return 0;
	else
	{
		x = a[front++];
		if (front > rear)
		{
			front = -1;
			rear = -1;
		}
		return 1;
	}
}
int pust(int a[], int &front, int &rear, int &x)
{
	if ((rear - front == MAX- 1) || (rear - front == -1))
		return 0;
	else
	{
		if (front == -1)
			front = 0;
		if (rear == MAX - 1)
			rear = 1;
		a[++rear] = x;
		return 1;
	}
}
int pop1(int a[], int &front, int &rear, int &x)
{
	if (front != 1)
	{
		x = a[front];
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else
		{
			front ++;
			if (front > MAX - 1)
				front = 0;
		}
		return 1;
	}
	return 0;
}
int isfull(int a[], int &front, int &rear)
{
	if (rear == MAX - 1)
		return 1;
	return 0;
}
int isempty(int a[], int &front, int &rear)
{
	if ((front == -1) || (rear == -1))
		return 1;
	return 0;
}
void xuat( int a[], int &front, int &rear)
{
		for (int i = rear; i >= front; i--)
			cout << a[i] << endl;
	
}
int main()
{
	int x, t, chon;
	char tt;
	do{
		cout << "\nNhap chon:\n"
			 << "1. Khoi tao\n"
			 << "2. Kiem tra rong\n"
			 << "3. Kiem tra day\n"
			 << "4. Them 1 phan tu\n"
			 << "5. Xoa 1 phan tu\n"
			 << "6. Them 1 phan tu theo kieu vong\n"
			 << "7 Xxoa 1 phan tu theo kieu vong\n"
			 << "8. Xuat danh sach\n"
			 << "Chon: ";
		cin >> chon;
		switch(chon)
		{
			case 1:
				init(a, front, rear);
				cout << "Khoi tao danh sach thanh cong\n";
				break;
			case 2:
				if (isempty(a, front, rear) != 0)
					cout << "Danh sach rong\n";
				else
					cout << "Danh sach khong rong\n";
				break;
			case 3:
				if (isfull(a, front, rear) != 0)
					cout << "Danh sach day\n";
				else
					cout << "Danh sach chua day\n";
				break;
			case 4:
				cout << "Nhap gia tri muon them: ";
				cin >> x;
				t = push(a, front, rear, x);
				if (t != 0)
					cout << "Them thanh cong!\n";
				else
					cout << "Stack day khong the them!\n";
				break;
			case 5:
				t = pop(a, front, rear, x);
				if (t != 0)
					cout << "Phan tu lay ra co gia tri la "<<x<<"\n";
				else
					cout << "Queue rong!\n";
				break;
			case 6:
				cout << "Nhap gia tri muon them: ";
				cin >> x;
				t = pust(a, front, rear, x);
				if (t != 0)
					cout << "Them thanh cong!\n";
				else
					cout << "Stack day khong the them!\n";
				break;
			case 7:
				t = pop1(a, front, rear, x);
				if (t != 0)
					cout << "Phan tu lay ra co gia tri la "<<x<<"\n";
				else
					cout << "Queue rong!\n";
				break;
			case 8:
				cout << "Danh sach cua queue:\n";
				xuat(a, front, rear);
				break;
			default:
				cout << "Gia tri chon khong hop le!\n";
				break;
		}
		cout << "Ban muon tiep tuc khong(Y/N):";
		cin >> tt;
	} while(tt == 'y'|| tt == 'Y');
	return 0;
}