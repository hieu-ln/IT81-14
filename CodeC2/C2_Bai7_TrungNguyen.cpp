#include <iostream>
#include <conio.h>
using namespace std;
#define MAX 100
int a[MAX];
int front, rear;

void init()
{
	front = -1;
	rear = -1;
}
bool isEmpty()
{
	if(front == - 1 || rear == -1 )
		return 1;
	return 0;
}
bool isFull()
{
	if(rear - front ==  MAX - 1)
		return 1;
	return 0;
}
int Push(int x)
{
	if(isFull())
		return 0;
	else
	{
		if(front == -1)
			front = 0;
		if(rear == MAX - 1)
		{
			for(int i = front; i <= rear; i++)
				a[i - front] = a[i];
			rear = MAX - 1 - front;
			front = 0;
		}
		a[++rear] = x;
		return 1;
	}
}
int Pop(int &x)
{
	if(front == -1)
		return 0;
	else
	{
		x = a[rear--];
		if(front > rear)
			init();
		return 1;
	}
}
void xuat()
{
	cout << "Danh Sach gom cac phan tu: \n";
	for (int i = rear; i >= front; i--)
	{
		cout << a[i] << endl;
	}
}
int main()
{
	int c = 0, x;
	while(c != 6)
	{
		system("cls");
		cout << "1. Khoi Tao\n2. Kiem tra rong\n3. Kiem tra day\n4. Them 1 phan tu\n5. Xoa 1 phan tu\n6. Xuat\n7. Thoat!\nChon: ";
		cin >> c;
		switch(c)
		{
		case 1:
			init();
			cout << "Khoi tao thanh cong\n";
			break;
		case 2:
			if(isEmpty() == true)
				cout << "Danh sach rong!\n";
			else
				cout << "Danh sach ko rong\n";
			break;
		case 3:
			if(isFull() == true)
				cout << "Danh sach da day\n";
			else
				cout << "Danh sach chua day\n";
			break;
		case 4:
			cout << "Nhap vao phan tu muon them: ";
			cin >> x;
			if(Push(x))
				cout << "Them thanh cong\n";
			else
				cout << "Them that bai\n";
			break;
		case 5:
			int y;
			if(Pop(y))
				cout << "Phan tu vua lay ra la: " << y << endl;
			else
				cout << "lay that bai!\n";
			break;
		case 6:
			xuat();
			break;
		case 7:
			cout << "Tam biet\n";
			break;
		default:
			cout << "Ko co trong lua chon, moi chon lai!\n";
		}
		_getch();
	}
	return 0;
}