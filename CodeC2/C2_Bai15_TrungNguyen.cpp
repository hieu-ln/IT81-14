// Bai 15 Chuong 2
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 100
typedef int SET [MAX];
int n;
void input (SET a, int &n)
{
	cout << "Nhap vao so luong phan tu cua danh sach: ";
	cin >> n;
	cout << "Nhap vao cac phan tu cua danh sach: " << endl;
	for (int i = 0 ; i < n; i++)
	{
		cout << "a[" << i << "]=";
		cin >> a[i];
	}
}
void output (SET a, int n)
{
	for (int i = 0; i < n;i++)
		cout << a[i] << "\t";
	cout << endl;
}
int search (SET a, int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
	{
		i++;
		if (i < n)
			return i;
	}
	return -1;
}
void makeNull(SET a)
{
	int i;
	for (i = 0; i < MAX; i++)
		a[i] = 0;
}
void SET_Union (SET a, SET b, SET c)
{
	int i;
	for (i = 0; i < MAX; i++)
		if ((a[i] == 1)||(b[i] == 1)) 
			c[i] = 1;
		else 
			c[i] = 0;
}
void SET_Intersection (SET a,SET b, SET c)
{
	int i;
	for (i = 0; i < MAX; i++)
		if ((a[i] == 1) && (b[i] == 1)) 
			c[i] = 1;
		else 
			c[i] = 0;
}
int main()
{
		int choice = 0;
	int x, i;
	system ("cls");
	cout << "-------- BAI TAP 15, CHUONG 2 DANH SACH DAC --------" << endl;
	cout << "1.Xuat cac phan tu thuoc tap hop cua hai danh sach" << endl;
	cout << "2.Xuat cac phan tu thuoc tap giao cua hai danh sach" << endl;
	cout << "3.Xuat danh sach phan bu cua hai danh sach" << endl;
	cout << "4.Thoat" << endl;
	do{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
			case 1:
				cout << "Tap hop cac phan tu cua 2 danh sach" << endl;
				SET_Union(SET a, SET b, SET c);
				break;
			case 2:
				cout << "Tap giao cac phan tu cua 2 danh sach" << endl;
				SET_Intersection(SET a, SET b, SET c);
				break;
			case 3:
				cout << "Danh sach phan bu cua 2 danh sach" << endl;
				SET_Intersection(SET a, SET b, SET c);
				break;
			case 4:
				cout << "Goodbye!\n";
				break;
			default:
				break;
		}
	}while(choice != 5);
	system ("pause");
	return 0;
}