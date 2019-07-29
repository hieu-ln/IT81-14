//Project: C2_Bai1_Cau2.cpp
#include <iostream>
using namespace std;

#define MAX 100
int a[MAX];
int n;

void nhap(int a[], int &n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}

void xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
}

int tim(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
		i++;
	if (i == n)
		return -1;
	else
		return i;
}

int them1(int a[], int &n, int x)
{
	int i;
	if ( n < MAX)
	{
		for (i = 0; i < n; i++)
		{
			if (a[i] > x)
			{
					for(int j = n - 1; j >= i; j--)
						a[j + 1] = a[j];
			}
			
		}
		a[i] = x;
		n++;
		return 1;
	}
	return 0;
}

int them(int a[], int &n, int x, int i)
{
	if ( i<= n && n < MAX)
	{
		for(int j = n - 1; j >= i; j--)
			a[j + 1] = a[j];
		n++;
		a[i] = x;
		return 1;
	}
	return 0;
}

int xoa(int a[], int &n, int i)
{
	if ( i >= 0 && i < n)
	{
		for (int j = i; j < n - 1; j++)
			a[j ] =a[j + 1];
		n--;
		return 1;
	}
	return 0;
}

bool timnhiphan(int a[], int n, int x)
{
	int mid , left = 0, right = n;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == x)
			return true;
		else
			if(a[mid] < x)
				right = mid - 1;
			else
				left = mid + 1;
	}
	return false;
}

int main()
{
	int x, i, t, chon;
	bool ti;
	do
	{
	cout << "Nhap so phan tu cua mang duoi 100 phan tu: ";
	cin >> n;
	if(n < 0 || n > 100)
		cout << "Nhap sai. Nhap lai\n";
	} while(n < 0 || n > 100);
	while (true)
	{
		cout << "\nNhap chon:\n"
			 << "0. Thoat\n"
			 << "1. Nhap vao n phan tu\n"
			 << "2. Them phan tu \n"
			 << "3. Tim nhi phan\n"
			 << "4. Tim\n"
			 << "5. Xuat danh sach\n"
			 << "6. Xoa phan tu\n"
			 << "Chon: ";
		cin >> chon;
		switch(chon)
		{
		case 0:
			return 1;
			break;
		case 1:
			nhap(a, n);
			break;
		case 2:
			cout << "Nhap gia tri can them vao mang: ";
			cin >> x;
			t = them1(a, n, x);
			if (t != 0)
				cout << "Them thanh cong\n";
			else
				cout << "Them khong thanh cong\n";
			break;
		case 3:
			cout << "Nhap gia tri can tim vao mang: ";
			cin >> x;
			ti = timnhiphan(a, n, x);
			if (ti == true)
			{
				cout<<"tim thanh cong\n";
			}
			else
				cout<<"tim khong thanh cong\n";
			break;
		case 4:
			cout << "Nhap vi tri can tim: ";
			cin >> x;
			t = tim(a, n, x);
			if (t != -1)
				cout << "Tim thay " << x << " o vi tri " << t << endl;
			else
				cout<<"Khong tim thay ";
			break;
		case 5:
			xuat(a, n);
			break;
		case 6:
			cout << "Nhap vi tri can xoa: ";
			cin >> i;
			t = xoa(a, n, i);
			if(t != 0)
				cout << "Xoa thanh cong\n";
			else
				cout << "Xoa khong thanh cong\n";
			break;
		default:
			cout << "Gia tri chon khong hop le\n";
			break;
		}
	}
	return 0;
}