#include <iostream>
#include <conio.h>
using namespace std;

struct Node
{
	int info;
	Node *link;
};
Node * sp;
void init()
{
	sp = NULL;
}
bool isEmpty()
{
	if(sp == NULL)
		return 1;
	return 0;
}
void Push(int x)
{
	Node * p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}
void Pop(int &x)
{
	if(sp != NULL)
	{
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
	}
}
int convert(int so)
{
	init();
	int np = 0;
	while(so != 0)
	{
		int du = so % 2;
		Push(du);
		so /= 2;
	}
	while(!isEmpty())
	{
		int x;
		Pop(x);
		np = np * 10 + x;
	}
	return np;
}
void xuat()
{
	cout << "Danh Sach gom cac phan tu: \n";
	Node * p = sp;
	while(p != NULL)
	{
		cout << p->info << endl;
		p = p->link;
	}
}
int main()
{
	int c = 0, x;
	while(c != 7)
	{
		system("cls");
		cout << "1. Khoi Tao\n2. Kiem tra rong\n3. Them 1 phan tu\n4. Xoa 1 phan tu\n5. Xuat\n6. Chuyen doi\n7. Thoat!\nChon: ";
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
			cout << "Nhap vao gia tri muon chuyen doi: ";
			cin >> x;
			cout << "Gia tri sau khi chuyen doi: " << convert(x) << endl;
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
