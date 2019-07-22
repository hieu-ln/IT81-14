#include <iostream>
using namespace std;

// Cau 3.1
struct Node
{
	int info;
	Node *link;
};
Node *first;

// Cau 3.2
void init()
{
	first = NULL;
}

// Cau 3.3
void process_list()
{
	Node *p;
	p = first;
	while(p != NULL)
	{
		cout << p -> info << " ";
		p = p->link;
	}
}

// Cau 3.4
Node *Search(int x)
{
	Node *p = first;
	while(p != NULL && (p -> info != x))
		p = p -> link;
	return p;
}

// Cau 3.5
void insert_first(int x)
{
	Node *p;
	p = new Node;
	p -> info = x;
	p -> link = first;
	first = p;
}

// Cau 3.6
int Delete_first()
{
	if(first != NULL)
	{
		Node *p = first;
		first = first -> link;
		delete p;
		return 1;
	}
	return 0;
}

// Cau 3.7
void insert_last(int x)
{
	Node *p;
	p = new Node;
	p -> info = x;
	p -> link = NULL;
	if (first == NULL)
		first = p;
	else
	{
		Node *q = first;
		while (q -> link != NULL)
			q = q -> link;
		q -> link = p;
	}
}

// Cau 3.8
void Delete_last()
{
	Node *p,*q;
	p = first;
	if(p != NULL)
		while(p -> link != NULL)
		{
			q = p;
			p = p -> link;
		}
		q -> link = NULL;
		delete p;
}

// Cau 3.9
int FindADelete(int x)
{
	if(first != NULL)
	{
		Node *p,*q;
		p = first; 
		q = first;
		while(p != NULL && p -> info != x)
		{
			q = p;
			p = p -> link;
		}
		if(p != first && p -> link != NULL)
		{
			//phan tu giua danh sach
			if(p -> link != NULL)
				q -> link = p -> link;
			else
				q -> link = NULL;
			delete p;
			return 1;
		}
		else
			if(p == first)
			{
				//phan tu dau danh sach
				first = p -> link;
				delete p;
				return 1;
			}
			else
				return 0;
	
	}
	return 0;
}

int main()
{
	cout << "1.Khoi tao danh sach rong\n";
	cout << "2.Xuat danh sach\n";
	cout << "3.Tim 1 phan tu trong danh sach\n";
	cout << "4.Them 1 phan tu vao dau danh sach\n";
	cout << "5.Xoa phan tu o dau danh sach\n";
	cout << "6.Them 1 phan tu o cuoi danh sach\n";
	cout << "7.Xoa 1 phan tu cuoi danh sach\n";
	cout << "8.Xoa phan tu can tim\n";
	cout << "9.Thoat!\n";
	int choice;
	int x;
	Node *p;
	do{
		cout << "Ban chon: ";
		cin >> choice;
		if(choice < 1 || choice > 9)
			cout << "Nhap sai.Nhap lai\n";
		switch(choice)
		{
		case 1:
			init();
			cout << "Ban khoi tao danh sach thanh cong!\n";
			break;
		case 2:
			cout << "Danh sach: ";
			process_list();
			cout << endl;
			break;
		case 3:
			
			cout << "Nhap gia tri can tim: ";
			cin >> x;
			p=Search(x);
			if (p!= NULL)
				cout <<" co trong danh sach x= "<<p -> info << endl;
			else
				cout << p -> info << " khong co trong danh sach\n";
			break;
		case 4:
			cout << "Nhap gia tri phan tu them vao: ";
			cin >> x;
			insert_first(x);
			break;
		case 5:
			Delete_first();
			cout << "Danh sach sau khi xoa: ";
			process_list();
			cout << endl;
			break;
		case 6:
			cout << "Nhap gia tri phan tu can them: ";
			cin >> x;
			insert_last(x);
			break;
		case 7:
			Delete_last();
			cout << "Danh sach sau khi xoa cuoi: ";
			process_list();
			cout << endl;
			break;
		case 8:
			cout << "Nhap gia tri phan tu can tim: ";
			cin >> x;
			if (FindADelete(x) != 0)
			{
				cout << "Danh sach sau khi xoa phan tu can tim: ";
				process_list();
			}
			else
				cout << "Khong tim thay phan tu can xoa\n";
			cout << endl;
			break;
		case 9:
			break;
		default:
			break;
		}
	} while (choice != 9);
	return 0;
}