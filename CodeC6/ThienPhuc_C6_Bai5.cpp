#include <iostream>
#include <fstream>
#include <stdio.h>
#include <iomanip>
using namespace std;
# define MAX 20
int a[MAX][MAX];
int n; // so dinh cua do thi
char vertex[MAX];

void initG()
{
	n = 0;
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
// khai bao TapE
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE = 0; // so phan tu tap E
 //khai bao Tap T
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT = 0; // so phan tap T
int TonTai(int d, int D[], int nD)
{
	for (int i = 0; i < nD; i++)
		if (D[i] == d)
			return 1;
	return 0;
}
void kruskal()
{
	for (int i = 0; i < nE; i++)
	{
		if (TonTai(E1[i], T1, nT) == 1 && TonTai(E2[i], T2, nT) == 1)
			continue;
		if (TonTai(E1[i], T2, nT) == 1 && TonTai(E2[i], T1, nT) == 1)
			continue;
		T1[nT] = E1[i];
		T2[nT] = E2[i];
		wT[nT] = wE[i];
		nT++;
		if (nT == n - 1)
			break;
	}
}

void taoE()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] != 0)
			{
				E1[nE] = i;
				E2[nE] = j;
				wE[nE] = a[i][j];
				a[i][j] = 0;
				a[j][i] = 0; 			
				nE++;
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
	cout << "2. Nhap ma tran ke" << endl;
	cout << "3. Xuat ma tran ke" << endl;
	cout << "4. Tim cay khung toi tieu bang KRUSKAL" << endl;
	cout << "5. Thoat" << endl;
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
			inputG();
			break;
		case 3:
			outputG();
			break;
		case 4:
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			(x);
			cout << "Cay khung toi tieu voi prim: " << endl;
			output(true);
			break;
		case 5:
			cout << "Goodbye!" << endl;
			break;
		default:
			break;
		}
	}while (choice != 5);
	system("pause");
	return 0;
}