#include <iostream>
#include <conio.h>
using namespace std;
struct Node
{
	int info;
	Node * link;
};
Node * front, *rear;
void init()
{
	front = NULL;
	rear = NULL;
}
bool isEmpty()
{
	if(front == NULL)
		return 1;
	return 0;
}
void Push(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if(rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
void Pop(int &x)
{
	if(front != NULL)
	{
		Node *p = front;
		x = p->info;
		front = front->link;
		if(front == NULL)
			rear = NULL;
		delete p;
	}
}
void xuat()
{
	cout << "Danh Sach gom cac phan tu: \n";
	Node * p = front;
	while(p != NULL)
	{
		cout << p->info << endl;
		p = p->link;
	}
}
int main()
{
	int c = 0, x;
	while(c != 6)
	{
		system("cls");
		cout << "1. Khoi Tao\n2. Kiem tra rong\n3. Them 1 phan tu\n4. Xoa 1 phan tu\n5. Xuat\n6. Thoat!\nChon: ";
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
			cout << "Nhap vao phan tu muon them: ";
			cin >> x;
			Push(x);
			cout << "Them thanh cong\n";
			break;
		case 4:
			int y;
			if(isEmpty())
				cout << "Lay that bai\n";
			else
			{
				Pop(y);
				cout << "Phan tu vua lay duoc la: " << y << endl;
			}
			break;
		case 5:
			xuat();
			break;
		case 6:
			cout << "Tam biet\n";
			break;
		default:
			cout << "Ko co trong lua chon, moi chon lai!\n";
		}
		_getch();
	}
	return 0;
}