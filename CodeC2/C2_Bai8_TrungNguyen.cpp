//Bai 8 Chuong 2
#include <iostream>
using namespace std;
struct Node
{
	int data;
	struct Node *pNext;
};
typedef struct Node Node;
struct stack
{
	Node *pTop;
};
typedef struct stack STACK;
void KhoiTaoStack(STACK &s)
{
	s.pTop = NULL;
}

void Init(STACK &s)
{
	s.pTop = NULL;
}
Node *KhoiTaoNode(int x)
{
	Node *p = new Node();
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		return NULL;
	}
	p->data = x;
	p->pNext = NULL;
	return p;
}
bool IsEmpty(STACK s)
{
	if (s.pTop == NULL)
		return false;
	return true;
}
bool Push(STACK &s, Node *p)
{
	if (p == NULL)
		return false;
	if (IsEmpty(s) == false)
		s.pTop = p;
	else
	{
		p->pNext = s.pTop; 
		s.pTop = p;
	}
	return true;
}
bool Pop(STACK &s, int &x)
{
	if (IsEmpty(s) == false)
		return false;
	Node *p = s.pTop; 
	s.pTop = s.pTop->pNext;  
	x = p->data;
	return true; 
}
bool Top(STACK s, int &x)
{
	if (IsEmpty(s) == false)
		return false;
	x = s.pTop->data;
	return true;
}
void outputStack(STACK &s)
{
	while (IsEmpty(s) == true)
	{
		int x;
		Pop(s, x);
		if (x < 10)	
			cout << x;
		else
		{
			if (x == 10)
				cout << "A";
			else if (x == 11)
				cout << "B";
			else if (x == 12)
				cout << "C";
			else if (x == 13)
				cout << "D";
			else if (x == 14)
				cout << "E";
			else if (x == 15)
				cout << "F";
		}
	}
}
void DoiCoSo (STACK &s, int coSoCanDoi, int heThapPhan)
{
	while (heThapPhan != 0)
	{
		int x = heThapPhan % coSoCanDoi;
		Node *p = KhoiTaoNode(x);
		Push(s, p);
		heThapPhan /= coSoCanDoi;
	}
}
int main()
{
	STACK s;
	KhoiTaoStack(s);
	int hethapphan;
	cout << "\nNhap gia tri he thap phan(10) can chuyen: ";
	cin >> hethapphan;
	int cosocandoi;
	cout << "\nNhap co so can chuyen(2, 8, 16):  ";
	cin >> cosocandoi;
	DoiCoSo(s, cosocandoi, hethapphan);
	cout << "\nKET QUA\n";
	outputStack(s);
	cout << endl;
	system("pause");
	return 0;
}