#include <iostream>
using namespace std;

struct node
{
	int info;
	node *link;
};
node *front, *rear;

void init()
{
	front = NULL;
	rear = NULL;
}

void push(int x)
{
	node *p;
	p = new node;
	p -> info = x;
	p -> link =  NULL;
	if(rear == NULL)
		front = p;
	else
		rear -> link = p;
	rear = p;
}

int pop( int &x)
{
	if (front != NULL)
	{
		node *p = front;
		x = p -> info;
		front = front -> link;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}

int isempty()
{
	if (front == NULL)
		return 1;
	return 0;
}

void xuat()
{
	node *p;
	p = front;
	while (p != NULL)
	{
		cout << p -> info << endl;
		p = p -> link;
	}
}

int main()
{
	int x,t,chon;
	char tt;
	do{
		cout << "\nNhap chon:\n"
			 << "1. Khoi tao\n"
		 	 << "2. Kiem tra rong\n"
			 << "3. Them 1 phan tu\n"
			 << "4. Xoa 1 phan tu\n"
			 << "5. Xuat danh sach\n"
			 << "Chon: ";
		cin >> chon;
		switch(chon)
		{
			case 1:
				init();
				cout << "Khoi tao danh sach thanh cong\n";
				break;
			case 2:
				if (isempty() != 0)
					cout << "Danh sach rong\n";
				else
					cout << "Danh sach khong rong\n";
				break;
			case 3:
				cout << "Nhap gia tri muon them: ";
				cin >> x;
				push(x);
					cout << "Them thanh cong!\n";
				break;
			case 4:
				t = pop(x);
				if (t != 0)
					cout << "Phan tu lay ra co gia tri la "<<x<<"\n";
				else
					cout << "queue rong!\n";
				break;
			case 5:
				cout << "Danh sach cua queue:\n";
				xuat();
				break;
			default:
				cout << "Gia tri chon khong hop le!\n";
				break;
		}
		cout << "Ban muon tiep tuc khong(Y/N):";
		cin >> tt;
	} while(tt =='y'|| tt =='Y');
	return 0;
}