#include <iostream>
#include <conio.h>
using namespace std;

struct Node
{
	int info;
	Node *link;
};
Node * sp1, *sp2;
void init(Node *sp)
{
	sp = NULL;
}
bool isEmpty(Node* sp)
{
	if(sp == NULL)
		return 1;
	return 0;
}
void Push(Node* &sp, int x)
{
	Node * p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}
void Pop(Node* &sp, int &x)
{
	if(sp != NULL)
	{
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
	}
}

void xuat(Node* sp)
{
	cout << "Danh Sach gom cac phan tu: \n";
	Node* p = sp;
	while (p != NULL)
	{
		cout << p->info << endl;
		p = p->link;
	}
}
void xuatTH(Node* sp1, Node* sp2)
{
	cout << "Danh Sach gom cac phan tu: \n";
	Node* p = sp1;
	while(p != NULL)
	{
		cout << p->info << endl;
		p = p->link;
	}
	Node* q = sp2;
	while (q != NULL)
	{
		cout << q->info << endl;
		q = q->link;
	}
}
void xuatPhangiao(Node* sp1, Node* sp2)
{
	cout << "Danh Sach gom cac phan tu: \n";
	for (Node* i = sp1; i != NULL;i = i->link)
		for (Node* j = sp2; j != NULL;j = j->link)
			if (i->info == j->info)
			{
				cout << i->info << " ";
				break;
			}
}
void xuatPhanbu(Node* sp1, Node* sp2)
{
	cout << "Danh Sach gom cac phan tu: \n";
	for (Node* i = sp1; i != NULL; i = i->link)
		for (Node* j = sp2; j != NULL;j = j->link)
			if (i->info != j->info)
			{
				cout << i->info << " ";
				break;
			}
}
void submenu(Node* &sp)
{
	int c = 0, x;
	while (c != 6)
	{
		system("cls");
		cout << "1. Khoi Tao\n2. Kiem tra rong\n3. Them 1 phan tu\n4. Xoa 1 phan tu\n5. Xuat\n6. Thoat!\nChon: ";
		cin >> c;
		switch (c)
		{
		case 1:
			init(sp);
			cout << "Khoi tao thanh cong\n";
			break;
		case 2:
			if (isEmpty(sp) == true)
				cout << "Danh sach rong!\n";
			else
				cout << "Danh sach ko rong\n";
			break;
		case 3:
			cout << "Nhap vao phan tu muon them: ";
			cin >> x;
			Push(sp, x);
			cout << "Them thanh cong\n";
			break;
		case 4:
			int y;
			if (isEmpty(sp))
				cout << "Lay that bai\n";
			else
			{
				Pop(sp, y);
				cout << "Phan tu vua lay duoc la: " << y << endl;
			}
			break;
		case 5:
			xuat(sp);
			break;
		case 6:
			cout << "Tam biet\n";
			break;
		default:
			cout << "Ko co trong lua chon, moi chon lai!\n";
			break;
		}
		_getch();
	}
}
int main()
{
	int c;
	do {
		system("cls");
		cout << "1.Thao tac voi DS1\n2. Thao tac voi DS2\n3. Xuat tap hop 2 DS\n4. Xuat tap hop giao\n5. Xuat phan bu cua DS1 doi voi DS2\n6. Xuat phan bu cua DS2 doi voi DS1\n7. Thoat!\nCHon: ";
		cin >> c;
		switch (c)
		{
		case 1:
			submenu(sp1);
			break;
		case 2:
			submenu(sp2);
			break;
		case 3:
			xuatTH(sp1, sp2);
			break;
		case 4:
			xuatPhangiao(sp1, sp2);
			break;
		case 5:
			xuatPhanbu(sp1, sp2);
			break;
		case 6:
			xuatPhanbu(sp2, sp1);
			break;
		case 7:
			cout << "Tam biet!\n";
			break;
		default:
			cout << "Ko co trong lua chon!\n";
			break;
		}
		_getch();
	} while (c != 7);
	return 0;
}
