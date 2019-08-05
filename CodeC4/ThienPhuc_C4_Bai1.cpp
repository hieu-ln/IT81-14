//Bai1
#include<stdio.h>
#include<iostream>
using namespace std;

#define COUNT 20
//1.1
struct Node
{
	int info;
	Node *left;
	Node *right;
};
Node *root;
//1.2
void tree_empty()
{
	root = NULL;
}
//1.3
void InsertNode(Node *&p, int x)
{
	if(p == NULL)
	{
		p = new Node;
		p ->info = x;
		p ->left = NULL;
		p ->right = NULL;
	}
	else
	{
		if(p -> info == x)
			return;
		else if(p ->info > x)
			return InsertNode(p ->left, x);
		else
			return InsertNode(p ->right, x);
	}
}
//1.4
Node *search(Node *p, int x)
{
	if(p != NULL)
	{
		if(p ->info == x)
			return p;
		else 
			if(x > p->info)
				return search(p ->right, x);
			else
				return search(p ->left, x);
	}
	return NULL;
}
//1.5
void searchStandFor(Node *&p, Node *&q)
{
	if(q->left == NULL)
	{
		p ->info = q->info;
		p = q;
		q = q->right;
	}
	else
		searchStandFor(p, q->left);
}
int Delete(Node *&T ,int x)
{
	if(T == NULL)
		return 0;
	if(T-> info == x)
	{
		Node *p = T;
		if(T->left == NULL)
			T = T->right;
		else if(T->right == NULL)
			T = T->left;
		else
			searchStandFor(p, T->right);
		delete p;
		return 1;
	}
	if(T->info < x)
		return Delete(T->right, x);
	if(T->info > x)
		return Delete(T->left, x);
}
//1.6
void duyetNLR(Node *p)
{
	if(p != NULL)
	{
		cout << p->info <<" ";
		duyetNLR(p ->left);
		duyetNLR(p -> right);
	}
}
//1.7
void duyetLNR(Node *p)
{
	if(p != NULL)
	{
		duyetLNR(p ->left);
		cout << p->info <<" ";
		duyetLNR(p -> right);
	}
}
//1.8
void duyetLRN(Node *p)
{
	if(p != NULL)
	{
		duyetLRN(p ->left);
		duyetLRN(p -> right);
		cout << p->info <<" ";
	}
}
void print2DUtil(Node *p, int space)
{
	if(p == NULL)
		return;
	space += COUNT;
	print2DUtil(p->right, space);
	cout << endl;
	for(int i = COUNT; i < space; i++)
		cout <<" ";
	cout << p->info <<"\n";
	print2DUtil(p ->left, space);
}
void Process_Tree()
{
	print2DUtil(root, 0);
}
int main()
{
	int choice = 0;
	int x, i;
	Node *p;
	system("cls");
	cout <<"-------------BAI TAP 1, CHUONG 4, CAY NHI PHAN--------------/n";
	cout <<"1. Khoi tao cay NPTK rong" << endl;
	cout <<"2. Them phan tu vao cay NPTK\n";
	cout <<"3. Tim mot phan tu co gia tri x trong cay NPTK\n";
	cout <<"4. Xoa mot phan tu co gia tri x trong cay NPTK\n";
	cout <<"5. Duyet cay nhi phan tim kiem theo LNR\n";
	cout <<"6. Duyet cay nhi phan tim kiem theo NLR\n";
	cout <<"7. Duyet cay nhi phan tim kiem theo LRN\n";
	cout <<"8. Xuat cay NPTK\n";
	cout <<"9. Thoat\n";
	do{
		cout <<"\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch(choice)
		{
		case 1:
			tree_empty();
			cout <<"Ban vua khoi tao cay NPTK rong thanh cong\n";
			break;
		case 2:
			cout <<"Vui long nhap gia tri x can them: ";
			cin >> x;
			InsertNode(root, x);
			cout <<"Cay nhi phan tim kiem sau khi them la\n";
			Process_Tree();
			break;
		case 3:
			cout <<"Vui long nhap gia tri x can tim: ";
			cin >> x;
			p = search(root, x);
			if(p != NULL)
				cout <<"Tim thay x = " << x << "trong cay NPTK\n";
			else
				cout <<"Khong tim thay x = " << x << "trong cay NPTK\n";
		case 4:
			cout <<"Vui long nhap gia tri x can xoa: ";
			cin >> x;
			i = Delete(root, x);
			if(i == 0)
				cout <<"Xoa khong thanh cong\n";
			else
			{
				cout <<"Xoa thanh cong. Mang sau khi xoa la:\n";
				Process_Tree();
			}
			break;
		case 5:
			cout <<"Cay nhi phan tim kiem duyet theo LNR la: ";
			duyetLNR(root);
			break;
		case 6:
			cout <<"Cay nhi phan tim kiem duyet theo NLR la: ";
			duyetNLR(root);
			break;
		case 7:
			cout <<"Cay nhi phan tim kiem duyet theo LRN la: ";
			duyetLRN(root);
			break;
		case 8:
			cout <<"Cay NPTK nhu sau: ";
			Process_Tree();
			break;
		case 9:
			cout <<"Goodbye\n";
			break;
		default:
			break;
		}
	}while(choice != 10);
	system("pause");
	return 0;
}