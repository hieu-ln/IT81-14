#include <iostream>
#include <fstream>
#include <stdio.h>
#include <iomanip>
using namespace std;

//khai bao ma tran
#define MAX 20
int a[MAX][MAX];
int n;
char vertex[MAX];

void initG()
{
	n = 0;
}
void inputGfromtext()
{
	string line;
	ifstream myfile("matrantrongso1.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				myfile >> a[i][j];
		}
	}
}
void inputG()
{
	cout << "Nhap so dinh do thi n: ";
	cin >> n;
	cout << "Nhap ten dinh: ";
	for (int i = 0; i < n; i++)
		cin >> vertex[i];
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap vao dong thu" << i + 1 << ": ";
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
}
//xuat ma tran ke cua do thi
void outputG()
{
	cout << setw(6) << left;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << setw(6) << left;
		cout << endl;
	}
}
//khai bao tap E
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE = 0;
//khai bao tap T
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT = 0;

int tontai(int d, int D[], int nD)
{
	for (int i = 0; i < nD; i++)
		if (D[i] == d)
			return 1;
	return 0;
}
void xoavitriE(int i)
{
	for (int j = i; j < nE; j++)
	{
		E1[j] = E1[j + 1];
		E2[j] = E2[j + 1];
		wE[j] = wE[j + 1];
	}
	nE--;
}
void xoacanhE(int u, int v)
{
	for (int i = 0; i < nE; i++)
		if (E1[i] == u && E2[i] == v)
		{
			xoavitriE(i);
			break;
		}
}
//Prim
void prim(int s)
{
	int u = s, min, i, d1, d2;
	while (nT < n - 1)
	{
		for (int v = 0; v < n; v++)
		{
			if (a[u][v] != 0)
				if (tontai(v, T2, nT) == 0)
				{
					E1[nE] = u;
					E2[nE] = v;
					wE[nE] = a[u][v];
					nE++;
				}
			for (i = 0; i < nE; i++)
				if (tontai(E2[i], T2, nT) == 0)
				{
					min = wE[i];
					d1 = E1[i];
					d2 = E2[i];
					break;
				}
			for (i = 0; i < nE; i++)
				if (tontai(E2[i], T2, nT) == 0)
					if (min > wE[i])
					{
						min = wE[i];
						d1 = E1[i];
						d2 = E2[i];
					}
			T1[nT] = d1;
			T2[nT] = d2;
			wT[nT] = a[d1][d2];
			a[d1][d2] = 0;
			a[d2][d1] = 0;
			nT++;
			xoacanhE(d1, d2);
			u = d2;
		}
	}
}
void output(bool vertexname)
{
	int tong = 0;
	for (int i = 0; i < nT; i++)
	{
		if (vertexname)
			cout << endl << "(" << vertex[T1[i]] << "," << vertex[T2[i]] << ") = " << wT[i];
		else
			cout << endl << "(" << T1[i] << "," << T2[i] << ") = " << wT[i];
		tong += wT[i];
	}
	cout << "\nTong = " << tong;
}
int main()
{
	int choice, x, i;
	cout << "Bai tap 5-----chuong 5-----Do thi" << endl;
	cout << "1. Khoi tao ma tran ke rong " << endl;
	cout << "2. Nhap ma tran ke tu file text" << endl;
	cout << "3. Nhap ma tran ke" << endl;
	cout << "4. Xuat ma tran ke" << endl;
	cout << "5. Tim cay khung toi tieu bang prim" << endl;
	cout << "6. Thoat" << endl;
	do
	{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			initG();
			cout << "Ban vua khoi tao ma tran ke rong thanh cong!";
			break;
		case 2:
			inputGfromtext();
			cout << "Ban vua nhap ma tran ke tu file\n";
			outputG();
			break;
		case 3:
			inputG();
			break;
		case 4:
			outputG();
			break;
		case 5:
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			prim(x);
			cout << "Cay khung toi tieu voi prim: " << endl;
			output(true);
			break;
		case 6:
			cout << "Goodbye!" << endl;
			break;
		default:
			break;
		}
	} while (choice != 6);
	system("pause");
	return 0;
}