// Project C2_Bai4_Cau14.cpp
#include <iostream>
using namespace std;

struct Donthuc 
{ 
	float heso; 
	int somu; 
}; 
struct Node 
{
	Donthuc Info; 
	Node *link; 
};  
struct Dathuc 
{ 
	Node *first; 
}; 
void ListInit(Dathuc &tmp) 
{ 
	tmp.first=0; 
} 
void Add(Dathuc &L, Donthuc t) 
{ 
	Node *tmp = new Node; 
	tmp -> Info = t; 
    if (L.first == NULL || L.first -> Info.somu < t.somu) 
    {
		tmp -> link = L.first; 
		L.first=tmp; 
	}
	else 
    {
		Node *cur=L.first; 
		while (cur -> link && cur -> link -> Info.somu >= t.somu) 
		{ 
			cur = cur -> link; 
		} 
		if (cur -> Info.somu == t.somu) 
			cur -> Info.heso += t.heso; 
		else 
		{ 
			tmp -> link = cur -> link; 
			cur -> link = tmp; 
		}
	}
}
void Sub(Dathuc &L, Donthuc t) 
{ 
	Node *tmp = new Node; 
	tmp -> Info = t; 
	if (L.first == NULL || L.first -> Info.somu < t.somu) 
	{
		tmp -> link = L.first; 
		L.first = tmp; 
	} 
	else 
	{
		Node *cur = L.first; 
		while (cur -> link && cur -> link -> Info.somu >= t.somu) 
			cur = cur -> link;
		if (cur -> Info.somu == t.somu) 
			cur -> Info.heso -= t.heso; 
		else 
		{
			tmp -> link = cur -> link; 
			cur -> link = tmp; 
		}
	}
}
void NhapDathuc ( Dathuc &tmp) 
{
	Donthuc t; 
	do 
	{ 
		cout << endl << "He so: ";
		cin >> t.heso; 
		cout << "So mu: ";
		cin >> t.somu; 
		Add(tmp, t);
	} 
	while (t.somu > 0); 
}
void XuatDathuc(Dathuc L) 
{
	Node *cur = L.first;
	if (cur)
	{ 
		cout << cur -> Info.heso << "X^" << cur -> Info.somu; 
		cur = cur -> link; 
	} 
	while (cur) 
	{
		if (cur -> Info.heso)
		{ 
			if (cur -> Info.heso > 0)
				cout << "+"; 
			cout << cur -> Info.heso; 
			if (cur -> Info.somu)
				cout << "X^" << cur -> Info.somu; 
		} 
		cur = cur -> link; 
	} 
} 
Dathuc Cong2Dathuc(Dathuc a, Dathuc b) 
{ 
	Dathuc tmp; 
	ListInit(tmp); 
	Node *cur = a.first; 
	while (cur) 
	{ 
		Add(tmp,cur -> Info); 
		cur = cur -> link; 
	} 
	cur = b.first; 
	 while (cur) 
	 { 
		 Add(tmp, cur -> Info); 
		 cur = cur -> link; 
	 }
	 return tmp; 
}
Dathuc Tru2Dathuc(Dathuc a, Dathuc b) 
{
	Dathuc tmp; 
	ListInit(tmp); 
	Node *cur = a.first; 
	while (cur) 
	{
		Sub(tmp, cur -> Info); 
		cur=cur->link;
	} 
	cur = b.first; 
	while (cur) 
	{ 
		Sub(tmp, cur -> Info); 
		cur = cur -> link;
	} 
	return tmp; 
}
Dathuc Nhan2Dathuc(Dathuc a, Dathuc b) 
{ 
	Dathuc tmp; 
	ListInit(tmp); 
	Node *cur_a = a.first; 
		Node *cur_b; 
	Donthuc t; 
	while (cur_a) 
	{ 
		cur_b = b.first; 
		while (cur_b) 
		{ 
			t.heso = cur_a -> Info.heso * cur_b -> Info.heso; 
			t.somu = cur_a -> Info.somu + cur_b -> Info.somu; 
			Add(tmp, t); 
			cur_b=cur_b -> link; 
		}
		cur_a = cur_a -> link; 
	}
	return tmp; 
} 
void Rutgon(Dathuc &tmp) 
{
	Node *cur; 
	while (tmp.first && tmp.first -> Info.heso == 0) 
	{ 
		cur = tmp.first; 
		tmp.first = tmp.first -> link; 
		delete cur;
	}
	if (tmp.first) 
	{ 
		cur=tmp.first; 
		while (cur -> link) 
		{ 
			if (cur -> link -> Info.heso == 0)
			{ 
				Node *del = cur -> link; 
				cur -> link = del -> link; 
				delete del;
			}
			else 
				cur = cur -> link;
		}
	} 
} 
float TinhGiatri(float X, Dathuc L) 
{ 
	float Ret = 0;
	Node *cur = L.first; 
	while (cur) 
	{
		Ret += cur -> Info.heso * pow(X, cur -> Info.somu); 
		cur = cur -> link; 
	}
	return Ret; 
} 
int main() 
{ 
	Dathuc A, B, C, D, E;
	ListInit(A); 
	ListInit(B); 
	ListInit(C);
	float X; 
	cout << "Nhap da thuc thu nhat: " << endl; 
	NhapDathuc(A); 
	cout << "Da thuc thu nhat: " << endl; 
	XuatDathuc(A); 
	cout << endl << "Nhap da thuc thu hai: " << endl; 
	NhapDathuc(B); 
	cout << endl << "Da thuc thu hai: " << endl; 
	XuatDathuc(B); 
	C = Cong2Dathuc(A, B); 
	cout << endl << "Tong hai da thuc: " << endl; 
	Rutgon(C); 
	XuatDathuc(C); 
	cout << endl << "X = "; 
	cin >> X; 
	cout << endl << "Gia tri da thuc tong: " << TinhGiatri(X, C) << endl; 
	D = Nhan2Dathuc(A, B); 
	cout << endl<<"Tich hai da thuc: " << endl; 
	Rutgon(D); 
	XuatDathuc(D); 
	cout << endl << "X = "; 
	cin >> X; 
	cout << endl << "Gia tri da thuc tich: " << TinhGiatri(X, D) << endl; 
	E = Tru2Dathuc(A, B); 
	cout << endl << "Hieu hai da thuc: " << endl; 
	Rutgon(E); 
	XuatDathuc(E); 
	cout << endl << "X = "; 
	cin >> X; 
	cout << endl << "Gia tri da thuc hieu: " << TinhGiatri(X, E) << endl;
	return 0;
} 