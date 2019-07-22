#include <iostream>
#include <conio.h>
using namespace std;
#define MAX 100
struct type
{
	int n;
	char a = 'A', b = 'B', c = 'C';
};
type a[MAX];
int sp;

void init(type a[], int &sp)
{
	sp = -1;
}

bool isEmpty(type a[], int sp)
{
	if(sp == -1)
		return 1;
	return 0;
}
bool isFull(type a[], int sp)
{
	if(sp == MAX - 1)
		return 1;
	return 0;
}
int Push(type a[], int &sp, type x)
{
	if(sp < MAX - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}
int Pop(type a[], int &sp, type &x)
{
	if(sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}
void THN(type a[], int sp, type x)
{
	type temp1, temp2;
	init(a, sp);
	Push(a, sp, x);
	do {
		Pop(a, sp, temp1);
		if (temp1.n == 1)
			cout << "Chuyen dia tu " << temp1.a << " sang " << temp1.b << endl;
		else
		{
			//Move(n-1, c, b, a)
			temp2.n = temp1.n - 1;
			temp2.a = temp1.c;
			temp2.b = temp1.b;
			temp2.c = temp1.a;
			Push(a, sp, temp2);
			//Move(1, a, b, c)
			temp2.n = 1;
			temp2.a = temp1.a;
			temp2.b = temp1.b;
			temp2.c = temp1.c;
			Push(a, sp, temp2);
			//Move(n-1, a, c, b)
			temp2.n = temp1.n - 1;
			temp2.a = temp1.a;
			temp2.b = temp1.c;
			temp2.c = temp1.b;
			Push(a, sp, temp2);
		}
	} while (!isEmpty(a, sp));
}
int main()
{
	type n;
	cout << "Nhap so luong dia: ";
	cin >> n.n;
	THN(a, sp, n);
	return 0;
}